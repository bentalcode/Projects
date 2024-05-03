#ifndef POST_REFRESH_EVENT_b99ef78a_651d_4ae6_bac4_f8a82ee0a980
#define POST_REFRESH_EVENT_b99ef78a_651d_4ae6_bac4_f8a82ee0a980

#include "AbstractWXEvent.h"
#include "PostRefreshEventInternal.h"
#include "IGuiTransaction.h"

namespace WXWidgets {

    /**
     * The PostRefreshEvent class implements an event of post-refreshing a GUI component.
     */
    class PostRefreshEvent final : public AbstractWXEvent<PostRefreshEventInternal> {
    public:
        /**
         * Creates a post refresh event.
         */
        static IWXEventSharedPtr Create(IGuiTransactionSharedPtr guiTransaction);

        /**
         * The PostRefreshEvent constructor.
         */
        explicit PostRefreshEvent(IGuiTransactionSharedPtr guiTransaction);

        /**
         * The PostRefreshEvent destructor.
         */
        virtual ~PostRefreshEvent();

        /**
         * Gets a GUI transaction.
         */
        IGuiTransactionSharedPtr GetGuiTransaction();

    private:
        IGuiTransactionSharedPtr m_guiTransaction;
    };

}  // namespace WXWidgets

#endif // POST_REFRESH_EVENT_b99ef78a_651d_4ae6_bac4_f8a82ee0a980
