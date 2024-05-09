#include "DataModel.h"
#include "CallInformationCollection.h"
#include "CompositorInformationCollection.h"
#include "RenderingPipelineInformationCollection.h"

using namespace VideoRenderingVisualizer::Model;

/**
 * Creates a Data Model.
 */
IDataModelSharedPtr DataModel::Make()
{
    return std::make_shared<DataModel>();
}

/**
 * The DataModel constructor.
 */
DataModel::DataModel() : 
    m_callsInformation(CallInformationCollection::Make()), 
    m_compositorsInformation(CompositorInformationCollection::Make()), 
    m_renderingPipelinesInformation(RenderingPipelineInformationCollection::Make())
{
}

/**
 * The DataModel destructor.
 */
DataModel::~DataModel()
{
}

/**
 * Gets calls information.
 */
ICallInformationCollectionSharedPtr DataModel::GetCalls()
{
    return m_callsInformation;
}

/**
 * Gets calls information.
 */
const ICallInformationCollectionSharedPtr DataModel::GetCalls() const
{
    return m_callsInformation;
}

/**
 * Gets compositors information.
 */
ICompositorInformationCollectionSharedPtr DataModel::GetCompositors()
{
    return m_compositorsInformation;
}

const ICompositorInformationCollectionSharedPtr DataModel::GetCompositors() const
{
    return m_compositorsInformation;
}

/**
 * Gets rendering pipelines information.
 */
IRenderingPipelineInformationCollectionSharedPtr DataModel::GetRenderingPipelines()
{
    return m_renderingPipelinesInformation;
}

/**
 * Gets rendering pipelines information.
 */
const IRenderingPipelineInformationCollectionSharedPtr DataModel::GetRenderingPipelines() const
{
    return m_renderingPipelinesInformation;
}
