#ifndef REFRESH_EVENT_ae109d36_f8e1_44a4_939c_4d57cbc28583
#define REFRESH_EVENT_ae109d36_f8e1_44a4_939c_4d57cbc28583

#include "AbstractWXEvent.h"
#include "RefreshEventInternal.h"
#include "IGuiTransaction.h"

namespace wxwidgets {

    /**
     * The RefreshEvent class implements an event of refreshing a GUI component.
     */
    class RefreshEvent final : public AbstractWXEvent<RefreshEventInternal> {
    public:
        /**
         * Creates a refresh event.
         */
        static IWXEventSharedPtr Create(IGuiTransactionSharedPtr guiTransaction);

        /**
         * The RefreshEvent constructor.
         */
        explicit RefreshEvent(IGuiTransactionSharedPtr guiTransaction);

        /**
         * The RefreshEvent destructor.
         */
        virtual ~RefreshEvent();

        /**
         * Gets a GUI transaction.
         */
        IGuiTransactionSharedPtr GetGuiTransaction();

    private:
        IGuiTransactionSharedPtr m_guiTransaction;
    };

} // namespace wxwidgets

#endif // REFRESH_EVENT_ae109d36_f8e1_44a4_939c_4d57cbc28583
