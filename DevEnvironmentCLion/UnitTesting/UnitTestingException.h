#ifndef UNIT_TESTING_EXCEPTION_H_4cda4787_08cd_4811_b791_1a8e9ddf949e
#define UNIT_TESTING_EXCEPTION_H_4cda4787_08cd_4811_b791_1a8e9ddf949e

#include "BaseException.h"

namespace unit_testing
{
    /**
     * The UnitTestingException captured errors in the unit-testing module.
     */
    class UnitTestingException : public base::BaseException
    {
    public:
        explicit UnitTestingException(const std::string& errorMessage) :
            base::BaseException(errorMessage)
        {
        }

        UnitTestingException(
            const std::string& errorMessage,
            std::exception& innerException) :
            base::BaseException(errorMessage, innerException)
        {
        }
    };

}

#endif // UNIT_TESTING_EXCEPTION_H_4cda4787_08cd_4811_b791_1a8e9ddf949e
