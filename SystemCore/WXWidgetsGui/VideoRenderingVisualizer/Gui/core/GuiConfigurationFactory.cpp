#include "GuiConfigurationFactory.h"
#include "GuiConfigurationManager.h"
#include "AppConfiguration.h"
#include "ClientConfiguration.h"
#include "FramesConfiguration.h"
#include "FrameConfiguration.h"
#include "DialogsConfiguration.h"
#include "DialogConfiguration.h"
#include "MenusConfiguration.h"
#include "MenuItemsConfiguration.h"
#include "MenuItemConfiguration.h"
#include "SlidersConfiguration.h"
#include "LabelsConfiguration.h"
#include "LabelConfiguration.h"
#include "SliderConfiguration.h"
#include "WXObjectId.h"
#include "GuiPaths.h"
#include "AppConfigurationItems.h"
#include "FrameConfigurationItems.h"
#include "DialogConfigurationItems.h"
#include "MenuItemConfigurationItems.h"
#include "SliderConfigurationItems.h"
#include "LabelConfigurationItems.h"

using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates a GUI Configuration Factory.
 */
IGuiConfigurationFactorySharedPtr GuiConfigurationFactory::Make()
{
    return std::make_shared<GuiConfigurationFactory>();
}

/**
 * The GuiConfigurationFactory constructor.
 */
GuiConfigurationFactory::GuiConfigurationFactory() 
{
}

/**
 * The GuiConfigurationFactory destructor.
 */
GuiConfigurationFactory::~GuiConfigurationFactory() 
{
}

/**
 * Creates a configuration manager of GUI.
 */
GuiConfiguration::IGuiConfigurationManagerSharedPtr GuiConfigurationFactory::CreateConfigurationManager() const
{
    //
    // Create a new GUI confgiuration...
    //
    GuiConfiguration::IGuiConfigurationManagerSharedPtr configuration = GuiConfiguration::GuiConfigurationManager::Make();

    //
    // Set app configuration...
    //
    GuiConfiguration::IAppConfigurationSharedPtr appConfiguration = CreateAppConfiguration();
    configuration->SetAppConfiguration(appConfiguration);

    //
    // Set client configuration...
    //
    GuiConfiguration::IClientConfigurationSharedPtr clientConfiguration = CreateClientConfiguration();
    configuration->SetClientConfiguration(clientConfiguration);

    //
    // Set frames configuration...
    //
    GuiConfiguration::IFramesConfigurationSharedPtr framesConfiguration = CreateFramesConfiguration();
    configuration->SetFramesConfiguration(framesConfiguration);

    //
    // Set dialogs configuration...
    //
    GuiConfiguration::IDialogsConfigurationSharedPtr dialogsConfiguration = CreateDialogsConfiguration();
    configuration->SetDialogsConfiguration(dialogsConfiguration);

    //
    // Set menus configuration...
    //
    GuiConfiguration::IMenusConfigurationSharedPtr menusConfiguration = CreateMenusConfiguration();
    configuration->SetMenusConfiguration(menusConfiguration);

    //
    // Set menu items configuration...
    //
    GuiConfiguration::IMenuItemsConfigurationSharedPtr menuItemsConfiguration = CreateMenuItemsConfiguration();
    configuration->SetMenuItemsConfiguration(menuItemsConfiguration);

    //
    // Set sliders configuration...
    //
    GuiConfiguration::ISlidersConfigurationSharedPtr slidersConfiguration = CreateSlidersConfiguration();
    configuration->SetSlidersConfiguration(slidersConfiguration);

    //
    // Set labels configuration...
    //
    GuiConfiguration::ILabelsConfigurationSharedPtr labelsConfiguration = CreateLabelsConfiguration();
    configuration->SetLabelsConfiguration(labelsConfiguration);

    return configuration;
}

/**
 * Creates a configuration of app.
 */
GuiConfiguration::IAppConfigurationSharedPtr GuiConfigurationFactory::CreateAppConfiguration()
{
    std::wstring name = AppConfigurationItems::Read().GetAppName();
    std::wstring logPath = AppConfigurationItems::Read().GetLogPath();

    GuiConfiguration::IAppConfigurationSharedPtr configuration = GuiConfiguration::AppConfiguration::Make(
        name, 
        logPath);
    
    return configuration;
}

