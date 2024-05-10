#pragma once

#include "Dialog.h"
#include "IGuiManager.h"
#include "RenderingPipelinesHtmlWindow.h"

namespace VideoRenderingVisualizer {

namespace Gui {

/**
 * The RenderingPipelinesVisualizerDialog class implements a dialog of Rendering Pipelines Visualizer.
 */
class RenderingPipelinesVisualizerDialog final : public WXWidgets::Dialog {
public:
    /**
     * Creates a Rendering Pipelines Visualizer Dialog.
     */
    static WXWidgets::IDialogPtr Make(
        wxWindow& parent, 
        IGuiManager& guiManager);

    /**
     * The RenderingPipelinesVisualizerDialog constructor.
     */
    RenderingPipelinesVisualizerDialog(
        wxWindow& parent, 
        IGuiManager& guiManager);

    /**
     * The RenderingPipelinesVisualizerDialog destructor.
     */
    virtual ~RenderingPipelinesVisualizerDialog();

private:
    /**
     * Initializes a GUI component.
     */
    void Initialize(IGuiManager& guiManager);

    //
    // The GUI Manager...
    //
    IGuiManager& m_guiManager;

    //
    // The HTML Document of Rendering Pipelines...
    //
    WXWidgets::IHtmlWindowPtr m_renderingPiplinesHtmlWindow;
};

}  // namespace Gui

}  // namespace VideoRenderingVisualizer
