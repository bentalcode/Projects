#ifndef WINDOWS_EXCEPTION_H_aca0d27e_01ce_482d_9049_5964052b7dd0
#define WINDOWS_EXCEPTION_H_aca0d27e_01ce_482d_9049_5964052b7dd0

#include "BaseException.h"
#include "WindowsErrors.h"

namespace base {

    /**
     * The WindowsException class implements a windows exception.
     */
    class WindowsException final : public base::BaseException
    {
    public:
        /**
         * The WindowsException constructor.
         */
        WindowsException() :
            WindowsException(::GetLastError(), WindowsErrors::getLastErrorAsString())
        {
        }

        /**
         * The WindowsException constructor.
         */
        WindowsException(
            DWORD errorCode,
            const std::string &errorMessage) :
            base::BaseException(errorMessage),
            m_errorCode(errorCode)
        {
        }

        /**
         * The WindowsException constructor with an inner exception.
         */
        WindowsException(
            DWORD errorCode,
            const std::string &errorMessage,
            std::exception &innerException) :
            base::BaseException(errorMessage, innerException),
            m_errorCode(errorCode)
        {
        }

        /**
         * Gets the error code.
         */
        DWORD getErrorCode() const
        {
            return m_errorCode;
        }

    private:
        DWORD m_errorCode;
    };

}

#endif // WINDOWS_EXCEPTION_H_aca0d27e_01ce_482d_9049_5964052b7dd0
