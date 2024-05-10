#include "EventListView.h"
#include "GuiManager.h"
#include "IDataCatalog.h"
#include "GuiPaths.h"
#include "GuiDataItems.h"
#include "EventLog.h"
#include "DataItem.h"
#include "Font.h"
#include "WXProperty.h"
#include "StringUtils.h"
#include <algorithm>

using namespace VideoRenderingVisualizer;
using namespace VideoRenderingVisualizer::Gui;

namespace EventListViewFunctors {

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
        EventListView::UpdateDataContainerStartIntervalTime(m_dataContainer, time);
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
        EventListView::UpdateDataContainerEndIntervalTime(m_dataContainer, time);
    }

private:
    DataContainerManagement::IDataContainer& m_dataContainer;
};

/**
 * The EventComparatorByTime class implements a comporator of events by time in descending order.
 */
class EventComparatorByTime final {
public:
    bool operator()(
        const TabularData::IEventSharedPtr& left, 
        const TabularData::IEventSharedPtr& right) const
    {
        return left->GetTime() >= right->GetTime();
    }
};

}  // namespace EventListViewFunctors

/**
 * Creates an Event List View.
 */
WXWidgets::IListViewPtr EventListView::Make(
    wxWindow& parent, 
    TabularData::IEventLogSharedPtr eventLog,
    const Utilities::DateTimeIntervalSharedPtr intervalTime,
    IGuiManager& guiManager)
{
    return WXWidgets::IListViewPtr::Make(
        new EventListView(
            parent,
            eventLog,
            intervalTime, 
            guiManager));
}

/**
 * The EventListView constructor.
 */
EventListView::EventListView(
    wxWindow& parent, 
    TabularData::IEventLogSharedPtr eventLog,
    const Utilities::DateTimeIntervalSharedPtr intervalTime,
    IGuiManager& guiManager) : 
        ListView(
            parent, 
            GuiPaths::Read().GetMainFrameTopMenuBarViewMenuEventViewerDialogListView()), 
        m_guiManager(guiManager), 
        m_eventLog(eventLog),
        m_intervalTime(intervalTime)
{
    //
    // Initialize a GUI component...
    //
    Initialize(guiManager);
}

/**
 * The EventListView destructor.
 */
EventListView::~EventListView() 
{
}

/**
 * Initializes a GUI component.
 */
void EventListView::Initialize(IGuiManager& guiManager)
{
    //
    // Initialize a list view with event information...
    //
    std::vector<std::wstring> headers;
    std::vector<std::vector<std::wstring>> values;
    GetListViewInformation(headers, values);

    ListView::Initialize(
        headers, 
        values, 
        wxLIST_FORMAT_LEFT, 
        wxLIST_DEFAULT_COL_WIDTH * 2,
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
    // Align columns widths by header...
    //
    AlignColumnsWidthByHeader();

    //
    // Register data update functors...
    //
    DataContainerManagement::IDataContainer& dataContainer = GetData();

    std::wstring dataItemStartIntervalTime = GuiDataItems::Read().GetEventsStartIntervalTime();
    std::wstring dataItemEndIntervalTime = GuiDataItems::Read().GetEventsEndIntervalTime();

    dataContainer.GetCatalog().RegisterDataItem(dataItemStartIntervalTime);
    dataContainer.GetCatalog().RegisterDataItem(dataItemEndIntervalTime);

    DataContainerManagement::IDataContainerUpdateFunctors::IDateTimeFunctorSharedPtr startIntervalTimeFunctor =
        std::make_shared<DataContainerManagement::IDataContainerUpdateFunctors::IDateTimeFunctor>(
            EventListViewFunctors::UpdateDataContainerStartIntervalTimeFunctor{ dataContainer });

    GetDataUpdateFunctors().RegisterUpdateFunctor(
        dataItemStartIntervalTime, 
        startIntervalTimeFunctor);

    DataContainerManagement::IDataContainerUpdateFunctors::IDateTimeFunctorSharedPtr endIntervalTimeFunctor =
        std::make_shared<DataContainerManagement::IDataContainerUpdateFunctors::IDateTimeFunctor>(
            EventListViewFunctors::UpdateDataContainerEndIntervalTimeFunctor{ dataContainer });

    GetDataUpdateFunctors().RegisterUpdateFunctor(
        dataItemEndIntervalTime,
        endIntervalTimeFunctor);
}

/**
 * Updates data container (start interval time).
 */
void EventListView::UpdateDataContainerStartIntervalTime(
    DataContainerManagement::IDataContainer& data, 
    const Utilities::DateTime& time)
{
    std::wstring dataItemName = GuiDataItems::Read().GetEventsStartIntervalTime();

    DataContainerManagement::IDataItemSharedPtr dataItem =
        DataContainerManagement::DataItem::Create(
            dataItemName, 
            time);

    data.SetDataItem(dataItem);
}

/**
 * Updates data container (end interval time).
 */
void EventListView::UpdateDataContainerEndIntervalTime(
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
bool EventListView::UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer)
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
void EventListView::Update()
{
    //
    // Update the list view...
    //
    WXWidgets::ListView::Update();
}

/**
 * Gets list view information.
 */
void EventListView::GetListViewInformation(
    std::vector<std::wstring>& headers,
    std::vector<std::vector<std::wstring>>& values) const
{
    GetListViewHeaders(headers);
    GetListViewValues(values);
}

/**
 * Gets list view headers.
 */
void EventListView::GetListViewHeaders(std::vector<std::wstring>& headers) const
{
    assert(headers.empty());

    headers.push_back(L"Event Type");
    headers.push_back(L"Date and Time");
    headers.push_back(L"Source");
    headers.push_back(L"Event Id");
    headers.push_back(L"Name");
    headers.push_back(L"Description");
}

/**
 * Gets list view values.
 */
void EventListView::GetListViewValues(std::vector<std::vector<std::wstring>>& values) const
{
    assert(values.empty());

    const TabularData::EventList& errorEvents = m_eventLog->GetErrorEvents();
    const TabularData::EventList& warningEvents = m_eventLog->GetWarningEvents();
    const TabularData::EventList& informationalEvents = m_eventLog->GetInformationalEvents();

    std::vector<TabularData::IEventSharedPtr> events;

    events.insert(events.end(), errorEvents.begin(), errorEvents.end());
    events.insert(events.end(), warningEvents.begin(), warningEvents.end());
    events.insert(events.end(), informationalEvents.begin(), informationalEvents.end());

    SortEventsByTime(events);

    for (const TabularData::IEventSharedPtr& event : events) {
        std::vector<std::wstring> eventValues;
        values.reserve(6);

        std::wstring eventType = TabularData::EventTypeToString(event->GetType());
        std::wstring time = event->GetTime().ToString();
        std::wstring source = event->GetSource();
        std::wstring eventId = event->GetId();
        std::wstring name = event->GetName();
        std::wstring description = event->GetDescription();
        Utilities::StringUtils::Trim(description);

        eventValues.push_back(eventType);
        eventValues.push_back(time);
        eventValues.push_back(source);
        eventValues.push_back(eventId);
        eventValues.push_back(name);
        eventValues.push_back(description);

        values.push_back(eventValues);
    }
}

/**
 * Sorts events by time.
 */
void EventListView::SortEventsByTime(std::vector<TabularData::IEventSharedPtr>& events)
{
    std::sort(
        events.begin(),
        events.end(),
        EventListViewFunctors::EventComparatorByTime());
}
