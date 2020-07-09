#ifndef I_TEST_REGISTRATION_H_81822a01_32cd_49ca_bca1_533fa9955cab
#define I_TEST_REGISTRATION_H_81822a01_32cd_49ca_bca1_533fa9955cab

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
         * The constructor.
         */
        ITestRegistration() = default;

        /**
         * The destructor.
         */
        virtual ~ITestRegistration() = default;

        /**
         * The copy/move constructors.
         */
        ITestRegistration(const ITestRegistration&) = delete;
        ITestRegistration(ITestRegistration&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ITestRegistration& operator=(const ITestRegistration&) = delete;
        ITestRegistration& operator=(ITestRegistration&&) = delete;

        /**
         * Registers a test.
         */
        virtual void registerTest(ITestFunctionPtr testFunction) = 0;
    };
}

#endif // I_TEST_REGISTRATION_H_81822a01_32cd_49ca_bca1_533fa9955cab
