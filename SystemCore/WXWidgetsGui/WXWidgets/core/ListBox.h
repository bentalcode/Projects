#ifndef LIST_BOX_131229c5_126c_4c66_b4c2_dec6649ebf33
#define LIST_BOX_131229c5_126c_4c66_b4c2_dec6649ebf33

#include "AbstractListBox.h"
#include "WXObjectId.h"

namespace wxwidgets {

    /**
     * The ListBox class implements an abstract list box.
     */
    class ListBox : public AbstractListBox {
    public:
        /**
         * Creates a list box.
         */
        static IListBoxPtr Make(
            wxWindow& parent,
            const wxString& name,
            long style = 0,
            wxWindowID id = wxwidgets::WXObjectId::NextId(),
            const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            int n = 0,
            const wxValidator& validator = wxDefaultValidator);

        /**
         * The ListBox constructor.
         */
        ListBox(
            wxWindow& parent,
            const wxString& name,
            long style = 0,
            wxWindowID id = wxwidgets::WXObjectId::NextId(),
            const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            int n = 0,
            const wxValidator& validator = wxDefaultValidator);

        /**
         * The ListBox destructor.
         */
        virtual ~ListBox();

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(
            const std::vector<std::wstring>& items,
            IGuiControllerSharedPtr guiController,
            bool showMode = true) override;
    };

} // namespace wxwidgets

#endif // LIST_BOX_131229c5_126c_4c66_b4c2_dec6649ebf33
