#ifndef I_MENU_CONFIGURATION_ITEMS_H_8a5a9ffb_2498_4733_abd1_3da2379a7875
#define I_MENU_CONFIGURATION_ITEMS_H_8a5a9ffb_2498_4733_abd1_3da2379a7875

#include "IConfigurationItems.h"

namespace VideoRenderingVisualizer { 
    
    namespace Gui {

        /**
         * The IMenuConfigurationItems interface defines configuration items of menus.
         */
        class IMenuConfigurationItems : public GuiConfiguration::IConfigurationItems {
        public:
            IMenuConfigurationItems() = default;
            virtual ~IMenuConfigurationItems() = default;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // I_MENU_CONFIGURATION_ITEMS_H_8a5a9ffb_2498_4733_abd1_3da2379a7875
