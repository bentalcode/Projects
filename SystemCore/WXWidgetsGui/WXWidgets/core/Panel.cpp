#include "Panel.h"

using namespace WXWidgets;

/**
 * Creates a panel.
 */
IPanelPtr Panel::Make(
    wxWindow& parent, 
    const wxString& name, 
    wxWindowID id, 
    const wxPoint& position,
    const wxSize& size, 
    long style)
{
    return IPanelPtr::Make(
        new Panel(
            parent, 
            name, 
            id, 
            position,
            size,
            style));
}

/**
 * The Panel constructor.
 */
Panel::Panel(
    wxWindow& parent, 
    const wxString& name, 
    wxWindowID id,
    const wxPoint& position, 
    const wxSize& size, 
    long style) : 
        wxPanel(
            &parent, 
            id,
            position,
            size,
            style,
            name)
{
}

/**
 * The Panel destructor.
 */
Panel::~Panel() 
{
}

/**
 * Initializes a GUI component.
 */
void Panel::Initialize(IGuiControllerSharedPtr guiController)
{
    /**
     * Initializes window...
     */
    Window::Initialize(
        *this, 
        guiController);
}

/**
 * Sets a sizer.
 */
void Panel::SetSizer(wxSizer& sizer)
{
    wxPanel::SetSizer(&sizer);
}
