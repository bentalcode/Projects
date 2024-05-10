#pragma once

#include "ControllerManager.h"
#include "IGuiController.h"
#include "IEventLog.h"
#include "IDataRepository.h"
#include <filesystem> 

namespace GuiConfiguration {
class IGuiConfigurationManager;
}

namespace VideoRenderingVisualizer {

namespace Gui {

/**
 * The IGuiManager interface defines a GUI Manager of Video Rendering Visualizer.
 */
class IGuiManager {
public:
    IGuiManager() = default;
    virtual ~IGuiManager() = default;

    /**
     * Gets a GUI Configuration Manager.
     */
    virtual const GuiConfiguration::IGuiConfigurationManager& GetConfigurationManager() const = 0;

    /**
     * Gets a Controller Manager.
     */
    virtual VideoRenderingVisualizer::Controller::IControllerManagerSharedPtr GetControllerManager() = 0;

    /**
     * Gets a GUI Controller.
     */
    virtual WXWidgets::IGuiControllerSharedPtr GetGuiController() = 0;

    /**
     * Gets an Event Log.
     */
    virtual TabularData::IEventLogSharedPtr GetEventLog() = 0;
    virtual const TabularData::IEventLogSharedPtr GetEventLog() const = 0;

    /**
     * Gets a Data Repository.
     */
    virtual Model::IDataRepositorySharedPtr GetDataRepository() = 0;
    virtual const Model::IDataRepositorySharedPtr GetDataRepository() const = 0;

    /**
     * Gets path of rendering pipelines visualizer html.
     */
    virtual const std::filesystem::path& GetRenderingPipelinesVisualizerHtmlPath() const = 0;

    /**
     * Gets path of app log.
     */
    virtual const std::filesystem::path& GetAppLogPath() const = 0;
};

/**
 * Defines the Shared Ptr of GUI Manager.
 */
using IGuiManagerSharedPtr = std::shared_ptr<IGuiManager>;

} // namespace Gui

}  // namespace VideoRenderingVisualizer
