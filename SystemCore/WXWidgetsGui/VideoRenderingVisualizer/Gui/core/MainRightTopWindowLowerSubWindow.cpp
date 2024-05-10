#include "MainRightTopWindowLowerSubWindow.h"
#include "GuiManager.h"
#include "RenderingPipelinesTimeSlider.h"

using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates a Main Right Top Window - Lower Sub Window.
 */
IGuiWindowSharedPtr MainRightTopWindowLowerSubWindow::Make(
    wxWindow& parent, 
    IGuiManager& guiManager)
{
    return std::make_shared<MainRightTopWindowLowerSubWindow>(
        parent, 
        guiManager);
}

/**
 * The MainRightTopWindowLowerSubWindow constructor.
 */
MainRightTopWindowLowerSubWindow::MainRightTopWindowLowerSubWindow(
    wxWindow& parent, 
    IGuiManager& guiManager) : 
        AbstractGuiWindow(
            L"MainRightTopWindowLowerSubWindow",
            guiManager)
{
    //
    // Initialize window...
    //
    Initialize(parent);
}

/**
 * The MainRightTopWindowLowerSubWindow destructor.
 */
MainRightTopWindowLowerSubWindow::~MainRightTopWindowLowerSubWindow() 
{
}

/**
 * Initializes a window.
 */
void MainRightTopWindowLowerSubWindow::Initialize(wxWindow& parent)
{
    //
    // Create a time slider of rendering pipelines...
    //
    IGuiManager& guiManager = GetGuiManager();

    const Model::IDataRepositorySharedPtr dataRepository = guiManager.GetDataRepository();
    const Model::IDataQuerySharedPtr dataQuery = dataRepository->GetDataQuery();

    base::DateTimeIntervalSharedPtr intervalTime = dataQuery->QueryRenderingPipelinesTimeInterval();

    m_slider = RenderingPipelinesTimeSlider::Make(
        parent, 
        intervalTime, 
        guiManager);
}

/**
 * Gets a window.
 */
wxwidgets::IWindow& MainRightTopWindowLowerSubWindow::GetWindow()
{
    return m_slider->GetWindow();
}
