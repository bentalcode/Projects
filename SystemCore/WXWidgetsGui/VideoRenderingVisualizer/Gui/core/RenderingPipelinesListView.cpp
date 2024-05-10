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
    void operator()(const base::DateTime& time)
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
    void operator()(const base::DateTime& time)
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
wxwidgets::IListViewPtr RenderingPipelinesListView::Make(
    wxWindow& parent, 
    const base::DateTimeIntervalSharedPtr intervalTime,
    IGuiManager& guiManager)
{
    return wxwidgets::IListViewPtr::Make(
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
    const base::DateTimeIntervalSharedPtr intervalTime,
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
    wxwidgets::ColorType fontColorType = wxwidgets::ColorType::BLACK;
    wxwidgets::ColorType backgroundColorType = wxwidgets::ColorType::WHITE;
    wxwidgets::Font headerFont;
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
    base::IIteratorSharedPtr<Model::IRenderingPipelineInformationSharedPtr> renderingPipelineIterator =
        m_renderingPipelines->GetIterator();

    size_t rowIndex = 0;

    while (renderingPipelineIterator->HasNext()) {
        Model::IRenderingPipelineInformationSharedPtr renderingPipeline = renderingPipelineIterator->Next();

        wxwidgets::ColorType renderingStatusColor = GetRenderingStatusColor(renderingPipeline->GetRenderingStatus());
        SetRowBackgroundColor(rowIndex, renderingStatusColor);
    
        ++rowIndex;
    }
}

/**
 * Updates data container (start interval time).
 */
void RenderingPipelinesListView::UpdateDataContainerStartIntervalTime(
    DataContainerManagement::IDataContainer& data, 
    const base::DateTime& time)
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
    const base::DateTime& time)
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

        const base::DateTime& startIntervalTime = dataItem.GetValue()->GetDateTime();
        base::DateTimeSharedPtr startTime = m_intervalTime->GetStartTime();

        bool propertyUpdated = wxwidgets::WXProperty::UpdateSharedValuePtr(
            startTime,
            startIntervalTime);

        dataUpdated |= propertyUpdated;
    }

    std::wstring dataItemEndIntervalTime = GuiDataItems::Read().GetRenderingPipelinesEndIntervalTime();

    if (dataContainer.HasDataItem(dataItemEndIntervalTime)) {
        const DataContainerManagement::IDataItem& dataItem =
            dataContainer.GetDataItem(dataItemEndIntervalTime);

        const base::DateTime& endIntervalTime = dataItem.GetValue()->GetDateTime();
        base::DateTimeSharedPtr endTime = m_intervalTime->GetEndTime();

        bool propertyUpdated = wxwidgets::WXProperty::UpdateSharedValuePtr(
            endTime,
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

        wxwidgets::ListView::UpdateDataContainerValues(GetData(), values);
    }

    bool propertiesUpdated = wxwidgets::ListView::UpdateFromDataContainer(dataContainer);
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
    wxwidgets::ListView::Update();

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
    base::IIteratorSharedPtr<Model::IRenderingPipelineInformationSharedPtr> renderingPipelineIterator =
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
wxwidgets::ColorType RenderingPipelinesListView::GetRenderingStatusColor(Model::RenderingStatus status) const
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

    map.insert(std::make_pair(Model::RenderingStatus::CREATED, wxwidgets::ColorType::YELLOW));
    map.insert(std::make_pair(Model::RenderingStatus::RENDERING, wxwidgets::ColorType::GREEN));
    map.insert(std::make_pair(Model::RenderingStatus::FROZEN, wxwidgets::ColorType::RED));
}
