#pragma once

#include "ListView.h"
#include "IEventLog.h"
#include "DateTimeInterval.h"
#include <vector>

namespace VideoRenderingVisualizer {

namespace Gui {

class IGuiManager;

/**
 * The EventListView class implements a list view of events.
 */
class EventListView final : public WXWidgets::ListView {
public:
    /**
     * Creates an Event List View.
     */
    static WXWidgets::IListViewPtr Make(
        wxWindow& parent, 
        TabularData::IEventLogSharedPtr eventLog,
        const Utilities::DateTimeIntervalSharedPtr intervalTime,
        IGuiManager& guiManager);

    /**
     * The EventListView constructor.
     */
    EventListView(
        wxWindow& parent, 
        TabularData::IEventLogSharedPtr eventLog,
        const Utilities::DateTimeIntervalSharedPtr intervalTime,
        IGuiManager& guiManager);

    /**
     * The EventListView destructor.
     */
    virtual ~EventListView();

    /**
     * Updates data container (start interval time).
     */
    static void UpdateDataContainerStartIntervalTime(
        DataContainerManagement::IDataContainer& data, 
        const Utilities::DateTime& time);

    /**
     * Updates data container (end interval time).
     */
    static void UpdateDataContainerEndIntervalTime(
        DataContainerManagement::IDataContainer& data, 
        const Utilities::DateTime& time);

protected:
    /**
     * Updates data from data container.
     * Returns true in case data has been updated.
     */
    virtual bool UpdateFromDataContainer(DataContainerManagement::IDataContainer& dataContainer) override;

    /**
     * Updates component.
     */
    virtual void Update() override;

private:
    /**
     * Initializes a GUI component.
     */
    void Initialize(IGuiManager& guiManager);

    /**
     * Gets list view information.
     */
    void GetListViewInformation(
        std::vector<std::wstring>& headers, 
        std::vector<std::vector<std::wstring>>& values) const;

    /**
     * Gets list view headers.
     */
    void GetListViewHeaders(std::vector<std::wstring>& headers) const;

    /**
     * Gets list view values.
     */
    void GetListViewValues(std::vector<std::vector<std::wstring>>& values) const;

    /**
     * Sorts events by time.
     */
    static void SortEventsByTime(std::vector<TabularData::IEventSharedPtr>& events);

    //
    // The GUI Manager...
    //
    IGuiManager& m_guiManager;

    //
    // The Event Log...
    //
    TabularData::IEventLogSharedPtr m_eventLog;

    //
    // The interval time for displaying events...
    //
    Utilities::DateTimeIntervalSharedPtr m_intervalTime;
};

}  // namespace Gui

}  // namespace VideoRenderingVisualizer
