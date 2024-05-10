#pragma once

#include "ListView.h"
#include "ITLogStatisticsCollection.h"

namespace VideoRenderingVisualizer {

namespace Gui {

class IGuiManager;

/**
 * The LogStatisticsListView class implements a list view of log statistics.
 */
class LogStatisticsListView final : public WXWidgets::ListView {
public:
    /**
     * Creates a Log Statistics List View.
     */
    static WXWidgets::IListViewPtr Make(
        wxWindow& parent, 
        TLogging::ITLogStatisticsCollectionSharedPtr logsStatistics,
        IGuiManager& guiManager);

    /**
     * The LogStatisticsListView constructor.
     */
    LogStatisticsListView(
        wxWindow& parent, 
        TLogging::ITLogStatisticsCollectionSharedPtr logsStatistics,
        IGuiManager& guiManager);

    /**
     * The LogStatisticsListView destructor.
     */
    virtual ~LogStatisticsListView();

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
     * Creates TLog records CallStarted/CallEnded counters string.
     */
    static std::wstring CreateCallStartedCallEndedCountersString(const TLogging::ITLogStatistics& logStatistics);

    /**
     * Creates TLog records CompositorCreated/CompositorDestroyed counters string.
     */
    static std::wstring CreateCompositorCreatedCompositorDestroyedCountersString(const TLogging::ITLogStatistics& logStatistics);

    /**
     * Creates TLog records AddView/RemoveView counters string.
     */
    static std::wstring CreateAddViewRemoveViewCountersString(const TLogging::ITLogStatistics& logStatistics);

    /**
     * Creates TLog records SetConfiguration/SetViewProperties counters string.
     */
    static std::wstring CreateSetConfigurationSetViewPropertiesCountersString(const TLogging::ITLogStatistics& logStatistics);

    //
    // The GUI Manager...
    //
    IGuiManager& m_guiManager;

    //
    // The Log Statistics Collection...
    //
    TLogging::ITLogStatisticsCollectionSharedPtr m_logsStatistics;
};

}  // namespace Gui

}  // namespace VideoRenderingVisualizer
