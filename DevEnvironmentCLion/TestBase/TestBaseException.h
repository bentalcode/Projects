#ifndef TEST_BASE_EXCEPTION_H_4cc67362_8400_476c_8436_8e5b96732e0d
#define TEST_BASE_EXCEPTION_H_4cc67362_8400_476c_8436_8e5b96732e0d

#include "BaseException.h"

namespace test_base {

    /**
     * The TestBaseException captured errors in the test module.
     */
    class TestBaseException : public base::BaseException
    {
    public:
        explicit TestBaseException(const std::string& errorMessage) :
            base::BaseException(errorMessage)
        {
        }

        TestBaseException(
            const std::string& errorMessage,
            std::exception& innerException) :
            base::BaseException(errorMessage, innerException)
        {
        }
    };
}

#endif // TEST_BASE_EXCEPTION_H_4cc67362_8400_476c_8436_8e5b96732e0d
