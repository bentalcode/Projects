#ifndef UNIT_TEST_BASE_H_9d7b131d_8eec_47f4_bdfd_07b981f91491
#define UNIT_TEST_BASE_H_9d7b131d_8eec_47f4_bdfd_07b981f91491

#include "IUnitTest.h"

namespace test_base {
    /**
     * The UnitTestBase class implements a unit test.
     */
    class UnitTestBase : public IUnitTest {
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
         * Gets the name of the test.
         */
        virtual const std::string& getName() const;

        /**
         * Runs the logic pre-running the test.
         */
        virtual void preRun();

        /**
         * Runs the logic post running the test.
         */
        virtual void postRun();

        /**
         * Sets the output stream.
         */
        virtual void setOutputStream(std::ostream &stream);

    protected:
        /**
         * Gets the informational stream.
         */
        std::ostream& getInformationalStream() const;

        /**
         * Gets the warning stream.
         */
        std::ostream& getWarningStream() const;

        /**
         * Gets the error stream.
         */
        std::ostream& getErrorStream() const;

    private:
        std::string m_name;
        std::ostream* m_stream;
    };
}

#endif /* UNIT_TEST_BASE_H_9d7b131d_8eec_47f4_bdfd_07b981f91491 */
