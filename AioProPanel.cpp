// -*- C++ -*-
//
// generated by wxGlade 1.0.0 on Mon Oct 18 22:25:21 2021
//
// Example for compiling a single file project under Linux using g++:
//  g++ MyApp.cpp $(wx-config --libs) $(wx-config --cxxflags) -o MyApp
//
// Example for compiling a multi file project under Linux using g++:
//  g++ main.cpp $(wx-config --libs) $(wx-config --cxxflags) -o MyApp Dialog1.cpp Frame1.cpp
//

#include "AioProPanel.h"

// begin wxGlade: ::extracode
// end wxGlade



AioProPanel::AioProPanel(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style):
  wxPanel(parent, id, pos, size, wxTAB_TRAVERSAL)
{
  // begin wxGlade: AioProPanel::AioProPanel
  wxBoxSizer* sizer_1 = new wxBoxSizer(wxVERTICAL);
  wxFlexGridSizer* sizer_2 = new wxFlexGridSizer(4, 1, 0, 0);
  sizer_1->Add(sizer_2, 0, wxALIGN_CENTER_HORIZONTAL, 0);
  wxBoxSizer* sizer_3 = new wxBoxSizer(wxHORIZONTAL);
  sizer_2->Add(sizer_3, 1, wxEXPAND, 0);
  wxStaticBoxSizer* sizer_13 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Clock Source")), wxVERTICAL);
  sizer_3->Add(sizer_13, 1, wxALL|wxEXPAND, 4);
  clockSourceLabel = new wxStaticText(this, wxID_ANY, wxT("Internal"));
  sizer_13->Add(clockSourceLabel, 0, wxEXPAND|wxLEFT|wxRIGHT, 4);
  wxStaticBoxSizer* sizer_14 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Sample Rate")), wxVERTICAL);
  sizer_3->Add(sizer_14, 1, wxALL|wxEXPAND, 4);
  sampleRateLabel = new wxStaticText(this, wxID_ANY, wxT("47999 Hz"));
  sampleRateLabel->SetBackgroundColour(wxColour(255, 198, 0));
  sizer_14->Add(sampleRateLabel, 0, wxEXPAND|wxLEFT|wxRIGHT, 4);
  wxStaticBoxSizer* sizer_15 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Buffer Size")), wxVERTICAL);
  sizer_3->Add(sizer_15, 1, wxALL|wxEXPAND, 4);
  bufferSizeLabel = new wxStaticText(this, wxID_ANY, wxT("1024"));
  sizer_15->Add(bufferSizeLabel, 0, wxEXPAND|wxLEFT|wxRIGHT, 4);
  wxStaticBoxSizer* sizer_20 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("FW version")), wxHORIZONTAL);
  sizer_3->Add(sizer_20, 0, wxALL|wxEXPAND, 4);
  fwVersionLabel = new wxStaticText(this, wxID_ANY, wxT("21"));
  sizer_20->Add(fwVersionLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  wxStaticBoxSizer* sizer_12 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Prefered Clock Source / Input Status")), wxVERTICAL);
  sizer_2->Add(sizer_12, 0, wxALL|wxEXPAND, 4);
  wxFlexGridSizer* grid_sizer_2 = new wxFlexGridSizer(7, 5, 4, 4);
  sizer_12->Add(grid_sizer_2, 1, wxEXPAND, 0);
  masterButton = new wxRadioButton(this, masterID, wxT("Internal"));
  grid_sizer_2->Add(masterButton, 0, wxALIGN_CENTER_VERTICAL, 0);
  wxStaticText* label_8 = new wxStaticText(this, wxID_ANY, wxEmptyString);
  grid_sizer_2->Add(label_8, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  internalFreqLabel = new wxStaticText(this, wxID_ANY, wxT("44.1 KHz"));
  internalFreqLabel->Hide();
  grid_sizer_2->Add(internalFreqLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  const wxString internalFreqChoice_choices[] = {
    wxT("32 KHz"),
    wxT("44.1 KHz"),
    wxT("48 KHz"),
    wxT("64 Khz"),
    wxT("88.2 KHz"),
    wxT("96 KHz"),
    wxT("128 KHz"),
    wxT("176.4 KHz"),
    wxT("192 KHz"),
  };
  internalFreqChoice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 9, internalFreqChoice_choices);
  grid_sizer_2->Add(internalFreqChoice, 0, wxRESERVE_SPACE_EVEN_IF_HIDDEN, 0);
  internalWarn = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxT("./dialog-warning.png"), wxBITMAP_TYPE_ANY));
  grid_sizer_2->Add(internalWarn, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 16);
  wclkSyncButton = new wxRadioButton(this, wclkSyncID, wxT("Word Clk"));
  grid_sizer_2->Add(wclkSyncButton, 0, 0, 0);
  wclkStatusLabel = new wxStaticText(this, wxID_ANY, wxT("No Lock"));
  grid_sizer_2->Add(wclkStatusLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  wclkFreqLabel = new wxStaticText(this, wxID_ANY, wxEmptyString);
  grid_sizer_2->Add(wclkFreqLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  grid_sizer_2->Add(0, 0, 0, 0, 0);
  wclkWarn = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxT("./dialog-warning.png"), wxBITMAP_TYPE_ANY));
  wclkWarn->Hide();
  grid_sizer_2->Add(wclkWarn, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 16);
  aesSyncButton = new wxRadioButton(this, aesSyncID, wxT("AES"));
  grid_sizer_2->Add(aesSyncButton, 0, 0, 0);
  aesStatusLabel = new wxStaticText(this, wxID_ANY, wxT("No Lock"));
  grid_sizer_2->Add(aesStatusLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  aesFreqLabel = new wxStaticText(this, wxID_ANY, wxEmptyString);
  grid_sizer_2->Add(aesFreqLabel, 0, wxALL, 4);
  grid_sizer_2->Add(0, 0, 0, 0, 0);
  aesWarn = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxT("./dialog-warning.png"), wxBITMAP_TYPE_ANY));
  aesWarn->Hide();
  grid_sizer_2->Add(aesWarn, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 16);
  spdifSyncButton = new wxRadioButton(this, spdifSyncID, wxT("S/PDIF"));
  grid_sizer_2->Add(spdifSyncButton, 0, 0, 0);
  spdifStatusLabel = new wxStaticText(this, wxID_ANY, wxT("Sync"));
  grid_sizer_2->Add(spdifStatusLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  spdifFreqLabel = new wxStaticText(this, wxID_ANY, wxT("48 KHz"));
  grid_sizer_2->Add(spdifFreqLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  grid_sizer_2->Add(0, 0, 0, 0, 0);
  spdifWarn = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxT("./dialog-warning.png"), wxBITMAP_TYPE_ANY));
  spdifWarn->Hide();
  grid_sizer_2->Add(spdifWarn, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 16);
  adatSyncButton = new wxRadioButton(this, adatSyncID, wxT("ADAT"));
  grid_sizer_2->Add(adatSyncButton, 0, 0, 0);
  adatStatusLabel = new wxStaticText(this, wxID_ANY, wxT("Lock"));
  grid_sizer_2->Add(adatStatusLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  adatFreqLabel = new wxStaticText(this, wxID_ANY, wxT("48 KHz"));
  grid_sizer_2->Add(adatFreqLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  grid_sizer_2->Add(0, 0, 0, 0, 0);
  adatWarn = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxT("./dialog-warning.png"), wxBITMAP_TYPE_ANY));
  adatWarn->Hide();
  grid_sizer_2->Add(adatWarn, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 16);
  tcoSyncButton = new wxRadioButton(this, tcoSyncID, wxT("TCO"));
  tcoSyncButton->Enable(0);
  grid_sizer_2->Add(tcoSyncButton, 0, 0, 0);
  tcoStatusLabel = new wxStaticText(this, wxID_ANY, wxT("N/A"));
  grid_sizer_2->Add(tcoStatusLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  tcoFreqLabel = new wxStaticText(this, wxID_ANY, wxEmptyString);
  grid_sizer_2->Add(tcoFreqLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  grid_sizer_2->Add(0, 0, 0, 0, 0);
  tcoWarn = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxT("./dialog-warning.png"), wxBITMAP_TYPE_ANY));
  tcoWarn->Hide();
  grid_sizer_2->Add(tcoWarn, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 16);
  syncInSyncButton = new wxRadioButton(this, syncInSyncID, wxT("Sync In"));
  grid_sizer_2->Add(syncInSyncButton, 0, 0, 0);
  syncInStatusLabel = new wxStaticText(this, wxID_ANY, wxT("No Lock"));
  grid_sizer_2->Add(syncInStatusLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  syncInFreqLabel = new wxStaticText(this, wxID_ANY, wxEmptyString);
  grid_sizer_2->Add(syncInFreqLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  grid_sizer_2->Add(0, 0, 0, 0, 0);
  syncInWarn = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxT("./dialog-warning.png"), wxBITMAP_TYPE_ANY));
  syncInWarn->Hide();
  grid_sizer_2->Add(syncInWarn, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 16);
  wxStaticBoxSizer* sizer_16 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Pitch (PPM)")), wxVERTICAL);
  sizer_2->Add(sizer_16, 1, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 4);
  pitchSlider = new wxSlider(this, pitchID, 0, -50000, 50000, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS|wxSL_LEFT|wxSL_RIGHT);
  sizer_16->Add(pitchSlider, 0, wxEXPAND|wxFIXED_MINSIZE, 0);
  wxBoxSizer* sizer_10 = new wxBoxSizer(wxHORIZONTAL);
  sizer_2->Add(sizer_10, 1, wxEXPAND, 0);
  wxBoxSizer* sizer_4 = new wxBoxSizer(wxVERTICAL);
  sizer_10->Add(sizer_4, 1, wxALL|wxEXPAND, 4);
  const wxString inputLevelBox_choices[] = {
    wxT("+24 dBu"),
    wxT("+19 dBu"),
    wxT("+13 dBu"),
    wxT("+4 dBu"),
  };
  inputLevelBox = new wxRadioBox(this, inputLevelID, wxT("Input Level"), wxDefaultPosition, wxDefaultSize, 4, inputLevelBox_choices, 1, wxRA_SPECIFY_COLS);
  inputLevelBox->SetSelection(2);
  sizer_4->Add(inputLevelBox, 0, wxEXPAND|wxFIXED_MINSIZE, 0);
  sizer_4->Add(20, 4, 0, 0, 0);
  const wxString spdifInBox_choices[] = {
    wxT("Optical"),
    wxT("Coaxial"),
    wxT("Internal"),
  };
  spdifInBox = new wxRadioBox(this, spdifInID, wxT("S/PDIF In"), wxDefaultPosition, wxDefaultSize, 3, spdifInBox_choices, 1, wxRA_SPECIFY_COLS);
  spdifInBox->SetSelection(1);
  sizer_4->Add(spdifInBox, 0, wxEXPAND|wxFIXED_MINSIZE, 0);
  wxBoxSizer* sizer_5 = new wxBoxSizer(wxVERTICAL);
  sizer_10->Add(sizer_5, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 4);
  const wxString outputLevelBox_choices[] = {
    wxT("+24 dBu"),
    wxT("+19 dBu"),
    wxT("+13 dBu"),
    wxT("+4 dBu"),
  };
  outputLevelBox = new wxRadioBox(this, outputLevelID, wxT("Output Level"), wxDefaultPosition, wxDefaultSize, 4, outputLevelBox_choices, 1, wxRA_SPECIFY_COLS);
  outputLevelBox->SetSelection(2);
  sizer_5->Add(outputLevelBox, 0, wxEXPAND, 0);
  sizer_5->Add(20, 4, 0, 0, 0);
  wxStaticBoxSizer* sizer_8 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("S/PDIF Out")), wxVERTICAL);
  sizer_5->Add(sizer_8, 0, wxEXPAND|wxFIXED_MINSIZE, 0);
  spdifOpticalButton = new wxCheckBox(this, spdifOpticalID, wxT("Optical"));
  sizer_8->Add(spdifOpticalButton, 0, 0, 0);
  spdifProButton = new wxCheckBox(this, spdifProID, wxT("Professional"));
  sizer_8->Add(spdifProButton, 0, 0, 0);
  wxBoxSizer* sizer_6 = new wxBoxSizer(wxVERTICAL);
  sizer_10->Add(sizer_6, 1, wxALL|wxEXPAND, 4);
  const wxString analogOutBox_choices[] = {
    wxT("XLR"),
    wxT("RCA"),
  };
  analogOutBox = new wxRadioBox(this, analogOutID, wxT("Analog Out"), wxDefaultPosition, wxDefaultSize, 2, analogOutBox_choices, 1, wxRA_SPECIFY_COLS);
  analogOutBox->SetSelection(0);
  sizer_6->Add(analogOutBox, 0, wxEXPAND|wxFIXED_MINSIZE, 0);
  const wxString phonesLevelBox_choices[] = {
    wxT("Hi-Power"),
    wxT("Lo-Power"),
  };
  phonesLevelBox = new wxRadioBox(this, phonesLevelID, wxT("Phones"), wxDefaultPosition, wxDefaultSize, 2, phonesLevelBox_choices, 1, wxRA_SPECIFY_COLS);
  phonesLevelBox->SetSelection(0);
  sizer_6->Add(phonesLevelBox, 0, wxEXPAND|wxFIXED_MINSIZE, 0);
  wxStaticBoxSizer* sizer_7 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Word Clk Out")), wxVERTICAL);
  sizer_6->Add(sizer_7, 0, wxEXPAND|wxFIXED_MINSIZE, 0);
  singleSpeedWclkButton = new wxCheckBox(this, singleSpeedWclkID, wxT("Single Speed"));
  sizer_7->Add(singleSpeedWclkButton, 0, 0, 0);
  wxStaticBoxSizer* sizer_11 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("TMS")), wxHORIZONTAL);
  sizer_6->Add(sizer_11, 1, wxEXPAND, 0);
  tmsButton = new wxCheckBox(this, tmsID, wxT("Enable"));
  tmsButton->SetToolTip(wxT("Encode AES or S/PDIF input channel status and track markers in the least significant bits of the audio samples."));
  sizer_11->Add(tmsButton, 0, 0, 0);
  
  sizer_2->AddGrowableCol(0);
  SetSizer(sizer_1);
  sizer_1->Fit(this);
  // end wxGlade
}


