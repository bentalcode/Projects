#ifndef I_TEST_FUNCTION_H_fad4afe5_1383_4250_931e_0454b5f93fb5
#define I_TEST_FUNCTION_H_fad4afe5_1383_4250_931e_0454b5f93fb5

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
        ITestFunction() {}

        /**
         * The ITestFunction destructor.
         */
        virtual ~ITestFunction() {};

        /**
         * Runs the test.
         */
        virtual void operator()() = 0;
    };
}

#endif /* I_TEST_FUNCTION_H_fad4afe5_1383_4250_931e_0454b5f93fb5 */
