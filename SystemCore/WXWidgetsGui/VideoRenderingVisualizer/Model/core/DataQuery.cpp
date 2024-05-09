#include "DataQuery.h"
#include "RenderingPipelineInformationCollection.h"
#include "CompositorInformationCollection.h"
#include "DateTime.h"

using namespace VideoRenderingVisualizer::Model;

/**
 * Creates a Data Query.
 */
IDataQuerySharedPtr DataQuery::Make(Model::IDataModel& dataModel)
{
    return std::make_shared<DataQuery>(dataModel);
}

/**
 * The DataQuery constructor.
 */
DataQuery::DataQuery(Model::IDataModel& dataModel) :
    m_dataModel(dataModel) 
{
}

/**
 * The DataQuery destructor.
 */
DataQuery::~DataQuery() 
{
}

/**
 * Queries compositors information.
 */
ICallInformationCollectionSharedPtr DataQuery::QueryCalls() const
{
    return m_dataModel.GetCalls();
}

/**
 * Queries compositors information.
 */
ICompositorInformationCollectionSharedPtr DataQuery::QueryCompositors(const std::wstring& callId) const
{
    //
    // Retrieve specified call infromation from model...
    //
    ICallInformationCollectionSharedPtr callInformationCollection = m_dataModel.GetCalls();
    ICallInformationSharedPtr callInformation = callInformationCollection->GetItem(callId);
    
    //
    // Return compositors of call...
    //
    return callInformation->GetCompoistors();
}

/**
 * Queries rendering pipelines time interval.
 */
base::DateTimeIntervalSharedPtr DataQuery::QueryRenderingPipelinesTimeInterval(const std::wstring& callId) const
{ 
    ICallInformationCollectionSharedPtr callInformationCollection = m_dataModel.GetCalls();

    //
    // If a call id is not specified (during startup), then use the first call in the model...
    //
    ICallInformationSharedPtr callInformation;

    if (!callId.empty()) {
        callInformation = callInformationCollection->GetItem(callId);
    } 
    else {
        base::IIteratorSharedPtr<Model::ICallInformationSharedPtr> callInformationIterator =
            callInformationCollection->GetIterator();

        if (callInformationIterator->HasNext()) {
            callInformation = callInformationIterator->Next();
        } 
    }

    //
    // If no call is available, then use time interval of the last 24 hours...
    //
    if (callInformation == nullptr) {
        base::DurationSharedPtr dayInterval = base::Duration::FromDays(1);
        base::DateTimeSharedPtr endTime = base::DateTime::Now();
        base::DateTimeSharedPtr startTime = *endTime - *dayInterval;
        return base::DateTimeInterval::Make(startTime, endTime);
    }

    base::DateTimeSharedPtr startTime = callInformation->GetStartTime();
    base::DateTimeSharedPtr endTime = callInformation->GetEndTime();

    //
    // If call is in progress based on information, then use current time as end time...
    //
    if (endTime == nullptr) {
        endTime = base::DateTime::Now();
    }

    return base::DateTimeInterval::Make(startTime, endTime);
}

/**
 * Queries rendering pipelines.
 */
IRenderingPipelineInformationCollectionSharedPtr DataQuery::QueryRenderingPipelines(
    const base::DateTimeInterval& intervalTime) const
{ 
    IRenderingPipelineInformationCollectionSharedPtr result = RenderingPipelineInformationCollection::Make();

    IRenderingPipelineInformationCollectionSharedPtr renderingPipelines = m_dataModel.GetRenderingPipelines();

    base::IIteratorSharedPtr<Model::IRenderingPipelineInformationSharedPtr> renderingPipelineIterator =
        renderingPipelines->GetIterator();

    while (renderingPipelineIterator->HasNext()) {
        Model::IRenderingPipelineInformationSharedPtr renderingPipeline = renderingPipelineIterator->Next();
        result->AddItem(renderingPipeline);
    }

    return result;
}
