#ifndef UNIT_TEST_HANDLER_H_abe00977_e2d2_4a34_9627_45b73ef9de43
#define UNIT_TEST_HANDLER_H_abe00977_e2d2_4a34_9627_45b73ef9de43

#include "IUnitTestHandler.h"
#include "ITestRegistration.h"
#include "IUnitTest.h"
#include "TestRunningResults.h"

namespace base {
    class DateTime;
}

namespace unit_testing
{
    /**
     * The UnitTestHandler class implements a handler for running a single unit test.
     */
    class UnitTestHandler: public IUnitTestHandler, ITestRegistration
    {
    public:
        /**
         * The UnitTestHandler constructor.
         */
        UnitTestHandler(
            IUnitTest& unitTest,
            base::LogStreamWriter& logStreamWriter);

        /**
         * The UnitTestHandler destructor.
         */
        virtual ~UnitTestHandler();

        /**
         * Registers a test.
         */
        virtual void registerTest(ITestFunctionPtr testFunction);

        /**
         * Runs the unit test.
         */
        virtual const ITestRunningResults& run();

    private:
        /**
         * Processes a test.
         */
        void processTest(ITestFunction& unitTestFunction);

        /**
         * Runs a test.
         */
        bool runTest(ITestFunction& unitTestFunction, std::string& errorMessage);

        /**
         * Disables the constructor and the assignment operator.
         */
        UnitTestHandler(const UnitTestHandler& rhs);
        UnitTestHandler& operator=(const UnitTestHandler& rhs);

        IUnitTest& m_unitTest;

        base::LogStreamWriter& m_logStreamWriter;

        typedef std::list<ITestFunctionPtr> TestList;
        TestList m_unitTests;

        TestRunningResults m_unitTestRunningResults;
    };
}

#endif // UNIT_TEST_HANDLER_H_abe00977_e2d2_4a34_9627_45b73ef9de43
