#ifndef TEST_BASE_EXCEPTION_H_0a7dddde_b8fa_46e8_b746_39e58961423b
#define TEST_BASE_EXCEPTION_H_0a7dddde_b8fa_46e8_b746_39e58961423b

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

#endif // TEST_BASE_EXCEPTION_H_0a7dddde_b8fa_46e8_b746_39e58961423b
