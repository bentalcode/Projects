#ifndef I_UNIT_TEST_HANDLER_H_468be4fa_4f37_478b_8e29_79004d0ad18a
#define I_UNIT_TEST_HANDLER_H_468be4fa_4f37_478b_8e29_79004d0ad18a

#include "ITestRunningResults.h"

namespace unit_testing
{
    /**
     * The IUnitTestHandler interface defines a handler for running a single unit test.
     */
    class IUnitTestHandler
    {
    public :
        /**
         * The constructor.
         */
        IUnitTestHandler() = default;

        /**
         * The destructor.
         */
        virtual ~IUnitTestHandler() = default;

        /**
         * The copy/move constructors.
         */
        IUnitTestHandler(const IUnitTestHandler&) = delete;
        IUnitTestHandler(IUnitTestHandler&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IUnitTestHandler& operator=(const IUnitTestHandler&) = delete;
        IUnitTestHandler& operator=(IUnitTestHandler&&) = delete;

        /**
         * Runs the unit test.
         */
        virtual const ITestRunningResults& run() = 0;
    };
}

#endif // I_UNIT_TEST_HANDLER_H_468be4fa_4f37_478b_8e29_79004d0ad18a
