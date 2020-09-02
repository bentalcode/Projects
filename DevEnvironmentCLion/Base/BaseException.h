#ifndef BASE_EXCEPTION_H_865da64a_61f3_4334_9825_a69df087d9e4
#define BASE_EXCEPTION_H_865da64a_61f3_4334_9825_a69df087d9e4

#include "PreCompiled.h"
#include <exception>

namespace base {

    /**
     * The BaseException class captured errors in the base module.
     */
    class BaseException : public std::logic_error
    {
    public:
        explicit BaseException(const std::string& errorMessage) :
            std::logic_error(errorMessage),
            m_innerExceptionPtr(nullptr)
        {
        }

        BaseException(
            const std::string& errorMessage,
            std::exception& innerException) :
            std::logic_error(errorMessage),
            m_innerExceptionPtr(std::make_exception_ptr(innerException))
        {
        }

        /**
         * Gets the error message of an exception.
         */
        inline std::string getErrorMessage()
        {
            return this->what();
        }

        /**
         * Gets the inner exception.
         */
        inline std::exception_ptr getInnerException()
        {
            return m_innerExceptionPtr;
        }

    private:
        std::exception_ptr m_innerExceptionPtr;
    };
}

#endif // BASE_EXCEPTION_H_865da64a_61f3_4334_9825_a69df087d9e4
