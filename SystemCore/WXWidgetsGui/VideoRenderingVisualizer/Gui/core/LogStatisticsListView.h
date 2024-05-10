#ifndef LOG_STATISTICS_LIST_VIEW_H_4b18d1d6_e647_4bdd_a585_bd4da6fff134
#define LOG_STATISTICS_LIST_VIEW_H_4b18d1d6_e647_4bdd_a585_bd4da6fff134

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
                tlogging::ITLogStatisticsCollectionSharedPtr logsStatistics,
                IGuiManager& guiManager);

            /**
             * The LogStatisticsListView constructor.
             */
            LogStatisticsListView(
                wxWindow& parent,
                tlogging::ITLogStatisticsCollectionSharedPtr logsStatistics,
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
            static std::wstring CreateCallStartedCallEndedCountersString(const tlogging::ITLogStatistics& logStatistics);

            /**
             * Creates TLog records CompositorCreated/CompositorDestroyed counters string.
             */
            static std::wstring CreateCompositorCreatedCompositorDestroyedCountersString(const tlogging::ITLogStatistics& logStatistics);

            /**
             * Creates TLog records AddView/RemoveView counters string.
             */
            static std::wstring CreateAddViewRemoveViewCountersString(const tlogging::ITLogStatistics& logStatistics);

            /**
             * Creates TLog records SetConfiguration/SetViewProperties counters string.
             */
            static std::wstring CreateSetConfigurationSetViewPropertiesCountersString(const tlogging::ITLogStatistics& logStatistics);

            //
            // The GUI Manager...
            //
            IGuiManager& m_guiManager;

            //
            // The Log Statistics Collection...
            //
            tlogging::ITLogStatisticsCollectionSharedPtr m_logsStatistics;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // LOG_STATISTICS_LIST_VIEW_H_4b18d1d6_e647_4bdd_a585_bd4da6fff134
