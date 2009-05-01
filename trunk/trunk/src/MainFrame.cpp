#include <MainFrame.h>
#include <iostream>
#include <Parser.h>

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
	inputText = new wxTextCtrl(panel, ID_In, "test\nhaha", wxPoint(2,2), wxSize(350,309),wxTE_MULTILINE);
	inputText->SetHelpText("Paste you RC here");

	// output text
	outputText = new wxTextCtrl(panel, ID_Out, "result", wxPoint(448,2), wxSize(348,309),wxTE_READONLY | wxTE_MULTILINE);
	outputText->SetHelpText("Get you RC here");
	
}


void MainFrame::Clic(wxCommandEvent &event)
{
	SetStatusText("Converting ....");
	
	//Get the text
	string s = inputText->GetRange(0,inputText->GetLastPosition());
	//Parse it
	Parser p(s);
	p.readAndParse();

	p.compil();

	outputText->SetValue(p.getOutput());

	SetStatusText("Done ! ");
}

BEGIN_EVENT_TABLE(MainFrame,wxFrame)
    EVT_BUTTON(ID_Clic,MainFrame::Clic)
END_EVENT_TABLE()
