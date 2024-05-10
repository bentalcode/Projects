#pragma once

#include "AbstractGuiWindow.h"
#include "ISplitterWindow.h"

namespace VideoRenderingVisualizer {

namespace Gui {

class IGuiManager;

/**
 * The MainRightWindow class implements a gui of Main Right Window of frame.
 */
class MainRightWindow final : public AbstractGuiWindow {
public:
    /**
     * Creates a Main Right Window.
     */
    static IGuiWindowSharedPtr Make(
        wxWindow& parent, 
        IGuiManager& guiManager);

    /**
     * The MainRightWindow constructor.
     */
    MainRightWindow(
        wxWindow& parent, 
        IGuiManager& guiManager);

    /**
     * The MainRightWindow destructor.
     */
    virtual ~MainRightWindow();

    /**
     * Gets a window.
     */
    virtual WXWidgets::IWindow& GetWindow() override;

private:
    /**
     * Initializes a window.
     */
    void Initialize(wxWindow& parent);

    /**
     * Creates a configuration of a splitter window.
     */
    static const WXWidgets::ISplitterWindowConfigurationSharedPtr CreateSplitterWindowConfiguration(
        const wxWindow& window, 
        const std::wstring& topWindowBorderLabel,
        const std::wstring& bottomWindowBorderLabel);

    /**
     * Creates a gravity of splitter window.
     */
    static double CalculateSplitterWindowGravity(const wxWindow& window);

    WXWidgets::ISplitterWindowPtr m_splitterWindow;
    IGuiWindowSharedPtr m_topWindow;
    IGuiWindowSharedPtr m_bottomWindow;
};

} // namespace Gui

} // namespace VideoRenderingVisualizer
