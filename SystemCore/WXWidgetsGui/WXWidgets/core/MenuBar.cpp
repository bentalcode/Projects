#include "MenuBar.h"

using namespace WXWidgets;

/**
 * Creates a menu bar.
 */
IMenuBarPtr MenuBar::Make(
    const std::wstring& name,
    long style)
{
    return IMenuBarPtr::Make(
        new MenuBar(
            name,
            style));
}

/**
 * The MenuBar constructor.
 */
MenuBar::MenuBar(
    const std::wstring& name,
    long style) : 
    wxMenuBar(style), 
    m_name(name) 
{
}

/**
 * The MenuBar destructor.
 */
MenuBar::~MenuBar() 
{
}

/**
 * Initializes a GUI component.
 */
void MenuBar::Initialize(IGuiControllerSharedPtr guiController)
{
    //
    // Initialize Window...
    //
    GuiComponent::Initialize(
        m_name,
        *this, 
        guiController);
}

/**
 * Gets a menu bar.
 */
wxMenuBar& MenuBar::GetMenuBar()
{
    return *this;
}

/**
 * Appends a menu.
 */
void MenuBar::Append(wxMenu& menu, const wxString& title)
{
    wxMenuBar::Append(&menu, title);
}
