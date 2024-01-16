#include "EventLog.h"
#include "Event.h"
#include "Uuid.h"

using namespace TabularData;

/**
 * Creates an Event Log.
 */
IEventLogSharedPtr EventLog::Make()
{
    return std::make_shared<EventLog>();
}

/**
 * The EventLog constructor.
 */
EventLog::EventLog() 
{
}

/**
 * The EventLog destructor.
 */
EventLog::~EventLog() 
{
}

/**
 * Sets an event source.
 */
void EventLog::SetEventSource(const std::wstring& source) 
{
    m_source = source;
}

/**
 * Sets an informational event.
 */
void EventLog::SetInformationalEvent(
    const std::wstring& name, 
    const std::wstring& description)
{
    IEventSharedPtr event = CreateEvent(
        EventType::INFORMATIONAL_EVENT, 
        name, 
        description);

    m_informationalEvents.push_back(event);
}

/**
 * Sets a warning event.
 */
void EventLog::SetWarningEvent(
    const std::wstring& name, 
    const std::wstring& description)
{
    IEventSharedPtr event = CreateEvent(
        EventType::WARNING_EVENT, 
        name, 
        description);

    m_warningEvents.push_back(event);
}

/**
 * Sets an error event.
 */
void EventLog::SetErrorEvent(
    const std::wstring& name, 
    const std::wstring& description)
{
    IEventSharedPtr event = CreateEvent(
        EventType::ERROR_EVENT, 
        name, 
        description);

    m_errorEvents.push_back(event);
}

/**
 * Gets a collection of informational events.
 */
const EventList& EventLog::GetInformationalEvents() const
{
    return m_informationalEvents;
}

/**
 * Gets a collection of warning events.
 */
const EventList& EventLog::GetWarningEvents() const
{
    return m_warningEvents;
}

/**
 * Gets a collection of error events.
 */
const EventList& EventLog::GetErrorEvents() const
{
    return m_errorEvents;
}

/**
 * Creates a new event.
 */
IEventSharedPtr EventLog::CreateEvent(
    EventType type, 
    const std::wstring& name, 
    const std::wstring& description) 
{
    base::IUuidSharedPtr id = base::Uuid::New();
    std::wstring eventId = id->ToString();

    base::DateTimeSharedPtr creationTime = base::DateTime::Now();

    return Event::Make(
        eventId, 
        type, 
        name, 
        description, 
        m_source, 
        creationTime);
}
