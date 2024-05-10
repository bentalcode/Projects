#pragma once

#include "OpenGLInitializer.h"
#include "ILoggers.h"
#include "wx\init.h"

namespace VideoRenderingVisualizer {

namespace Gui {

/**
 * The Main class implements a main of the Video Rendering Visualizer.
 */
class Main final {
public:
    /**
     * The Main constructor.
     */
    Main();

    /**
     * The Main destructor.
     */
    ~Main();

    /**
     * Runs the Video Rendering Visualizer GUI.
     */
    int Run(
        HINSTANCE hInstance, 
        HINSTANCE hPrevInstance, 
        wxCmdLineArgType lpCmdLine, 
        int nCmdShow);

private:
    //
    // The name of the app..
    //
    std::wstring m_appName;

    //
    // The Open GL Initializer...
    //
    using OpenGLInitializerUniquePtr = std::unique_ptr<WXWidgets::OpenGLInitializer>;
    OpenGLInitializerUniquePtr m_openGLInitializer;

    //
    // The loggers...
    //
    Logging::ILoggersSharedPtr m_loggers;
};

}  // namespace Gui

}  // namespace VideoRenderingVisualizer
