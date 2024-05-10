#ifndef I_GUI_WINDOW_H_41d5d3f0_5144_484b_85ce_9f1e84587b12
#define I_GUI_WINDOW_H_41d5d3f0_5144_484b_85ce_9f1e84587b12

#include <memory>

namespace WXWidgets {
    class IWindow;
}

namespace VideoRenderingVisualizer {
    
    namespace Gui {

        /**
         * The IGuiWindow interface defines a GUI Window of
         * Video Rendering Visualizer.
         */
        class IGuiWindow {
        public:
            IGuiWindow() = default;
            virtual ~IGuiWindow() = default;

            /**
             * Gets a window.
             */
            virtual WXWidgets::IWindow& GetWindow() = 0;
        };

        /**
         * Defines the Shared Ptr of GUI Window.
         */
        using IGuiWindowSharedPtr = std::shared_ptr<IGuiWindow>;

    } // namespace Gui

} // namespace VideoRenderingVisualizer

#endif // I_GUI_WINDOW_H_41d5d3f0_5144_484b_85ce_9f1e84587b12
