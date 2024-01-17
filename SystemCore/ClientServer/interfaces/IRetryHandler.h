#ifndef I_RETRY_HANDLER_H_67becc3f_85ce_4bbb_b436_e2fd8bef5c67
#define I_RETRY_HANDLER_H_67becc3f_85ce_4bbb_b436_e2fd8bef5c67

#include <memory>

namespace client_server {

    class IRetryLogic;

    /**
     * The IRetryHandler interface defines a Retry Handler.
     */
    class IRetryHandler {
    public:
        IRetryHandler() = default;
        virtual ~IRetryHandler() = default;

        /**
         * The copy/move constructors.
         */
        IRetryHandler(const IRetryHandler&) = delete;
        IRetryHandler(IRetryHandler&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IRetryHandler& operator=(const IRetryHandler&) = delete;
        IRetryHandler& operator=(IRetryHandler&&) = delete;

        /**
         * Retries to run a logic.
         */
        virtual void Retry(IRetryLogic& logic) = 0;
    };

    /**
     * Defines the Shared Ptr of Retry Handler.
     */
    using IRetryHandlerSharedPtr = std::shared_ptr<IRetryHandler>;

} // namespace client_server

#endif // I_RETRY_HANDLER_H_67becc3f_85ce_4bbb_b436_e2fd8bef5c67
