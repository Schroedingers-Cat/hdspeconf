// -*- C++ -*-
//
// generated by wxGlade 1.0.3 on Fri Nov 26 21:56:13 2021
//
// Example for compiling a single file project under Linux using g++:
//  g++ MyApp.cpp $(wx-config --libs) $(wx-config --cxxflags) -o MyApp
//
// Example for compiling a multi file project under Linux using g++:
//  g++ main.cpp $(wx-config --libs) $(wx-config --cxxflags) -o MyApp Dialog1.cpp Frame1.cpp
//

#include "AESPanel.h"

// begin wxGlade: ::extracode
// end wxGlade



AESPanel::AESPanel(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style):
  wxPanel(parent, id, pos, size, wxTAB_TRAVERSAL)
{
  // begin wxGlade: AESPanel::AESPanel
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
  wxFlexGridSizer* grid_sizer_2 = new wxFlexGridSizer(12, 5, 4, 4);
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
  aes1SyncButton = new wxRadioButton(this, aes1SyncID, wxT("AES1"));
  grid_sizer_2->Add(aes1SyncButton, 0, 0, 0);
  aes1StatusLabel = new wxStaticText(this, wxID_ANY, wxT("No Lock"));
  grid_sizer_2->Add(aes1StatusLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  aes1FreqLabel = new wxStaticText(this, wxID_ANY, wxEmptyString);
  grid_sizer_2->Add(aes1FreqLabel, 0, wxALL, 4);
  grid_sizer_2->Add(0, 0, 0, 0, 0);
  aes1Warn = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxT("./dialog-warning.png"), wxBITMAP_TYPE_ANY));
  aes1Warn->Hide();
  grid_sizer_2->Add(aes1Warn, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 16);
  aes2SyncButton = new wxRadioButton(this, aes2SyncID, wxT("AES2"));
  grid_sizer_2->Add(aes2SyncButton, 0, 0, 0);
  aes2StatusLabel = new wxStaticText(this, wxID_ANY, wxT("Lock"));
  grid_sizer_2->Add(aes2StatusLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  aes2FreqLabel = new wxStaticText(this, wxID_ANY, wxT("48 KHz"));
  grid_sizer_2->Add(aes2FreqLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  grid_sizer_2->Add(0, 0, 0, 0, 0);
  aes2Warn = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxT("./dialog-warning.png"), wxBITMAP_TYPE_ANY));
  aes2Warn->Hide();
  grid_sizer_2->Add(aes2Warn, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 16);
  aes3SyncButton = new wxRadioButton(this, aes3SyncID, wxT("AES3"));
  grid_sizer_2->Add(aes3SyncButton, 0, 0, 0);
  aes3StatusLabel = new wxStaticText(this, wxID_ANY, wxT("Lock"));
  grid_sizer_2->Add(aes3StatusLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  aes3FreqLabel = new wxStaticText(this, wxID_ANY, wxT("48 KHz"));
  grid_sizer_2->Add(aes3FreqLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  grid_sizer_2->Add(0, 0, 0, 0, 0);
  aes3Warn = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxT("./dialog-warning.png"), wxBITMAP_TYPE_ANY));
  aes3Warn->Hide();
  grid_sizer_2->Add(aes3Warn, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 16);
  aes4SyncButton = new wxRadioButton(this, aes4SyncID, wxT("AES4"));
  grid_sizer_2->Add(aes4SyncButton, 0, 0, 0);
  aes4StatusLabel = new wxStaticText(this, wxID_ANY, wxT("Lock"));
  grid_sizer_2->Add(aes4StatusLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  aes4FreqLabel = new wxStaticText(this, wxID_ANY, wxT("48 KHz"));
  grid_sizer_2->Add(aes4FreqLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  grid_sizer_2->Add(0, 0, 0, 0, 0);
  aes4Warn = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxT("./dialog-warning.png"), wxBITMAP_TYPE_ANY));
  aes4Warn->Hide();
  grid_sizer_2->Add(aes4Warn, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 16);
  aes5SyncButton = new wxRadioButton(this, aes5SyncID, wxT("AES5"));
  grid_sizer_2->Add(aes5SyncButton, 0, 0, 0);
  aes5StatusLabel = new wxStaticText(this, wxID_ANY, wxT("Lock"));
  grid_sizer_2->Add(aes5StatusLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  aes5FreqLabel = new wxStaticText(this, wxID_ANY, wxT("48 KHz"));
  grid_sizer_2->Add(aes5FreqLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  grid_sizer_2->Add(0, 0, 0, 0, 0);
  aes5Warn = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxT("./dialog-warning.png"), wxBITMAP_TYPE_ANY));
  aes5Warn->Hide();
  grid_sizer_2->Add(aes5Warn, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 16);
  aes6SyncButton = new wxRadioButton(this, aes6SyncID, wxT("AES6"));
  grid_sizer_2->Add(aes6SyncButton, 0, 0, 0);
  aes6StatusLabel = new wxStaticText(this, wxID_ANY, wxT("Lock"));
  grid_sizer_2->Add(aes6StatusLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  aes6FreqLabel = new wxStaticText(this, wxID_ANY, wxT("48 KHz"));
  grid_sizer_2->Add(aes6FreqLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  grid_sizer_2->Add(0, 0, 0, 0, 0);
  aes6Warn = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxT("./dialog-warning.png"), wxBITMAP_TYPE_ANY));
  aes6Warn->Hide();
  grid_sizer_2->Add(aes6Warn, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 16);
  aes7SyncButton = new wxRadioButton(this, aes7SyncID, wxT("AES7"));
  grid_sizer_2->Add(aes7SyncButton, 0, 0, 0);
  aes7StatusLabel = new wxStaticText(this, wxID_ANY, wxT("Lock"));
  grid_sizer_2->Add(aes7StatusLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  aes7FreqLabel = new wxStaticText(this, wxID_ANY, wxT("48 KHz"));
  grid_sizer_2->Add(aes7FreqLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  grid_sizer_2->Add(0, 0, 0, 0, 0);
  aes7Warn = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxT("./dialog-warning.png"), wxBITMAP_TYPE_ANY));
  aes7Warn->Hide();
  grid_sizer_2->Add(aes7Warn, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 16);
  aes8SyncButton = new wxRadioButton(this, aes8SyncID, wxT("AES8"));
  grid_sizer_2->Add(aes8SyncButton, 0, 0, 0);
  aes8StatusLabel = new wxStaticText(this, wxID_ANY, wxT("Lock"));
  grid_sizer_2->Add(aes8StatusLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  aes8FreqLabel = new wxStaticText(this, wxID_ANY, wxT("48 KHz"));
  grid_sizer_2->Add(aes8FreqLabel, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 4);
  grid_sizer_2->Add(0, 0, 0, 0, 0);
  aes8Warn = new wxStaticBitmap(this, wxID_ANY, wxBitmap(wxT("./dialog-warning.png"), wxBITMAP_TYPE_ANY));
  aes8Warn->Hide();
  grid_sizer_2->Add(aes8Warn, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 16);
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
  wxBoxSizer* sizer_5 = new wxBoxSizer(wxVERTICAL);
  sizer_10->Add(sizer_5, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 4);
  wxStaticBoxSizer* sizer_8 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Output")), wxVERTICAL);
  sizer_5->Add(sizer_8, 0, wxEXPAND|wxFIXED_MINSIZE, 0);
  professionalButton = new wxCheckBox(this, professionalID, wxT("Professional"));
  sizer_8->Add(professionalButton, 0, wxTOP, 0);
  emphasisButton = new wxCheckBox(this, emphasisID, wxT("Emphasis"));
  sizer_8->Add(emphasisButton, 0, wxBOTTOM|wxTOP, 0);
  nonAudioButton = new wxCheckBox(this, nonAudioID, wxT("Non Audio"));
  sizer_8->Add(nonAudioButton, 0, wxBOTTOM|wxTOP, 0);
  wxStaticBoxSizer* sizer_7 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("Word Clk Out")), wxVERTICAL);
  sizer_5->Add(sizer_7, 0, wxEXPAND|wxFIXED_MINSIZE, 0);
  singleSpeedWclkButton = new wxCheckBox(this, singleSpeedWclkID, wxT("Single Speed"));
  sizer_7->Add(singleSpeedWclkButton, 0, 0, 0);
  wxBoxSizer* sizer_4 = new wxBoxSizer(wxVERTICAL);
  sizer_10->Add(sizer_4, 1, wxALL|wxEXPAND, 4);
  const wxString dsModeBox_choices[] = {
    wxT("Single Wire"),
    wxT("Double Wire"),
  };
  dsModeBox = new wxRadioBox(this, dsModeID, wxT("Double Speed"), wxDefaultPosition, wxDefaultSize, 2, dsModeBox_choices, 2, wxRA_SPECIFY_ROWS);
  dsModeBox->SetSelection(0);
  sizer_4->Add(dsModeBox, 1, wxALL|wxEXPAND, 0);
  wxStaticBoxSizer* sizer_11 = new wxStaticBoxSizer(new wxStaticBox(this, wxID_ANY, wxT("TMS")), wxHORIZONTAL);
  sizer_4->Add(sizer_11, 0, wxEXPAND, 0);
  tmsButton = new wxCheckBox(this, tmsID, wxT("Enable"));
  tmsButton->SetToolTip(wxT("Encode AES or S/PDIF input channel status and track markers in the least significant bits of the audio samples."));
  sizer_11->Add(tmsButton, 0, 0, 0);
  wxBoxSizer* sizer_6 = new wxBoxSizer(wxVERTICAL);
  sizer_10->Add(sizer_6, 1, wxALL|wxEXPAND, 4);
  const wxString qsModeBox_choices[] = {
    wxT("Single Wire"),
    wxT("Double Wire"),
    wxT("Quad Wire"),
  };
  qsModeBox = new wxRadioBox(this, qsModeID, wxT("Quad Speed"), wxDefaultPosition, wxDefaultSize, 3, qsModeBox_choices, 3, wxRA_SPECIFY_ROWS);
  qsModeBox->SetSelection(0);
  sizer_6->Add(qsModeBox, 1, wxALL|wxEXPAND, 0);
  
  sizer_2->AddGrowableCol(0);
  SetSizer(sizer_1);
  sizer_1->Fit(this);
  // end wxGlade
}