/**
 * Creates a configuration of client.
 */
GuiConfiguration::IClientConfigurationSharedPtr GuiConfigurationFactory::CreateClientConfiguration()
{
    std::wstring name = AppConfigurationItems::Read().GetAppName();
    GuiConfiguration::IClientConfigurationSharedPtr configuration = GuiConfiguration::ClientConfiguration::Make(name);
    return configuration;
}

/**
 * Creates a configuration of frames.
 */
GuiConfiguration::IFramesConfigurationSharedPtr GuiConfigurationFactory::CreateFramesConfiguration()
{
    GuiConfiguration::IFramesConfigurationSharedPtr configuration = GuiConfiguration::FramesConfiguration::Make();

    GuiConfiguration::IFrameConfigurationSharedPtr mainFrame = GuiConfiguration::FrameConfiguration::Make(
        FrameConfigurationItems::Read().GetMainFrameName(), 
        FrameConfigurationItems::Read().GetMainFrameStatusText());

    configuration->AddConfiguration(
        GuiPaths::Read().GetMainFrame(), 
        mainFrame);

    return configuration;
}

/**
 * Creates a configuration of dialogs.
 */
GuiConfiguration::IDialogsConfigurationSharedPtr GuiConfigurationFactory::CreateDialogsConfiguration()
{
    GuiConfiguration::IDialogsConfigurationSharedPtr configuration = GuiConfiguration::DialogsConfiguration::Make();

    //
    // Set Rendering Pipelines Visualizer dialog...
    //
    GuiConfiguration::IDialogConfigurationSharedPtr renderingPipelinesVisualizerDialog =
        GuiConfiguration::DialogConfiguration::Make(
            DialogConfigurationItems::Read().GetRenderingPipelinesVisualizerDialogTitle());

    configuration->AddConfiguration(
        GuiPaths::Read().GetMainFrameTopMenuBarViewMenuRenderingPipelinesVisualizerDialog(), 
        renderingPipelinesVisualizerDialog);

    //
    // Set Event Viewer dialog...
    //
    GuiConfiguration::IDialogConfigurationSharedPtr eventViewerDialog =
        GuiConfiguration::DialogConfiguration::Make(
            DialogConfigurationItems::Read().GetEventViewerDialogTitle());

    configuration->AddConfiguration(GuiPaths::Read().GetMainFrameTopMenuBarViewMenuEventViewerDialog(), eventViewerDialog);

    //
    // Set Log Statistics dialog...
    //
    GuiConfiguration::IDialogConfigurationSharedPtr logStatisticsDialog =
        GuiConfiguration::DialogConfiguration::Make(
            DialogConfigurationItems::Read().GetLogStatisticsDialogTitle());

    configuration->AddConfiguration(
        GuiPaths::Read().GetMainFrameTopMenuBarViewMenuLogStatisticsDialog(), 
        logStatisticsDialog);

    //
    // Set App Log dialog...
    //
    GuiConfiguration::IDialogConfigurationSharedPtr appLogDialog =
        GuiConfiguration::DialogConfiguration::Make(DialogConfigurationItems::Read().GetAppLogDialogTitle());

    configuration->AddConfiguration(
        GuiPaths::Read().GetMainFrameTopMenuBarViewMenuAppLogDialog(), 
        appLogDialog);

    return configuration;
}

/**
 * Creates a configuration of menus.
 */
GuiConfiguration::IMenusConfigurationSharedPtr GuiConfigurationFactory::CreateMenusConfiguration()
{
    GuiConfiguration::IMenusConfigurationSharedPtr configuration = GuiConfiguration::MenusConfiguration::Make();
    GuiConfiguration::IMenuConfigurationSharedPtr fileMenu = GuiConfiguration::MenuConfiguration::Make(L"");
    
    configuration->AddMenuConfiguration(
        GuiPaths::Read().GetMainFrameTopMenuBarFileMenu(), 
        fileMenu);
    
    return configuration;
}

/**
 * Creates a configuration of menu items.
 */
