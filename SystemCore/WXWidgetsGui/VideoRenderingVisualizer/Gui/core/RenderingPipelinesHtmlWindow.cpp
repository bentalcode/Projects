#include "RenderingPipelinesHtmlWindow.h"
#include "GuiManager.h"
#include "IDataQuery.h"
#include "IDataCatalog.h"
#include "GuiPaths.h"
#include "GuiDataItems.h"
#include "DataItem.h"
#include "RenderingPipelineInformation.h"
#include "WXProperty.h"
#include "video_rendering_visualizer_exception.h"

using namespace VideoRenderingVisualizer;
using namespace VideoRenderingVisualizer::Gui;

namespace RenderingPipelinesListViewFunctors {

/**
 * The UpdateDataContainerStartIntervalTimeFunctor class implements an update functor of start interval time.
 */
class UpdateDataContainerStartIntervalTimeFunctor final {
public:
    /**
     * The functor constructor.
     */
    UpdateDataContainerStartIntervalTimeFunctor(DataContainerManagement::IDataContainer& dataContainer) : 
        m_dataContainer(dataContainer)
    {
    }

    /**
     * The functor logic.
     */
    void operator()(const Utilities::DateTime& time)
    {
        RenderingPipelinesHtmlWindow::UpdateDataContainerStartIntervalTime(m_dataContainer, time);
    }

private:
    DataContainerManagement::IDataContainer& m_dataContainer;
};

/**
 * The UpdateDataContainerEndIntervalTimeFunctor class implements an update functor of end interval time.
 */
class UpdateDataContainerEndIntervalTimeFunctor final {
public:
    /**
     * The functor constructor.
     */
    UpdateDataContainerEndIntervalTimeFunctor(DataContainerManagement::IDataContainer& dataContainer) : 
        m_dataContainer(dataContainer)
    {
    }

    /**
     * The functor logic.
     */
    void operator()(const Utilities::DateTime& time)
    {
        RenderingPipelinesHtmlWindow::UpdateDataContainerEndIntervalTime(m_dataContainer, time);
    }

private:
    DataContainerManagement::IDataContainer& m_dataContainer;
};

} // namespace RenderingPipelinesListViewFunctors

/**
 * Creates a Rendering Pipelines Html Window.
 */
WXWidgets::IHtmlWindowPtr RenderingPipelinesHtmlWindow::Make(
    wxWindow& parent, 
    const Utilities::DateTimeIntervalSharedPtr intervalTime,
    IGuiManager& guiManager)
{
    return WXWidgets::IHtmlWindowPtr::Make(
        new RenderingPipelinesHtmlWindow(
            parent, 
            intervalTime, 
            guiManager));
}

/**
 * The RenderingPipelinesHtmlWindow constructor.
 */
RenderingPipelinesHtmlWindow::RenderingPipelinesHtmlWindow(
    wxWindow& parent, 
    const Utilities::DateTimeIntervalSharedPtr intervalTime,
    IGuiManager& guiManager) : 
        HtmlWindow(
            parent, 
            GuiPaths::Read().GetMainFrameTopMenuBarViewMenuRenderingPipelinesVisualizerDialogHtmlWindow()), 
        m_guiManager(guiManager), 
        m_intervalTime(intervalTime)
{
    //
    // Initialize a GUI component...
    //
    Initialize(guiManager);
}

/**
 * The RenderingPipelinesHtmlWindow destructor.
 */
RenderingPipelinesHtmlWindow::~RenderingPipelinesHtmlWindow() 
{
}

/**
 * Initializes a GUI component.
 */
void RenderingPipelinesHtmlWindow::Initialize(IGuiManager& guiManager)
{
    //
    // Initialize a Html Window with rendering pipelines...
    //
    m_renderingPipelines = QueryRenderingPipelinesInformation();

    std::vector<std::wstring> headers;
    std::vector<std::vector<std::wstring>> values;
    GetListViewInformation(headers, values);

    HtmlWindow::Initialize(guiManager.GetGuiController());

    //
    // Reset component...
    //
    Reset();

    //
    // Register data update functors...
    //
    DataContainerManagement::IDataContainer& dataContainer = GetData();

    std::wstring dataItemStartIntervalTime = GuiDataItems::Read().GetRenderingPipelinesStartIntervalTime();
    std::wstring dataItemEndIntervalTime = GuiDataItems::Read().GetRenderingPipelinesEndIntervalTime();

    dataContainer.GetCatalog().RegisterDataItem(dataItemStartIntervalTime);
    dataContainer.GetCatalog().RegisterDataItem(dataItemEndIntervalTime);

    DataContainerManagement::IDataContainerUpdateFunctors::IDateTimeFunctorSharedPtr startIntervalTimeFunctor =
        std::make_shared<DataContainerManagement::IDataContainerUpdateFunctors::IDateTimeFunctor>(
            RenderingPipelinesListViewFunctors::UpdateDataContainerStartIntervalTimeFunctor{ dataContainer });

    GetDataUpdateFunctors().RegisterUpdateFunctor(
        dataItemStartIntervalTime, 
        startIntervalTimeFunctor);

    DataContainerManagement::IDataContainerUpdateFunctors::IDateTimeFunctorSharedPtr endIntervalTimeFunctor =
        std::make_shared<DataContainerManagement::IDataContainerUpdateFunctors::IDateTimeFunctor>(
            RenderingPipelinesListViewFunctors::UpdateDataContainerEndIntervalTimeFunctor{ dataContainer });

    GetDataUpdateFunctors().RegisterUpdateFunctor(
        dataItemEndIntervalTime,
        endIntervalTimeFunctor);
}

/**
 * Resets component.
 */
