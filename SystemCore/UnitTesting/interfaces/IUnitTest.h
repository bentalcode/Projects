#ifndef I_UNIT_TEST_H_d86268d1_323b_4615_b062_2313f504fe9c
#define I_UNIT_TEST_H_d86268d1_323b_4615_b062_2313f504fe9c

#include "ITestRegistration.h"
#include "IMessageWriter.h"

namespace unit_testing
{
    //
    // Defines the SharedPtr of Unit Test...
    //
    class IUnitTest;
    using IUnitTestSharedPtr = std::shared_ptr<IUnitTest>;

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
        virtual const std::wstring& GetName() const = 0;

        /**
         * Registers tests of the unit test.
         */
        virtual void RegisterTests(ITestRegistration& registration) = 0;

        /**
         * Runs the logic of pre-running the tests.
         */
        virtual void PreRun() = 0;

        /**
         * Runs the logic post running the tests.
         */
        virtual void PostRun() = 0;

        /**
         * Sets the message writer.
         */
        virtual void SetMessageWriter(base::IMessageWriterSharedPtr messageWriter) = 0;
    };
}

#endif // I_UNIT_TEST_H_d86268d1_323b_4615_b062_2313f504fe9c
