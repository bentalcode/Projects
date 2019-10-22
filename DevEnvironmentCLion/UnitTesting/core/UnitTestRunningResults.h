#ifndef UNIT_TEST_RUNNING_RESULTS_H_452435c5_7474_4592_849a_149cb8effe70
#define UNIT_TEST_RUNNING_RESULTS_H_452435c5_7474_4592_849a_149cb8effe70

#include "IUnitTestRunningResults.h"

namespace unit_testing
{
    class IUnitTest;

    /**
     * The UnitTestRunningResults implements running results of unit tests.
     */
    class UnitTestRunningResults : public IUnitTestRunningResults
    {
    public :
        UnitTestRunningResults();
        virtual ~UnitTestRunningResults();

        /**
         * Sets a successful running result of a unit test.
         */
        void setSuccessfulRunningResult(const std::string& testName);

        /**
         * Sets a failed running result of a unit test
         */
        void setFailedRunningResult(const std::string& testName, const std::string& errorMessage);

        /**
         * Gets the results.
         */
        virtual const IUnitTestRunningResultList& getResults() const;

        /**
         * Gets the information of the running results.
         */
        virtual void getRunningResultsInformation(std::ostream& stream) const;

        /**
         * Adds new running results.
         */
        void add(const IUnitTestRunningResults& results);

    private:
        int m_numberOfSuccessfulTests;
        int m_numberOfFailedTests;

        IUnitTestRunningResultList m_runningResults;
    };
}

#endif // UNIT_TEST_RUNNING_RESULTS_H_452435c5_7474_4592_849a_149cb8effe70
