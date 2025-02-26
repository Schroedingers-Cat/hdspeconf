/*! \file HDSPeCard.cpp
 *! \brief RME HDSPe sound card enumeration and common control.
 * 20210810,11,12,0902,06,08,09,10,1117,20,25,1207,08
 * - Philippe.Bekaert@uhasselt.be */

#include <math.h>
#include <stdexcept>
#include <iostream>
#include <string>

#include "HDSPeCard.h"
#include "AES.h"
#include "Aio.h"
#include "AioPro.h"
#include "RayDAT.h"
#include "TCO.h"
#include "MADI.h"

HDSPeCardEnumerator::HDSPeCardEnumerator()
{
  for (int i = -1; snd_card_next(&i) >= 0 && i >= 0; ) {
    char* name;
    snd_card_get_longname(i, &name);
    std::cout << "Card " << i << " : " << name << "\n";

    HDSPeCard* newcard {nullptr};
    try {
      if (strncmp(name, "RME AIO Pro", strlen("RME AIO Pro")) == 0) {
	newcard = new AioProCard(i);
      }
      else if (strncmp(name, "RME AIO", strlen("RME AIO")) == 0) {
	newcard = new AioCard(i);
      }
      else if (strncmp(name, "RME RayDAT", strlen("RME RayDAT")) == 0) {
	newcard = new RayDATCard(i);
      }
      else if (strncmp(name, "RME AES", strlen("RME AES")) == 0) {
	newcard = new AESCard(i);
      }
      else if (strncmp(name, "RME MADI", strlen("RME MADI")) == 0) {
	newcard = new MADICard(i);
      }
    } catch (std::runtime_error& e) {
      std::cerr << e.what() << "\n";
      delete newcard; newcard = nullptr;
    }
    if (newcard)
      cards.push_back(newcard);
  }
}

HDSPeCardEnumerator::~HDSPeCardEnumerator()
{
  for (auto card: cards)
    delete card;
}

//////////////////////////////////////////////////////////////////////////

HDSPeCard::DriverCheck::DriverCheck(SndCard* card)
{
  if (card->getDriver() != "HDSPe")
    throw std::runtime_error(card->getLongName()
			     + " is not a HDSPe driven card.\n");
}

HDSPeCard::HDSPeCard(int index)
  : SndCard      (index)
  , driverCheck  (this)
  , statusPolling(this, "Status Polling")
  , cardRevision (this, "Card Revision")
  , fwBuild      (this, "Firmware Build")
  , serial       (this, "Serial")
  , running      (this, "Running")
  , bufferSize   (this, "Buffer Size")
  , tcoPresent   (this, "TCO Present")  
  , clockMode    (this, "Clock Mode")
  , internalFreq (this, "Internal Frequency")
  , preferredRef (this, "Preferred AutoSync Reference")
  , syncRef      (this, "Current AutoSync Reference")
  , syncStatus   (this, "AutoSync Status")
  , syncFreq     (this, "AutoSync Frequency")
  , sampleRate   (this, "Raw Sample Rate", SndControl::HWDEP)
  , dds          (this, "DDS", SndControl::HWDEP)
{
  if (tcoPresent)
    tco = new HDSPeTCO(this);

  statusPolling.callOnValueChange([this](){ onStatusChange(); });
  statusPolling.set(statusPollFreq);
}

HDSPeCard::~HDSPeCard()
{
  statusPolling.callOnValueChange(nullptr);
  delete tco;
}

void HDSPeCard::onStatusChange(void)
{
  if (statusPolling < statusPollFreq) {
    // Driver deactivates status polling after detecting a change.
    // Re-enable it. Or if other applications want to poll at a different
    // rate, take the maximum of their desired rate and ours.
    statusPolling.set(statusPollFreq);
  }
}

const std::string HDSPeCard::getPrettyName(void) const
{
  return modelName + " (" + std::to_string(serial) + ")";
}

bool HDSPeCard::hasTco(void) const
{
  return tcoPresent;
}

void HDSPeCard::syncToTco(int enable)
{
  if (enable && tcoPresent) {
    preferredRef.set(tcoSyncChoice);
    clockMode.set(0);
  } else if (!enable) {
    clockMode.set(1);
  }
}

bool HDSPeCard::isSyncedToTco(void)
{
  return !isMaster() && ((int)preferredRef == tcoSyncChoice);
}

class wxPanel* HDSPeCard::makeTcoPanel(class wxWindow* parent)
{
  return tco ? new MyTCOPanel(tco, parent) : nullptr;
}

int HDSPeCard::freqRate(unsigned freq)
{
  static const int freqRates[10] = {
    0,
    32000, 44100, 48000,
    64000, 88200, 96000,
    128000, 176400, 192000
  };
  
  return (freq < 0 || freq >= 10) ? 0 : freqRates[freq];
}

int HDSPeCard::nearestStandardSampleRate(int rate)
{
  int speed_factor = 1;

  if (rate >= 112000)
    speed_factor = 4;
  else if (rate >= 56000)
    speed_factor = 2;

  rate /= speed_factor;

  if (rate < 38050)
    rate = 32000;
  else if (rate < 46050)
    rate = 44100;
  else
    rate = 48000;

  return rate * speed_factor;
}

double HDSPeCard::singleSpeedRate(double rate)
{
  if (rate >= 112000.)
    rate *= 0.25;
  else if (rate >= 56000.)
    rate *= 0.5;
  return rate;
}

