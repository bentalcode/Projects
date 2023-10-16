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
        virtual size_t NumberOfSuccessfulTests() const override;

        /**
         * Gets the number of failed tests.
         */
        virtual size_t NumberOfFailedTests() const override;

        /**
         * Gets the start time of the tests.
         */
        virtual base::DateTimeSharedPtr GetStartTime() const override;

        /**
         * Gets the end time of the tests.
         */
        virtual base::DateTimeSharedPtr GetEndTime() const override;

        /**
         * Gets the duration of the tests.
         */
        virtual base::DurationSharedPtr GetDuration() const override;

        /**
         * Gets the results.
         */
        virtual const ITestRunningResultList& GetResults() const override;

        /**
         * Sets the start time of the tests.
         */
        void SetStartTime();

        /**
        * Sets the end time of the tests.
        */
        void SetEndTime();

        /**
         * Sets a successful running result of a test.
         */
        void SetSuccessfulRunningResult(
            const std::wstring& testName,
            const base::DateTime& startTime,
            const base::DateTime& endTime);

        /**
         * Sets a failed running result of a test
         */
        void SetFailedRunningResult(
            const std::wstring& testName,
            const base::DateTime& startTime,
            const base::DateTime& endTime,
            const std::wstring& errorMessage);

        /**
         * Adds new running results.
         */
        void Add(const ITestRunningResults& results);

        /**
         * Gets the string representation of this instance.
         */
        virtual std::wstring ToString() const override;

        /**
         * Writes the result of the tests.
         */
        virtual void Write(base::IMessageWriter& messageWriter) const override;

    private:
        size_t m_numberOfSuccessfulTests;
        size_t m_numberOfFailedTests;
        base::DateTimeSharedPtr m_startTime;
        base::DateTimeSharedPtr m_endTime;
        ITestRunningResultList m_runningResults;
    };
}

#endif // TEST_RUNNING_RESULTS_H_2d82bc69_c581_46d3_84f0_d54192a60ee9
