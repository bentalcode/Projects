#include "RichTextControl.h"

using namespace wxwidgets;

/**
 * Creates a rich text control.
 */
std::shared_ptr<RichTextControl> RichTextControl::Make(
    wxWindow& parent, 
    const wxString& name, 
    const wxString& value,
    wxWindowID id,
    const wxPoint& position,
    const wxSize& size, 
    long style, 
    const wxValidator& validator)
{
    return std::make_shared<wxwidgets::RichTextControl>(
        parent, 
        name,
        value,
        id, 
        position, 
        size, 
        style, 
        validator);
}

/**
 * The RichTextControl constructor.
 */
RichTextControl::RichTextControl(
    wxWindow& parent, 
    const wxString& name, 
    const wxString& value,
    wxWindowID id, 
    const wxPoint& position, 
    const wxSize& size, 
    long style, 
    const wxValidator& validator) : 
        wxRichTextCtrl(
            &parent, 
            id, 
            value, 
            position, 
            size, 
            style, 
            validator, 
            name)
{
}

/**
 * The RichTextControl destructor.
 */
RichTextControl::~RichTextControl() 
{
}

/**
 * Initializes a GUI component.
 */
void RichTextControl::Initialize(IGuiControllerSharedPtr guiController)
{
    /**
     * Initializes window...
     */
    Window::Initialize(
        *this, 
        guiController);
}
