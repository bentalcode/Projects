#ifndef I_TLOG_EXCEPTION_H_e23f770d_ae2d_4af3_b67e_3d8558b52b58
#define I_TLOG_EXCEPTION_H_e23f770d_ae2d_4af3_b67e_3d8558b52b58

#include "BaseException.h"

namespace tlogging {

    /**
     * The TLoggingException class implements an exception in the TLogging module.
     */
    class TLoggingException : public base::BaseException {
    public:
        /**
         * The tlogging_exception constructor.
         */
        explicit TLoggingException(const std::wstring& errorMessage) :
            BaseException(errorMessage)
        {
        }

        /**
         * The tlogging_exception constructor.
         */
        TLoggingException(
            unsigned long errorCode,
            const std::wstring& errorMessage) :
                BaseException(
                    errorCode,
                    errorMessage)
        {
        }

        /**
         * The TLoggingException destructor.
         */
        virtual ~TLoggingException() = default;
    };

} // namespace tlogging

#endif // I_TLOG_EXCEPTION_H_e23f770d_ae2d_4af3_b67e_3d8558b52b58