BEGIN_EVENT_TABLE(AESPanel, wxPanel)
  // begin wxGlade: AESPanel::event_table
  EVT_RADIOBUTTON(masterID, AESPanel::masterCB)
  EVT_CHOICE(wxID_ANY, AESPanel::internalFreqCB)
  EVT_RADIOBUTTON(wclkSyncID, AESPanel::wclkSyncCB)
  EVT_RADIOBUTTON(aes1SyncID, AESPanel::aes1SyncCB)
  EVT_RADIOBUTTON(aes2SyncID, AESPanel::aes2SyncCB)
  EVT_RADIOBUTTON(aes3SyncID, AESPanel::aes3SyncCB)
  EVT_RADIOBUTTON(aes4SyncID, AESPanel::aes4SyncCB)
  EVT_RADIOBUTTON(aes5SyncID, AESPanel::aes5SyncCB)
  EVT_RADIOBUTTON(aes6SyncID, AESPanel::aes6SyncCB)
  EVT_RADIOBUTTON(aes7SyncID, AESPanel::aes7SyncCB)
  EVT_RADIOBUTTON(aes8SyncID, AESPanel::aes8SyncCB)
  EVT_RADIOBUTTON(tcoSyncID, AESPanel::tcoSyncCB)
  EVT_RADIOBUTTON(syncInSyncID, AESPanel::syncInSyncCB)
  EVT_COMMAND_SCROLL_LINEDOWN(pitchID, AESPanel::pitchDownCB)
  EVT_COMMAND_SCROLL_LINEUP(pitchID, AESPanel::pitchUpCB)
  EVT_COMMAND_SCROLL_PAGEDOWN(pitchID, AESPanel::pitchPrevCB)
  EVT_COMMAND_SCROLL_PAGEUP(pitchID, AESPanel::pitchNextCB)
  EVT_SLIDER(pitchID, AESPanel::pitchSliderCB)
  EVT_CHECKBOX(professionalID, AESPanel::professionalCB)
  EVT_CHECKBOX(emphasisID, AESPanel::emphasisCB)
  EVT_CHECKBOX(nonAudioID, AESPanel::nonAudioCB)
  EVT_CHECKBOX(singleSpeedWclkID, AESPanel::singleSpeedWclkOutCB)
  EVT_RADIOBOX(dsModeID, AESPanel::dsModeCB)
  EVT_CHECKBOX(tmsID, AESPanel::tmsCB)
  EVT_RADIOBOX(qsModeID, AESPanel::qsModeCB)
  // end wxGlade
