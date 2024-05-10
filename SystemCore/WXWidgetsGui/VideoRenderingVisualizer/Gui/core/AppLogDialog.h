#pragma once

#include "Dialog.h"
#include "IGuiManager.h"
#include "IListView.h"

namespace VideoRenderingVisualizer {

namespace Gui {

/**
 * The AppLogDialog class implements a dialog of App Log.
 */
class AppLogDialog final : public WXWidgets::Dialog {
public:
    /**
     * Creates an App Log Dialog.
     */
    static WXWidgets::IDialogPtr Make(
        wxWindow& parent, 
        IGuiManager& guiManager);

    /**
     * The AppLogDialog constructor.
     */
    AppLogDialog(
        wxWindow& parent, 
        IGuiManager& guiManager);

    /**
     * The AppLogDialog destructor.
     */
    virtual ~AppLogDialog();

private:
    /**
     * Initializes a GUI component.
     */
    void Initialize(IGuiManager& guiManager);

    //
    // The GUI Manager...
    //
    IGuiManager& m_guiManager;

    //
    // The list view of log...
    //
    WXWidgets::IListViewPtr m_logListView;
};

}  // namespace Gui

}  // namespace VideoRenderingVisualizer
