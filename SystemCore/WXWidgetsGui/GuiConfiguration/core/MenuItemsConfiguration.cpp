#include "MenuItemsConfiguration.h"
#include "GuiComponentsConfiguration.h"

using namespace GuiConfiguration;

/**
 * Creates menu items configuration.
 */
IMenuItemsConfigurationSharedPtr MenuItemsConfiguration::Make()
{
    return std::make_shared<MenuItemsConfiguration>();
}

/**
 * The MenuItemsConfiguration constructor.
 */
MenuItemsConfiguration::MenuItemsConfiguration() : 
    m_impl(std::make_shared<GuiComponentsConfiguration<IMenuItemConfiguration>>())
{
}

/**
 * The MenuItemsConfiguration destructor.
 */
MenuItemsConfiguration::~MenuItemsConfiguration() 
{
}

/**
 * Adds a configuration of a component by path.
 */
void MenuItemsConfiguration::AddConfiguration(
    const std::wstring& path, 
    IMenuItemConfigurationSharedPtr configuration)
{
    m_impl->AddConfiguration(path, configuration);
}

/**
 * Gets a configuration of a component by path.
 */
const IMenuItemConfigurationSharedPtr MenuItemsConfiguration::GetConfiguration(const std::wstring& path) const
{
    return m_impl->GetConfiguration(path);
}

/**
 * Checks whether a configuration of a component exists.
 */
bool MenuItemsConfiguration::ConfigurationExists(const std::wstring& path) const
{
    return m_impl->ConfigurationExists(path);
}
