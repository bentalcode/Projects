#ifndef I_UNIT_TEST_H_d86268d1_323b_4615_b062_2313f504fe9c
#define I_UNIT_TEST_H_d86268d1_323b_4615_b062_2313f504fe9c

#include "ITestRegistration.h"
#include "IMessageWriter.h"

namespace unit_testing
{
    class IUnitTest;
    using IUnitTestPtr = std::shared_ptr<IUnitTest>;

    /**
     * The IUnitTest interface defines a unit test.
     */
    class IUnitTest
    {
    public :
        /**
         * The constructor.
         */
        IUnitTest() = default;

        /**
         * The destructor.
         */
        virtual ~IUnitTest() = default;

        /**
         * The copy/move constructors.
         */
        IUnitTest(const IUnitTest&) = delete;
        IUnitTest(IUnitTest&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IUnitTest& operator=(const IUnitTest&) = delete;
        IUnitTest& operator=(IUnitTest&&) = delete;

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
         * Sets the message writer.
         */
        virtual void setMessageWriter(base::IMessageWriterPtr messageWriter) = 0;
    };
}

#endif // I_UNIT_TEST_H_d86268d1_323b_4615_b062_2313f504fe9c
