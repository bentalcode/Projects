#pragma once

#include "AbstractGuiWindow.h"
#include "IListView.h"

namespace VideoRenderingVisualizer {

namespace Gui {

/**
 * The MainRightBottomWindow class implements a gui of Main Right Bottom Window.
 */
class MainRightBottomWindow final : public AbstractGuiWindow {
public:
    /**
     * Creates a Main Right Bottom Window.
     */
    static IGuiWindowSharedPtr Make(
        wxWindow& parent, 
        IGuiManager& guiManager);

    /**
     * The MainRightBottomWindow constructor.
     */
    MainRightBottomWindow(
        wxWindow& parent, 
        IGuiManager& guiManager);

    /**
     * The MainRightBottomWindow destructor.
     */
    virtual ~MainRightBottomWindow();

    /**
     * Gets a window.
     */
    virtual WXWidgets::IWindow& GetWindow() override;

private:
    /**
     * Initializes a window.
     */
    void Initialize(wxWindow& parent);

    //
    // The list view of rendering pipelines...
    //
    WXWidgets::IListViewPtr m_listView;
};

} // namespace Gui

} // namespace VideoRenderingVisualizer
