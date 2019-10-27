#ifndef TEST_RUNNING_RESULTS_H_452435c5_7474_4592_849a_149cb8effe70
#define TEST_RUNNING_RESULTS_H_452435c5_7474_4592_849a_149cb8effe70

#include "ITestRunningResults.h"

namespace unit_testing
{
    /**
     * The TestRunningResults implements running results of tests.
     */
    class TestRunningResults final : public ITestRunningResults
    {
    public :
        TestRunningResults();
        virtual ~TestRunningResults();

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
        virtual DurationPtr getDuration() const override;

        /**
         * Gets the results.
         */
        virtual const ITestRunningResultList& getResults() const override;

        /**
         * Gets the information of the running results.
         */
        virtual void getRunningResultsInformation(std::ostream& stream) const override;

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

    private:
        int m_numberOfSuccessfulTests;
        int m_numberOfFailedTests;
        base::DateTimePtr m_startTime;
        base::DateTimePtr m_endTime;
        ITestRunningResultList m_runningResults;
    };
}

#endif // TEST_RUNNING_RESULTS_H_452435c5_7474_4592_849a_149cb8effe70
