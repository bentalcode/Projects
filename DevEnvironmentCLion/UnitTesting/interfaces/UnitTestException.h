#ifndef UNIT_TEST_EXCEPTION_H_45db7a45_05e3_4893_9ac3_62d9584e8597
#define UNIT_TEST_EXCEPTION_H_45db7a45_05e3_4893_9ac3_62d9584e8597

#include <exception>

namespace unit_testing {

    /**
     * The UnitTestException captured errors in the unit test module.
     */
    class UnitTestException : public std::runtime_error
    {
    public:
        explicit UnitTestException(const std::string &errorMessage) :
            std::runtime_error(errorMessage),
            m_innerExceptionPtr(nullptr) {
        }

        explicit UnitTestException(
            const std::string &errorMessage,
            std::exception &innerException) :
            std::runtime_error(errorMessage),
            m_innerExceptionPtr(std::make_exception_ptr(innerException)) {
        }

        /**
         * Gets the error message of an exception.
         */
        inline std::string getErrorMessage() {
            return this->what();
        }

        /**
         * Gets the inner exception.
         */
        inline std::exception_ptr getInnerException() {
            return m_innerExceptionPtr;
        }

    private:
        std::exception_ptr m_innerExceptionPtr;
    };
}

#endif // UNIT_TEST_EXCEPTION_H_45db7a45_05e3_4893_9ac3_62d9584e8597
