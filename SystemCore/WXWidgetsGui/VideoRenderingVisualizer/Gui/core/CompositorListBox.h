#pragma once

#include "ListBox.h"

namespace VideoRenderingVisualizer {

namespace Gui {

class IGuiManager;

/**
 * The CompositorListBox class implements a list box of compositors.
 */
class CompositorListBox final : public WXWidgets::ListBox {
public:
    /**
     * Creates a compositor list box.
     */
    static WXWidgets::IListBoxPtr Make(
        wxWindow& parent, 
        const std::vector<std::wstring>& items, 
        IGuiManager& guiManager);

    /**
     * The CompositorListBox constructor.
     */
    CompositorListBox(
        wxWindow& parent, 
        const std::vector<std::wstring>& items, 
        IGuiManager& guiManager);

    /**
     * The CompositorListBox destructor.
     */
    virtual ~CompositorListBox();

    /**
     * The on selected callback.
     */
    virtual void OnSelectedItem(const std::wstring& item) override;
    
private:
    /**
     * Initializes a GUI component.
     */
    void Initialize(const std::vector<std::wstring>& items);

    //
    // The GUI Manager...
    //
    IGuiManager& m_guiManager;
};

}  // namespace Gui

}  // namespace VideoRenderingVisualizer
