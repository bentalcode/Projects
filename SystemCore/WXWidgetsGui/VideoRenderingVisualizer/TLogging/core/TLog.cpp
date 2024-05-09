#include "TLog.h"
#include "Log.h"
#include "TLogRecordIterator.h"

using namespace tlogging;

/**
 * Creates a TLog.
 */
ITLogSharedPtr TLog::Make(
    const std::wstring& path, 
    tabular_data::ParsingPolicyType parsingPolicyType,
    tabular_data::IEventLogSharedPtr eventLog)
{
    return std::make_shared<TLog>(
        path,
        parsingPolicyType, 
        eventLog);
}

/**
 * The TLog constructor.
 */
TLog::TLog(
    const std::wstring& path, 
    tabular_data::ParsingPolicyType parsingPolicyType,
    tabular_data::IEventLogSharedPtr eventLog) :
    m_log(logging::Log::Make(
        path, 
        parsingPolicyType, 
        eventLog)) 
{
}

/**
 * The TLog destructor.
 */
TLog::~TLog() 
{
}

/**
 * Gets a log.
 */
const logging::ILog& TLog::GetLog() const
{
    return *m_log;
}

/**
 * Gets an iterator of records of tlog.
 */
base::IIteratorSharedPtr<ITLogRecordSharedPtr> TLog::GetIterator() const
{
    base::IIteratorSharedPtr<logging::ILogRecordSharedPtr> recordIterator = m_log->GetIterator();
    return tlogging::TLogRecordIterator::Make(recordIterator);
}
