#include "TriggerEndRefreshingEvent.h"

using namespace WXWidgets;

/**
 * Creates an end refreshing event.
 */
IWXEventSharedPtr TriggerEndRefreshingEvent::Create()
{
    return std::make_shared<TriggerEndRefreshingEvent>();
}

/**
 * The TriggerEndRefreshingEvent constructor.
 */
TriggerEndRefreshingEvent::TriggerEndRefreshingEvent() : 
    AbstractWXEvent<TriggerEndRefreshingEventInternal>(
        std::make_shared<TriggerEndRefreshingEventInternal>())
{
}

/**
 * The TriggerEndRefreshingEvent destructor.
 */
TriggerEndRefreshingEvent::~TriggerEndRefreshingEvent() 
{
}
