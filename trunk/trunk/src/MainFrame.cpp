#include <MainFrame.h>
#include <iostream>
#include <Parser.h>

#include <iostream>

#include <wx/clipbrd.h>

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame((wxFrame*)NULL,-1,title,pos,size, wxMINIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN)
{

	panel= new wxPanel(this);


	// create frame statusbar
	CreateStatusBar();
	// set statusbar text
	SetStatusText(_T("Welcome to RCConverter!"));


	//button
	button = new wxButton(panel, ID_Clic, "Convertir",wxPoint(360,100),wxSize(80,40));
	bPaste = new wxButton(panel, ID_Paste, "Coller",wxPoint(130,312),wxSize(70,30));
	bCopy = new wxButton(panel, ID_Copy, "Copier",wxPoint(600,312),wxSize(70,30));

	// input text
	inputText = new wxTextCtrl(panel, ID_In, "Collez votre RC ici", wxPoint(2,2), wxSize(350,309),wxTE_MULTILINE);
	inputText->SetHelpText("Paste you RC here");

	// output text
	outputText = new wxTextCtrl(panel, ID_Out, "", wxPoint(448,2), wxSize(348,309),wxTE_READONLY | wxTE_MULTILINE);
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

	SetStatusText(p.getErrorString());

	p.compil();

	SetStatusText(p.getErrorString());

	outputText->SetValue(p.getOutput());

	SetStatusText(p.getErrorString());
}

void MainFrame::Copy(wxCommandEvent &event)
{
	if (wxTheClipboard->Open())
	{
		// This data objects are held by the clipboard, 
		// so do not delete them in the app.
		wxTheClipboard->SetData( new wxTextDataObject(outputText->GetValue()) );
		wxTheClipboard->Close();
	}
}


void MainFrame::Paste(wxCommandEvent &event)
{
	if (wxTheClipboard->Open())
	{
		if (wxTheClipboard->IsSupported( wxDF_TEXT ))
		{
			wxTextDataObject data;
			wxTheClipboard->GetData( data );
			inputText->SetValue(data.GetText());
		}  
		wxTheClipboard->Close();
	}

}



BEGIN_EVENT_TABLE(MainFrame,wxFrame)
    EVT_BUTTON(ID_Clic,MainFrame::Clic)
    EVT_BUTTON(ID_Paste,MainFrame::Paste)
    EVT_BUTTON(ID_Copy,MainFrame::Copy)
END_EVENT_TABLE()