GuiConfiguration::IMenuItemsConfigurationSharedPtr GuiConfigurationFactory::CreateMenuItemsConfiguration()
{
    GuiConfiguration::IMenuItemsConfigurationSharedPtr configuration = GuiConfiguration::MenuItemsConfiguration::Make();

    //
    // Set File menu items...
    //
    GuiConfiguration::IMenuItemConfigurationSharedPtr openMenuItem = CreateOpenMenuItemConfiguration();

    configuration->AddConfiguration(
        GuiPaths::Read().GetMainFrameTopMenuBarFileMenuOpenMenuItem(),
        openMenuItem);

    GuiConfiguration::IMenuItemConfigurationSharedPtr exitMenuItem = CreateExitMenuItemConfiguration();

    configuration->AddConfiguration(
        GuiPaths::Read().GetMainFrameTopMenuBarFileMenuExitMenuItem(),
        exitMenuItem);

    //
    // Set View menu items...
    //
    GuiConfiguration::IMenuItemConfigurationSharedPtr renderingPipelinesMenuItem = CreateRenderingPipelinesMenuItemConfiguration();

    configuration->AddConfiguration(
        GuiPaths::Read().GetMainFrameTopMenuBarViewMenuRenderingPipelinesVisualizerMenuItem(), 
        renderingPipelinesMenuItem);

    GuiConfiguration::IMenuItemConfigurationSharedPtr eventViewerMenuItem = CreateEventViewerMenuItemConfiguration();

    configuration->AddConfiguration(
        GuiPaths::Read().GetMainFrameTopMenuBarViewMenuEventViewerMenuItem(),
        eventViewerMenuItem);

    GuiConfiguration::IMenuItemConfigurationSharedPtr logStatisticsMenuItem = CreateLogStatisticsMenuItemConfiguration();

    configuration->AddConfiguration(
        GuiPaths::Read().GetMainFrameTopMenuBarViewMenuLogStatisticsMenuItem(),
        logStatisticsMenuItem);

    GuiConfiguration::IMenuItemConfigurationSharedPtr appLogMenuItem = CreateAppLogMenuItemConfiguration();

    configuration->AddConfiguration(
        GuiPaths::Read().GetMainFrameTopMenuBarViewMenuAppLogMenuItem(), 
        appLogMenuItem);

    //
    // Set About menu items...
    //
    GuiConfiguration::IMenuItemConfigurationSharedPtr aboutMenuItem = CreateAboutMenuItemConfiguration();

    configuration->AddConfiguration(
        GuiPaths::Read().GetMainFrameTopMenuBarHelpMenuAboutMenuItem(),
        aboutMenuItem);

    return configuration;
}

/**
 * Creates a configuration of sliders.
 */
GuiConfiguration::ISlidersConfigurationSharedPtr GuiConfigurationFactory::CreateSlidersConfiguration()
{
    GuiConfiguration::ISlidersConfigurationSharedPtr configuration = GuiConfiguration::SlidersConfiguration::Make();

    GuiConfiguration::ISliderConfigurationSharedPtr sliderConfiguration = GuiConfiguration::SliderConfiguration::Make(
        SliderConfigurationItems::Read().GetMainRightTopWindowLowerSubWindowSliderMinNumberOfUnits(),
        SliderConfigurationItems::Read().GetMainRightTopWindowLowerSubWindowSliderMaxNumberOfUnits());

    configuration->AddConfiguration(
        GuiPaths::Read().GetMainFrameMainRightTopWindowLowerSubWindowSlider(),
        sliderConfiguration);

    return configuration;
}

/**
 * Creates a configuration of labels.
 */
