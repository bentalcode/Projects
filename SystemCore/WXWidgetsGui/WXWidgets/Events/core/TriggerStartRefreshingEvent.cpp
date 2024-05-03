#include "TriggerStartRefreshingEvent.h"

using namespace WXWidgets;

/**
 * Creates a start refreshing event.
 */
IWXEventSharedPtr TriggerStartRefreshingEvent::Create()
{
    return std::make_shared<TriggerStartRefreshingEvent>();
}

/**
 * The TriggerStartRefreshingEvent constructor.
 */
TriggerStartRefreshingEvent::TriggerStartRefreshingEvent() : 
    AbstractWXEvent<TriggerStartRefreshingEventInternal>(
        std::make_shared<TriggerStartRefreshingEventInternal>())
{
}

/**
 * The TriggerStartRefreshingEvent destructor.
 */
TriggerStartRefreshingEvent::~TriggerStartRefreshingEvent() 
{
}
