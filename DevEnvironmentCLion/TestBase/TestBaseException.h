#ifndef TEST_BASE_EXCEPTION_H_8d5f6aba_62e6_4a69_a29a_a7550e21128c
#define TEST_BASE_EXCEPTION_H_8d5f6aba_62e6_4a69_a29a_a7550e21128c

#include <exception>

/**
 * The TestBaseException captured errors in the test module.
 */
class TestBaseException : public std::runtime_error
{
public:
    explicit TestBaseException(const std::string& errorMessage) :
        std::runtime_error(errorMessage),
        m_innerExceptionPtr(nullptr)
    {
    }

    explicit TestBaseException(
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

#endif // TEST_BASE_EXCEPTION_H_8d5f6aba_62e6_4a69_a29a_a7550e21128c
