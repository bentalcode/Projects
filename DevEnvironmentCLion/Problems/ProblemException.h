#ifndef PROBLEM_EXCEPTION_H_f652863d_618c_4bb5_8a6c_37a2a9b39dec
#define PROBLEM_EXCEPTION_H_f652863d_618c_4bb5_8a6c_37a2a9b39dec

#include "PreCompiled.h"
#include <exception>

/**
 * The ProblemException captured errors in the problems module.
 */
class ProblemException : public std::runtime_error
{
public:
    explicit ProblemException(const std::string& errorMessage) :
        std::runtime_error(errorMessage),
        m_innerExceptionPtr(nullptr)
    {
    }

    explicit ProblemException(
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

#endif // PROBLEM_EXCEPTION_H_f652863d_618c_4bb5_8a6c_37a2a9b39dec
