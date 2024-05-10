#ifndef MENU_ITEM_CONFIGURATION_ITEMS_H_d1a39dc7_e854_4a59_b454_457b9bed185e
#define MENU_ITEM_CONFIGURATION_ITEMS_H_d1a39dc7_e854_4a59_b454_457b9bed185e

#include "IMenuItemConfigurationItems.h"
#include <string>

namespace VideoRenderingVisualizer { 
    
    namespace Gui {

        /**
         * The MenuItemConfigurationItems class implements configuration items of menu items.
         */
        class MenuItemConfigurationItems final : public IMenuItemConfigurationItems {
        public:
            /**
             * Reads menu item configuration items from configuration.
             */
            static const IMenuItemConfigurationItems& Read();

            /**
             * Creates menu item configuration items.
             */
            static GuiConfiguration::IConfigurationItemsSharedPtr Make();

            /**
             * The MenuItemConfigurationItems constructor.
             */
            MenuItemConfigurationItems();

            /**
             * The MenuItemConfigurationItems destructor.
             */
            virtual ~MenuItemConfigurationItems();

            /**
             * Gets category name of data items.
             */
            virtual const std::wstring& GetName() const override;

            /**
             * Gets text of main frame - top menu bar - file menu - open menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarFileMenuOpenMenuItemText() const override;

            /**
             * Gets help of main frame - top menu bar - file menu - open menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarFileMenuOpenMenuItemHelp() const override;

            /**
             * Gets text of main frame - top menu bar - file menu - exit menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarFileMenuExitMenuItemText() const override;

            /**
             * Gets help of main frame - top menu bar - file menu - exit menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarFileMenuExitMenuItemHelp() const override;

            /**
             * Gets text of main frame - top menu bar - view menu - rendering pipelines visualzier menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarViewMenuRenderingPipelinesVisualizerMenuItemText() const override;

            /**
             * Gets help of main frame - top menu bar - view menu - rendering pipelines visualzier menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarViewMenuRenderingPipelinesVisualizerMenuItemHelp() const override;

            /**
             * Gets help of main frame - top menu bar - view menu - event viewer menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarViewMenuEventViewerMenuItemText() const override;

            /**
             * Gets help of main frame - top menu bar - view menu - event viewer menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarViewMenuEventViewerMenuItemHelp() const override;

            /**
             * Gets text of main frame - top menu bar - view menu - log statistics menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarViewMenuLogStatisticsMenuItemText() const override;

            /**
             * Gets text of main frame - top menu bar - view menu - log statistics menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarViewMenuLogStatisticsMenuItemHelp() const override;

            /**
             * Gets text of main frame - top menu bar - view menu - app log menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarViewMenuAppLogMenuItemText() const override;

            /**
             * Gets text of main frame - top menu bar - view menu - app log menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarViewMenuAppLogMenuItemHelp() const override;

            /**
             * Gets text of main frame - top menu bar - help menu - about menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarHelpMenuAboutMenuItemText() const override;

            /**
             * Gets help of main frame - top menu bar - help menu - about menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarHelpMenuAboutMenuItemHelp() const override;

            /**
             * Gets message of main frame - top menu bar - help menu - about menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarHelpMenuAboutMenuItemMessage() const override;

            /**
             * Gets caption of main frame - top menu bar - help menu - about menu item.
             */
            virtual const std::wstring& GetMainFrameTopMenuBarHelpMenuAboutMenuItemCaption() const override;

            /**
             * Gets style of main frame - top menu bar - help menu - about menu item.
             */
            virtual long GetMainFrameTopMenuBarHelpMenuAboutMenuItemStyle() const override;

        private:
            static const std::wstring NAME;

            static const std::wstring MAIN_FRAME_TOP_MENU_BAR_FILE_MENU_OPEN_MENU_ITEM_TEXT;
            static const std::wstring MAIN_FRAME_TOP_MENU_BAR_FILE_MENU_OPEN_MENU_ITEM_HELP;

            static const std::wstring MAIN_FRAME_TOP_MENU_BAR_FILE_MENU_EXIT_MENU_ITEM_TEXT;
            static const std::wstring MAIN_FRAME_TOP_MENU_BAR_FILE_MENU_EXIT_MENU_ITEM_HELP;

            static const std::wstring MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_RENDERING_PIPELINES_VISUALIZER_MENU_ITEM_TEXT;
            static const std::wstring MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_RENDERING_PIPELINES_VISUALIZER_MENU_ITEM_HELP;

            static const std::wstring MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_EVENT_VIEWER_MENU_ITEM_TEXT;
            static const std::wstring MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_EVENT_VIEWER_MENU_ITEM_HELP;

            static const std::wstring MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_LOG_STATISTICS_MENU_ITEM_TEXT;
            static const std::wstring MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_LOG_STATISTICS_MENU_ITEM_HELP;

            static const std::wstring MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_APP_LOG_MENU_ITEM_TEXT;
            static const std::wstring MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_APP_LOG_MENU_ITEM_HELP;

            static const std::wstring MAIN_FRAME_TOP_MENU_BAR_HELP_MENU_ABOUT_MENU_ITEM_TEXT;
            static const std::wstring MAIN_FRAME_TOP_MENU_BAR_HELP_MENU_ABOUT_MENU_ITEM_HELP;

            static const std::wstring MAIN_FRAME_TOP_MENU_BAR_HELP_MENU_ABOUT_MENU_ITEM_MESSAGE;
            static const std::wstring MAIN_FRAME_TOP_MENU_BAR_HELP_MENU_ABOUT_MENU_ITEM_CAPTION;
            static const long MAIN_FRAME_TOP_MENU_BAR_HELP_MENU_ABOUT_MENU_ITEM_STYLE;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // MENU_ITEM_CONFIGURATION_ITEMS_H_d1a39dc7_e854_4a59_b454_457b9bed185e
