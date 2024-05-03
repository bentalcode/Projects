#ifndef I_FOLDER_DIALOG_a33f3afd_a1f4_49d6_916d_dc8c8c3989c3
#define I_FOLDER_DIALOG_a33f3afd_a1f4_49d6_916d_dc8c8c3989c3

#include "IGuiController.h"
#include "WXObjectPtr.h"
#include <vector>
#include <string>

namespace WXWidgets {

    /**
     * The IFolderDialog interface defines a folder dialog for selecting folder(s).
     */
    class IFolderDialog {
    public:
        IFolderDialog() = default;
        virtual ~IFolderDialog() = default;

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) = 0;

        /**
         * Activates a modal.
         */
        virtual int ActivateModal() = 0;

        /**
         * Get a selected list of folders.
         */
        virtual void GetSelectedFolders(std::vector<std::wstring>& folders) const = 0;
    };

    //
    // Defines the WX Object Ptr of Folder Dialog.
    //
    using IFolderDialogPtr = WXObjectPtr<IFolderDialog>;

}  // namespace WXWidgets

#endif // I_FOLDER_DIALOG_a33f3afd_a1f4_49d6_916d_dc8c8c3989c3
