#pragma once

#include "FolderDialog.h"
#include "IGuiManager.h"

namespace VideoRenderingVisualizer {

namespace Gui {

/**
 * The TLogsFolderDialog class implements a folder dialog of TLogs.
 */
class TLogsFolderDialog final : public WXWidgets::FolderDialog {
public:
    /**
     * Creates a TLogs Folder Dialog.
     */
    static WXWidgets::IFolderDialogPtr Make(
        wxWindow& parent, 
        IGuiManager& guiManager);

    /**
     * The TLogsFolderDialog constructor.
     */
    TLogsFolderDialog(
        wxWindow& parent, 
        IGuiManager& guiManager);

    /**
     * The TLogsFolderDialog destructor.
     */
    virtual ~TLogsFolderDialog();
};

}  // namespace Gui

}  // namespace VideoRenderingVisualizer
