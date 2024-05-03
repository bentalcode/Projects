#include "WindowUpdationEvent.h"

using namespace WXWidgets;

/**
 * Creates an event.
 */
IWXEventSharedPtr WindowUpdationEvent::Create()
{
    return std::make_shared<WindowUpdationEvent>();
}

/**
 * The WindowUpdationEvent constructor.
 */
WindowUpdationEvent::WindowUpdationEvent() : 
    AbstractWXEvent<WindowUpdationEventInternal>(
        std::make_shared<WindowUpdationEventInternal>())
{
}

/**
 * The WindowUpdationEvent destructor.
 */
WindowUpdationEvent::~WindowUpdationEvent() 
{
}
