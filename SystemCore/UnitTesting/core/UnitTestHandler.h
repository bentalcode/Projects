#ifndef UNIT_TEST_HANDLER_H_e7a28f85_7473_4a7c_95de_1f89dbff797f
#define UNIT_TEST_HANDLER_H_e7a28f85_7473_4a7c_95de_1f89dbff797f

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
            base::IMessageWriter& messageWriter);

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
        virtual void RegisterTest(ITestFunctionSharedPtr testFunction) override;

        /**
         * Runs the unit test.
         */
        virtual const ITestRunningResults& Run() override;

    private:
        /**
         * Processes a test.
         */
        void processTest(ITestFunction& unitTestFunction);

        /**
         * Runs a test.
         */
        bool runTest(ITestFunction& unitTestFunction, std::wstring& errorMessage);

        IUnitTest& m_unitTest;
        base::IMessageWriter& m_messageWriter;

        using TestList = std::list<ITestFunctionSharedPtr>;
        TestList m_unitTests;

        TestRunningResults m_unitTestRunningResults;
    };
}

#endif // UNIT_TEST_HANDLER_H_e7a28f85_7473_4a7c_95de_1f89dbff797f
