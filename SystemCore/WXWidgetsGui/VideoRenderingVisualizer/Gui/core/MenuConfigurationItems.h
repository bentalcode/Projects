#ifndef MENU_CONFIGURATION_ITEMS_H_a77af761_8dea_4086_9601_f3ac8a2559bd
#define MENU_CONFIGURATION_ITEMS_H_a77af761_8dea_4086_9601_f3ac8a2559bd

#include "IMenuConfigurationItems.h"

namespace VideoRenderingVisualizer { 
    
    namespace Gui {

        /**
         * The MenuConfigurationItems class implements configuration items of menus.
         */
        class MenuConfigurationItems final : public IMenuConfigurationItems {
        public:
            /**
             * Reads menu configuration items from configuration catalog.
             */
            static const IMenuConfigurationItems& Read();

            /**
             * Creates menu configuration items.
             */
            static GuiConfiguration::IConfigurationItemsSharedPtr Make();

            /**
             * The MenuConfigurationItems constructor.
             */
            MenuConfigurationItems();

            /**
             * The MenuConfigurationItems destructor.
             */
            virtual ~MenuConfigurationItems();

            /**
             * Gets category name of data items.
             */
            virtual const std::wstring& GetName() const override;

        private:
            static const std::wstring NAME;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // MENU_CONFIGURATION_ITEMS_H_a77af761_8dea_4086_9601_f3ac8a2559bd
