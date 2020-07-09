#ifndef UNIT_TEST_HANDLER_H_2086d3e4_1e3b_40ac_bb6b_388be533d172
#define UNIT_TEST_HANDLER_H_2086d3e4_1e3b_40ac_bb6b_388be533d172

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
    class UnitTestHandler final : public IUnitTestHandler, ITestRegistration
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
         * The copy/move constructors.
         */
        UnitTestHandler(const UnitTestHandler&) = delete;
        UnitTestHandler(UnitTestHandler&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        UnitTestHandler& operator=(const UnitTestHandler&) = delete;
        UnitTestHandler& operator=(UnitTestHandler&&) = delete;

        /**
         * Registers a test.
         */
        virtual void registerTest(ITestFunctionPtr testFunction) override;

        /**
         * Runs the unit test.
         */
        virtual const ITestRunningResults& run() override;

    private:
        /**
         * Processes a test.
         */
        void processTest(ITestFunction& unitTestFunction);

        /**
         * Runs a test.
         */
        bool runTest(ITestFunction& unitTestFunction, std::string& errorMessage);

        IUnitTest& m_unitTest;

        base::LogStreamWriter& m_logStreamWriter;

        using TestList = std::list<ITestFunctionPtr>;
        TestList m_unitTests;

        TestRunningResults m_unitTestRunningResults;
    };
}

#endif // UNIT_TEST_HANDLER_H_2086d3e4_1e3b_40ac_bb6b_388be533d172
