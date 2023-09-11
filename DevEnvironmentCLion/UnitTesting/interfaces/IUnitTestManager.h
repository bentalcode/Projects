#ifndef I_UNIT_TEST_MANAGER_H_6212aaf5_a889_4733_94fd_d41b6193fbe0
#define I_UNIT_TEST_MANAGER_H_6212aaf5_a889_4733_94fd_d41b6193fbe0

namespace unit_testing
{
    /**
     * The IUnitTestManager interface defines a unit test manager.
     */
    class IUnitTestManager
    {
    public :
        /**
         * The constructor.
         */
        IUnitTestManager() = default;

        /**
         * The destructor.
         */
        virtual ~IUnitTestManager() = default;

        /**
         * The copy/move constructors.
         */
        IUnitTestManager(const IUnitTestManager&) = delete;
        IUnitTestManager(IUnitTestManager&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IUnitTestManager& operator=(const IUnitTestManager&) = delete;
        IUnitTestManager& operator=(IUnitTestManager&&) = delete;

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

#endif // I_UNIT_TEST_MANAGER_H_6212aaf5_a889_4733_94fd_d41b6193fbe0
