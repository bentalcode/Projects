#include "Main.h"
#include "VideoRenderingVisualizerApp.h"
#include "ConfigurationProvider.h"
#include "Loggers.h"
#include "LoggerFactory.h"

using namespace VideoRenderingVisualizer;
using namespace VideoRenderingVisualizer::Gui;

/**
 * The main entry of the Video Rendering Visualizer GUI.
 */
extern "C" int __stdcall WinMain(
    HINSTANCE hInstance, 
    HINSTANCE hPrevInstance, 
    wxCmdLineArgType lpCmdLine, 
    int nCmdShow)
{
    //
    // Initialize logs...
    //
    std::wstring logPath = VideoRenderingVisualizer::Gui::ConfigurationProvider::GetInstance()
        ->GetGuiConfigurationManager()
        ->GetAppConfiguration()
        ->GetLogPath();
    
    Logging::LoggerFactory::GetInstance()->Initialize(logPath);

    //
    // Run main...
    //
    Main main;
    int status = main.Run(
        hInstance, 
        hPrevInstance, 
        lpCmdLine, 
        nCmdShow);

    return status;
}

/**
 * Gets an app.
 */
VideoRenderingVisualizer::Gui::VideoRenderingVisualizerApp& wxGetApp()
{
    return *static_cast<VideoRenderingVisualizer::Gui::VideoRenderingVisualizerApp*>(wxApp::GetInstance());
}

/**
 * Creates an app.
 */
wxAppConsole* wxCreateApp()
{
    WXWidgets::IAppPtr app = VideoRenderingVisualizer::Gui::VideoRenderingVisualizerApp::Make();
    return &app->GetAppConsole();
}

/**
 * The app initializer.
 */
static wxAppInitializer wxTheAppInitializer(static_cast<wxAppInitializerFunction>(wxCreateApp));

/**
 * The main constructor.
 */
Main::Main() : 
    m_appName(
        VideoRenderingVisualizer::Gui::ConfigurationProvider::GetInstance()->GetGuiConfigurationManager()->GetAppConfiguration()->GetName()),
    m_loggers(Logging::Loggers::Make(typeid(VideoRenderingVisualizer::Gui::Main))) 
{
    std::wstringstream informationalStream;
    informationalStream << L"The Main of " << m_appName << L" GUI is starting.";
    std::wstring informationalMessage = informationalStream.str(); 

    LOG_INFO(m_loggers->GetLogger(), informationalMessage);
}

/**
 * The main destructor.
 */
Main::~Main() 
{
    std::wstringstream informationalStream;
    informationalStream << L"The Main of " << m_appName << L" GUI has ended.";
    std::wstring informationalMessage = informationalStream.str();

    LOG_INFO(m_loggers->GetLogger(), informationalMessage);
}

/**
 * Runs the Video Rendering Visualizer GUI.
 */
int Main::Run(HINSTANCE hInstance, HINSTANCE hPrevInstance, wxCmdLineArgType lpCmdLine, int nCmdShow)
{
    std::wstringstream informationalStream;
    informationalStream << L"Start running WXWidgets GUI of " << m_appName << L".";

    std::wstring informationalMessage = informationalStream.str();
    LOG_INFO(
        m_loggers->GetLogger(), 
        informationalMessage);

    //
    // Initialize Open GL...
    //
    m_openGLInitializer = std::make_unique<WXWidgets::OpenGLInitializer>();

    //
    // Initialize WX Widgets...
    //
    int status = wxEntry(hInstance, hPrevInstance, lpCmdLine, nCmdShow);

    if (status == 0) {
        std::wstringstream informationalStream;
        informationalStream << L"The WXWidgets GUI of " << m_appName << L" has ended successfully";

        std::wstring informationalMessage = informationalStream.str();
        LOG_INFO(m_loggers->GetLogger(), informationalMessage);
    } 
    else {
        std::wstringstream errorStream;
        errorStream 
            << L"The WXWidgets GUI of " << m_appName << L" has ended with failure" 
            << L"; Status:" << status;

        std::wstring errorMessage = errorStream.str();
        LOG_ERROR(m_loggers->GetLogger(), errorMessage);
    }

    return status;
}
