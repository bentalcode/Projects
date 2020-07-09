#ifndef PROBLEM_EXCEPTION_H_5f40a0b5_6b4e_432f_85a0_93b5d2d11ad5
#define PROBLEM_EXCEPTION_H_5f40a0b5_6b4e_432f_85a0_93b5d2d11ad5

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

#endif // PROBLEM_EXCEPTION_H_5f40a0b5_6b4e_432f_85a0_93b5d2d11ad5
