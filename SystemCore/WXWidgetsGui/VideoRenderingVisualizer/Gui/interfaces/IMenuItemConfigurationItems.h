#ifndef I_MENU_ITEM_CONFIGURATION_ITEMS_H_df601731_7da0_4229_8f94_653df785f2ff
#define I_MENU_ITEM_CONFIGURATION_ITEMS_H_df601731_7da0_4229_8f94_653df785f2ff

#include "IConfigurationItems.h"

namespace VideoRenderingVisualizer { 
    
    namespace Gui {

        /**
         * The IMenuItemConfigurationItems interface defines configuration items of menu items.
         */
        class IMenuItemConfigurationItems : public GuiConfiguration::IConfigurationItems {
        public:
            IMenuItemConfigurationItems() = default;
            virtual ~IMenuItemConfigurationItems() = default;

            /**
             * Gets text of main frame - top menu bar - file menu - open menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarFileMenuOpenMenuItemText() const = 0;

            /**
             * Gets help of main frame - top menu bar - file menu - open menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarFileMenuOpenMenuItemHelp() const = 0;

            /**
             * Gets text of main frame - top menu bar - file menu - exit menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarFileMenuExitMenuItemText() const = 0;

            /**
             * Gets help of main frame - top menu bar - file menu - exit menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarFileMenuExitMenuItemHelp() const = 0;

            /**
             * Gets text of main frame - top menu bar - view menu - rendering pipelines visualizer menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarViewMenuRenderingPipelinesVisualizerMenuItemText() const = 0;

            /**
             * Gets help of main frame - top menu bar - view menu - rendering pipelines visualizer menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarViewMenuRenderingPipelinesVisualizerMenuItemHelp() const = 0;

            /**
             * Gets help of main frame - top menu bar - view menu - event viewer menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarViewMenuEventViewerMenuItemText() const = 0;

            /**
             * Gets help of main frame - top menu bar - view menu - event viewer menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarViewMenuEventViewerMenuItemHelp() const = 0;

            /**
             * Gets text of main frame - top menu bar - view menu - log statistics menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarViewMenuLogStatisticsMenuItemText() const = 0;

            /**
             * Gets text of main frame - top menu bar - view menu - log statistics menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarViewMenuLogStatisticsMenuItemHelp() const = 0;

            /**
             * Gets text of main frame - top menu bar - view menu - app log menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarViewMenuAppLogMenuItemText() const = 0;

            /**
             * Gets text of main frame - top menu bar - view menu - app log menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarViewMenuAppLogMenuItemHelp() const = 0;

            /**
             * Gets text of main frame - top menu bar - help menu - about menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarHelpMenuAboutMenuItemText() const = 0;

            /**
             * Gets help of main frame - top menu bar - help menu - about menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarHelpMenuAboutMenuItemHelp() const = 0;

            /**
             * Gets message of main frame - top menu bar - help menu - about menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarHelpMenuAboutMenuItemMessage() const = 0;

            /**
             * Gets caption of main frame - top menu bar - help menu - about menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarHelpMenuAboutMenuItemCaption() const = 0;

            /**
             * Gets style of main frame - top menu bar - help menu - about menu item.
             */
            virtual long GetMainFrameTopMenuBarHelpMenuAboutMenuItemStyle() const = 0;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // I_MENU_ITEM_CONFIGURATION_ITEMS_H_df601731_7da0_4229_8f94_653df785f2ff
