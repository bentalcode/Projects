#include "Frame.h"

using namespace wxwidgets;

/**
 * Creates a frame.
 */
IFramePtr Frame::Make(
    wxWindow* parent,
    const wxString& name,
    const wxString& title,
    wxWindowID id,
    const wxPoint& position,
    const wxSize& size,
    long style)
{ 
    return IFramePtr::Make(new Frame(
        parent, 
        name, 
        title, 
        id, 
        position, 
        size,
        style));
}

/**
 * The Frame constructor.
 */
Frame::Frame(
    wxWindow* parent, 
    const wxString& name, 
    const wxString& title,
    wxWindowID id, 
    const wxPoint& position,
    const wxSize& size, 
    long style) :
        AbstractFrame(
            parent,
            name, 
            title, 
            id, 
            position, 
            size, 
            style)
{
}

/**
 * The Frame destructor.
 */
Frame::~Frame() 
{
}

/**
 * Initializes a GUI component.
 */
void Frame::Initialize(IGuiControllerSharedPtr guiController)
{
    //
    // Initialize GUI component...
    //
    AbstractFrame::Initialize(guiController);
}
