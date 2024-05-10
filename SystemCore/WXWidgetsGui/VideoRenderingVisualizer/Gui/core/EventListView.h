#ifndef EVENT_LIST_VIEW_H_e68ac0b9_b474_4ccf_9837_544b71b2db96
#define EVENT_LIST_VIEW_H_e68ac0b9_b474_4ccf_9837_544b71b2db96

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
                tabular_data::IEventLogSharedPtr eventLog,
                const base::DateTimeIntervalSharedPtr intervalTime,
                IGuiManager& guiManager);

            /**
             * The EventListView constructor.
             */
            EventListView(
                wxWindow& parent,
                tabular_data::IEventLogSharedPtr eventLog,
                const base::DateTimeIntervalSharedPtr intervalTime,
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
                const base::DateTime& time);

            /**
             * Updates data container (end interval time).
             */
            static void UpdateDataContainerEndIntervalTime(
                DataContainerManagement::IDataContainer& data,
                const base::DateTime& time);

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
            static void SortEventsByTime(std::vector<tabular_data::IEventSharedPtr>& events);

            //
            // The GUI Manager...
            //
            IGuiManager& m_guiManager;

            //
            // The Event Log...
            //
            tabular_data::IEventLogSharedPtr m_eventLog;

            //
            // The interval time for displaying events...
            //
            base::DateTimeIntervalSharedPtr m_intervalTime;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // EVENT_LIST_VIEW_H_e68ac0b9_b474_4ccf_9837_544b71b2db96
