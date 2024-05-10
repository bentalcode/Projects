#ifndef LIST_VIEW_d970ee8e_fac5_4e41_b6c2_da91dd96cf18
#define LIST_VIEW_d970ee8e_fac5_4e41_b6c2_da91dd96cf18

#include "AbstractListView.h"
#include "WXObjectId.h"

namespace wxwidgets {

    /**
     * The ListView class implements an abstract list view.
     */
    class ListView : public AbstractListView {
    public:
        /**
         * Creates a list view.
         */
        static IListViewPtr Make(
            wxWindow& parent,
            const wxString& name,
            wxWindowID id = wxwidgets::WXObjectId::NextId(),
            const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxLC_REPORT,
            const wxValidator& validator = wxDefaultValidator);

        /**
         * The ListView constructor.
         */
        ListView(
            wxWindow& parent,
            const wxString& name,
            wxWindowID id = wxwidgets::WXObjectId::NextId(),
            const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxLC_REPORT,
            const wxValidator& validator = wxDefaultValidator);

        /**
         * The ListView destructor.
         */
        virtual ~ListView();

        /**
         * Initializes a GUI component.
         */
        virtual void Initialize(
            const std::vector<std::wstring>& headers,
            const std::vector<std::vector<std::wstring>>& values,
            const wxListColumnFormat& headerFormat,
            size_t headerWidth,
            IGuiControllerSharedPtr guiController,
            bool showMode = true) override;
    };

} // namespace wxwidgets

#endif // LIST_VIEW_d970ee8e_fac5_4e41_b6c2_da91dd96cf18
