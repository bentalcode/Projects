#ifndef I_UNIT_TEST_H_eaebb607_7774_468b_a819_7e49bd38e777
#define I_UNIT_TEST_H_eaebb607_7774_468b_a819_7e49bd38e777

#include "ITestRegistration.h"
#include "LogStreamWriter.h"

namespace unit_testing
{
    class IUnitTest;
    typedef std::shared_ptr<IUnitTest> IUnitTestPtr;

    /**
     * The IUnitTest interface defines a unit test.
     */
    class IUnitTest
    {
    public :
        IUnitTest() = default;
        virtual ~IUnitTest() = default;

        /**
         * Disables the copy constructor and assignment operator.
         */
        IUnitTest(const IUnitTest& rhs) = delete;
        IUnitTest& operator=(const IUnitTest& rhs) = delete;

        /**
         * Gets the name of the unit test.
         */
        virtual const std::string& getName() const = 0;

        /**
         * Registers tests of the unit test.
         */
        virtual void registerTests(ITestRegistration& registration) = 0;

        /**
         * Runs the logic of pre-running the tests.
         */
        virtual void preRun() = 0;

        /**
         * Runs the logic post running the tests.
         */
        virtual void postRun() = 0;

        /**
         * Sets the log stream writer.
         */
        virtual void setLogStreamWriter(base::LogStreamWriterPtr logStreamWriter) = 0;
    };
}

#endif // I_UNIT_TEST_H_eaebb607_7774_468b_a819_7e49bd38e777
