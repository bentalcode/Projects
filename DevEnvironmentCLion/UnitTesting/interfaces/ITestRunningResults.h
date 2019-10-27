#ifndef I_TEST_RUNNING_RESULTS_H_734c32ec_0eca_47c0_97c7_7a9f849037b7
#define I_TEST_RUNNING_RESULTS_H_734c32ec_0eca_47c0_97c7_7a9f849037b7

#include "ITestRunningResult.h"

namespace unit_testing
{
    class ITestRunningResults;
    typedef std::shared_ptr<ITestRunningResults> ITestRunningResultsPtr;

    typedef std::list<ITestRunningResultPtr> ITestRunningResultList;

    /**
     * The ITestRunningResults interface defines the results of tests.
     */
    class ITestRunningResults
    {
    public :
        ITestRunningResults() = default;
        virtual ~ITestRunningResults() = default;

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
        virtual DurationPtr getDuration() const = 0;

        /**
         * Gets the results.
         */
        virtual const ITestRunningResultList& getResults() const = 0;

        /**
         * Gets the information of the running results.
         */
        virtual void getRunningResultsInformation(std::ostream& stream) const = 0;
    };

    /**
     * Gets the information of the running results.
     */
    inline std::ostream& operator<<(std::ostream& stream, const ITestRunningResults& runningResults)
    {
        runningResults.getRunningResultsInformation(stream);
        return stream;
    }
}

#endif // I_TEST_RUNNING_RESULTS_H_734c32ec_0eca_47c0_97c7_7a9f849037b7
