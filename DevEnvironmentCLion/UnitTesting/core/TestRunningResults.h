#ifndef TEST_RUNNING_RESULTS_H_2d82bc69_c581_46d3_84f0_d54192a60ee9
#define TEST_RUNNING_RESULTS_H_2d82bc69_c581_46d3_84f0_d54192a60ee9

#include "IConsoleColorHandler.h"
#include "ITestRunningResults.h"

namespace unit_testing
{
    /**
     * The TestRunningResults implements running results of tests.
     */
    class TestRunningResults final : public ITestRunningResults
    {
    public:
        /**
         * The constructor.
         */
        TestRunningResults();

        /**
         * The destructor.
         */
        virtual ~TestRunningResults();

        /**
         * The copy/move constructors.
         */
        TestRunningResults(const TestRunningResults&) = delete;
        TestRunningResults(TestRunningResults&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        TestRunningResults& operator=(const TestRunningResults&) = delete;
        TestRunningResults& operator=(TestRunningResults&&) = delete;

        /**
         * Gets the number of successful tests.
         */
        virtual int numberOfSuccessfulTests() const override;

        /**
         * Gets the number of failed tests.
         */
        virtual int numberOfFailedTests() const override;

        /**
         * Gets the start time of the tests.
         */
        virtual base::DateTimePtr getStartTime() const override;

        /**
         * Gets the end time of the tests.
         */
        virtual base::DateTimePtr getEndTime() const override;

        /**
         * Gets the duration of the tests.
         */
        virtual base::DurationPtr getDuration() const override;

        /**
         * Gets the results.
         */
        virtual const ITestRunningResultList& getResults() const override;

        /**
         * Sets the start time of the tests.
         */
        void setStartTime();

        /**
        * Sets the end time of the tests.
        */
        void setEndTime();

        /**
         * Sets a successful running result of a test.
         */
        void setSuccessfulRunningResult(
            const std::string& testName,
            const base::DateTime& startTime,
            const base::DateTime& endTime);

        /**
         * Sets a failed running result of a test
         */
        void setFailedRunningResult(
            const std::string& testName,
            const base::DateTime& startTime,
            const base::DateTime& endTime,
            const std::string& errorMessage);

        /**
         * Adds new running results.
         */
        void add(const ITestRunningResults& results);

        /**
         * Gets the string representation of this instance.
         */
        virtual std::string toString() const override;

        /**
         * Writes the result of the tests.
         */
        virtual void write(base::IMessageWriter& messageWriter) const override;

    private:
        int m_numberOfSuccessfulTests;
        int m_numberOfFailedTests;
        base::DateTimePtr m_startTime;
        base::DateTimePtr m_endTime;
        ITestRunningResultList m_runningResults;
    };
}

#endif // TEST_RUNNING_RESULTS_H_2d82bc69_c581_46d3_84f0_d54192a60ee9
