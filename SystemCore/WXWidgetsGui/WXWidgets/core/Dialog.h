#ifndef DIALOG_1fa7a45a_c709_48f7_842e_d656d3fc19da
#define DIALOG_1fa7a45a_c709_48f7_842e_d656d3fc19da

#include "AbstractDialog.h"
#include "WXObjectId.h"

namespace wxwidgets {

    /**
     * The Dialog class implements a dialog.
     */
    class Dialog : public AbstractDialog {
    public:
        /**
         * The Dialog constructor.
         */
        Dialog(
            wxWindow& parent,
            const wxString& name,
            long style = wxDEFAULT_DIALOG_STYLE,
            const wxString& title = L"",
            const wxSize& size = wxDefaultSize,
            wxWindowID id  = WXObjectId::NextId(),
            const wxPoint& position = wxDefaultPosition);

        /**
         * The Dialog destructor.
         */
        virtual ~Dialog();

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(IGuiControllerSharedPtr guiController) override;
    };

} // namespace wxwidgets

#endif // DIALOG_1fa7a45a_c709_48f7_842e_d656d3fc19da
