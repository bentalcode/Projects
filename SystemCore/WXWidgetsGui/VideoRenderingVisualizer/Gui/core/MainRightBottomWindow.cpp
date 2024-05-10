#include "MainRightBottomWindow.h"
#include "GuiManager.h"
#include "RenderingPipelinesListView.h"
#include "IDataQuery.h"

using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates a Main Right Bottom Window.
 */
IGuiWindowSharedPtr MainRightBottomWindow::Make(
    wxWindow& parent, 
    IGuiManager& guiManager)
{
    return std::make_shared<MainRightBottomWindow>(
        parent, 
        guiManager);
}

/**
 * The MainRightBottomWindow constructor.
 */
MainRightBottomWindow::MainRightBottomWindow(
    wxWindow& parent, 
    IGuiManager& guiManager) : 
        AbstractGuiWindow(
            L"MainRightBottomWindow",
            guiManager)
{
    //
    // Initialize window...
    //
    Initialize(parent);
}

/**
 * The MainRightBottomWindow destructor.
 */
MainRightBottomWindow::~MainRightBottomWindow() 
{
}

/**
 * Initializes a window.
 */
void MainRightBottomWindow::Initialize(wxWindow& parent)
{
    //
    // Create a list view with rendering pipelines...
    //
    IGuiManager& guiManager = GetGuiManager();

    const Model::IDataRepositorySharedPtr dataRepository = guiManager.GetDataRepository();
    const Model::IDataQuerySharedPtr dataQuery = dataRepository->GetDataQuery();

    base::DateTimeIntervalSharedPtr intervalTime = dataQuery->QueryRenderingPipelinesTimeInterval();

    m_listView = RenderingPipelinesListView::Make(
        parent, 
        intervalTime, 
        guiManager);
}

/**
 * Gets a window.
 */
wxwidgets::IWindow& MainRightBottomWindow::GetWindow()
{
    return m_listView->GetWindow();
}
