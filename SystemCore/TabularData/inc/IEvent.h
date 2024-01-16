#pragma once

#include "EventType.h"
#include "DateTime.h"
#include <list>

namespace TabularData {

/**
 * The IEvent interface defines an event of Event Log.
 */
class IEvent {
public:
    IEvent() = default;
    virtual ~IEvent() = default;

    /**
     * Gets unique identifier of an event.
     */
    virtual const std::wstring& GetId() const = 0;

    /**
     * Gets type of an event.
     */
    virtual EventType GetType() const = 0;

    /**
     * Gets name of an event.
     */
    virtual const std::wstring& GetName() const = 0;

    /**
     * Gets description of an event.
     */
    virtual const std::wstring& GetDescription() const = 0;

    /**
     * Gets source of an event.
     */
    virtual const std::wstring& GetSource() const = 0;

    /**
     * Gets time of an event.
     */
    virtual const base::DateTime& GetTime() const = 0;
};

/**
 * Defines the Shared Ptr of Event.
 */
using IEventSharedPtr = std::shared_ptr<IEvent>;

//
// Defines a collection of events...
//
using EventList = std::list<IEventSharedPtr>;

} // namespace TabularData
