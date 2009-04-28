// wxhello.cpp
// Version using dynamic event routing
// Robert Roebling, Martin Bernreuther

#include <wx/wx.h>
#include <MainFrame.h>


class MyApp : public wxApp
{
	virtual bool OnInit();
};

IMPLEMENT_APP_NO_MAIN(MyApp)

int main(int argc, char **argv)
{
   return wxEntry(argc, argv);
}


bool MyApp::OnInit()
{
	MainFrame *frame = new MainFrame(_T("DE RC converter v0.1"), wxPoint(50,50),
                wxSize(800,400));

/*	frame->Connect( ID_Quit, wxEVT_COMMAND_MENU_SELECTED,
		(wxObjectEventFunction) &MainFrame::OnQuit );
	frame->Connect( ID_About, wxEVT_COMMAND_MENU_SELECTED,
		(wxObjectEventFunction) &MainFrame::OnAbout );*/

	frame->Show(TRUE);
	SetTopWindow(frame);
	return TRUE;
}