GuiConfiguration::ILabelsConfigurationSharedPtr GuiConfigurationFactory::CreateLabelsConfiguration()
{
    GuiConfiguration::ILabelsConfigurationSharedPtr configuration = GuiConfiguration::LabelsConfiguration::Make();
    
    configuration->AddConfiguration(
        GuiPaths::Read().GetMainFrameMainLeftWindowLabel(),
        GuiConfiguration::LabelConfiguration::Make(LabelConfigurationItems::Read().GetMainLeftWindowLabel()));

    configuration->AddConfiguration(
        GuiPaths::Read().GetMainFrameMainRightWindowLabel(),
        GuiConfiguration::LabelConfiguration::Make(LabelConfigurationItems::Read().GetMainRightWindowLabel()));

    configuration->AddConfiguration(
        GuiPaths::Read().GetMainFrameMainLeftTopWindowLabel(), 
        GuiConfiguration::LabelConfiguration::Make(LabelConfigurationItems::Read().GetMainLeftTopWindowLabel()));

    configuration->AddConfiguration(
        GuiPaths::Read().GetMainFrameMainLeftBottomWindowLabel(),
        GuiConfiguration::LabelConfiguration::Make(LabelConfigurationItems::Read().GetMainLeftBottomWindowLabel()));

    configuration->AddConfiguration(
        GuiPaths::Read().GetMainFrameMainLeftTopWindowUpperSubWindowLabel(),
        GuiConfiguration::LabelConfiguration::Make(
        LabelConfigurationItems::Read().GetMainLeftTopWindowUpperSubWindowLabel()));

    configuration->AddConfiguration(
        GuiPaths::Read().GetMainFrameMainLeftTopWindowLowerSubWindowLabel(),
        GuiConfiguration::LabelConfiguration::Make(
        LabelConfigurationItems::Read().GetMainLeftTopWindowLowerSubWindowLabel()));

    configuration->AddConfiguration(
        GuiPaths::Read().GetMainFrameMainRightTopWindowLabel(),
        GuiConfiguration::LabelConfiguration::Make(LabelConfigurationItems::Read().GetMainRightTopWindowLabel()));

    configuration->AddConfiguration(
        GuiPaths::Read().GetMainFrameMainRightBottomWindowLabel(),
        GuiConfiguration::LabelConfiguration::Make(LabelConfigurationItems::Read().GetMainRightBottomWindowLabel()));

    configuration->AddConfiguration(
        GuiPaths::Read().GetMainFrameMainRightTopWindowUpperSubWindowLabel(),
        GuiConfiguration::LabelConfiguration::Make(LabelConfigurationItems::Read().GetMainRightTopWindowUpperSubWindowLabel()));

    configuration->AddConfiguration(
        GuiPaths::Read().GetMainFrameMainRightTopWindowLowerSubWindowLabel(),
        GuiConfiguration::LabelConfiguration::Make(LabelConfigurationItems::Read().GetMainRightTopWindowLowerSubWindowLabel()));

    return configuration;
}

/**
 * Creates a configuration of an open menu item.
 */
GuiConfiguration::IMenuItemConfigurationSharedPtr GuiConfigurationFactory::CreateOpenMenuItemConfiguration()
{
    int id = WXWidgets::WXObjectId::NextId();
    std::wstring text = MenuItemConfigurationItems::Read().GetMainFrameTopMenuBarFileMenuOpenMenuItemText();
    std::wstring help = MenuItemConfigurationItems::Read().GetMainFrameTopMenuBarFileMenuOpenMenuItemHelp();
    wxItemKind kind = wxITEM_NORMAL;

    GuiConfiguration::IMenuItemConfigurationSharedPtr menuItem = 
        GuiConfiguration::MenuItemConfiguration::Make(
            id, 
            text, 
            help, 
            kind);

    return menuItem;
}

/**
 * Creates a configuration of an exit menu item.
 */
GuiConfiguration::IMenuItemConfigurationSharedPtr GuiConfigurationFactory::CreateExitMenuItemConfiguration()
{
    int id = WXWidgets::WXObjectId::NextId();
    std::wstring text = MenuItemConfigurationItems::Read().GetMainFrameTopMenuBarFileMenuExitMenuItemText();
    std::wstring help = MenuItemConfigurationItems::Read().GetMainFrameTopMenuBarFileMenuExitMenuItemHelp();
    wxItemKind kind = wxITEM_NORMAL;

    GuiConfiguration::IMenuItemConfigurationSharedPtr menuItem = 
        GuiConfiguration::MenuItemConfiguration::Make(
            id, 
            text, 
            help, 
            kind);

    return menuItem;
}

/**
 * Creates a configuration of a rendering pipelines menu item.
 */
