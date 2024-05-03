#include "AbstractFrame.h"
#include "IMenuBar.h"

using namespace WXWidgets;

/**
 * The AbstractFrame constructor.
 */
AbstractFrame::AbstractFrame(
    wxWindow* parent, 
    const wxString& name, 
    const wxString& title, 
    wxWindowID id, 
    const wxPoint& position,
    const wxSize& size, 
    long style) : 
        wxFrame(
            parent, 
            id, 
            title, 
            position,
            size,
            style,
            name)
{
}

/**
 * The AbstractFrame destructor.
 */
AbstractFrame::~AbstractFrame() 
{
}

/**
 * Initializes a GUI component.
 */
void AbstractFrame::Initialize(IGuiControllerSharedPtr guiController)
{
    //
    // Initialize window...
    //
    Window::Initialize(
        *this, 
        guiController);
}

/**
 * Gets a window.
 */
IWindow& AbstractFrame::GetWindow()
{
    return *this;
}

/**
 * Sets menu bar.
 */
void AbstractFrame::SetMenuBar(wxMenuBar& menuBar)
{
    wxFrame::SetMenuBar(&menuBar);
}

/**
 * Sets status text.
 */
void AbstractFrame::SetStatusText(const wxString& text)
{
    wxFrame::SetStatusText(text);
}

/**
 * Maximizes frame.
 */
void AbstractFrame::Maximize()
{
    wxFrame::Maximize(false);
    wxFrame::Maximize(true);
}

/**
 * Maximizes and centeralizes frame.
 */
void AbstractFrame::MaximizeAndCenteralize()
{
    Maximize();
    GetWindow().Centralize();
}
