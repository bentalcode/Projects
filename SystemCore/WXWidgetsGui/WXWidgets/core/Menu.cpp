#include "Menu.h"

using namespace wxwidgets;

/**
 * Creates a menu.
 */
IMenuPtr Menu::Make(
    const std::wstring& name,
    const std::wstring& title, 
    long style)
{
    return IMenuPtr::Make(
        new Menu(
            name, 
            title, 
            style));
}

/**
 * The Menu constructor.
 */
Menu::Menu(
    const std::wstring& name, 
    const std::wstring& title, 
    long style) : 
        wxMenu(title, style), 
        m_name(name) 
{
}

/**
 * The Menu destructor.
 */
Menu::~Menu() 
{
}

/**
 * Initializes a GUI component.
 */
void Menu::Initialize(IGuiControllerSharedPtr guiController)
{
    //
    // Initialize GUI component...
    //
    GuiComponent::Initialize(
        m_name, 
        *this, 
        guiController);
}

/**
 * Gets a menu.
 */
wxMenu* Menu::GetMenu()
{
    return this;
}

/**
 * Appends an item.
 */
wxMenuItem* Menu::Append(
    int itemId, 
    const wxString& text, 
    const wxString& help,
    wxItemKind kind)
{
    return wxMenu::Append(
        itemId, 
        text, 
        help, 
        kind);
}

/**
 * Appends a separator.
 */
wxMenuItem* Menu::AppendSeparator()
{
    return wxMenu::AppendSeparator();
}
