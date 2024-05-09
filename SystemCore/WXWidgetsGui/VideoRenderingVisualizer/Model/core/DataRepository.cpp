#include "DataRepository.h"
#include "DataModel.h"
#include "DataQuery.h"
#include "RenderingPipelineInformation.h"
#include "TLogModelBuilder.h"
#include "TLogStatisticsCollection.h"
#include "SmartPointers.h"
#include <experimental/filesystem>

using namespace VideoRenderingVisualizer::Model;

/**
 * Creates a data repository.
 */
IDataRepositorySharedPtr DataRepository::Make(tabular_data::IEventLogSharedPtr eventLog)
{
    return std::make_shared<DataRepository>(eventLog);
}

/**
 * The DataRepository constructor.
 */
DataRepository::DataRepository(tabular_data::IEventLogSharedPtr eventLog) :
    m_dataModel(DataModel::Make())
{
	base::SmartPointers::Validate(eventLog);
    m_eventLog = eventLog;
}

/**
 * The DataRepository destructor.
 */
DataRepository::~DataRepository() 
{
}

/**
 * Reads from a resource directory.
 */
void DataRepository::ReadFromResourceDirectory(const std::wstring& path)
{
    ResetModel();

    for (const auto& entry : std::experimental::filesystem::directory_iterator(path)) {
        ReadFromResource(entry.path());
    }
}

/**
 * Reads from resource directories.
 */
void DataRepository::ReadFromResourceDirectories(const std::vector<std::wstring>& paths) 
{
    ResetModel();

    for (const std::wstring& path : paths) {
        for (const auto& entry : std::experimental::filesystem::directory_iterator(path)) {
            ReadFromResource(entry.path());
        }
    }
}

/**
 * Gets Data Model.
 */
const IDataModelSharedPtr DataRepository::GetDataModel() const 
{
    return m_dataModel;
}

/**
 * Gets Data Query.
 */
const IDataQuerySharedPtr DataRepository::GetDataQuery() const
{
    return DataQuery::Make(*m_dataModel);
}

/**
 * Gets TLog Statistics Collection.
 */
tlogging::ITLogStatisticsCollectionSharedPtr DataRepository::GetTLogStatisticsCollection() const
{
    return m_tlogsStatistics;
}

/**
 * Resets model.
 */
void DataRepository::ResetModel()
{
    m_dataModel = DataModel::Make();
    m_tlogsStatistics = tlogging::TLogStatisticsCollection::Make();
}

/**
 * Reads from resource.
 */
void DataRepository::ReadFromResource(const std::wstring& path)
{
    //
    // Update model...
    //
    UpdateModel(path);
}

/**
 * Updates model.
 */
void DataRepository::UpdateModel(const std::wstring& path)
{
    //
    // Build the model...
    //
    IModelBuilderSharedPtr modelBuilder = TLogModelBuilder::Make(
        path,
        *m_dataModel, 
        m_eventLog);

    modelBuilder->Build();

    //
    // Update statistics...
    //
    tlogging::ITLogStatisticsSharedPtr statistics = modelBuilder->GetStatistics();
    m_tlogsStatistics->AddTLogStatistics(statistics);

    InitializeRenderingPipelines();
}

/**
 * Initializes rendering pipelines.
 */
void DataRepository::InitializeRenderingPipelines()
{
    Model::IRenderingPipelineInformationCollectionSharedPtr renderingPipelinesInformationCollection =
        m_dataModel->GetRenderingPipelines();

    renderingPipelinesInformationCollection->AddItem(CreateRenderingPipeline1());
    renderingPipelinesInformationCollection->AddItem(CreateRenderingPipeline2());
    renderingPipelinesInformationCollection->AddItem(CreateRenderingPipeline3());
    renderingPipelinesInformationCollection->AddItem(CreateRenderingPipeline4());
    renderingPipelinesInformationCollection->AddItem(CreateRenderingPipeline5());
}

/**
 * Creates rendering pipeline1.
 */
IRenderingPipelineInformationSharedPtr DataRepository::CreateRenderingPipeline1()
{
    std::wstring id = L"5";
    unsigned int msi = 378;
    double fps = 22.3;
    RenderingStatus renderingStatus = RenderingStatus::RENDERING;

    return Model::RenderingPipelineInformation::Make(
        id, 
        msi, 
        fps,
        renderingStatus);
}

/**
 * Creates rendering pipeline2.
 */
IRenderingPipelineInformationSharedPtr DataRepository::CreateRenderingPipeline2()
{
    std::wstring id = L"13";
    unsigned int msi = 124;
    double fps = 26.4;
    RenderingStatus renderingStatus = RenderingStatus::RENDERING;

    return Model::RenderingPipelineInformation::Make(
        id, 
        msi, 
        fps, 
        renderingStatus);
}

/**
 * Creates rendering pipeline3.
 */
IRenderingPipelineInformationSharedPtr DataRepository::CreateRenderingPipeline3()
{
    std::wstring id = L"45";
    unsigned int msi = 12;
    double fps = 13.2;
    RenderingStatus renderingStatus = RenderingStatus::RENDERING;

    return Model::RenderingPipelineInformation::Make(
        id, 
        msi, 
        fps, 
        renderingStatus);
}

/**
 * Creates rendering pipeline4.
 */
IRenderingPipelineInformationSharedPtr DataRepository::CreateRenderingPipeline4()
{
    std::wstring id = L"78";
    unsigned int msi = 14;
    double fps = 0;
    RenderingStatus renderingStatus = RenderingStatus::FROZEN;

    return Model::RenderingPipelineInformation::Make(
        id, 
        msi, 
        fps, 
        renderingStatus);
}

/**
 * Creates rendering pipeline5.
 */
IRenderingPipelineInformationSharedPtr DataRepository::CreateRenderingPipeline5()
{
    std::wstring id = L"38";
    unsigned int msi = 2;
    double fps = 0;
    RenderingStatus renderingStatus = RenderingStatus::CREATED;

    return Model::RenderingPipelineInformation::Make(
        id, 
        msi, 
        fps, 
        renderingStatus);
}
