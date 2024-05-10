#pragma once

#include "AbstractGuiWindow.h"
#include "IListBox.h"

class wxWindow;

namespace VideoRenderingVisualizer {

namespace Gui {

/**
 * The MainLeftTopWindowUpperSubWindow class implements a gui of Main Left Top Window - Upper Sub Window.
 */
class MainLeftTopWindowUpperSubWindow final : public AbstractGuiWindow {
public:
    /**
     * Creates a Main Left Top Window - Upper Sub Window.
     */
    static IGuiWindowSharedPtr Make(
        wxWindow& parent, 
        const std::vector<std::wstring>& items,
        IGuiManager& guiManager);

    /**
     * The MainLeftTopWindowUpperSubWindow constructor.
     */
    MainLeftTopWindowUpperSubWindow(
        wxWindow& parent, 
        const std::vector<std::wstring>& items, 
        IGuiManager& guiManager);

    /**
     * The MainLeftTopWindowUpperSubWindow destructor.
     */
    virtual ~MainLeftTopWindowUpperSubWindow();

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
