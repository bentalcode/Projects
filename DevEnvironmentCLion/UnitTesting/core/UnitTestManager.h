#ifndef UNIT_TEST_MANAGER_H_f04f0b91_37ae_4bad_860a_c20bdfe39065
#define UNIT_TEST_MANAGER_H_f04f0b91_37ae_4bad_860a_c20bdfe39065

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
         * The default constructor.
         */
        UnitTestManager();

        /**
         * The constructor.
         */
        explicit UnitTestManager(base::LogStreamWriterPtr logStreamWriter);

        /**
         * The destructor.
         */
        virtual ~UnitTestManager();

        /**
         * The copy/move constructors.
         */
        UnitTestManager(const UnitTestManager&) = delete;
        UnitTestManager(UnitTestManager&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        UnitTestManager& operator=(const UnitTestManager&) = delete;
        UnitTestManager& operator=(UnitTestManager&&) = delete;

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

#endif // UNIT_TEST_MANAGER_H_f04f0b91_37ae_4bad_860a_c20bdfe39065
