#ifndef CONCURRENCY_EXCEPTION_H_3e965933_2909_43a0_b74f_9e7f0c489243
#define CONCURRENCY_EXCEPTION_H_3e965933_2909_43a0_b74f_9e7f0c489243

#include "PreCompiled.h"
#include <exception>

/**
 * The ConcurrencyException captured errors in the concurrency module.
 */
class ConcurrencyException : public std::runtime_error
{
public:
    explicit ConcurrencyException(const std::string& errorMessage) :
        std::runtime_error(errorMessage),
        m_innerExceptionPtr(nullptr)
    {
    }

    explicit ConcurrencyException(
        const std::string& errorMessage,
        std::exception& innerException) :
        std::runtime_error(errorMessage),
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

#endif // CONCURRENCY_EXCEPTION_H_3e965933_2909_43a0_b74f_9e7f0c489243
