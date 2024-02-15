#ifndef UNIT_TEST_MANAGER_H_f04f0b91_37ae_4bad_860a_c20bdfe39065
#define UNIT_TEST_MANAGER_H_f04f0b91_37ae_4bad_860a_c20bdfe39065

#include "IUnitTest.h"
#include "IUnitTestManager.h"
#include "TestRunningResults.h"

namespace unit_testing
{
    /**
     * The UnitTestManager class implements a unit Test manager.
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
        explicit UnitTestManager(base::IMessageWriterSharedPtr messageWriter);

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
         * Registers a Test.
         */
        virtual void RegisterTest(IUnitTestSharedPtr unitTest) override;

        /**
         * Unregisters a Test.
         */
        virtual void UnRegisterTest(IUnitTestSharedPtr unitTest) override;

        /**
         * Runs the registered tests.
         */
        virtual void Run() override;

    private:
        /**
         * Runs a unit Test.
         */
        void runUnitTest(IUnitTest& unitTest);

        base::IMessageWriterSharedPtr m_messageWriter;

        using UnitTestList = std::list<IUnitTestSharedPtr>;
        UnitTestList m_unitTests;

        TestRunningResults m_unitTestRunningResults;
    };
}

#endif // UNIT_TEST_MANAGER_H_f04f0b91_37ae_4bad_860a_c20bdfe39065
