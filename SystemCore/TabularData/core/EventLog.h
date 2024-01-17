#ifndef EVENT_LOG_H_c3a26a34_18b2_45e3_bfb4_684178e798fb
#define EVENT_LOG_H_c3a26a34_18b2_45e3_bfb4_684178e798fb

#include "IEventLog.h"

namespace tabular_data {

/**
 * The EventLog class implements an Event Log.
 */
class EventLog final : public IEventLog {
public:
    /**
     * Creates an Event Log.
     */
    static IEventLogSharedPtr Make();

    /**
     * The EventLog constructor.
     */    EventLog();

    /**
     * The EventLog destructor.
     */
    virtual ~EventLog();

    /**
     * Sets an event source.
     */
    virtual void SetEventSource(const std::wstring& source) override;

    /**
     * Sets an informational event.
     */
    virtual void SetInformationalEvent(
        const std::wstring& name, 
        const std::wstring& description) override;

    /**
     * Sets a warning event.
     */
    virtual void SetWarningEvent(
        const std::wstring& name, 
        const std::wstring& description) override;

    /**
     * Sets an error event.
     */
    virtual void SetErrorEvent(
        const std::wstring& name, 
        const std::wstring& description) override;

    /**
     * Gets a collection of informational events.
     */
    virtual const EventList& GetInformationalEvents() const override;

    /**
     * Gets a collection of warning events.
     */
    virtual const EventList& GetWarningEvents() const override;

    /**
     * Gets a collection of error events.
     */
    virtual const EventList& GetErrorEvents() const override;

private:
    /**
     * Creates a new event.
     */
    IEventSharedPtr CreateEvent(
        EventType type,
        const std::wstring& name, 
        const std::wstring& description);

    std::wstring m_source;
    EventList m_informationalEvents;
    EventList m_warningEvents;
    EventList m_errorEvents;
};

}  // namespace tabular_data

#endif // EVENT_LOG_H_c3a26a34_18b2_45e3_bfb4_684178e798fb
