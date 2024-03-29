#ifndef I_EVENT_LOG_H_a7cb20a8_18cc_4617_9bda_c395e6b0c2ef
#define I_EVENT_LOG_H_a7cb20a8_18cc_4617_9bda_c395e6b0c2ef

#include "IEvent.h"

namespace tabular_data {

/**
 * The IEventLog interface defines an event log.
 */
class IEventLog {
public:
    IEventLog() = default;
    virtual ~IEventLog() = default;

    /**
     * Sets an event source.
     */
    virtual void SetEventSource(const std::wstring& source) = 0;

    /**
     * Sets an informational event.
     */
    virtual void SetInformationalEvent(
        const std::wstring& name, 
        const std::wstring& description) = 0;

    /**
     * Sets a warning event.
     */
    virtual void SetWarningEvent(
        const std::wstring& name, 
        const std::wstring& description) = 0;

    /**
     * Sets an error event.
     */
    virtual void SetErrorEvent(
        const std::wstring& name, 
        const std::wstring& description) = 0;

    /**
     * Gets a collection of informational events.
     */
    virtual const EventList& GetInformationalEvents() const = 0;

    /**
     * Gets a collection of warning events.
     */
    virtual const EventList& GetWarningEvents() const = 0;

    /**
     * Gets a collection of error events.
     */
    virtual const EventList& GetErrorEvents() const = 0;
};

/**
 * Defines the Shared Ptr of Event Log.
 */
using IEventLogSharedPtr = std::shared_ptr<IEventLog>;

} // namespace tabular_data

#endif // I_EVENT_LOG_H_a7cb20a8_18cc_4617_9bda_c395e6b0c2ef
