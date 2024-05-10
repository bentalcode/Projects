#pragma once

#include "AbstractGuiWindow.h"
#include "ISlider.h"

class wxWindow;

namespace VideoRenderingVisualizer {

namespace Gui {

/**
 * The MainRightTopWindowLowerSubWindow class implements a gui of Main Right Top Window - Lower Sub Window.
 */
class MainRightTopWindowLowerSubWindow final : public AbstractGuiWindow {
public:
    /**
     * Creates a Main Right Top Window - Lower Sub Window.
     */
    static IGuiWindowSharedPtr Make(
        wxWindow& parent, 
        IGuiManager& guiManager);

    /**
     * The MainRightTopWindowLowerSubWindow constructor.
     */
    MainRightTopWindowLowerSubWindow(
        wxWindow& parent, 
        IGuiManager& guiManager);

    /**
     * The MainRightTopWindowLowerSubWindow destructor.
     */
    virtual ~MainRightTopWindowLowerSubWindow();

    /**
     * Gets a window.
     */
    virtual WXWidgets::IWindow& GetWindow() override;

private:
    /**
     * Initializes a window.
     */
    void Initialize(wxWindow& parent);

    WXWidgets::ISliderPtr m_slider;
};

} // namespace Gui

} // namespace VideoRenderingVisualizer
