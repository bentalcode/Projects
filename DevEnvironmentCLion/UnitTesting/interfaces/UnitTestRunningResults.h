#ifndef UNIT_TEST_RUNNING_RESULTS_H_452435c5_7474_4592_849a_149cb8effe70
#define UNIT_TEST_RUNNING_RESULTS_H_452435c5_7474_4592_849a_149cb8effe70

#include "UnitTestRunningResult.h"

namespace test_base
{
    class IUnitTest;

    /**
     * The UnitTestRunningResults implements running results of unit tests.
     */
    class UnitTestRunningResults
    {
    public :
        UnitTestRunningResults();
        ~UnitTestRunningResults();

        /**
         * Sets a successful running result of a unit test.
         */
        void setSuccessfulRunningResult(IUnitTest& unitTest);

        /**
         * Sets a failed running result of a unit test
         */
        void setFailedRunningResult(IUnitTest& unitTest, const std::string& errorMessage);

        /**
         * Gets the information of the running results.
         */
        void getRunningResultsInformation(std::ostream& stream) const;

    private:
        int m_numberOfSuccessfulTests;
        int m_numberOfFailedTests;

        typedef std::list<UnitTestRunningResultPtr> UnitTestRunningResultList;
        UnitTestRunningResultList m_runningResults;
    };

    /**
     * Gets the information of the running results.
     */
    std::ostream& operator<<(std::ostream& stream, const UnitTestRunningResults& runningResults);
}

#endif // UNIT_TEST_RUNNING_RESULTS_H_452435c5_7474_4592_849a_149cb8effe70
