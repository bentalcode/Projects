#pragma once

#include "IConfigurationItems.h"

namespace VideoRenderingVisualizer { 
    
namespace Gui {

/**
 * The IDialogConfigurationItems interface defines configuration items of dialogs.
 */
class IDialogConfigurationItems : public GuiConfiguration::IConfigurationItems {
public:
    IDialogConfigurationItems() = default;
    virtual ~IDialogConfigurationItems() = default;

    /**
     * Gets title of rendering pipelines visualizer dialog.
     */
    virtual const std::wstring& GetRenderingPipelinesVisualizerDialogTitle() const = 0;

    /**
     * Gets title of event viewer dialog.
     */
    virtual const std::wstring& GetEventViewerDialogTitle() const = 0;

    /**
     * Gets title of log statistics dialog.
     */
    virtual const std::wstring& GetLogStatisticsDialogTitle() const = 0;

    /**
     * Gets title of app log dialog.
     */
    virtual const std::wstring& GetAppLogDialogTitle() const = 0;
};

}

}  // namespace VideoRenderingVisualizer::Gui