bool HDSPeCard::isStandardSampleRate(double rate)
{
  return !sampleRateDeviates(rate, nearestStandardSampleRate(rate));
}

bool HDSPeCard::sampleRateDeviates(double rate, double ref)
{
  return rate != 0.0 && ref != 0.0 && fabs(getPitch(rate, ref)) >= 1e-4;
}

bool HDSPeCard::singleSpeedRateDeviates(double rate, double ref)
{
  return sampleRateDeviates(singleSpeedRate(rate), singleSpeedRate(ref));
}

bool HDSPeCard::isRunning(void) const
{
  return running != 0;
}

bool HDSPeCard::isMaster(void) const
{
  return clockMode != 0;
}

int HDSPeCard::getExternalFreq(void) const
{
  return syncFreq[syncRef];
}

int HDSPeCard::getReferenceSampleRate(void) const
{
  return freqRate(isMaster() ? internalFreq+1 : getExternalFreq());
}

double HDSPeCard::getSystemSampleRate(void) const
{
  return (double)sampleRate[0] / (double)sampleRate[1];
}

double HDSPeCard::getInternalSampleRate(void) const
{
  return (double)sampleRate[0] / (double)dds;
}

bool HDSPeCard::internalRateDeviates(void) const
{
  return sampleRateDeviates(getInternalSampleRate(), getSystemSampleRate());
}

bool HDSPeCard::isClockCompatible(unsigned freq) const
{
  return !singleSpeedRateDeviates(freqRate(freq), getSystemSampleRate());
}

double HDSPeCard::getPitch(double rate, double ref)
{
  rate = singleSpeedRate(rate);
  ref = singleSpeedRate(ref);
  return (rate - ref) / ref;
}

double HDSPeCard::getPitch(double rate) const
{
  return getPitch(rate, getReferenceSampleRate());
}

double HDSPeCard::getPitch(void) const
{
  return getPitch(getSystemSampleRate());
}

void HDSPeCard::setPitch(double pitch)
{
  double desiredRate = (double)freqRate(internalFreq+1) * (1.0 + pitch);
  dds.set((double)sampleRate[0] / desiredRate);
}

double HDSPeCard::upPitch(void)
{
  double rate = round(getSystemSampleRate()) + 1.0;
  return getPitch(rate);
}

double HDSPeCard::downPitch(void)
{
  double rate = round(getSystemSampleRate()) - 1.0;
  return getPitch(rate);
}

static double pitchTab[5] = {
    24./25.   - 1.,  // -4%   (25 -> 24)
  1000./1001. - 1.,  // -0.1% (PAL -> NTSC)
                0.,  // neutral
  1001./1000. - 1.,  // +0.1% (NTSC -> PAL)
    25./24.   - 1.   // +4%   (24 -> 25)
};

static double getNextPitch(double pitch)
{
  double newpitch = pitchTab[4];
  for (int i=0; i<4; i++)
    if (pitch < pitchTab[i] - 1e-5) {
      newpitch = pitchTab[i];
      break;
    }
  return newpitch;
}

static double getPrevPitch(double pitch)
{
  double newpitch = pitchTab[0];
  for (int i=4; i>0; i--)
    if (pitch > pitchTab[i] + 1e-5) {
      newpitch = pitchTab[i];
      break;
    }
  return newpitch;
}

double HDSPeCard::nextPitch(void)
{
  return getNextPitch(getPitch());
}

double HDSPeCard::prevPitch(void)
{
  return getPrevPitch(getPitch());  
}

HDSPeTCO::HDSPeTCO(HDSPeCard* _card)
  : card          (_card)
  , ltcIn         (_card, "LTC In")
  , ltcInValid    (_card, "LTC In Valid")
  , ltcInFps      (_card, "LTC In Frame Rate")
  , ltcInDropFrame(_card, "LTC In Drop Frame")
  , ltcInPullFac  (_card, "LTC In Pull Factor")
  , ltcOut        (_card, "LTC Out")
  , ltcRun        (_card, "LTC Run")
  , sampleRate    (_card, "LTC Sample Rate")
  , frameRate     (_card, "LTC Frame Rate")
  , videoFormat   (_card, "TCO Video Format")
  , wckValid      (_card, "TCO WordClk Valid")
  , wckSpeed      (_card, "TCO WordClk Speed")
  , lock          (_card, "TCO Lock")
  , pull          (_card, "TCO Pull")
  , wckConversion (_card, "TCO WordClk Conversion")
  , syncSrc       (_card, "TCO Sync Source")
  , wordTerm      (_card, "TCO WordClk Term")
{
}

HDSPeTCO::~HDSPeTCO()
{
}

void HDSPeTCO::getFrameRate(int *fps, int *df)
{
  static int fpss[6] = { 0, 1, 2, 2, 3, 3 };
  static int dfs[6]  = { 0, 0, 0, 1, 0, 1 };
  if (frameRate > 6)
    throw std::runtime_error("Unrecognized TCO frame rate value "
			     + std::to_string(frameRate) + ".\n");
  *fps = fpss[frameRate];
  *df = dfs[frameRate];
}

void HDSPeTCO::setFrameRate(int fps, int df)
{
  int fr[8] = { 0, 1, 2, 4,   0, 1, 3, 5 };
  frameRate.set(fr[4*df + fps]);
}
