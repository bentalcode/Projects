#pragma once

#include "AbstractGuiWindow.h"
#include "IStaticText.h"

class wxWindow;

namespace VideoRenderingVisualizer { 

namespace Gui {

/**
 * The MainLeftBottomWindow class implements a gui of Main Left Bottom Window.
 */
class MainLeftBottomWindow final : public AbstractGuiWindow {
public:
    /**
     * Creates a Main Left Bottom Window.
     */
    static IGuiWindowSharedPtr Make(
        wxWindow& parent, 
        IGuiManager& guiManager);

    /**
     * The MainLeftBottomWindow constructor.
     */
    MainLeftBottomWindow(
        wxWindow& parent, 
        IGuiManager& guiManager);

    /**
     * The MainLeftBottomWindow destructor.
     */
    virtual ~MainLeftBottomWindow();

    /**
     * Gets a window.
     */
    virtual WXWidgets::IWindow& GetWindow() override;

private:
    /**
     * Initializes a window.
     */
    void Initialize(wxWindow& parent);

    WXWidgets::IStaticTextPtr m_staticText;
};

}

}  // namespace VideoRenderingVisualizer::Gui
