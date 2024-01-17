#ifndef RETRY_POLICY_H_f0a6bd4c_7d23_400b_83f9_9870b6a7f43b
#define RETRY_POLICY_H_f0a6bd4c_7d23_400b_83f9_9870b6a7f43b

#include "IRetryPolicy.h"

namespace client_server {

    /**
     * The RetryPolicy class implements a retry policy.
     */
    class RetryPolicy final : public IRetryPolicy {
    public:
        /**
         * Creates a default retry policy.
         */
        static IRetryPolicySharedPtr MakeDefault();

        /**
         * Creates a retry policy.
         */
        static IRetryPolicySharedPtr Make(
            unsigned int numOfAttempts,
            base::DurationSharedPtr intervalDuration);

        /**
         * The RetryPolicy constructor.
         */
        RetryPolicy(
            unsigned int numOfAttempts,
            base::DurationSharedPtr intervalDuration);

        /**
         * The RetryPolicy destructor.
         */
        virtual ~RetryPolicy();

        /**
         * Gets the number of attempts.
         */
        virtual unsigned int GetNumberOfAttempts() const override;

        /**
         * Gets the interval duration.
         */
        virtual base::DurationSharedPtr GetIntervalDuration() const override;

    private:
        static const unsigned int DEFAULT_NUM_OF_ATTEMPTS;
        static const base::DurationSharedPtr DEFAULT_DURATION;

        unsigned int m_numOfAttempts;
        base::DurationSharedPtr m_intervalDuration;
    };

} // namespace client_server

#endif // RETRY_POLICY_H_f0a6bd4c_7d23_400b_83f9_9870b6a7f43b
