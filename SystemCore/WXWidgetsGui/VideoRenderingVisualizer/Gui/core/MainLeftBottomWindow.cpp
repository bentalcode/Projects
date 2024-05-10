#include "MainLeftBottomWindow.h"
#include "CompositorTextBox.h"
#include "GuiPaths.h"

using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates a Main Left Bottom Window.
 */
IGuiWindowSharedPtr MainLeftBottomWindow::Make(
    wxWindow& parent, 
    IGuiManager& guiManager)
{
    return std::make_shared<MainLeftBottomWindow>(
        parent, 
        guiManager);
}

/**
 * The MainLeftBottomWindow constructor.
 */
MainLeftBottomWindow::MainLeftBottomWindow(
    wxWindow& parent, 
    IGuiManager& guiManager) : 
    AbstractGuiWindow(
        L"MainLeftBottomWindow", 
        guiManager)
{
    //
    // Initialize window...
    //
    Initialize(parent);
}

/**
 * The MainLeftBottomWindow destructor.
 */
MainLeftBottomWindow::~MainLeftBottomWindow() 
{
}

/**
 * Initializes a window.
 */
void MainLeftBottomWindow::Initialize(wxWindow& parent)
{
    //
    // Create a compositor text box...
    //
    m_staticText = CompositorTextBox::Make(
        parent, 
        GetGuiManager());
}

/**
 * Gets a window.
 */
wxwidgets::IWindow& MainLeftBottomWindow::GetWindow()
{
    return m_staticText->GetWindow();
}
