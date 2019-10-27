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
        IUnitTestManager() = default;
        virtual ~IUnitTestManager() = default;
        /**
         * Disables the copy constructor and assignment operator.
         */
        IUnitTestManager(const IUnitTestManager& rhs) = delete;
        IUnitTestManager& operator=(const IUnitTestManager& rhs) = delete;

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
    };
}

#endif // I_UNIT_TEST_MANAGER_H_aeec5f3c_e414_42d4_8fd3_6638bbbdca28
