#ifndef PRE_REFRESH_EVENT_INTERNAL_966d9d8b_fc1b_49dd_91e5_1eff08849755
#define PRE_REFRESH_EVENT_INTERNAL_966d9d8b_fc1b_49dd_91e5_1eff08849755

#include "wx\event.h"
#include "IGuiTransaction.h"

namespace WXWidgets {

    /**
     * The PreRefreshEventInternal class implements an internal event of pre-refreshing a GUI component.
     */
    class PreRefreshEventInternal final : public wxCommandEvent {
    public:
        //
        // Defines the WX Event Type...
        //
        using Type = wxEventTypeTag<PreRefreshEventInternal>;
        static const Type TYPE;

        /**
         * Gets an event id.
         */
        static int GetId();

        /**
         * The PreRefreshEventInternal constructor.
         */
        explicit PreRefreshEventInternal(IGuiTransactionSharedPtr guiTransaction);

        /**
         * The PreRefreshEventInternal destructor.
         */
        virtual ~PreRefreshEventInternal();

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

}  // namespace WXWidgets

#endif // PRE_REFRESH_EVENT_INTERNAL_966d9d8b_fc1b_49dd_91e5_1eff08849755
