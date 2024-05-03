#include "WindowUpdationEventInternal.h"
#include "WXObjectId.h"

using namespace WXWidgets;

const WindowUpdationEventInternal::Type WindowUpdationEventInternal::TYPE(wxNewEventType());

/**
 * Gets an event id.
 */
int WindowUpdationEventInternal::GetId()
{
    return WXObjectId::NextId();
}

/**
 * The WindowUpdationEventInternal constructor.
 */
WindowUpdationEventInternal::WindowUpdationEventInternal() : 
    wxCommandEvent(
        WindowUpdationEventInternal::TYPE, 
        WindowUpdationEventInternal::GetId())
{
}

/**
 * The WindowUpdationEventInternal destructor.
 */
WindowUpdationEventInternal::~WindowUpdationEventInternal() 
{
}

/**
 * Clones an event.
 */
wxEvent* WindowUpdationEventInternal::Clone() const
{
    return new WindowUpdationEventInternal(*this);
}
