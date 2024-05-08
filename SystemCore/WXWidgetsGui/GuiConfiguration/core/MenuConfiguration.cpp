#include "MenuConfiguration.h"

using namespace GuiConfiguration;

/**
 * Creates frames configuration.
 */
IMenuConfigurationSharedPtr MenuConfiguration::Make(const std::wstring& name)
{
    return std::make_shared<MenuConfiguration>(name);
}

/**
 * The MenuConfiguration constructor.
 */
MenuConfiguration::MenuConfiguration(const std::wstring& name) : 
    m_name(name) 
{
}

/**
 * The MenuConfiguration destructor.
 */
MenuConfiguration::~MenuConfiguration() 
{
}

/**
 * Gets name of a menu.
 */
const std::wstring& MenuConfiguration::GetName() const
{
    return m_name;
}
