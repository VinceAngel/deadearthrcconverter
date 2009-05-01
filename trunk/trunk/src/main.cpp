

#include <wx/wx.h>
#include <MainFrame.h>

#include <define.h>

class MyApp : public wxApp
{
	virtual bool OnInit();
};

IMPLEMENT_APP_NO_MAIN(MyApp)

#ifdef _RELEASE
	int WinMain(HINSTANCE h, HINSTANCE p, LPSTR cmd, int nbcmd)
	{
	   return wxEntry(h, p, cmd, nbcmd);
	}
#else
	int main(int argc, char **argv)
	{
	   return wxEntry(argc, argv);
	}
#endif

bool MyApp::OnInit()
{
	string version = VERSION;
	string title = "DE RC converter "+version ;
	MainFrame *frame = new MainFrame(_T(title), wxPoint(50,50),
                wxSize(800,400));


	frame->Show(TRUE);
	SetTopWindow(frame);
	return TRUE;
}
