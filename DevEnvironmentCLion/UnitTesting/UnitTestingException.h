#ifndef UNIT_TESTING_EXCEPTION_H_4cda4787_08cd_4811_b791_1a8e9ddf949e
#define UNIT_TESTING_EXCEPTION_H_4cda4787_08cd_4811_b791_1a8e9ddf949e

#include <exception>

/**
 * The UnitTestingException captured errors in the test module.
 */
class UnitTestingException : public std::runtime_error
{
public:
    explicit UnitTestingException(const std::string& errorMessage) :
        std::runtime_error(errorMessage),
        m_innerExceptionPtr(nullptr)
    {
    }

    explicit UnitTestingException(
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

#endif // UNIT_TESTING_EXCEPTION_H_4cda4787_08cd_4811_b791_1a8e9ddf949e
