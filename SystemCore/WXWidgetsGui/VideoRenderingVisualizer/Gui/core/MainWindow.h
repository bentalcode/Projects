#pragma once

#include "AbstractGuiWindow.h"
#include "ISplitterWindow.h"
#include <vector>

namespace VideoRenderingVisualizer {

namespace Gui {

/**
 * The MainWindow class implements a gui of Main Window of frame.
 */
class MainWindow final : public AbstractGuiWindow {
public:
    /**
     * Creates a Video Rendering Visualizer Main Window.
     */
    static IGuiWindowSharedPtr Make(
        wxWindow& parent, 
        const std::vector<std::wstring>& leftTopWindowItems,
        IGuiManager& guiManager);

    /**
     * The MainWindow constructor.
     */
    MainWindow(
        wxWindow& parent, 
        const std::vector<std::wstring>& leftTopWindowItems, 
        IGuiManager& guiManager);

    /**
     * The MainWindow destructor.
     */
    virtual ~MainWindow();

    /**
     * Gets a window.
     */
    virtual WXWidgets::IWindow& GetWindow() override;

private:
    /**
     * Initializes window.
     */
   void Initialize(
        wxWindow& parent, 
        const std::vector<std::wstring>& leftTopWindowItems);

    /**
     * Creates a configuration of a splitter window.
     */
    static const WXWidgets::ISplitterWindowConfigurationSharedPtr CreateSplitterWindowConfiguration(
        const wxWindow& window, 
        const std::wstring& leftWindowBorderLabel,
        const std::wstring& rightWindowBorderLabel);

    /**
     * Creates a gravity of splitter window.
     */
    static double CalculateSplitterWindowGravity(const wxWindow& window);

    WXWidgets::ISplitterWindowPtr m_splitterWindow;
    IGuiWindowSharedPtr m_leftWindow;
    IGuiWindowSharedPtr m_rightWindow;
};

} // namespace Gui

} // namespace VideoRenderingVisualizer
