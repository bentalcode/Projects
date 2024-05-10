#pragma once

#include <memory>

namespace WXWidgets {
class IWindow;
}

namespace VideoRenderingVisualizer {
    
namespace Gui {

/**
 * The IGuiWindow interface defines a GUI Window of Video Rendering Visualizer.
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

}  // namespace VideoRenderingVisualizer