BEGIN_EVENT_TABLE(AioProPanel, wxPanel)
  // begin wxGlade: AioProPanel::event_table
  EVT_RADIOBUTTON(masterID, AioProPanel::masterCB)
  EVT_CHOICE(wxID_ANY, AioProPanel::internalFreqCB)
  EVT_RADIOBUTTON(wclkSyncID, AioProPanel::wclkSyncCB)
  EVT_RADIOBUTTON(aesSyncID, AioProPanel::aesSyncCB)
  EVT_RADIOBUTTON(spdifSyncID, AioProPanel::spdifSyncCB)
  EVT_RADIOBUTTON(adatSyncID, AioProPanel::adatSyncCB)
  EVT_RADIOBUTTON(tcoSyncID, AioProPanel::tcoSyncCB)
  EVT_RADIOBUTTON(syncInSyncID, AioProPanel::syncInSyncCB)
  EVT_COMMAND_SCROLL_LINEDOWN(pitchID, AioProPanel::pitchDownCB)
  EVT_COMMAND_SCROLL_LINEUP(pitchID, AioProPanel::pitchUpCB)
  EVT_COMMAND_SCROLL_PAGEDOWN(pitchID, AioProPanel::pitchPrevCB)
  EVT_COMMAND_SCROLL_PAGEUP(pitchID, AioProPanel::pitchNextCB)
  EVT_SLIDER(pitchID, AioProPanel::pitchSliderCB)
  EVT_RADIOBOX(inputLevelID, AioProPanel::inputLevelCB)
  EVT_RADIOBOX(spdifInID, AioProPanel::spdifInCB)
  EVT_RADIOBOX(outputLevelID, AioProPanel::outputLevelCB)
  EVT_CHECKBOX(spdifOpticalID, AioProPanel::spdifOpticalCB)
  EVT_CHECKBOX(spdifProID, AioProPanel::spdifProfessionalCB)
  EVT_RADIOBOX(analogOutID, AioProPanel::analogOutCB)
  EVT_RADIOBOX(phonesLevelID, AioProPanel::phonesLevelCB)
  EVT_CHECKBOX(singleSpeedWclkID, AioProPanel::singleSpeedWclkOutCB)
  EVT_CHECKBOX(tmsID, AioProPanel::tmsCB)
  // end wxGlade
