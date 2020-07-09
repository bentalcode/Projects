#ifndef DATA_STRUCTURE_EXCEPTION_H_2e1c7881_982e_47ee_8246_df22145460e3
#define DATA_STRUCTURE_EXCEPTION_H_2e1c7881_982e_47ee_8246_df22145460e3

#include "PreCompiled.h"
#include <exception>

/**
 * The BaseException captured errors in the base module.
 */
class BaseException : public std::runtime_error
{
public:
    explicit BaseException(const std::string& errorMessage) :
        std::runtime_error(errorMessage),
        m_innerExceptionPtr(nullptr)
    {
    }

    explicit BaseException(
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

#endif // DATA_STRUCTURE_EXCEPTION_H_2e1c7881_982e_47ee_8246_df22145460e3
