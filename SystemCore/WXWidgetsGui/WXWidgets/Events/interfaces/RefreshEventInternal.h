#ifndef REFRESH_EVENT_INTERNAL_ae109d36_f8e1_44a4_939c_4d57cbc28583
#define REFRESH_EVENT_INTERNAL_ae109d36_f8e1_44a4_939c_4d57cbc28583

#include "wx/event.h"
#include "IGuiTransaction.h"

namespace WXWidgets {

    /**
     * The RefreshEventInternal class implements an internal event of refreshing a GUI component.
     */
    class RefreshEventInternal final : public wxCommandEvent {
    public:
        //
        // Defines the WX Event Type...
        //
        using Type = wxEventTypeTag<RefreshEventInternal>;
        static const Type TYPE;

        /**
         * Gets an event id.
         */
        static int GetId();

        /**
         * The RefreshEventInternal constructor.
         */
        explicit RefreshEventInternal(IGuiTransactionSharedPtr guiTransaction);

        /**
         * The RefreshEventInternal destructor.
         */
        virtual ~RefreshEventInternal();

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

#endif // REFRESH_EVENT_INTERNAL_ae109d36_f8e1_44a4_939c_4d57cbc28583
