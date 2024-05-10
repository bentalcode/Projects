#include "AbstractDialog.h"

using namespace wxwidgets;

/**
 * The AbstractApp constructor.
 */
AbstractDialog::AbstractDialog(
    wxWindow& parent, 
    const wxString& name, 
    long style, 
    const wxString& title, 
    wxWindowID id,
    const wxPoint& position, 
    const wxSize& size) : 
        wxDialog(
            &parent, 
            id, 
            title, 
            position, 
            size, 
            style, 
            name), 
    m_name(name)
{
}

/**
 * The AbstractDialog destructor.
 */
AbstractDialog::~AbstractDialog() 
{
}

/**
 * Initializes a GUI component.
 */
void AbstractDialog::Initialize(IGuiControllerSharedPtr guiController)
{
    //
    // Initialize component...
    //
    Window::Initialize(
        *this, 
        guiController);
}

/**
 * Activates a modal.
 */
int AbstractDialog::ActivateModal() 
{
    return wxDialog::ShowModal();
}

/**
 * Gets a window.
 */
IWindow& AbstractDialog::GetWindow()
{
    return *this;
}