END_EVENT_TABLE();


void AESPanel::masterCB(wxCommandEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::masterCB) not implemented yet"));
}

void AESPanel::internalFreqCB(wxCommandEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::internalFreqCB) not implemented yet"));
}

void AESPanel::wclkSyncCB(wxCommandEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::wclkSyncCB) not implemented yet"));
}

void AESPanel::aes1SyncCB(wxCommandEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::aes1SyncCB) not implemented yet"));
}

void AESPanel::aes2SyncCB(wxCommandEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::aes2SyncCB) not implemented yet"));
}

void AESPanel::aes3SyncCB(wxCommandEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::aes3SyncCB) not implemented yet"));
}

void AESPanel::aes4SyncCB(wxCommandEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::aes4SyncCB) not implemented yet"));
}

void AESPanel::aes5SyncCB(wxCommandEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::aes5SyncCB) not implemented yet"));
}

void AESPanel::aes6SyncCB(wxCommandEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::aes6SyncCB) not implemented yet"));
}

void AESPanel::aes7SyncCB(wxCommandEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::aes7SyncCB) not implemented yet"));
}

void AESPanel::aes8SyncCB(wxCommandEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::aes8SyncCB) not implemented yet"));
}

void AESPanel::tcoSyncCB(wxCommandEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::tcoSyncCB) not implemented yet"));
}

