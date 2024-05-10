#ifndef MAIN_H_86c71b86_a326_4049_8012_9a173c7aae6c
#define MAIN_H_86c71b86_a326_4049_8012_9a173c7aae6c

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
            logging::ILoggersSharedPtr m_loggers;
        };

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // MAIN_H_86c71b86_a326_4049_8012_9a173c7aae6c
