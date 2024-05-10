#include "TLogsFolderDialog.h"
#include "GuiPaths.h"

using namespace VideoRenderingVisualizer;
using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates a TLog Folder Dialog.
 */
WXWidgets::IFolderDialogPtr TLogsFolderDialog::Make(
    wxWindow& parent, 
    IGuiManager& guiManager)
{
    return WXWidgets::IFolderDialogPtr::Make(
        new TLogsFolderDialog(
            parent, 
            guiManager));
}

/**
 * The TLogsFolderDialog constructor.
 */
TLogsFolderDialog::TLogsFolderDialog(
    wxWindow& parent, 
    IGuiManager& guiManager) : 
        WXWidgets::FolderDialog(
            parent, 
            GuiPaths::Read().GetMainFrameTopMenuBarFileMenuOpenFolderDialog(),
            wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST)
{
    //
    // Initialize a GUI component...
    //
    WXWidgets::FolderDialog::Initialize(guiManager.GetGuiController());
}

/**
 * The TLogsFolderDialog destructor.
 */
TLogsFolderDialog::~TLogsFolderDialog() 
{
}