END_EVENT_TABLE();


void AioProPanel::masterCB(wxCommandEvent &event)  // wxGlade: AioProPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AioProPanel::masterCB) not implemented yet"));
}

void AioProPanel::internalFreqCB(wxCommandEvent &event)  // wxGlade: AioProPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AioProPanel::internalFreqCB) not implemented yet"));
}

void AioProPanel::wclkSyncCB(wxCommandEvent &event)  // wxGlade: AioProPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AioProPanel::wclkSyncCB) not implemented yet"));
}

void AioProPanel::aesSyncCB(wxCommandEvent &event)  // wxGlade: AioProPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AioProPanel::aesSyncCB) not implemented yet"));
}

void AioProPanel::spdifSyncCB(wxCommandEvent &event)  // wxGlade: AioProPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AioProPanel::spdifSyncCB) not implemented yet"));
}

void AioProPanel::adatSyncCB(wxCommandEvent &event)  // wxGlade: AioProPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AioProPanel::adatSyncCB) not implemented yet"));
}

void AioProPanel::tcoSyncCB(wxCommandEvent &event)  // wxGlade: AioProPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AioProPanel::tcoSyncCB) not implemented yet"));
}

void AioProPanel::syncInSyncCB(wxCommandEvent &event)  // wxGlade: AioProPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AioProPanel::syncInSyncCB) not implemented yet"));
}

