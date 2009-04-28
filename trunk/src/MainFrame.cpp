#include <MainFrame.h>
#include <iostream>



MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame((wxFrame*)NULL,-1,title,pos,size)
{

	panel= new wxPanel(this);

	// create menubar
/*	wxMenuBar *menuBar = new wxMenuBar;
	// create menu
	wxMenu *menuFile = new wxMenu;
	// append menu entries
	menuFile->Append(ID_About,_T("&About..."));
	menuFile->AppendSeparator();
	menuFile->Append(ID_Quit,_T("E&xit"));
	// append menu to menubar
	menuBar->Append(menuFile,_T("&File"));
	// set frame menubar
	SetMenuBar(menuBar);*/

	// create frame statusbar
	CreateStatusBar();
	// set statusbar text
	SetStatusText(_T("Welcome to RCConverter!"));


	//button
	button = new wxButton(panel, ID_Clic, "Convertir",wxPoint(360,100),wxSize(80,40));

	// input text
	inputText = new wxTextCtrl(panel, ID_In, "test\nhaha", wxPoint(2,2), wxSize(350,399));
	inputText->SetEditable(true);
	inputText->SetHelpText("Paste you RC here");
	inputText->SetWindowStyle(wxTE_MULTILINE);

	// output text
	outputText = new wxTextCtrl(panel, ID_Out, "result", wxPoint(448,2), wxSize(348,399));
	outputText->SetEditable(false);
	outputText->SetHelpText("Get you RC here");
	outputText->SetWindowStyle(wxTE_READONLY | wxTE_MULTILINE);
	
}
/*
void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
	Close(TRUE);
}

void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	wxMessageBox(_T("DeadEarth RC converter"),_T("version 0.1"),
                wxOK|wxICON_INFORMATION, this);
}*/

void MainFrame::Clic(wxCommandEvent &event)
{
	std::cout << "Converting ...." << std::endl;
	std::cout << "Done ! " << std::endl;
}

BEGIN_EVENT_TABLE(MainFrame,wxFrame)
    EVT_BUTTON(ID_Clic,MainFrame::Clic)
END_EVENT_TABLE()
