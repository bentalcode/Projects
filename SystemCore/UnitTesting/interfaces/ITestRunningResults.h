#ifndef I_TEST_RUNNING_RESULTS_H_15064a1c_72bb_4089_a240_8dd37b54a382
#define I_TEST_RUNNING_RESULTS_H_15064a1c_72bb_4089_a240_8dd37b54a382

#include "ITestRunningResult.h"
#include "IMessageWriter.h"
#include <list>

namespace unit_testing
{
    //
    // Defines the SharedPtr of Test Running Results...
    //
    class ITestRunningResults;
    using ITestRunningResultsSharedPtr = std::shared_ptr<ITestRunningResults>;

    using ITestRunningResultList = std::list<ITestRunningResultSharedPtr>;

    /**
     * The ITestRunningResults interface defines the results of tests.
     */
    class ITestRunningResults
    {
    public :
        ITestRunningResults() = default;
        virtual ~ITestRunningResults() = default;

        /**
         * The copy/move constructors.
         */
        ITestRunningResults(const ITestRunningResults&) = delete;
        ITestRunningResults(ITestRunningResults&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        ITestRunningResults& operator=(const ITestRunningResults&) = delete;
        ITestRunningResults& operator=(ITestRunningResults&&) = delete;

        /**
         * Gets the number of successful tests.
         */
        virtual size_t NumberOfSuccessfulTests() const = 0;

        /**
         * Gets the number of failed tests.
         */
        virtual size_t NumberOfFailedTests() const = 0;

        /**
         * Gets the start time of the tests.
         */
        virtual base::DateTimeSharedPtr GetStartTime() const = 0;

        /**
         * Gets the end time of the tests.
         */
        virtual base::DateTimeSharedPtr GetEndTime() const = 0;

        /**
         * Gets the duration of the tests.
         */
        virtual base::DurationSharedPtr GetDuration() const = 0;

        /**
         * Gets the results.
         */
        virtual const ITestRunningResultList& GetResults() const = 0;

        /**
         * Gets the string representation of this instance.
         */
        virtual std::wstring ToString() const = 0;

        /**
         * Writes the result of the tests.
         */
        virtual void Write(base::IMessageWriter& messageWriter) const = 0;
    };

    /**
     * Gets the information of the running results.
     */
    inline std::wostream& operator<<(std::wostream& stream, const ITestRunningResults& runningResults)
    {
        std::wstring string = runningResults.ToString();
        stream << string;
        return stream;
    }
}

#endif // I_TEST_RUNNING_RESULTS_H_15064a1c_72bb_4089_a240_8dd37b54a382
