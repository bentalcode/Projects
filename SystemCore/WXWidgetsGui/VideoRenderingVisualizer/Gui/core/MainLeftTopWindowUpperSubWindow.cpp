#include "MainLeftTopWindowUpperSubWindow.h"
#include "GuiManager.h"
#include "CallListBox.h"

using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates a Main Left Top Window - Upper Sub Window.
 */
IGuiWindowSharedPtr MainLeftTopWindowUpperSubWindow::Make(
    wxWindow& parent, 
    const std::vector<std::wstring>& items, 
    IGuiManager& guiManager)
{
    return std::make_shared<MainLeftTopWindowUpperSubWindow>(
        parent, 
        items, 
        guiManager);
}

/**
 * The MainLeftTopWindowUpperSubWindow constructor.
 */
MainLeftTopWindowUpperSubWindow::MainLeftTopWindowUpperSubWindow(
    wxWindow& parent, 
    const std::vector<std::wstring>& items, 
    IGuiManager& guiManager) : 
        AbstractGuiWindow(
            L"MainLeftTopWindowUpperSubWindow",
            guiManager)
{
    //
    // Initialize window...
    //
    Initialize(
        parent, 
        items);
}

/**
 * The MainLeftTopWindowUpperSubWindow destructor.
 */
MainLeftTopWindowUpperSubWindow::~MainLeftTopWindowUpperSubWindow() 
{
}

/**
 * Initializes a window.
 */
void MainLeftTopWindowUpperSubWindow::Initialize(
    wxWindow& parent, 
    const std::vector<std::wstring>& items)
{
    //
    // Create a list box...
    //
    m_listBox = CallListBox::Make(
        parent, 
        items, 
        GetGuiManager());
}

/**
 * Gets a window.
 */
WXWidgets::IWindow& MainLeftTopWindowUpperSubWindow::GetWindow()
{
    return m_listBox->GetWindow();
}
