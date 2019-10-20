#ifndef I_UNIT_TEST_H_eaebb607_7774_468b_a819_7e49bd38e777
#define I_UNIT_TEST_H_eaebb607_7774_468b_a819_7e49bd38e777

#include "LogStreamWriter.h"

namespace test_base
{
    class IUnitTest;
    typedef std::shared_ptr<IUnitTest> IUnitTestPtr;

    /**
     * The IUnitTest interface defines a unit test.
     */
    class IUnitTest
    {
    public :
        IUnitTest();
        virtual ~IUnitTest();

        /**
         * Gets the name of the test.
         */
        virtual const std::string& getName() const = 0;

        /**
         * Runs the logic of pre-running the test.
         */
        virtual void preRun() = 0;

        /**
         * Runs the logic of the test.
         */
        virtual void run() = 0;

        /**
         * Runs the logic post running the test.
         */
        virtual void postRun() = 0;

        /**
         * Sets the log stream writer.
         */
        virtual void setLogStreamWriter(base::LogStreamWriterPtr logStreamWriter) = 0;

    private:
        /**
         * Disables the constructor and the assignment operator.
         */
        IUnitTest(const IUnitTest& rhs);
        IUnitTest& operator=(const IUnitTest& rhs);
    };

    /**
     * The IUnitTest constructor.
     */
    inline IUnitTest::IUnitTest()
    {
    }

    /**
     * The IUnitTest destructor.
     */
    inline IUnitTest::~IUnitTest()
    {
    }
}

#endif // I_UNIT_TEST_H_eaebb607_7774_468b_a819_7e49bd38e777
