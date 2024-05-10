#include "AppConfigurationItems.h"
#include "ConfigurationItemCatalog.h"

using namespace VideoRenderingVisualizer::Gui;

const std::wstring AppConfigurationItems::NAME = L"AppConfigurationItems";
const std::wstring AppConfigurationItems::APP_NAME = L"Video Rendering Visualizer";
const std::wstring AppConfigurationItems::LOG_PATH = L"c:\\Tools\\VideoRenderingVisualizer\\Logs\\VideoRenderingVisualizer.log";

/**
 * Reads app configuration items from configuration catalog.
 */
const IAppConfigurationItems& AppConfigurationItems::Read() 
{
    std::wstring configurationItemsName = NAME;

    GuiConfiguration::IConfigurationItemCatalogSharedPtr configurationItemCatalog = GuiConfiguration::ConfigurationItemCatalog::GetInstance();

    if (!configurationItemCatalog->HasConfigurationItems(configurationItemsName)) {
        GuiConfiguration::IConfigurationItemsSharedPtr configurationItems = AppConfigurationItems::Make();
        configurationItemCatalog->RegisterConfigurationItems(configurationItems);
    }

    return configurationItemCatalog->GetConfigurationItems<IAppConfigurationItems>(configurationItemsName);
}

/**
 * Creates app configuration items.
 */
GuiConfiguration::IConfigurationItemsSharedPtr AppConfigurationItems::Make()
{
    return std::make_shared<AppConfigurationItems>();
}

/**
 * The AppConfigurationItems constructor.
 */
AppConfigurationItems::AppConfigurationItems()
{
}

/**
 * The AppConfigurationItems destructor.
 */
AppConfigurationItems::~AppConfigurationItems()
{
}

/**
 * Gets category name of data items.
 */
const std::wstring& AppConfigurationItems::GetName() const 
{
    return NAME;
}

/**
 * Gets name of an app.
 */
const std::wstring& AppConfigurationItems::GetAppName() const
{
    return APP_NAME;
}

/**
 * Gets log path.
 */
const std::wstring& AppConfigurationItems::GetLogPath() const
{
    return LOG_PATH;
}
