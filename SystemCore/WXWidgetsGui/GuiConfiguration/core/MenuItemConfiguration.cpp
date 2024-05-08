#include "MenuItemConfiguration.h"

using namespace GuiConfiguration;

/**
 * Creates menu item configuration.
 */
IMenuItemConfigurationSharedPtr MenuItemConfiguration::Make(
    int id, 
    const std::wstring& text,
    const std::wstring& help, 
    wxItemKind kind)
{
    return std::make_shared<MenuItemConfiguration>(
        id, 
        text, 
        help, 
        kind);
}

/**
 * The MenuItemConfiguration constructor.
 */
MenuItemConfiguration::MenuItemConfiguration(
    int id, 
    const std::wstring& text, 
    const std::wstring& help, 
    wxItemKind kind) : 
    m_id(id), 
    m_text(text), 
    m_help(help), 
    m_kind(kind)
{
}

/**
 * The MenuItemConfiguration destructor.
 */
MenuItemConfiguration::~MenuItemConfiguration() {}

/**
 * Gets a menu item id.
 */
int MenuItemConfiguration::GetItemId() const
{
    return m_id;
}

/**
 * Gets text.
 */
const std::wstring& MenuItemConfiguration::GetText() const
{
    return m_text;
}

/**
 * Gets help.
 */
const std::wstring& MenuItemConfiguration::GetHelp() const
{
    return m_help;
}

/**
 * Gets kind.
 */
wxItemKind MenuItemConfiguration::GetKind() const
{
    return m_kind;
}
