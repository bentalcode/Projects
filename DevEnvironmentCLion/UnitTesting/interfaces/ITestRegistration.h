#ifndef I_TEST_REGISTRATION_H_f934f9a4_5f37_45bb_bc19_f7731eb5b394
#define I_TEST_REGISTRATION_H_f934f9a4_5f37_45bb_bc19_f7731eb5b394

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

#endif // I_TEST_REGISTRATION_H_f934f9a4_5f37_45bb_bc19_f7731eb5b394
