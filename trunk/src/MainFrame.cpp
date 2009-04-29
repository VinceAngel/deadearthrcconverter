#include <MainFrame.h>
#include <iostream>



MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame((wxFrame*)NULL,-1,title,pos,size)
{

	panel= new wxPanel(this);


	// create frame statusbar
	CreateStatusBar();
	// set statusbar text
	SetStatusText(_T("Welcome to RCConverter!"));


	//button
	button = new wxButton(panel, ID_Clic, "Convertir",wxPoint(360,100),wxSize(80,40));

	// input text
	inputText = new wxTextCtrl(panel, ID_In, "test\nhaha", wxPoint(2,2), wxSize(350,399),wxTE_MULTILINE);
	inputText->SetHelpText("Paste you RC here");

	// output text
	outputText = new wxTextCtrl(panel, ID_Out, "result", wxPoint(448,2), wxSize(348,399),wxTE_READONLY | wxTE_MULTILINE);
	outputText->SetHelpText("Get you RC here");
	
}


void MainFrame::Clic(wxCommandEvent &event)
{
	std::cout << "Converting ...." << std::endl;
	outputText->AppendText("\nDone");
	std::cout << "Done ! " << std::endl;
}

BEGIN_EVENT_TABLE(MainFrame,wxFrame)
    EVT_BUTTON(ID_Clic,MainFrame::Clic)
END_EVENT_TABLE()