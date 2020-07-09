#ifndef I_TEST_FUNCTION_H_faf9b76c_58fb_499b_9b8a_95e7fe27db54
#define I_TEST_FUNCTION_H_faf9b76c_58fb_499b_9b8a_95e7fe27db54

#include "BaseDependencies.h"

namespace unit_testing {

    class ITestFunction;
    using ITestFunctionPtr = std::shared_ptr<ITestFunction>;

    /**
     * The ITestFunction interface defines a test function.
     */
    class ITestFunction
    {
    public:
        /**
         * The constructor.
         */
        ITestFunction() = default;

        /**
         * The destructor.
         */
        virtual ~ITestFunction() = default;

        /**
         * The copy/move constructors.
         */
        ITestFunction(const ITestFunction&) = delete;
        ITestFunction(ITestFunction&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ITestFunction& operator=(const ITestFunction&) = delete;
        ITestFunction& operator=(ITestFunction&&) = delete;

        /**
         * Gets the name of the test.
         */
        virtual const std::string& getName() const = 0;

        /**
         * Runs the test.
         */
        virtual void operator()() = 0;
    };
}

#endif // I_TEST_FUNCTION_H_faf9b76c_58fb_499b_9b8a_95e7fe27db54
