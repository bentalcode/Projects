#ifndef POST_REFRESH_EVENT_INTERNAL_ebcafe4c_df12_4f0b_95a4_d52277e54508
#define POST_REFRESH_EVENT_INTERNAL_ebcafe4c_df12_4f0b_95a4_d52277e54508

#include "wx/event.h"
#include "IGuiTransaction.h"

namespace WXWidgets {

    /**
     * The PostRefreshEventInternal class implements an internal event of post-refreshing a GUI component.
     */
    class PostRefreshEventInternal final : public wxCommandEvent {
    public:
        //
        // Defines the WX Event Type...
        //
        using Type = wxEventTypeTag<PostRefreshEventInternal>;
        static const Type TYPE;

        /**
         * Gets an event id.
         */
        static int GetId();

        /**
         * The PostRefreshEventInternal constructor.
         */
        explicit PostRefreshEventInternal(IGuiTransactionSharedPtr guiTransaction);

        /**
         * The PostRefreshEventInternal destructor.
         */
        virtual ~PostRefreshEventInternal();

        /**
         * Clones an event.
         */
        wxEvent* Clone() const;

        /**
         * Gets a GUI transaction.
         */
        IGuiTransactionSharedPtr GetGuiTransaction();

    private:
        IGuiTransactionSharedPtr m_guiTransaction;
    };

} // namespace WXWidgets

#endif // POST_REFRESH_EVENT_INTERNAL_ebcafe4c_df12_4f0b_95a4_d52277e54508
