#ifndef LOGGING_EXCEPTION_H_025bbfc9_5ef4_48df_8953_a37a8e89e85f
#define LOGGING_EXCEPTION_H_025bbfc9_5ef4_48df_8953_a37a8e89e85f

#include "BaseException.h"

namespace logging {

    /**
     * The logging_exception class implements an exception in the Logging module.
     */
    class LoggingException : public base::BaseException {
    public:
        /**
         * The LoggingException constructor.
         */
        explicit LoggingException(const std::wstring& errorMessage) :
            BaseException(errorMessage)
        {
        }

        /**
         * The LoggingException constructor.
         */
        LoggingException(
            long errorCode,
            const std::wstring& errorMessage) :
                BaseException(
                    errorCode,
                    errorMessage)
        {
        }

        /**
         * The LoggingException destructor.
         */
        virtual ~LoggingException() = default;
    };

} // namespace logging

#endif // LOGGING_EXCEPTION_H_025bbfc9_5ef4_48df_8953_a37a8e89e85f