GuiConfiguration::IMenuItemConfigurationSharedPtr GuiConfigurationFactory::CreateRenderingPipelinesMenuItemConfiguration()
{
    int id = WXWidgets::WXObjectId::NextId();
    std::wstring text = MenuItemConfigurationItems::Read().GetMainFrameTopMenuBarViewMenuRenderingPipelinesVisualizerMenuItemText();
    std::wstring help = MenuItemConfigurationItems::Read().GetMainFrameTopMenuBarViewMenuRenderingPipelinesVisualizerMenuItemHelp();
    wxItemKind kind = wxITEM_NORMAL;

    GuiConfiguration::IMenuItemConfigurationSharedPtr menuItem =
        GuiConfiguration::MenuItemConfiguration::Make(
            id, 
            text, 
            help, 
            kind);

    return menuItem;
}

/**
 * Creates a configuration of an event viewer menu item.
 */
GuiConfiguration::IMenuItemConfigurationSharedPtr GuiConfigurationFactory::CreateEventViewerMenuItemConfiguration()
{
    int id = WXWidgets::WXObjectId::NextId();
    std::wstring text = MenuItemConfigurationItems::Read().GetMainFrameTopMenuBarViewMenuEventViewerMenuItemText();
    std::wstring help = MenuItemConfigurationItems::Read().GetMainFrameTopMenuBarViewMenuEventViewerMenuItemHelp();
    wxItemKind kind = wxITEM_NORMAL;

    GuiConfiguration::IMenuItemConfigurationSharedPtr menuItem =
        GuiConfiguration::MenuItemConfiguration::Make(id, text, help, kind);

    return menuItem;
}

/**
 * Creates a configuration of a log statistics menu item.
 */
GuiConfiguration::IMenuItemConfigurationSharedPtr GuiConfigurationFactory::CreateLogStatisticsMenuItemConfiguration()
{
    int id = WXWidgets::WXObjectId::NextId();
    std::wstring text = MenuItemConfigurationItems::Read().GetMainFrameTopMenuBarViewMenuLogStatisticsMenuItemText();
    std::wstring help = MenuItemConfigurationItems::Read().GetMainFrameTopMenuBarViewMenuLogStatisticsMenuItemHelp();
    wxItemKind kind = wxITEM_NORMAL;

    GuiConfiguration::IMenuItemConfigurationSharedPtr menuItem =
        GuiConfiguration::MenuItemConfiguration::Make(
            id, 
            text, 
            help, 
            kind);

    return menuItem;
}

/**
 * Creates a configuration of an app log menu item.
 */
GuiConfiguration::IMenuItemConfigurationSharedPtr GuiConfigurationFactory::CreateAppLogMenuItemConfiguration()
{
    int id = WXWidgets::WXObjectId::NextId();
    std::wstring text = MenuItemConfigurationItems::Read().GetMainFrameTopMenuBarViewMenuAppLogMenuItemText();
    std::wstring help = MenuItemConfigurationItems::Read().GetMainFrameTopMenuBarViewMenuAppLogMenuItemHelp();
    wxItemKind kind = wxITEM_NORMAL;

    GuiConfiguration::IMenuItemConfigurationSharedPtr menuItem =
        GuiConfiguration::MenuItemConfiguration::Make(
            id, 
            text, 
            help, 
            kind);

    return menuItem;
}

/**
 * Creates a configuration of an about menu item.
 */
GuiConfiguration::IMenuItemConfigurationSharedPtr GuiConfigurationFactory::CreateAboutMenuItemConfiguration()
{
    int id = WXWidgets::WXObjectId::NextId();
    std::wstring text = MenuItemConfigurationItems::Read().GetMainFrameTopMenuBarHelpMenuAboutMenuItemText();
    std::wstring help = MenuItemConfigurationItems::Read().GetMainFrameTopMenuBarHelpMenuAboutMenuItemHelp();
    wxItemKind kind = wxITEM_NORMAL;

    GuiConfiguration::IMenuItemConfigurationSharedPtr menuItem = 
        GuiConfiguration::MenuItemConfiguration::Make(
            id, 
            text, 
            help, 
            kind);

    return menuItem;
}
