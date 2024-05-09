#include "EventTLog.h"
#include "ITLogRecord.h"
#include "SmartPointers.h"

using namespace tlogging;

/**
 * Creates an Event TLog.
 */
IEventTLogSharedPtr EventTLog::Make(tabular_data::IEventLogSharedPtr eventLog)
{
    return std::make_shared<EventTLog>(eventLog);
}

/**
 * The EventTLog constructor.
 */
EventTLog::EventTLog(tabular_data::IEventLogSharedPtr eventLog)
{
    base::SmartPointers::Validate<tabular_data::IEventLog>(eventLog);
    m_eventLog = eventLog;
}

/**
 * The EventTLog destructor.
 */
EventTLog::~EventTLog() 
{
}

/**
 * Sets an informational event.
 */
void EventTLog::SetInformationalEvent(
    const std::wstring& name, 
    const std::wstring& description, 
    const ITLogRecord& record)
{
    std::wstring extendedDescription = CreateTLogDescription(
        description, 
        record);
    
    m_eventLog->SetInformationalEvent(
        name, 
        extendedDescription);
}

/**
 * Sets a warning event.
 */
void EventTLog::SetWarningEvent(
    const std::wstring& name, 
    const std::wstring& description, 
    const ITLogRecord& record)
{
    std::wstring extendedDescription = CreateTLogDescription(
        description, 
        record);

    m_eventLog->SetWarningEvent(
        name, 
        extendedDescription);
}

/**
 * Sets an error event.
 */
void EventTLog::SetErrorEvent(
    const std::wstring& name, 
    const std::wstring& description, 
    const ITLogRecord& record)
{
    std::wstring extendedDescription = CreateTLogDescription(
        description, 
        record);

    m_eventLog->SetErrorEvent(
        name, 
        extendedDescription);
}

/**
 * Gets an event log.
 */
tabular_data::IEventLogSharedPtr EventTLog::GetEventLog()
{
    return m_eventLog;
}

/**
 * Creates tlog message.
 */
std::wstring EventTLog::CreateTLogDescription(
    const std::wstring& description, 
    const ITLogRecord& record)
{
    std::wstringstream stream;
    stream 
        << L"Record Index: " << record.GetLogRecord().GetIndex() 
        << L", Logging Time: " << record.GetLogRecord().GetLoggingTime()->ToString() 
        << L", Logging Function: " << record.GetLogRecord().GetLoggingFunction() 
        << L", Source File: " << record.GetLogRecord().GetSourceFile()
        << L", Source Line: " << record.GetLogRecord().GetSourceLine() 
        << L"; " << description;

    return stream.str();
}
