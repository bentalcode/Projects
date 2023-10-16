#ifndef I_UNIT_TEST_HANDLER_H_8ad3fa43_c2d0_4be1_84cb_19b1b8b67a87
#define I_UNIT_TEST_HANDLER_H_8ad3fa43_c2d0_4be1_84cb_19b1b8b67a87

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
        virtual const ITestRunningResults& Run() = 0;
    };
}

#endif // I_UNIT_TEST_HANDLER_H_8ad3fa43_c2d0_4be1_84cb_19b1b8b67a87
