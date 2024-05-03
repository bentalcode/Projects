#ifndef FOLDER_DIALOG_f8b27af5_5a33_4f71_82d7_8338b704d262
#define FOLDER_DIALOG_f8b27af5_5a33_4f71_82d7_8338b704d262

#include "IFolderDialog.h"
#include "GuiComponent.h"
#include "wx/dirdlg.h"
#include <vector>

namespace WXWidgets {

    /**
     * The FolderDialog class implements a folder dialog for selecting folder(s).
     */
    class FolderDialog : public IFolderDialog, public GuiComponent, public wxDirDialog {
    public:
        /**
         * Creates a folder dialog.
         */
        static IFolderDialogPtr Make(
            wxWindow& parent,
            const wxString& name,
            long style = wxDD_DEFAULT_STYLE,
            const wxString& message = wxDirSelectorPromptStr,
            const wxString& defaultPath = wxEmptyString,
            const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize);

        /**
         * The FolderDialog constructor.
         */
        FolderDialog(
            wxWindow& parent,
            const wxString& name,
            long style = wxDD_DEFAULT_STYLE,
            const wxString& message = wxDirSelectorPromptStr,
            const wxString& defaultPath = wxEmptyString,
            const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize);

        /**
         * The FolderDialog destructor.
         */
        virtual ~FolderDialog();

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) override;

        /**
         * Activates a modal.
         */
        virtual int ActivateModal() override;

        /**
         * Get a selected list of folders.
         */
        virtual void GetSelectedFolders(std::vector<std::wstring>& folders) const override;

    private:
        std::wstring m_name;
    };

}  // namespace WXWidgets

#endif // FOLDER_DIALOG_f8b27af5_5a33_4f71_82d7_8338b704d262
