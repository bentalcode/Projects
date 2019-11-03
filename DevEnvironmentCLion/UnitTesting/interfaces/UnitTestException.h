#ifndef UNIT_TEST_EXCEPTION_H_7de2081c_b47c_4fb1_86ce_3efa10febec5
#define UNIT_TEST_EXCEPTION_H_7de2081c_b47c_4fb1_86ce_3efa10febec5

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

#endif // UNIT_TEST_EXCEPTION_H_7de2081c_b47c_4fb1_86ce_3efa10febec5
