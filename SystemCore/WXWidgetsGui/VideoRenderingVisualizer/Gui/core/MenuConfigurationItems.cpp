#include "MenuConfigurationItems.h"
#include "ConfigurationItemCatalog.h"

using namespace VideoRenderingVisualizer::Gui;

const std::wstring MenuConfigurationItems::NAME = L"MenuConfigurationItems";

/**
 * Reads menu configuration items from configuration catalog.
 */
const IMenuConfigurationItems& MenuConfigurationItems::Read()
{
    std::wstring configurationItemsName = NAME;

    GuiConfiguration::IConfigurationItemCatalogSharedPtr configurationItemCatalog =
        GuiConfiguration::ConfigurationItemCatalog::GetInstance();

    if (!configurationItemCatalog->HasConfigurationItems(configurationItemsName)) {
        GuiConfiguration::IConfigurationItemsSharedPtr configurationItems = MenuConfigurationItems::Make();
        configurationItemCatalog->RegisterConfigurationItems(configurationItems);
    }

    return configurationItemCatalog->GetConfigurationItems<IMenuConfigurationItems>(configurationItemsName);
}

/**
 * Creates menu configuration items.
 */
GuiConfiguration::IConfigurationItemsSharedPtr MenuConfigurationItems::Make()
{
    return std::make_shared<MenuConfigurationItems>();
}

/**
 * The MenuConfigurationItems constructor.
 */
MenuConfigurationItems::MenuConfigurationItems() 
{
}

/**
 * The MenuConfigurationItems destructor.
 */
MenuConfigurationItems::~MenuConfigurationItems() 
{
}

/**
 * Gets category name of data items.
 */
const std::wstring& MenuConfigurationItems::GetName() const
{
    return NAME;
}
