#ifndef I_UNIT_TEST_MANAGER_H_aeec5f3c_e414_42d4_8fd3_6638bbbdca28
#define I_UNIT_TEST_MANAGER_H_aeec5f3c_e414_42d4_8fd3_6638bbbdca28

namespace unit_testing
{
    /**
     * The IUnitTestManager interface defines a unit test manager.
     */
    class IUnitTestManager
    {
    public :
        IUnitTestManager() {};
        virtual ~IUnitTestManager() {};

        /**
         * Registers a test.
         */
        virtual void registerTest(IUnitTestPtr unitTest) = 0;

        /**
         * Unregisters a test.
         */
        virtual void unregisterTest(IUnitTestPtr unitTest) = 0;

        /**
         * Runs the registered tests.
         */
        virtual void run() = 0;

    private:
        /**
         * Disables the constructor and the assignment operator.
         */
        IUnitTestManager(const IUnitTestManager& rhs);
        IUnitTestManager& operator=(const IUnitTestManager& rhs);
    };
}

#endif // I_UNIT_TEST_MANAGER_H_aeec5f3c_e414_42d4_8fd3_6638bbbdca28
