#ifndef UNIT_TEST_BASE_H_9d7b131d_8eec_47f4_bdfd_07b981f91491
#define UNIT_TEST_BASE_H_9d7b131d_8eec_47f4_bdfd_07b981f91491

#include "IUnitTest.h"
#include "Assertion.h"

namespace unit_testing {
    /**
     * The UnitTestBase class implements a unit test.
     */
    class UnitTestBase : public IUnitTest
    {
    public:
        /**
         * The UnitTestBase constructor.
         */
        explicit UnitTestBase(const std::string& name);

        /**
         * The UnitTestBase destructor.
         */
        virtual ~UnitTestBase();

        /**
         * Gets the name of the unit test.
         */
        virtual const std::string& getName() const override;

        /**
         * Runs the logic pre-running the tests.
         */
        virtual void preRun() override;

        /**
         * Runs the logic post running the tests.
         */
        virtual void postRun() override;

        /**
         * Sets the log stream writer.
         */
        virtual void setLogStreamWriter(base::LogStreamWriterPtr logStreamWriter) override;

    protected:
        /**
         * Gets the assertion.
         */
        test_base::Assertion& getAssertion();

        /**
         * Gets the log stream writer.
         */
        base::LogStreamWriter& getLogStreamWriter();

    private:
        std::string m_name;
        test_base::Assertion m_assertion;
        base::LogStreamWriterPtr m_logStreamWriter;
    };
}

#endif /* UNIT_TEST_BASE_H_9d7b131d_8eec_47f4_bdfd_07b981f91491 */
