#include "TriggerEndRefreshingEventInternal.h"
#include "WXObjectId.h"

using namespace wxwidgets;

const TriggerEndRefreshingEventInternal::Type TriggerEndRefreshingEventInternal::TYPE(wxNewEventType());

/**
 * Gets an event id.
 */
int TriggerEndRefreshingEventInternal::GetId()
{
    return WXObjectId::NextId();
}

/**
 * The TriggerEndRefreshingEventInternal constructor.
 */
TriggerEndRefreshingEventInternal::TriggerEndRefreshingEventInternal() : 
    wxCommandEvent(
        TriggerEndRefreshingEventInternal::TYPE, 
        TriggerEndRefreshingEventInternal::GetId())
{
}

/**
 * The TriggerEndRefreshingEventInternal destructor.
 */
TriggerEndRefreshingEventInternal::~TriggerEndRefreshingEventInternal() 
{
}

/**
 * Clones an event.
 */
wxEvent* TriggerEndRefreshingEventInternal::Clone() const
{
    return new TriggerEndRefreshingEventInternal(*this);
}
