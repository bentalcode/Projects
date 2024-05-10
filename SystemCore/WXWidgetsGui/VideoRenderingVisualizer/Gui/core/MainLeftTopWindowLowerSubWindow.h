#pragma once

#include "AbstractGuiWindow.h"
#include "IListBox.h"

class wxWindow;

namespace VideoRenderingVisualizer {

namespace Gui {

/**
 * The MainLeftTopWindowLowerSubWindow class implements a gui of Main Left Top Window - Lower Sub Window.
 */
class MainLeftTopWindowLowerSubWindow final : public AbstractGuiWindow {
public:
    /**
     * Creates a Main Left Top Window - Lower Sub Window.
     */
    static IGuiWindowSharedPtr Make(
        wxWindow& parent, 
        const std::vector<std::wstring>& items,
        IGuiManager& guiManager);

    /**
     * The MainLeftTopWindowLowerSubWindow constructor.
     */
    MainLeftTopWindowLowerSubWindow(
        wxWindow& parent, 
        const std::vector<std::wstring>& items, 
        IGuiManager& guiManager);

    /**
     * The MainLeftTopWindowLowerSubWindow destructor.
     */
    virtual ~MainLeftTopWindowLowerSubWindow();

    /**
     * Gets a window.
     */
    virtual WXWidgets::IWindow& GetWindow() override;

private:
    /**
     * Initializes a window.
     */
    void Initialize(
        wxWindow& parent, 
        const std::vector<std::wstring>& items);

    WXWidgets::IListBoxPtr m_listBox;
};

} // namespace Gui

} // namespace VideoRenderingVisualizer
