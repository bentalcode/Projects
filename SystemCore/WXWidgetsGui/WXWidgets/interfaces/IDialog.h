#ifndef I_DIALOG_cf415f65_69f1_4aaa_9efd_ace8a3fdab38
#define I_DIALOG_cf415f65_69f1_4aaa_9efd_ace8a3fdab38

#include "IGuiController.h"
#include "IWindow.h"
#include "WXObjectPtr.h"

namespace WXWidgets {

    /**
     * The IDialog interface defines a dialog.
     */
    class IDialog {
    public:
        IDialog() = default;
        virtual ~IDialog() = default;

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) = 0;

        /**
         * Activates a modal.
         */
        virtual int ActivateModal() = 0;

        /**
         * Gets a window.
         */
        virtual IWindow& GetWindow() = 0;
    };

    //
    // Defines the WX Object Ptr of Dialog.
    //
    using IDialogPtr = WXObjectPtr<IDialog>;

} // namespace WXWidgets

#endif // I_DIALOG_cf415f65_69f1_4aaa_9efd_ace8a3fdab38

