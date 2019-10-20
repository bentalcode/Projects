#ifndef UNIT_TEST_MANAGER_H_7148c9a7_e860_42d9_83ed_9b3e22511389
#define UNIT_TEST_MANAGER_H_7148c9a7_e860_42d9_83ed_9b3e22511389

#include "IUnitTest.h"
#include "IUnitTestManager.h"
#include "UnitTestRunningResults.h"

namespace test_base
{
    /**
     * The UnitTestManager class implements a unit test manager.
     */
    class UnitTestManager : public IUnitTestManager
    {
    public :
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
         * Registers a test.
         */
        virtual void registerTest(IUnitTestPtr unitTest);

        /**
         * Unregisters a test.
         */
        virtual void unregisterTest(IUnitTestPtr unitTest);

        /**
         * Runs the registered tests.
         */
        virtual void run();

    private:
        /**
         * Runs a test.
         */
        void runTest(IUnitTest& unitTest);

        /**
         * Sets a successful running result of a unit test
         */
        void setSuccessfulRunningResult(IUnitTest& unitTest);

        /**
         * Sets a failed running result of a unit test
        */
        void setFailedRunningResult(IUnitTest& unitTest, const std::string& errorMessage);

        /**
         * Disables the constructor and the assignment operator.
         */
        UnitTestManager(const UnitTestManager& rhs);
        UnitTestManager& operator=(const UnitTestManager& rhs);

        base::LogStreamWriterPtr m_logStreamWriter;

        typedef std::list<IUnitTestPtr> UnitTestList;
        UnitTestList m_unitTests;

        UnitTestRunningResults m_unitTestRunningResults;
    };
}

#endif // UNIT_TEST_MANAGER_H_7148c9a7_e860_42d9_83ed_9b3e22511389
