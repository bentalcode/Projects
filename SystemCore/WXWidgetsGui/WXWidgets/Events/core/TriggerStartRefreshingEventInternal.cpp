#include "TriggerStartRefreshingEventInternal.h"
#include "WXObjectId.h"

using namespace WXWidgets;

const TriggerStartRefreshingEventInternal::Type TriggerStartRefreshingEventInternal::TYPE(wxNewEventType());

/**
 * Gets an event id.
 */
int TriggerStartRefreshingEventInternal::GetId()
{
    return WXObjectId::NextId();
}

/**
 * The TriggerStartRefreshingEventInternal constructor.
 */
TriggerStartRefreshingEventInternal::TriggerStartRefreshingEventInternal() : 
    wxCommandEvent(
        TriggerStartRefreshingEventInternal::TYPE, 
        TriggerStartRefreshingEventInternal::GetId())
{
}

/**
 * The TriggerStartRefreshingEventInternal destructor.
 */
TriggerStartRefreshingEventInternal::~TriggerStartRefreshingEventInternal() 
{
}

/**
 * Clones an event.
 */
wxEvent* TriggerStartRefreshingEventInternal::Clone() const
{
    return new TriggerStartRefreshingEventInternal(*this);
}
