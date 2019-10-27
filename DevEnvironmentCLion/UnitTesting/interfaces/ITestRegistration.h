#ifndef I_TEST_REGISTRATION_H_c0ed3a41_f212_4b3a_81e0_8ddb907c399d
#define I_TEST_REGISTRATION_H_c0ed3a41_f212_4b3a_81e0_8ddb907c399d

#include "ITestFunction.h"

namespace unit_testing
{
    /**
     * The ITestRegistration interface defines a test registration.
     */
    class ITestRegistration
    {
    public:
        /**
         * The ITestRegistration constructor.
         */
        ITestRegistration() = default;

        /**
         * The ITestRegistration destructor.
         */
        virtual ~ITestRegistration() = default;

        /**
         * Disables the copy constructor and assignment operator.
         */
        ITestRegistration(const ITestRegistration& rhs) = delete;
        ITestRegistration& operator=(const ITestRegistration& rhs) = delete;

        /**
         * Registers a test.
         */
        virtual void registerTest(ITestFunctionPtr testFunction) = 0;
    };
}

#endif // I_TEST_REGISTRATION_H_c0ed3a41_f212_4b3a_81e0_8ddb907c399d
