#include "MainRightTopWindowUpperSubWindow.h"
#include "GuiManager.h"
#include "RenderingPipelinesCanvas.h"
#include "GuiPaths.h"

using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates a Main Right Top Window Upper Sub Window.
 */
IGuiWindowSharedPtr MainRightTopWindowUpperSubWindow::Make(
    wxWindow& parent, 
    IGuiManager& guiManager)
{
    return std::make_shared<MainRightTopWindowUpperSubWindow>(
        parent, 
        guiManager);
}

/**
 * The MainRightTopWindowUpperSubWindow constructor.
 */
MainRightTopWindowUpperSubWindow::MainRightTopWindowUpperSubWindow(
    wxWindow& parent, 
    IGuiManager& guiManager) : 
        AbstractGuiWindow(
            L"MainRightTopWindowUpperSubWindow",
            guiManager)
{
    //
    // Initialize window...
    //
    Initialize(parent);
}

/**
 * The MainRightTopWindowUpperSubWindow destructor.
 */
MainRightTopWindowUpperSubWindow::~MainRightTopWindowUpperSubWindow() 
{
}

/**
 * Initializes a window.
 */
void MainRightTopWindowUpperSubWindow::Initialize(wxWindow& parent)
{
    //
    // Create a canvas for rendering pipelines...
    //
    IGuiManager& guiManager = GetGuiManager();

    const Model::IDataRepositorySharedPtr dataRepository = guiManager.GetDataRepository();
    const Model::IDataQuerySharedPtr dataQuery = dataRepository->GetDataQuery();

    base::DateTimeIntervalSharedPtr intervalTime = dataQuery->QueryRenderingPipelinesTimeInterval();

    m_canvas = RenderingPipelinesCanvas::Make(
        parent, 
        intervalTime,
        guiManager);
}

/**
 * Gets a window.
 */
wxwidgets::IWindow& MainRightTopWindowUpperSubWindow::GetWindow()
{
    return m_canvas->GetWindow();
}
