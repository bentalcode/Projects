#ifndef BASE_EXCEPTION_H_865da64a_61f3_4334_9825_a69df087d9e4
#define BASE_EXCEPTION_H_865da64a_61f3_4334_9825_a69df087d9e4

#include "ErrorCodes.h"

namespace base {

    /**
     * The BaseException class captured errors in the base module.
     */
    class BaseException
    {
    public:
        explicit BaseException(
            const std::wstring& errorMessage) :
            m_statusCode(ErrorCodes::FAIL),
            m_errorMessage(errorMessage)
        {
        }

        BaseException(
            long statusCode,
            const std::wstring& errorMessage) :
            m_statusCode(statusCode),
            m_errorMessage(errorMessage)
        {
        }

        /**
         * Gets an error code of an exception.
         */
        inline long GetStatusCode()
        {
            return m_statusCode;
        }

        /**
         * Gets an error message of an exception.
         */
        inline std::wstring GetErrorMessage()
        {
            return m_errorMessage;
        }

    private:
        long m_statusCode;
        std::wstring m_errorMessage;
    };

} // namespace base

#endif // BASE_EXCEPTION_H_865da64a_61f3_4334_9825_a69df087d9e4
