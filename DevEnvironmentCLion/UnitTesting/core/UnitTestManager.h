#ifndef UNIT_TEST_MANAGER_H_7148c9a7_e860_42d9_83ed_9b3e22511389
#define UNIT_TEST_MANAGER_H_7148c9a7_e860_42d9_83ed_9b3e22511389

#include "IUnitTest.h"
#include "IUnitTestManager.h"
#include "TestRunningResults.h"

namespace unit_testing
{
    /**
     * The UnitTestManager class implements a unit test manager.
     */
    class UnitTestManager final : public IUnitTestManager
    {
    public:
        /**
         * The UnitTestManager default constructor.
         */
        UnitTestManager();

        /**
         * The UnitTestManager constructor.
         */
        explicit UnitTestManager(base::LogStreamWriterPtr logStreamWriter);

        /**
         * The UnitTestManager destructor.
         */
        virtual ~UnitTestManager();

        /**
         * Disables the constructor and the assignment operator.
         */
        UnitTestManager(const UnitTestManager& rhs) = delete;
        UnitTestManager& operator=(const UnitTestManager& rhs) = delete;

        /**
         * Registers a test.
         */
        virtual void registerTest(IUnitTestPtr unitTest) override;

        /**
         * Unregisters a test.
         */
        virtual void unregisterTest(IUnitTestPtr unitTest) override;

        /**
         * Runs the registered tests.
         */
        virtual void run() override;

    private:
        /**
         * Runs a unit test.
         */
        void runUnitTest(IUnitTest& unitTest);

        base::LogStreamWriterPtr m_logStreamWriter;

        using UnitTestList = std::list<IUnitTestPtr>;
        UnitTestList m_unitTests;

        TestRunningResults m_unitTestRunningResults;
    };
}

#endif // UNIT_TEST_MANAGER_H_7148c9a7_e860_42d9_83ed_9b3e22511389
