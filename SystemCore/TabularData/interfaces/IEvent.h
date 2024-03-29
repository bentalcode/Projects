#ifndef I_EVENT_H_22ea9a65_5bf4_4fb9_b26d_fbfdaafc3097
#define I_EVENT_H_22ea9a65_5bf4_4fb9_b26d_fbfdaafc3097

#include "EventType.h"
#include "DateTime.h"
#include <list>

namespace tabular_data {

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

} // namespace tabular_data

#endif // I_EVENT_H_22ea9a65_5bf4_4fb9_b26d_fbfdaafc3097
