#include "VideoRenderingVisualizerApp.h"
#include "GuiManager.h"
#include "VideoRenderingVisualizerFrame.h"
#include "GuiPaths.h"

using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates an app.
 */
WXWidgets::IAppPtr VideoRenderingVisualizerApp::Make()
{
    return WXWidgets::IAppPtr::Make(new VideoRenderingVisualizerApp());
}

/**
 * The VideoRenderingVisualizerApp constructor.
 */
VideoRenderingVisualizerApp::VideoRenderingVisualizerApp() : 
    App(), 
    m_guiManager(GuiManager::Make())
{ 
}

/**
 * The VideoRenderingVisualizerApp destructor.
 */
VideoRenderingVisualizerApp::~VideoRenderingVisualizerApp()
{
}

/**
 * Initializes a GUI component.
 */
void VideoRenderingVisualizerApp::Initialize() 
{
    App::Initialize(
        GuiPaths::Read().GetApp(),
        m_guiManager->GetGuiController());
}

/**
 * The on app initialiazion logic.
 */
void VideoRenderingVisualizerApp::OnAppInitialization()
{
    //
    // Initialize the app...
    //
    Initialize();

    //
    // Create the main frame of the app... 
    //
    m_mainFrame = CreateMainFrame();
    m_mainFrame->GetWindow().ShowOrHide(true);
}

/**
 * Creates a main frame.
 */
WXWidgets::IFramePtr VideoRenderingVisualizerApp::CreateMainFrame() 
{
    //
    // Retrieve configuration...
    //
    GuiConfiguration::IAppConfigurationSharedPtr configuration = 
        m_guiManager->GetConfigurationManager().GetAppConfiguration();

    //
    // Create a frame...
    //
    std::wstring frameName(configuration->GetName());
    wxPoint leftUpperCorener(wxDefaultPosition);
    wxSize size = wxDefaultSize;

    return VideoRenderingVisualizerFrame::Make(
        frameName, 
        leftUpperCorener, 
        size, 
        *m_guiManager);
}

/**
 * The On Trigger End Refreshing callback.
 */
void VideoRenderingVisualizerApp::OnTriggerEndRefreshing()
{
    m_mainFrame->MaximizeAndCenteralize();
}
