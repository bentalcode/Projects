#include "TLogModelBuilder.h"
#include "TLogParser.h"
#include "TLogModelNotificationHandler.h"
#include "EventTLog.h"
#include "SmartPointers.h"

using namespace VideoRenderingVisualizer::Model;

/**
 * Creates a Model Builder.
 */
IModelBuilderSharedPtr TLogModelBuilder::Make(
    const std::wstring& path,
    IDataModel& model,
    tabular_data::IEventLogSharedPtr eventLog)
{
    return std::make_shared<TLogModelBuilder>(
        path, 
        model, 
        eventLog);
}

/**
 * The TLogModelBuilder constructor.
 */
TLogModelBuilder::TLogModelBuilder(
    const std::wstring& path, 
    IDataModel& model, 
    tabular_data::IEventLogSharedPtr eventLog) :
    m_path(path), 
    m_model(model) 
{ 
    base::SmartPointers::Validate<tabular_data::IEventLog>(eventLog);
    m_eventLog = eventLog;
}

/**
 * The TLogModelBuilder destructor.
 */
TLogModelBuilder::~TLogModelBuilder() 
{
}

/**
 * Builds a model.
 */
void TLogModelBuilder::Build() 
{
    tlogging::IEventTLogSharedPtr eventTLog = tlogging::EventTLog::Make(m_eventLog);
    tlogging::ITLogNotificationHandlerSharedPtr notificationHandler = TLogModelNotificationHandler::Make(
        m_model, 
        *eventTLog);
    
    tabular_data::ParsingPolicyType parsingPolicyType = tabular_data::ParsingPolicyType::FAIL_ON_FIRST_ERROR;

    tlogging::ITLogParserSharedPtr parser = tlogging::TLogParser::Make(
        m_path, 
        parsingPolicyType, 
        eventTLog,
        notificationHandler);

    parser->Parse();

    m_statistics = parser->GetTLogStatistics();
}

/**
 * Gets statistics.
 */
const tlogging::ITLogStatisticsSharedPtr TLogModelBuilder::GetStatistics() const
{
    return m_statistics;
}
