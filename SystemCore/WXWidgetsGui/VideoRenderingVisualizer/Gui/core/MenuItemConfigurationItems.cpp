#include "MenuItemConfigurationItems.h"
#include "ConfigurationItemCatalog.h"
#include "wx\defs.h"

using namespace VideoRenderingVisualizer::Gui;

const std::wstring MenuItemConfigurationItems::NAME = L"MenuItemConfigurationItems";

const std::wstring MenuItemConfigurationItems::MAIN_FRAME_TOP_MENU_BAR_FILE_MENU_OPEN_MENU_ITEM_TEXT =
    L"&Open...\tCtrl-O";

const std::wstring MenuItemConfigurationItems::MAIN_FRAME_TOP_MENU_BAR_FILE_MENU_OPEN_MENU_ITEM_HELP =
    L"Open file or directory...";

const std::wstring MenuItemConfigurationItems::MAIN_FRAME_TOP_MENU_BAR_FILE_MENU_EXIT_MENU_ITEM_TEXT =
    L"&Exit...\tCtrl-Q";

const std::wstring MenuItemConfigurationItems::MAIN_FRAME_TOP_MENU_BAR_FILE_MENU_EXIT_MENU_ITEM_HELP =
    L"Exit Video Rendering Visualizer...";

const std::wstring MenuItemConfigurationItems::MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_RENDERING_PIPELINES_VISUALIZER_MENU_ITEM_TEXT =
    L"&Rendering Pipelines Visualizer...\tCtrl-Q";

const std::wstring MenuItemConfigurationItems::MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_RENDERING_PIPELINES_VISUALIZER_MENU_ITEM_HELP =
    L"Visualizing Rendering Pipelines of selected Compositor...";

const std::wstring MenuItemConfigurationItems::MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_EVENT_VIEWER_MENU_ITEM_TEXT =
    L"&Event Viewer...\tCtrl-Q";

const std::wstring MenuItemConfigurationItems::MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_EVENT_VIEWER_MENU_ITEM_HELP =
    L"Viewing events of Video Rendering Visualizer...";

const std::wstring MenuItemConfigurationItems::MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_LOG_STATISTICS_MENU_ITEM_TEXT =
    L"&Log Statistics...\tCtrl-Q";

const std::wstring MenuItemConfigurationItems::MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_LOG_STATISTICS_MENU_ITEM_HELP =
    L"Viewing parsed logs statistics for feeding model of Video Rendering Visualizer...";

const std::wstring MenuItemConfigurationItems::MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_APP_LOG_MENU_ITEM_TEXT =
    L"&App Log...\tCtrl-Q";

const std::wstring MenuItemConfigurationItems::MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_APP_LOG_MENU_ITEM_HELP =
    L"Viewing logs of Video Rendering Visualizer...";

const std::wstring MenuItemConfigurationItems::MAIN_FRAME_TOP_MENU_BAR_HELP_MENU_ABOUT_MENU_ITEM_TEXT =
    L"&About...\tCtrl-A";

const std::wstring MenuItemConfigurationItems::MAIN_FRAME_TOP_MENU_BAR_HELP_MENU_ABOUT_MENU_ITEM_HELP =
    L"About Video Rendering Visualizer...";

const std::wstring MenuItemConfigurationItems::MAIN_FRAME_TOP_MENU_BAR_HELP_MENU_ABOUT_MENU_ITEM_MESSAGE =
    L"About video Rendering Visualizer with wx widgets!";

const std::wstring MenuItemConfigurationItems::MAIN_FRAME_TOP_MENU_BAR_HELP_MENU_ABOUT_MENU_ITEM_CAPTION =
    L"About Video Rendering";

const long MenuItemConfigurationItems::MAIN_FRAME_TOP_MENU_BAR_HELP_MENU_ABOUT_MENU_ITEM_STYLE = 
    wxOK | wxICON_INFORMATION;

/**
 * Reads menu item configuration items from configuration.
 */
const IMenuItemConfigurationItems& MenuItemConfigurationItems::Read()
{
    std::wstring configurationItemsName = NAME;

    GuiConfiguration::IConfigurationItemCatalogSharedPtr configurationItemCatalog =
        GuiConfiguration::ConfigurationItemCatalog::GetInstance();

    if (!configurationItemCatalog->HasConfigurationItems(configurationItemsName)) {
        GuiConfiguration::IConfigurationItemsSharedPtr configurationItems = MenuItemConfigurationItems::Make();
        configurationItemCatalog->RegisterConfigurationItems(configurationItems);
    }

    return configurationItemCatalog->GetConfigurationItems<IMenuItemConfigurationItems>(configurationItemsName);
}

/**
 * Creates menu item configuration items.
 */
GuiConfiguration::IConfigurationItemsSharedPtr MenuItemConfigurationItems::Make()
{
    return std::make_shared<MenuItemConfigurationItems>();
}

/**
 * The MenuItemConfigurationItems constructor.
 */
MenuItemConfigurationItems::MenuItemConfigurationItems() 
{
}

/**
 * The MenuItemConfigurationItems destructor.
 */
MenuItemConfigurationItems::~MenuItemConfigurationItems() 
{
}

/**
 * Gets category name of data items.
 */
const std::wstring& MenuItemConfigurationItems::GetName() const
{
    return NAME;
}

/**
 * Gets text of main frame - top menu bar - file menu - open menu item.
 */
const std::wstring& MenuItemConfigurationItems::GetMainFrameTopMenuBarFileMenuOpenMenuItemText() const 
{
    return MAIN_FRAME_TOP_MENU_BAR_FILE_MENU_OPEN_MENU_ITEM_TEXT;
}

