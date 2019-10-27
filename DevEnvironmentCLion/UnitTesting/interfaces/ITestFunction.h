#ifndef I_TEST_FUNCTION_H_fad4afe5_1383_4250_931e_0454b5f93fb5
#define I_TEST_FUNCTION_H_fad4afe5_1383_4250_931e_0454b5f93fb5

#include "BaseDependencies.h"

namespace unit_testing {

    class ITestFunction;
    typedef std::shared_ptr<ITestFunction> ITestFunctionPtr;

    /**
     * The ITestFunction interface defines a test function.
     */
    class ITestFunction {
    public:
        /**
         * The ITestFunction constructor.
         */
        ITestFunction() = default;

        /**
         * The ITestFunction destructor.
         */
        virtual ~ITestFunction() = default;

        /**
         * Disables the copy constructor and assignment operator.
         */
        ITestFunction(const ITestFunction& rhs) = delete;
        ITestFunction& operator=(const ITestFunction& rhs) = delete;

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

#endif /* I_TEST_FUNCTION_H_fad4afe5_1383_4250_931e_0454b5f93fb5 */
