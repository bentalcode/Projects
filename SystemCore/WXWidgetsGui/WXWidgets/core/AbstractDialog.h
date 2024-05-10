#ifndef ABSTRACT_DIALOG_201497a4_9443_497c_8c16_e1425a52e87e
#define ABSTRACT_DIALOG_201497a4_9443_497c_8c16_e1425a52e87e

#include "IDialog.h"
#include "Window.h"
#include "wx/dialog.h"

namespace WXWidgets {

    /**
     * The AbstractDialog class implements an abstract base class of a dialog.
     */
    class AbstractDialog : public IDialog, public Window, public wxDialog {
    public:
        /**
         * The AbstractDialog constructor.
         */
        AbstractDialog(
            wxWindow& parent,
            const wxString& name,
            long style,
            const wxString& title,
            wxWindowID id,
            const wxPoint& position,
            const wxSize& size);

        /**
         * The AbstractDialog destructor.
         */
        virtual ~AbstractDialog();

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) override;

        /**
         * Activates a modal.
         */
        virtual int ActivateModal() override;

        /**
         * Gets a window.
         */
        virtual IWindow& GetWindow() override;

    private:
        std::wstring m_name;
    };

} // namespace WXWidgets

#endif // ABSTRACT_DIALOG_201497a4_9443_497c_8c16_e1425a52e87e