/**
 * Gets help of main frame - top menu bar - file menu - open menu item.
 */
const std::wstring& MenuItemConfigurationItems::GetMainFrameTopMenuBarFileMenuOpenMenuItemHelp() const 
{
    return MAIN_FRAME_TOP_MENU_BAR_FILE_MENU_OPEN_MENU_ITEM_HELP;
}

/**
 * Gets text of main frame - top menu bar - file menu - exit menu item.
 */
const std::wstring& MenuItemConfigurationItems::GetMainFrameTopMenuBarFileMenuExitMenuItemText() const 
{
    return MAIN_FRAME_TOP_MENU_BAR_FILE_MENU_EXIT_MENU_ITEM_TEXT;
}

/**
 * Gets help of main frame - top menu bar - file menu - exit menu item.
 */
const std::wstring& MenuItemConfigurationItems::GetMainFrameTopMenuBarFileMenuExitMenuItemHelp() const 
{
    return MAIN_FRAME_TOP_MENU_BAR_FILE_MENU_EXIT_MENU_ITEM_HELP;
}

/**
 * Gets text of main frame - top menu bar - view menu - rendering pipelines visualizer menu item.
 */
const std::wstring& MenuItemConfigurationItems::GetMainFrameTopMenuBarViewMenuRenderingPipelinesVisualizerMenuItemText() const
{
    return MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_RENDERING_PIPELINES_VISUALIZER_MENU_ITEM_TEXT;
}

/**
 * Gets text of main frame - top menu bar - view menu - rendering pipelines visualizer menu item.
 */
const std::wstring& MenuItemConfigurationItems::GetMainFrameTopMenuBarViewMenuRenderingPipelinesVisualizerMenuItemHelp() const
{
    return MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_RENDERING_PIPELINES_VISUALIZER_MENU_ITEM_HELP;
}

/**
 * Gets help of main frame - top menu bar - view menu - event viewer menu item.
 */
const std::wstring& MenuItemConfigurationItems::GetMainFrameTopMenuBarViewMenuEventViewerMenuItemText() const
{
    return MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_EVENT_VIEWER_MENU_ITEM_TEXT;
}

/**
 * Gets help of main frame - top menu bar - view menu - event viewer menu item.
 */
const std::wstring& MenuItemConfigurationItems::GetMainFrameTopMenuBarViewMenuEventViewerMenuItemHelp() const
{
    return MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_EVENT_VIEWER_MENU_ITEM_HELP;
}

/**
 * Gets text of main frame - top menu bar - view menu - log statistics menu item.
 */
const std::wstring& MenuItemConfigurationItems::GetMainFrameTopMenuBarViewMenuLogStatisticsMenuItemText() const
{
    return MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_LOG_STATISTICS_MENU_ITEM_TEXT;
}

/**
 * Gets text of main frame - top menu bar - view menu - log statistics menu item.
 */
const std::wstring& MenuItemConfigurationItems::GetMainFrameTopMenuBarViewMenuLogStatisticsMenuItemHelp() const
{
    return MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_LOG_STATISTICS_MENU_ITEM_HELP;
}

/**
 * Gets text of main frame - top menu bar - view menu - app log menu item.
 */
const std::wstring& MenuItemConfigurationItems::GetMainFrameTopMenuBarViewMenuAppLogMenuItemText() const
{
    return MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_APP_LOG_MENU_ITEM_TEXT;
}

/**
 * Gets text of main frame - top menu bar - view menu - app log menu item.
 */
const std::wstring& MenuItemConfigurationItems::GetMainFrameTopMenuBarViewMenuAppLogMenuItemHelp() const
{
    return MAIN_FRAME_TOP_MENU_BAR_VIEW_MENU_APP_LOG_MENU_ITEM_HELP;
}

/**
 * Gets text of main frame - top menu bar - help menu - about menu item.
 */
const std::wstring& MenuItemConfigurationItems::GetMainFrameTopMenuBarHelpMenuAboutMenuItemText() const 
{
    return MAIN_FRAME_TOP_MENU_BAR_HELP_MENU_ABOUT_MENU_ITEM_TEXT;
}

/**
 * Gets help of main frame - top menu bar - help menu - about menu item.
 */
const std::wstring& MenuItemConfigurationItems::GetMainFrameTopMenuBarHelpMenuAboutMenuItemHelp() const 
{
    return MAIN_FRAME_TOP_MENU_BAR_HELP_MENU_ABOUT_MENU_ITEM_HELP;
}

/**
 * Gets message of main frame - top menu bar - help menu - about menu item.
 */
const std::wstring& MenuItemConfigurationItems::GetMainFrameTopMenuBarHelpMenuAboutMenuItemMessage() const 
{
    return MAIN_FRAME_TOP_MENU_BAR_HELP_MENU_ABOUT_MENU_ITEM_MESSAGE;
}

/**
 * Gets caption of main frame - top menu bar - help menu - about menu item.
 */
const std::wstring& MenuItemConfigurationItems::GetMainFrameTopMenuBarHelpMenuAboutMenuItemCaption() const 
{
    return MAIN_FRAME_TOP_MENU_BAR_HELP_MENU_ABOUT_MENU_ITEM_CAPTION;
}

/**
 * Gets style of main frame - top menu bar - help menu - about menu item.
 */
long MenuItemConfigurationItems::GetMainFrameTopMenuBarHelpMenuAboutMenuItemStyle() const 
{
    return MAIN_FRAME_TOP_MENU_BAR_HELP_MENU_ABOUT_MENU_ITEM_STYLE;
}
