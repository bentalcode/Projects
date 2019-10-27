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
        IUnitTestHandler() = default;
        virtual ~IUnitTestHandler() = default;

        /**
         * Disables the copy constructor and assignment operator.
         */
        IUnitTestHandler(const IUnitTestHandler& rhs) = delete;
        IUnitTestHandler& operator=(const IUnitTestHandler& rhs) = delete;

        /**
         * Runs the unit test.
         */
        virtual const ITestRunningResults& run() = 0;
    };
}

#endif // I_UNIT_TEST_HANDLER_H_468be4fa_4f37_478b_8e29_79004d0ad18a
