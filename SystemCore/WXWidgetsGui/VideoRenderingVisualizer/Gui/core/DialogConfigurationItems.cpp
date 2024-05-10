#include "DialogConfigurationItems.h"
#include "ConfigurationItemCatalog.h"

using namespace VideoRenderingVisualizer::Gui;

const std::wstring DialogConfigurationItems::NAME = L"DialogConfigurationItems";
const std::wstring DialogConfigurationItems::RENDERING_PIPELINES_VISUALIZER_TITLE = L"Rendering Pipelines Visualizer";
const std::wstring DialogConfigurationItems::EVENT_VIEWER_TITLE = L"Event Viewer";
const std::wstring DialogConfigurationItems::LOG_STATISTICS_TITLE = L"Log Statistics";
const std::wstring DialogConfigurationItems::APP_LOG_TITLE = L"App Log";

/**
 * Reads dialog configuration items from configuration catalog.
 */
const IDialogConfigurationItems& DialogConfigurationItems::Read()
{
    std::wstring configurationItemsName = NAME;

    GuiConfiguration::IConfigurationItemCatalogSharedPtr configurationItemCatalog =
        GuiConfiguration::ConfigurationItemCatalog::GetInstance();

    if (!configurationItemCatalog->HasConfigurationItems(configurationItemsName)) {
        GuiConfiguration::IConfigurationItemsSharedPtr configurationItems = DialogConfigurationItems::Make();
        configurationItemCatalog->RegisterConfigurationItems(configurationItems);
    }

    return configurationItemCatalog->GetConfigurationItems<IDialogConfigurationItems>(configurationItemsName);
}

/**
 * Creates frame configuration items.
 */
GuiConfiguration::IConfigurationItemsSharedPtr DialogConfigurationItems::Make()
{
    return std::make_shared<DialogConfigurationItems>();
}

/**
 * The DialogConfigurationItems constructor.
 */
DialogConfigurationItems::DialogConfigurationItems() 
{
}

/**
 * The DialogConfigurationItems destructor.
 */
DialogConfigurationItems::~DialogConfigurationItems() 
{
}

/**
 * Gets category name of data items.
 */
const std::wstring& DialogConfigurationItems::GetName() const
{
    return NAME;
}

/**
 * Gets title of rendering pipelines visualizer dialog.
 */
const std::wstring& DialogConfigurationItems::GetRenderingPipelinesVisualizerDialogTitle() const
{
    return RENDERING_PIPELINES_VISUALIZER_TITLE;
}

/**
 * Gets title of event viewer dialog.
 */
const std::wstring& DialogConfigurationItems::GetEventViewerDialogTitle() const
{
    return EVENT_VIEWER_TITLE;
}

/**
 * Gets title of log statistics dialog.
 */
const std::wstring& DialogConfigurationItems::GetLogStatisticsDialogTitle() const 
{
    return LOG_STATISTICS_TITLE;
}

/**
 * Gets title of app log dialog.
 */
const std::wstring& DialogConfigurationItems::GetAppLogDialogTitle() const
{
    return APP_LOG_TITLE;
}
