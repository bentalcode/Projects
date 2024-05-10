#pragma once

#include "AbstractGuiWindow.h"
#include "ICanvas.h"

class wxWindow;

namespace VideoRenderingVisualizer {

namespace Gui {

class IGuiManager;

/**
 * The MainRightTopWindowUpperSubWindow class implements a gui of Main Right Top Window Upper Sub Window of frame.
 */
class MainRightTopWindowUpperSubWindow final : public AbstractGuiWindow {
public:
    /**
     * Creates a Main Right Top Window Upper Sub Window.
     */
    static IGuiWindowSharedPtr Make(
        wxWindow& parent, 
        IGuiManager& guiManager);

    /**
     * The MainRightTopWindowUpperSubWindow constructor.
     */
    MainRightTopWindowUpperSubWindow(
        wxWindow& parent, 
        IGuiManager& guiManager);

    /**
     * The MainRightTopWindowUpperSubWindow destructor.
     */
    virtual ~MainRightTopWindowUpperSubWindow();

    /**
     * Gets a window.
     */
    virtual WXWidgets::IWindow& GetWindow() override;

private:
    /**
     * Initializes a window.
     */
    void Initialize(wxWindow& parent);

    WXWidgets::ICanvasPtr m_canvas;
};

} // namespace Gui

} // namespace VideoRenderingVisualizer
