#pragma once

#include "App.h"
#include "IGuiManager.h"
#include "Frame.h"

namespace VideoRenderingVisualizer {

namespace Gui {

/**
 * The VideoRenderingVisualizerApp class implements an app.
 */
class VideoRenderingVisualizerApp final : public WXWidgets::App {
public:
    /**
     * Creates an app.
     */
    static WXWidgets::IAppPtr Make();

    /**
     * The VideoRenderingVisualizerApp constructor.
     */
    VideoRenderingVisualizerApp();

    /**
     * The VideoRenderingVisualizerApp destructor.
     */
    virtual ~VideoRenderingVisualizerApp();

    /**
     * The on app initialization logic.
     */
    virtual void OnAppInitialization() override;

    /**
     * The On Trigger End Refreshing callback.
     */
    virtual void OnTriggerEndRefreshing() override;

private:
    /**
     * Initializes a GUI component.
     */
    void Initialize();

    /**
     * Creates a main frame.
     */
    WXWidgets::IFramePtr CreateMainFrame();

    //
    // The main frame of the app...
    //
    WXWidgets::IFramePtr m_mainFrame;
    
    //
    // The GUI Manager...
    //
    IGuiManagerSharedPtr m_guiManager;
};

} // namespace Gui

} // namespace VideoRenderingVisualizer
