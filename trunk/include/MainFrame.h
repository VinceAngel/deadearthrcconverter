#ifndef _MAIN_FRAME_H_
#define _MAIN_FRAME_H_

#include <wx/wx.h>


enum
{
	ID_Quit=1,
	ID_About,
	ID_Clic,
	ID_In,
	ID_Out
};


class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

	void Clic(wxCommandEvent& event);
	DECLARE_EVENT_TABLE()

protected :

	wxPanel * panel;
	wxTextCtrl* inputText;
	wxTextCtrl* outputText;
	wxButton* button;
};

#endif //_MAIN_FRAME_H_

