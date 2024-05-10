#include "Dialog.h"

using namespace wxwidgets;

/**
 * The Dialog constructor.
 */
Dialog::Dialog(
    wxWindow& parent, 
    const wxString& name, 
    long style, 
    const wxString& title,
    const wxSize& size,
    wxWindowID id,
    const wxPoint& position) : 
        AbstractDialog(
            parent, 
            name, 
            style, 
            title,
            id, 
            position, 
            size)
{
}

/**
 * The Dialog destructor.
 */
Dialog::~Dialog() 
{
}

/**
 * Initializes a GUI component.
 */
void Dialog::Initialize(IGuiControllerSharedPtr guiController)
{
    //
    // Initialize GUI component...
    //
    AbstractDialog::Initialize(guiController);
}
