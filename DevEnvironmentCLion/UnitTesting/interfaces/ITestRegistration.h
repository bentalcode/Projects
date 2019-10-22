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
        ITestRegistration();
        virtual ~ITestRegistration();

        /**
         * Registers a test.
         */
        virtual void registerTest(ITestFunctionPtr testFunction) = 0;

    private:
        /**
         * Disables the constructor and the assignment operator.
         */
        ITestRegistration(const ITestRegistration& rhs);
        ITestRegistration& operator=(const ITestRegistration& rhs);
    };

    /**
     * The ITestRegistration constructor.
     */
    inline ITestRegistration::ITestRegistration()
    {
    }

    /**
     * The ITestRegistration destructor.
     */
    inline ITestRegistration::~ITestRegistration()
    {
    }
}

#endif // I_TEST_REGISTRATION_H_c0ed3a41_f212_4b3a_81e0_8ddb907c399d
