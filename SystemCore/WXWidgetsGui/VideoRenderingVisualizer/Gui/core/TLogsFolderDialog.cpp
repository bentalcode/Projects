#include "TLogsFolderDialog.h"
#include "GuiPaths.h"

using namespace VideoRenderingVisualizer;
using namespace VideoRenderingVisualizer::Gui;

/**
 * Creates a TLog Folder Dialog.
 */
wxwidgets::IFolderDialogPtr TLogsFolderDialog::Make(
    wxWindow& parent, 
    IGuiManager& guiManager)
{
    return wxwidgets::IFolderDialogPtr::Make(
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
        wxwidgets::FolderDialog(
            parent, 
            GuiPaths::Read().GetMainFrameTopMenuBarFileMenuOpenFolderDialog(),
            wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST)
{
    //
    // Initialize a GUI component...
    //
    wxwidgets::FolderDialog::Initialize(guiManager.GetGuiController());
}

/**
 * The TLogsFolderDialog destructor.
 */
TLogsFolderDialog::~TLogsFolderDialog() 
{
}