void AioProPanel::pitchDownCB(wxScrollEvent &event)  // wxGlade: AioProPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AioProPanel::pitchDownCB) not implemented yet"));
}

void AioProPanel::pitchUpCB(wxScrollEvent &event)  // wxGlade: AioProPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AioProPanel::pitchUpCB) not implemented yet"));
}

void AioProPanel::pitchPrevCB(wxScrollEvent &event)  // wxGlade: AioProPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AioProPanel::pitchPrevCB) not implemented yet"));
}

void AioProPanel::pitchNextCB(wxScrollEvent &event)  // wxGlade: AioProPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AioProPanel::pitchNextCB) not implemented yet"));
}

void AioProPanel::pitchSliderCB(wxCommandEvent &event)  // wxGlade: AioProPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AioProPanel::pitchSliderCB) not implemented yet"));
}

void AioProPanel::inputLevelCB(wxCommandEvent &event)  // wxGlade: AioProPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AioProPanel::inputLevelCB) not implemented yet"));
}

void AioProPanel::spdifInCB(wxCommandEvent &event)  // wxGlade: AioProPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AioProPanel::spdifInCB) not implemented yet"));
}

void AioProPanel::outputLevelCB(wxCommandEvent &event)  // wxGlade: AioProPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AioProPanel::outputLevelCB) not implemented yet"));
}

void AioProPanel::spdifOpticalCB(wxCommandEvent &event)  // wxGlade: AioProPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AioProPanel::spdifOpticalCB) not implemented yet"));
}

void AioProPanel::spdifProfessionalCB(wxCommandEvent &event)  // wxGlade: AioProPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AioProPanel::spdifProfessionalCB) not implemented yet"));
}

void AioProPanel::analogOutCB(wxCommandEvent &event)  // wxGlade: AioProPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AioProPanel::analogOutCB) not implemented yet"));
}

void AioProPanel::phonesLevelCB(wxCommandEvent &event)  // wxGlade: AioProPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AioProPanel::phonesLevelCB) not implemented yet"));
}

void AioProPanel::singleSpeedWclkOutCB(wxCommandEvent &event)  // wxGlade: AioProPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AioProPanel::singleSpeedWclkOutCB) not implemented yet"));
}

void AioProPanel::tmsCB(wxCommandEvent &event)  // wxGlade: AioProPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AioProPanel::tmsCB) not implemented yet"));
}


// wxGlade: add AioProPanel event handlers

