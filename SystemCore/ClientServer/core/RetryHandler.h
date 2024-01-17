#pragma once

#include "IRetryHandler.h"
#include "IRetryPolicy.h"
#include "ILogic.h"
#include "BaseException.h"

namespace client_server {

    /**
     * The RetryHandler class implements a retry handler
     */
    class RetryHandler final : public IRetryHandler {
    public:
        /**
         * Creates a default retry handler.
         */
        static IRetryHandlerSharedPtr MakeDefault();

        /**
         * Creates a Retry Handler.
         */
        static IRetryHandlerSharedPtr Make(
            IRetryPolicySharedPtr policy,
            ILogicSharedPtr idleLogic);

        /**
         * The RetryHandler constructor.
         */
        RetryHandler(
            IRetryPolicySharedPtr policy,
            ILogicSharedPtr idleLogic);

        /**
         * The RetryHandler destructor.
         */
        virtual ~RetryHandler();

        /**
         * Retries to run a logic.
         */
        virtual void Retry(IRetryLogic& logic) override;

    private:
        /**
         * Checks whether an exception is absorbed.
         */
        bool IsAbsorbedException(
            const IRetryLogic& logic,
            base::BaseException& exception) const;

        /**
         * Gets the information of a retry logic.
         */
        std::wstring GetLogicInformation(const IRetryLogic& logic) const;

        /**
         * Gets the retry logic attempt information.
         */
        std::wstring GetRetryLogicAttemptInformation(
            const IRetryLogic& logic,
            unsigned int attemptIndex) const;

        IRetryPolicySharedPtr m_policy;
        ILogicSharedPtr m_idleLogic;
        std::wstringstream* m_outstream;
    };

} // namespace client_server
