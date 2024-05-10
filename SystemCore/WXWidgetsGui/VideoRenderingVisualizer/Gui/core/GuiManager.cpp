#include "GuiManager.h"
#include "ConfigurationProvider.h"
#include "GuiController.h"
#include "ControllerManager.h"
#include "DataRepository.h"
#include "EventLog.h"
#include "AppConfigurationItems.h"

using namespace VideoRenderingVisualizer;
using namespace VideoRenderingVisualizer::Gui;

const std::wstring GuiManager::REPOSITORY_RESOURCES_PATH =
    L"c:\\Skype\\MSRTC\\msrtc\\src\\Tools\\VideoRenderingVisualizer\\Src\\Gui\\resources";

const std::wstring GuiManager::RENDERING_PIPELINES_VISUALIZER_HTML_PATH = 
    L"c:\\Skype\\MSRTC\\msrtc\\src\\Tools\\VideoRenderingVisualizer\\Src\\Gui\\html\\RenderingPipelinesVisualizer.html";

/**
 * Creates a GUI Manager.
 */
IGuiManagerSharedPtr GuiManager::Make()
{
    return std::make_shared<GuiManager>();
}

/**
 * The GuiManager constructor.
 */
GuiManager::GuiManager() : 
    m_configurationManager(ConfigurationProvider::GetInstance()->GetGuiConfigurationManager()),
    m_guiController(wxwidgets::GuiController::Create()),
    m_eventLog(tabular_data::EventLog::Make()),
    m_dataRepository(Model::DataRepository::Make(m_eventLog))
{
    //
    // Set event source of event log...
    // 
    m_eventLog->SetEventSource(AppConfigurationItems::Read().GetAppName());

    //
    // Initialize data repository from resources directory...
    //
    m_dataRepository->ReadFromResourceDirectory(REPOSITORY_RESOURCES_PATH);

    //
    // Initialize rendering pipelines html...
    //
    m_renderingPipelinesVisualizerHtmlPath.assign(RENDERING_PIPELINES_VISUALIZER_HTML_PATH);

    //
    // Initialize the log path...
    //
    m_logPath = m_configurationManager->GetAppConfiguration()->GetLogPath();
}

/**
 * The GuiManager destructor.
 */
GuiManager::~GuiManager()
{
}

/**
 * Gets a GUI Configuration manager.
 */
const GuiConfiguration::IGuiConfigurationManager& GuiManager::GetConfigurationManager() const
{
    return *m_configurationManager;
}

/**
 * Gets a Controller Manager.
 */
wxwidgets::controller::IControllerManagerSharedPtr GuiManager::GetControllerManager()
{
    return wxwidgets::controller::ControllerManager::Make(m_guiController);
}

/**
 * Gets a GUI Controller.
 */
wxwidgets::IGuiControllerSharedPtr GuiManager::GetGuiController()
{
    return m_guiController;
}

/**
 * Gets a Data Repository.
 */
Model::IDataRepositorySharedPtr GuiManager::GetDataRepository()
{
    return m_dataRepository;
}

/**
 * Gets a Data Repository.
 */
const Model::IDataRepositorySharedPtr GuiManager::GetDataRepository() const
{
    return m_dataRepository;
}

/**
 * Gets an Event Log.
 */
tabular_data::IEventLogSharedPtr GuiManager::GetEventLog()
{
    return m_eventLog;
}

/**
 * Gets an Event Log.
 */
const tabular_data::IEventLogSharedPtr GuiManager::GetEventLog() const
{
    return m_eventLog;
}

/**
 * Gets path of rendering pipelines visualizer html.
 */
const std::wstring& GuiManager::GetRenderingPipelinesVisualizerHtmlPath() const
{
    return m_renderingPipelinesVisualizerHtmlPath;
}

/**
 * Gets path of app log.
 */
const std::wstring& GuiManager::GetAppLogPath() const
{
    return m_logPath;
}
