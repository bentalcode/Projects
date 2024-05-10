#ifndef PRE_REFRESH_EVENT_db448be6_a616_4e52_bd96_e67188f8dac4
#define PRE_REFRESH_EVENT_db448be6_a616_4e52_bd96_e67188f8dac4

#include "AbstractWXEvent.h"
#include "PreRefreshEventInternal.h"
#include "IGuiTransaction.h"

namespace WXWidgets {

    /**
     * The PreRefreshEvent class implements an event of pre-refreshing a GUI component.
     */
    class PreRefreshEvent final : public AbstractWXEvent<PreRefreshEventInternal> {
    public:
        /**
         * Creates a pre refresh event.
         */
        static IWXEventSharedPtr Create(IGuiTransactionSharedPtr guiTransaction);

        /**
         * The PreRefreshEvent constructor.
         */
        explicit PreRefreshEvent(IGuiTransactionSharedPtr guiTransaction);

        /**
         * The PreRefreshEvent destructor.
         */
        virtual ~PreRefreshEvent();

        /**
         * Gets a GUI transaction.
         */
        IGuiTransactionSharedPtr GetGuiTransaction();

    private:
        IGuiTransactionSharedPtr m_guiTransaction;
    };

} // namespace WXWidgets

#endif // PRE_REFRESH_EVENT_db448be6_a616_4e52_bd96_e67188f8dac4
