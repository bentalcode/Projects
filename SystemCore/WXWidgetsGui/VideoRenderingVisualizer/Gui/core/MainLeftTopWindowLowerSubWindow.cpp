#include "MainLeftTopWindowLowerSubWindow.h"
#include "GuiManager.h"
#include "CompositorListBox.h"

using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates a Main Left Top Window - Lower Sub Window.
 */
IGuiWindowSharedPtr MainLeftTopWindowLowerSubWindow::Make(
    wxWindow& parent, 
    const std::vector<std::wstring>& items, 
    IGuiManager& guiManager)
{
    return std::make_shared<MainLeftTopWindowLowerSubWindow>(
        parent, 
        items, 
        guiManager);
}

/**
 * The MainLeftTopWindowLowerSubWindow constructor.
 */
MainLeftTopWindowLowerSubWindow::MainLeftTopWindowLowerSubWindow(
    wxWindow& parent, 
    const std::vector<std::wstring>& items, 
    IGuiManager& guiManager) : 
        AbstractGuiWindow(
            L"MainLeftTopWindowLowerSubWindow",
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
 * The MainLeftTopWindowLowerSubWindow destructor.
 */
MainLeftTopWindowLowerSubWindow::~MainLeftTopWindowLowerSubWindow() 
{
}

/**
 * Initializes a window.
 */
void MainLeftTopWindowLowerSubWindow::Initialize(
    wxWindow& parent, 
    const std::vector<std::wstring>& items)
{
    //
    // Create a list box...
    //
    m_listBox = CompositorListBox::Make(
        parent, 
        items, 
        GetGuiManager());
}

/**
 * Gets a window.
 */
wxwidgets::IWindow& MainLeftTopWindowLowerSubWindow::GetWindow()
{
    return m_listBox->GetWindow();
}
