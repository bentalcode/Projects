#include "Log.h"
#include "TabularFile.h"
#include "TabularHeaderParser.h"
#include "TabularRecordParser.h"
#include "LogTokensParser.h"
#include "LogRecordIterator.h"

using namespace logging;

/**
 * Creates a Log.
 */
ILogSharedPtr Log::Make(
    const std::wstring& path, 
    tabular_data::ParsingPolicyType parsingPolicyType,
    tabular_data::IEventLogSharedPtr eventLog)
{
    return std::make_shared<Log>(
        path, 
        parsingPolicyType, 
        eventLog);
}

/**
 * The Log constructor.
 */
Log::Log(
    const std::wstring& path, 
    tabular_data::ParsingPolicyType parsingPolicyType,
    tabular_data::IEventLogSharedPtr eventLog) :
	m_tabularFile(tabular_data::TabularFile::Make(
        path, 
        tabular_data::TabularHeaderParser::Make(parsingPolicyType, tabular_data::TokensParser::Make(), eventLog),
        tabular_data::TabularRecordParser::Make(parsingPolicyType, LogTokensParser::Make(), eventLog)))
{
}

/**
 * The Log destructor.
 */
Log::~Log() 
{
}

/**
 * Gets a tabular file.
 */
const tabular_data::ITabularFile& Log::GetTabularFile() const
{
    return *m_tabularFile;
}

/**
 * Gets an iterator of records of log.
 */
base::IIteratorSharedPtr<ILogRecordSharedPtr> Log::GetIterator() const
{
    const tabular_data::ITabularTable& data = m_tabularFile->GetTabularTable();
    base::IIteratorSharedPtr<tabular_data::ITabularRecordSharedPtr> recordIterator = data.GetRecordIterator();
    return LogRecordIterator::Make(recordIterator);
}
