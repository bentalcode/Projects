#ifndef GUI_DATA_ITEMS_H_e8cd7d05_b7cf_4bdd_9d5e_923f3d054133
#define GUI_DATA_ITEMS_H_e8cd7d05_b7cf_4bdd_9d5e_923f3d054133

#include "IGuiDataItems.h"

namespace VideoRenderingVisualizer {

    namespace Gui {

        /**
         * The GuiDataItems class implements extended data items of GUI.
         */
        class GuiDataItems final : public IGuiDataItems {
        public:
            /**
             * Reads GUI data items from data item catalog.
             */
            static const IGuiDataItems& Read();

            /**
             * Creates GUI data items.
             */
            static WXWidgets::IDataItemsSharedPtr Make();

            /**
             * The GuiDataItems constructor.
             */
            GuiDataItems();

            /**
             * The GuiDataItems destructor.
             */
            virtual ~GuiDataItems();

            /**
             * Gets category name of data items.
             */
            virtual const std::wstring& GetName() const override;

            /**
             * Gets a compositor id.
             */
            virtual const std::wstring& GetCompositorId() const override;

            /**
             * Gets events start interval time.
             */
            virtual const std::wstring& GetEventsStartIntervalTime() const override;

            /**
             * Gets events end interval time.
             */
            virtual const std::wstring& GetEventsEndIntervalTime() const override;

            /**
             * Gets rendering pipelines start interval time.
             */
            virtual const std::wstring& GetRenderingPipelinesStartIntervalTime() const override;

            /**
             * Gets rendering pipelines end interval time.
             */
            virtual const std::wstring& GetRenderingPipelinesEndIntervalTime() const override;

        private:
            static const std::wstring COMPOSITOR_ID;
            static const std::wstring EVENTS_START_INTERVAL_TIME;
            static const std::wstring EVENTS_END_INTERVAL_TIME;
            static const std::wstring RENDERING_PIPELINES_START_INTERVAL_TIME;
            static const std::wstring RENDERING_PIPELINES_END_INTERVAL_TIME;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // GUI_DATA_ITEMS_H_e8cd7d05_b7cf_4bdd_9d5e_923f3d054133
