#pragma once

#include "IGuiManager.h"
#include "IGuiConfigurationManager.h"

namespace VideoRenderingVisualizer {

namespace Gui {

/**
 * The GuiManager class implements a GUI Manager of Video Rendering Visualizer.
 */
class GuiManager final : public IGuiManager {
public:
    /**
     * Creates a GUI Manager.
     */
    static IGuiManagerSharedPtr Make();

    /**
     * The GuiManager constructor.
     */
    GuiManager();

    /**
     * The GuiManager destructor.
     */
    virtual ~GuiManager();

    /**
     * Gets a GUI Configuration Manager.
     */
    virtual const GuiConfiguration::IGuiConfigurationManager& GetConfigurationManager() const override;
    
    /**
     * Gets a Controller Manager.
     */
    virtual VideoRenderingVisualizer::Controller::IControllerManagerSharedPtr GetControllerManager() override;

    /**
     * Gets a GUI Controller.
     */
    virtual WXWidgets::IGuiControllerSharedPtr GetGuiController() override;

    /**
     * Gets an Event Log.
     */
    virtual TabularData::IEventLogSharedPtr GetEventLog() override;
    virtual const TabularData::IEventLogSharedPtr GetEventLog() const override;

    /**
     * Gets a Data Repository.
     */
    virtual VideoRenderingVisualizer::Model::IDataRepositorySharedPtr GetDataRepository() override;
    virtual const VideoRenderingVisualizer::Model::IDataRepositorySharedPtr GetDataRepository() const override;
    
    /**
     * Gets path of rendering pipelines visualizer html.
     */
    virtual const std::filesystem::path& GetRenderingPipelinesVisualizerHtmlPath() const override;

    /**
     * Gets path of app log.
     */
    virtual const std::filesystem::path& GetAppLogPath() const override;

private:
    //
    // The path of repository resources...
    //
    static const std::wstring REPOSITORY_RESOURCES_PATH;

    //
    // The path of rendering pipelines visualizer HTML...
    // 
    static const std::wstring RENDERING_PIPELINES_VISUALIZER_HTML_PATH;

    //
    // The path of app log...
    //
    static const std::wstring APP_LOG_PATH;

    GuiConfiguration::IGuiConfigurationManagerSharedPtr m_configurationManager;
    WXWidgets::IGuiControllerSharedPtr m_guiController;
    TabularData::IEventLogSharedPtr m_eventLog;
    Model::IDataRepositorySharedPtr m_dataRepository;
    std::filesystem::path m_renderingPipelinesVisualizerHtmlPath;
    std::filesystem::path m_logPath;
};

}  // namespace Gui

}  // namespace VideoRenderingVisualizer