void RenderingPipelinesHtmlWindow::Reset() 
{
    std::filesystem::path htmlPath = m_guiManager.GetRenderingPipelinesVisualizerHtmlPath();
    LoadFile(htmlPath);
}

/**
 * Updates data container (start interval time).
 */
void RenderingPipelinesHtmlWindow::UpdateDataContainerStartIntervalTime(
    DataContainerManagement::IDataContainer& data, 
    const Utilities::DateTime& time)
{
    std::wstring dataItemName = GuiDataItems::Read().GetRenderingPipelinesStartIntervalTime();

    DataContainerManagement::IDataItemSharedPtr dataItem =
        DataContainerManagement::DataItem::Create(
            dataItemName, 
            time);

    data.SetDataItem(dataItem);
}

/**
 * Updates data container (end interval time).
 */
void RenderingPipelinesHtmlWindow::UpdateDataContainerEndIntervalTime(
    DataContainerManagement::IDataContainer& data, 
    const Utilities::DateTime& time)
{
    std::wstring dataItemName = GuiDataItems::Read().GetRenderingPipelinesEndIntervalTime();

    DataContainerManagement::IDataItemSharedPtr dataItem = DataContainerManagement::DataItem::Create(
        dataItemName, 
        time);

    data.SetDataItem(dataItem);
}

/**
 * Updates data from data container.
 * Returns true in case data has been updated.
 */
bool RenderingPipelinesHtmlWindow::UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer)
{
    bool dataUpdated = false;

    std::wstring dataItemStartIntervalTime = GuiDataItems::Read().GetRenderingPipelinesStartIntervalTime();

    if (dataContainer.HasDataItem(dataItemStartIntervalTime)) {
        const DataContainerManagement::IDataItem& dataItem =
            dataContainer.GetDataItem(dataItemStartIntervalTime);

        const Utilities::DateTime& startIntervalTime = dataItem.GetValue()->GetDateTime();
        bool propertyUpdated = WXWidgets::WXProperty::UpdateSharedValuePtr(
            m_intervalTime->GetStartTime(), 
            startIntervalTime);

        dataUpdated |= propertyUpdated;
    }

    std::wstring dataItemEndIntervalTime = GuiDataItems::Read().GetRenderingPipelinesEndIntervalTime();

    if (dataContainer.HasDataItem(dataItemEndIntervalTime)) {
        const DataContainerManagement::IDataItem& dataItem =
            dataContainer.GetDataItem(dataItemEndIntervalTime);

        const Utilities::DateTime& endIntervalTime = dataItem.GetValue()->GetDateTime();
        
        bool propertyUpdated = WXWidgets::WXProperty::UpdateSharedValuePtr(
            m_intervalTime->GetEndTime(), 
            endIntervalTime);

        dataUpdated |= propertyUpdated;
    }

    if (dataUpdated) {
        //
        // Query rendering pipelines information...
        //
        m_renderingPipelines = QueryRenderingPipelinesInformation();

        //
        // Update Html Window values...
        //
        std::vector<std::vector<std::wstring>> values;
        GetListViewValues(values);
    }

    bool propertiesUpdated = WXWidgets::HtmlWindow::UpdateFromDataContainer(dataContainer);
    dataUpdated |= propertiesUpdated;

    return dataUpdated;
}

/**
 * Updates component.
 */
void RenderingPipelinesHtmlWindow::Update()
{
    //
    // Update the Html Window...
    //
    WXWidgets::HtmlWindow::Update();

    //
    // Reset component...
    //
    Reset();
}

/**
 * Queries rendering pipelines information.
 */
Model::IRenderingPipelineInformationCollectionSharedPtr RenderingPipelinesHtmlWindow::QueryRenderingPipelinesInformation() const
{
    const Model::IDataRepositorySharedPtr dataRepository = m_guiManager.GetDataRepository();
    const Model::IDataQuerySharedPtr dataQuery = dataRepository->GetDataQuery();

    Model::IRenderingPipelineInformationCollectionSharedPtr renderingPipelines = 
        dataQuery->QueryRenderingPipelines(*m_intervalTime);

    return renderingPipelines;
}

/**
 * Gets list view information.
 */
void RenderingPipelinesHtmlWindow::GetListViewInformation(
    std::vector<std::wstring>& headers,
    std::vector<std::vector<std::wstring>>& values) const
{
    GetListViewHeaders(headers);
    GetListViewValues(values);
}

/**
 * Gets list view headers.
 */
void RenderingPipelinesHtmlWindow::GetListViewHeaders(std::vector<std::wstring>& headers) const
{
    assert(headers.empty());
    Model::RenderingPipelineInformation::GetPropertiesNames(headers);
}

/**
 * Gets list view values.
 */
void RenderingPipelinesHtmlWindow::GetListViewValues(std::vector<std::vector<std::wstring>>& values) const
{
    assert(values.empty());

    //
    // Create corresponding compositors values...
    //
    Utilities::IIteratorSharedPtr<Model::IRenderingPipelineInformationSharedPtr> renderingPipelineIterator =
        m_renderingPipelines->GetIterator();

    while (renderingPipelineIterator->HasNext()) {
        std::vector<std::wstring> dataEntry;
        dataEntry.reserve(4);

        Model::IRenderingPipelineInformationSharedPtr renderingPipeline = renderingPipelineIterator->Next();

        dataEntry.push_back(renderingPipeline->GetId());
        dataEntry.push_back(std::to_wstring(renderingPipeline->GetMsi()));
        dataEntry.push_back(std::to_wstring(renderingPipeline->GetFps()));
        dataEntry.push_back(Model::RenderingPipelineInformation::GetRenderingStatusString(renderingPipeline->GetRenderingStatus()));

        values.push_back(dataEntry);
    }
}
