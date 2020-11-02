#ifndef UNIT_TEST_EXCEPTION_H_65737791_18b3_43ee_aad8_6c00b65070e6
#define UNIT_TEST_EXCEPTION_H_65737791_18b3_43ee_aad8_6c00b65070e6

#include <exception>

namespace unit_testing {

    /**
     * The UnitTestException class implements an exception for capturing errors in the unit-test module.
     */
    class UnitTestException : public base::BaseException {
    public:
        explicit UnitTestException(const std::string& errorMessage) :
            base::BaseException(errorMessage)
        {
        }

        UnitTestException(
            const std::string& errorMessage,
            std::exception& innerException) :
            base::BaseException(errorMessage, innerException)
        {
        }
    };
}

#endif // UNIT_TEST_EXCEPTION_H_65737791_18b3_43ee_aad8_6c00b65070e6
