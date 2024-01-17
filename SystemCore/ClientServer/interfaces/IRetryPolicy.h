#ifndef I_RETRY_POLICY_H_0c6d2eba_0864_448c_b6f2_ff669dd79681
#define I_RETRY_POLICY_H_0c6d2eba_0864_448c_b6f2_ff669dd79681

#include "Duration.h"
#include <sstream>

namespace client_server {

    /**
     * The IRetryPolicy interface defines a retry policy.
     */
    class IRetryPolicy {
    public:
        IRetryPolicy() = default;
        virtual ~IRetryPolicy() = default;

        /**
         * The copy/move constructors.
         */
        IRetryPolicy(const IRetryPolicy&) = delete;
        IRetryPolicy(IRetryPolicy&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IRetryPolicy& operator=(const IRetryPolicy&) = delete;
        IRetryPolicy& operator=(IRetryPolicy&&) = delete;

        /**
         * Gets the number of attempts.
         */
        virtual unsigned int GetNumberOfAttempts() const = 0;

        /**
         * Gets the interval duration.
         */
        virtual base::DurationSharedPtr GetIntervalDuration() const = 0;
    };

    /**
     * Defines the Shared Ptr of Retry Policy.
     */
    using IRetryPolicySharedPtr = std::shared_ptr<IRetryPolicy>;

    /**
     * Writes retry policy to an output stream.
     */
    inline std::wostream& operator<<(std::wostream& stream, const IRetryPolicy& retryPolicy)
    {
        stream
            << L"{ NumberOfAttempts " << retryPolicy.GetNumberOfAttempts()
            << L", IntervalDuration: " << retryPolicy.GetIntervalDuration()->ToString()
            << L" }";

        return stream;
    }

} // namespace client_server

#endif // I_RETRY_POLICY_H_0c6d2eba_0864_448c_b6f2_ff669dd79681