void AESPanel::syncInSyncCB(wxCommandEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::syncInSyncCB) not implemented yet"));
}

void AESPanel::pitchDownCB(wxScrollEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::pitchDownCB) not implemented yet"));
}

void AESPanel::pitchUpCB(wxScrollEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::pitchUpCB) not implemented yet"));
}

void AESPanel::pitchPrevCB(wxScrollEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::pitchPrevCB) not implemented yet"));
}

void AESPanel::pitchNextCB(wxScrollEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::pitchNextCB) not implemented yet"));
}

void AESPanel::pitchSliderCB(wxCommandEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::pitchSliderCB) not implemented yet"));
}

void AESPanel::professionalCB(wxCommandEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::professionalCB) not implemented yet"));
}

void AESPanel::emphasisCB(wxCommandEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::emphasisCB) not implemented yet"));
}

void AESPanel::nonAudioCB(wxCommandEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::nonAudioCB) not implemented yet"));
}

void AESPanel::singleSpeedWclkOutCB(wxCommandEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::singleSpeedWclkOutCB) not implemented yet"));
}

void AESPanel::dsModeCB(wxCommandEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::dsModeCB) not implemented yet"));
}

void AESPanel::tmsCB(wxCommandEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::tmsCB) not implemented yet"));
}

void AESPanel::qsModeCB(wxCommandEvent &event)  // wxGlade: AESPanel.<event_handler>
{
  event.Skip();
  // notify the user that he hasn't implemented the event handler yet
  wxLogDebug(wxT("Event handler (AESPanel::qsModeCB) not implemented yet"));
}


// wxGlade: add AESPanel event handlers

