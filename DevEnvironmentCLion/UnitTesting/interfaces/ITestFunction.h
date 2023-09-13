#ifndef I_TEST_FUNCTION_H_c08315bb_91d9_4184_8256_97c54ce7d12e
#define I_TEST_FUNCTION_H_c08315bb_91d9_4184_8256_97c54ce7d12e

#include "BaseDependencies.h"

namespace unit_testing {

    //
    // Defines the SharedPtr of Test Function...
    //
    class ITestFunction;
    using ITestFunctionSharedPtr = std::shared_ptr<ITestFunction>;

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

#endif // I_TEST_FUNCTION_H_c08315bb_91d9_4184_8256_97c54ce7d12e
