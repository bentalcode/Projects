#ifndef I_GUI_DATA_ITEMS_H_7335b3a4_09e9_47a0_bcc1_0fb5e5b32278
#define I_GUI_DATA_ITEMS_H_7335b3a4_09e9_47a0_bcc1_0fb5e5b32278

#include "IDataItems.h"

namespace VideoRenderingVisualizer {
    
    namespace Gui {

        /**
         * The IGuiDataItems interface defines data items of GUI.
         */
        class IGuiDataItems : public wxwidgets::IDataItems {
        public:
            IGuiDataItems() = default;
            virtual ~IGuiDataItems() = default;

            /**
             * Gets a compositor id.
             */
            virtual const std::wstring& GetCompositorId() const = 0;

            /**
             * Gets events start interval time.
             */
            virtual const std::wstring& GetEventsStartIntervalTime() const = 0;

            /**
             * Gets events end interval time.
             */
            virtual const std::wstring& GetEventsEndIntervalTime() const = 0;

            /**
             * Gets rendering pipelines start interval time.
             */
            virtual const std::wstring& GetRenderingPipelinesStartIntervalTime() const = 0;

            /**
             * Gets rendering pipelines end interval time.
             */
            virtual const std::wstring& GetRenderingPipelinesEndIntervalTime() const = 0;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // I_GUI_DATA_ITEMS_H_7335b3a4_09e9_47a0_bcc1_0fb5e5b32278
