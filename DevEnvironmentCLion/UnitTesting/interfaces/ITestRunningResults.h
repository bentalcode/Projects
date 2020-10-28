#ifndef I_TEST_RUNNING_RESULTS_H_15064a1c_72bb_4089_a240_8dd37b54a382
#define I_TEST_RUNNING_RESULTS_H_15064a1c_72bb_4089_a240_8dd37b54a382

#include "ITestRunningResult.h"
#include "IMessageWriter.h"

namespace unit_testing
{
    class ITestRunningResults;
    using ITestRunningResultsPtr = std::shared_ptr<ITestRunningResults>;

    using ITestRunningResultList = std::list<ITestRunningResultPtr>;

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
        virtual int numberOfSuccessfulTests() const = 0;

        /**
         * Gets the number of failed tests.
         */
        virtual int numberOfFailedTests() const = 0;

        /**
         * Gets the start time of the tests.
         */
        virtual base::DateTimePtr getStartTime() const = 0;

        /**
         * Gets the end time of the tests.
         */
        virtual base::DateTimePtr getEndTime() const = 0;

        /**
         * Gets the duration of the tests.
         */
        virtual base::DurationPtr getDuration() const = 0;

        /**
         * Gets the results.
         */
        virtual const ITestRunningResultList& getResults() const = 0;

        /**
         * Gets the string representation of this instance.
         */
        virtual std::string toString() const = 0;

        /**
         * Writes the result of the tests.
         */
        virtual void write(base::IMessageWriter& messageWriter) const = 0;
    };

    /**
     * Gets the information of the running results.
     */
    inline std::ostream& operator<<(std::ostream& stream, const ITestRunningResults& runningResults)
    {
        std::string string = runningResults.toString();
        stream << string;
        return stream;
    }
}

#endif // I_TEST_RUNNING_RESULTS_H_15064a1c_72bb_4089_a240_8dd37b54a382
