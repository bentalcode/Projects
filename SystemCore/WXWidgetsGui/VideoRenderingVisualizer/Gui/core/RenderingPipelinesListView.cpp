#include "RenderingPipelinesListView.h"
#include "GuiManager.h"
#include "IDataQuery.h"
#include "IDataCatalog.h"
#include "GuiPaths.h"
#include "GuiDataItems.h"
#include "DataItem.h"
#include "RenderingPipelineInformation.h"
#include "Font.h"
#include "WXProperty.h"

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
        RenderingPipelinesListView::UpdateDataContainerStartIntervalTime(m_dataContainer, time);
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
        RenderingPipelinesListView::UpdateDataContainerEndIntervalTime(m_dataContainer, time);
    }

private:
    DataContainerManagement::IDataContainer& m_dataContainer;
};

} // namespace RenderingPipelinesListViewFunctors

/**
 * Creates a Rendering Pipelines List View.
 */
WXWidgets::IListViewPtr RenderingPipelinesListView::Make(
    wxWindow& parent, 
    const Utilities::DateTimeIntervalSharedPtr intervalTime,
    IGuiManager& guiManager)
{
    return WXWidgets::IListViewPtr::Make(
        new RenderingPipelinesListView(
            parent, 
            intervalTime, 
            guiManager));
}

/**
 * The RenderingPipelinesListView constructor.
 */
RenderingPipelinesListView::RenderingPipelinesListView(
    wxWindow& parent, 
    const Utilities::DateTimeIntervalSharedPtr intervalTime,
    IGuiManager& guiManager) : 
        ListView(
            parent, 
            GuiPaths::Read().GetMainFrameMainRightBottomWindowListView()), 
        m_guiManager(guiManager), 
        m_intervalTime(intervalTime)
{
    //
    // Initialize a GUI component...
    //
    Initialize(guiManager);
}

/**
 * The RenderingPipelinesListView destructor.
 */
RenderingPipelinesListView::~RenderingPipelinesListView() 
{
}

/**
 * Initializes a GUI component.
 */
void RenderingPipelinesListView::Initialize(IGuiManager& guiManager)
{
    //
    // Initialize a list view with rendering pipelines...
    //
    m_renderingPipelines = QueryRenderingPipelinesInformation();

    std::vector<std::wstring> headers;
    std::vector<std::vector<std::wstring>> values;
    GetListViewInformation(headers, values);

    ListView::Initialize(
        headers, 
        values, 
        wxLIST_FORMAT_CENTRE, 
        wxLIST_DEFAULT_COL_WIDTH * 4,
        guiManager.GetGuiController());

    //
    // Set header attributes...
    //
    WXWidgets::ColorType fontColorType = WXWidgets::ColorType::BLACK;
    WXWidgets::ColorType backgroundColorType = WXWidgets::ColorType::WHITE;
    WXWidgets::Font headerFont;
    headerFont.MakeBold();
    
    SetHeaderAttributes(
        fontColorType, 
        backgroundColorType, 
        headerFont);

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
void RenderingPipelinesListView::Reset() 
{
    //
    // Color the rows of list view based on the rendering pipelines status...
    //
    Utilities::IIteratorSharedPtr<Model::IRenderingPipelineInformationSharedPtr> renderingPipelineIterator =
        m_renderingPipelines->GetIterator();

    size_t rowIndex = 0;

    while (renderingPipelineIterator->HasNext()) {
        Model::IRenderingPipelineInformationSharedPtr renderingPipeline = renderingPipelineIterator->Next();

        WXWidgets::ColorType renderingStatusColor = GetRenderingStatusColor(renderingPipeline->GetRenderingStatus());
        SetRowBackgroundColor(rowIndex, renderingStatusColor);
    
        ++rowIndex;
    }
}

/**
 * Updates data container (start interval time).
 */
void RenderingPipelinesListView::UpdateDataContainerStartIntervalTime(
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
void RenderingPipelinesListView::UpdateDataContainerEndIntervalTime(
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
bool RenderingPipelinesListView::UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer)
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
        // Update list view values...
        //
        std::vector<std::vector<std::wstring>> values;
        GetListViewValues(values);

        WXWidgets::ListView::UpdateDataContainerValues(GetData(), values);
    }

    bool propertiesUpdated = WXWidgets::ListView::UpdateFromDataContainer(dataContainer);
    dataUpdated |= propertiesUpdated;

    return dataUpdated;
}

/**
 * Updates component.
 */
void RenderingPipelinesListView::Update()
{
    //
    // Update the list view...
    //
    WXWidgets::ListView::Update();

    //
    // Reset component...
    //
    Reset();
}

/**
 * Queries rendering pipelines information.
 */
Model::IRenderingPipelineInformationCollectionSharedPtr RenderingPipelinesListView::QueryRenderingPipelinesInformation() const
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
void RenderingPipelinesListView::GetListViewInformation(
    std::vector<std::wstring>& headers,
    std::vector<std::vector<std::wstring>>& values) const
{
    GetListViewHeaders(headers);
    GetListViewValues(values);
}

/**
 * Gets list view headers.
 */
void RenderingPipelinesListView::GetListViewHeaders(std::vector<std::wstring>& headers) const
{
    assert(headers.empty());
    Model::RenderingPipelineInformation::GetPropertiesNames(headers);
}

/**
 * Gets list view values.
 */
void RenderingPipelinesListView::GetListViewValues(std::vector<std::vector<std::wstring>>& values) const
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

/**
 * Gets a color of rendering status.
 */
WXWidgets::ColorType RenderingPipelinesListView::GetRenderingStatusColor(Model::RenderingStatus status) const
{
    const RenderingStatusToColorMap& renderingStatusMap = GetRenderingStatusToColorMap();
    
    RenderingPipelinesListView::RenderingStatusToColorMap::const_iterator renderingStatusIterator =
        renderingStatusMap.find(status);

    return renderingStatusIterator->second;
}

/**
 * Gets the Rendering Status -> Color map.
 */
const RenderingPipelinesListView::RenderingStatusToColorMap& RenderingPipelinesListView::GetRenderingStatusToColorMap() const
{
    static std::unique_ptr<RenderingStatusToColorMap> mapPtr;

    if (!mapPtr) {
        mapPtr.reset(new RenderingStatusToColorMap);
        InitializeRenderingStatusToColorMap(*mapPtr);
    }

    return *mapPtr;
}

/**
 * Initializes the Rendering Status -> Color map.
 */
void RenderingPipelinesListView::InitializeRenderingStatusToColorMap(RenderingStatusToColorMap& map)
{
    assert(map.empty());

    map.insert(std::make_pair(Model::RenderingStatus::CREATED, WXWidgets::ColorType::YELLOW));
    map.insert(std::make_pair(Model::RenderingStatus::RENDERING, WXWidgets::ColorType::GREEN));
    map.insert(std::make_pair(Model::RenderingStatus::FROZEN, WXWidgets::ColorType::RED));
}
