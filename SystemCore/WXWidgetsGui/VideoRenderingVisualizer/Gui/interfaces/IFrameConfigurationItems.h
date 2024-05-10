#ifndef I_FRAME_CONFIGUATION_ITEMS_H_9e1773b1_0784_4ef1_823b_d0bb6e2da1ae
#define I_FRAME_CONFIGUATION_ITEMS_H_9e1773b1_0784_4ef1_823b_d0bb6e2da1ae

#include "IConfigurationItems.h"

namespace VideoRenderingVisualizer { 
    
    namespace Gui {

        /**
         * The IFrameConfigurationItems interface defines configuration items of frames.
         */
        class IFrameConfigurationItems : public GuiConfiguration::IConfigurationItems {
        public:
            IFrameConfigurationItems() = default;
            virtual ~IFrameConfigurationItems() = default;

            /**
             * Gets name of main frame.
             */
            virtual const std::wstring& GetMainFrameName() const = 0;

            /**
             * Gets status text of main frame.
             */
            virtual const std::wstring& GetMainFrameStatusText() const = 0;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // I_FRAME_CONFIGUATION_ITEMS_H_9e1773b1_0784_4ef1_823b_d0bb6e2da1ae
