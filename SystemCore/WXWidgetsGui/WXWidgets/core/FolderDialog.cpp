#include "FolderDialog.h"
#include <assert.h>

using namespace wxwidgets;

/**
 * Creates a folder dialog.
 */
IFolderDialogPtr FolderDialog::Make(
    wxWindow& parent, 
    const wxString& name, 
    long style, 
    const wxString& message, 
    const wxString& defaultPath, 
    const wxPoint& position, 
    const wxSize& size)
{
    return IFolderDialogPtr::Make(
        new FolderDialog(
            parent, 
            name, 
            style,
            message, 
            defaultPath, 
            position, 
            size));
}

/**
 * The FolderDialog constructor.
 */
FolderDialog::FolderDialog(
    wxWindow& parent, 
    const wxString& name, 
    long style, 
    const wxString& message, 
    const wxString& defaultPath, 
    const wxPoint& position, 
    const wxSize& size) : 
        wxDirDialog(
            &parent, 
            message, 
            defaultPath, 
            style, 
            position, 
            size, 
            name), 
    m_name(name)
{
}

/**
 * The FolderDialog destructor.
 */
FolderDialog::~FolderDialog() 
{
}

/**
 * Get a selected list of folders.
 */
void FolderDialog::GetSelectedFolders(std::vector<std::wstring>& folders) const
{
    assert(folders.empty());

    //
    // Retrieve a slelected paths or a selected path...
    //
    wxArrayString paths;
    GetPaths(paths);

    if (!paths.empty()) {
        folders.reserve(paths.size());

        for (const wxString& currPath : paths) {
            folders.push_back(currPath.ToStdWstring());
        }
    } else {
        wxString path = GetPath();
        folders.push_back(path.ToStdWstring());
    }
}

/**
 * Initializes a GUI component.
 */
void FolderDialog::Initialize(IGuiControllerSharedPtr guiController)
{
    //
    // Initialize component...
    //
    GuiComponent::Initialize(
        m_name,
        *this, 
        guiController);
}

/**
 * Activates a modal.
 */
int FolderDialog::ActivateModal()
{
    return wxDirDialog::ShowModal();
}
