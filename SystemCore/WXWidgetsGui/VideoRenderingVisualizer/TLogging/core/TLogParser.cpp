#include "TLogParser.h"
#include "TLog.h"
#include "TLogProcessor.h"
#include "TLogTree.h"
#include "TLogStatistics.h"
#include "ITabularFile.h"
#include "IFile.h"
#include "SmartPointers.h"
#include "Assert.h"
#include <iostream>

using namespace tlogging;

const size_t TLogParser::DEFAULT_VERBOSE_BATCH_SIZE = 100;

/**
 * Creates a TLogParser.
 */
ITLogParserSharedPtr TLogParser::Make(
    const std::wstring& path, 
    tabular_data::ParsingPolicyType parsingPolicyType,
    IEventTLogSharedPtr eventTLog,
    ITLogNotificationHandlerSharedPtr notificationHandler)
{
    return std::make_shared<TLogParser>(
        path, 
        parsingPolicyType, 
        eventTLog, 
        notificationHandler);
}

/**
 * The TLogParser constructor.
 */
TLogParser::TLogParser(
    const std::wstring& path, 
    tabular_data::ParsingPolicyType parsingPolicyType,
    IEventTLogSharedPtr eventTLog, 
    ITLogNotificationHandlerSharedPtr notificationHandler) :
    m_tlog(tlogging::TLog::Make(
        path, 
        parsingPolicyType, 
        eventTLog->GetEventLog())), 
    m_verbose(false), 
    m_verboseBatchSize(DEFAULT_VERBOSE_BATCH_SIZE)
{
    base::SmartPointers::Validate<tlogging::IEventTLog>(eventTLog);
    base::SmartPointers::Validate<tlogging::ITLogNotificationHandler>(notificationHandler);
    
    m_eventTLog = eventTLog;
    m_notificationHandler = notificationHandler;
}

/**
 * The TLogParser destructor.
 */
TLogParser::~TLogParser() 
{
}

/**
 * Parses a TLog.
 */
void TLogParser::Parse() 
{
    //
    // Reset log statistics...
    //
    std::wstring path = m_tlog->GetLog().GetTabularFile().GetFile().GetPath();
    m_tlogStatistics = TLogStatistics::Make(path);
    logging::ILogStatisticsSharedPtr logStatistics = m_tlogStatistics->GetLogStatistics();

    //
    // Set start execution time...
    //
    base::DateTimeSharedPtr startTime = base::DateTime::Now();
    logStatistics->SetStartExecutionTime(startTime);

    if (m_verbose) {
        std::wcout << L"Parsing has started at: " << startTime->ToString() << std::endl;
    }

    //
    // Create TLogProcessor....
    //
    ITLogTreeSharedPtr tree = TLogTree::Make();

    ITLogProcessorSharedPtr processor = TLogProcessor::Make(
        tree, 
        m_notificationHandler, 
        m_tlogStatistics,
        m_eventTLog);

    //
    // Iterate over records with iterator...
    //
    base::IIteratorSharedPtr<tlogging::ITLogRecordSharedPtr> recordIterator = m_tlog->GetIterator();

    while (recordIterator->HasNext()) {
        
        tlogging::ITLogRecordSharedPtr record = recordIterator->Next();
        
        logStatistics->IncrementNumberOfElementsProcessed();

        if (record != nullptr) {
            record->Process(*processor);

            logStatistics->IncrementNumberOfElementsOutput();
        }
        
        size_t numberOfElementsProcessed = logStatistics->GetNumberOfElementsProcessed();

        if (m_verbose && numberOfElementsProcessed % m_verboseBatchSize == 0) {
            std::wcout << L"Number of Elements Processed: " << numberOfElementsProcessed << std::endl;
        }
    }

    //
    // Set end execution time...
    //
    base::DateTimeSharedPtr endTime = base::DateTime::Now();
    logStatistics->SetEndExecutionTime(endTime);

    if (m_verbose) {
        std::wcout << *logStatistics;
    }
}

/**
 * Gets TLog statistics.
 */
const ITLogStatisticsSharedPtr TLogParser::GetTLogStatistics() const
{
    assert(m_tlogStatistics);
    base::SmartPointers::Validate<ITLogStatistics>(m_tlogStatistics);
    return m_tlogStatistics;
}

/**
 * Enables verbose.
 */
void TLogParser::EnableVerbose()
{
    m_verbose = true;
}

/**
 * Disables verbose.
 */
void TLogParser::DisableVerbose()
{
    m_verbose = false;
}

/**
 * Gets verbose batch size.
 */
size_t TLogParser::GetVerboseBatchSize() const
{
    return m_verboseBatchSize;
}

/**
 * Sets verbose batch size.
 */
void TLogParser::SetVerboseBatchSize(size_t size)
{
    m_verboseBatchSize = size;
}
