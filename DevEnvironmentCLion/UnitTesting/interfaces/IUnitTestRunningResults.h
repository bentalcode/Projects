#ifndef I_UNIT_TEST_RUNNING_RESULTS_H_734c32ec_0eca_47c0_97c7_7a9f849037b7
#define I_UNIT_TEST_RUNNING_RESULTS_H_734c32ec_0eca_47c0_97c7_7a9f849037b7

#include "IUnitTestRunningResult.h"

namespace unit_testing
{
    class IUnitTestRunningResults;
    typedef std::shared_ptr<IUnitTestRunningResults> IUnitTestRunningResultsPtr;

    typedef std::list<IUnitTestRunningResultPtr> IUnitTestRunningResultList;

    /**
     * The IUnitTestRunningResults interface defines the results of unit tests.
     */
    class IUnitTestRunningResults
    {
    public :
        IUnitTestRunningResults();
        virtual ~IUnitTestRunningResults();

        /**
         * Gets the results.
         */
        virtual const IUnitTestRunningResultList& getResults() const = 0;

        /**
         * Gets the information of the running results.
         */
        virtual void getRunningResultsInformation(std::ostream& stream) const = 0;
    };

    /**
     * The IUnitTestRunningResults constructor.
     */
    inline IUnitTestRunningResults::IUnitTestRunningResults()
    {
    }

    /**
     * The IUnitTestRunningResults destructor.
     */
    inline IUnitTestRunningResults::~IUnitTestRunningResults()
    {
    }

    /**
     * Gets the information of the running results.
     */
    inline std::ostream& operator<<(std::ostream& stream, const IUnitTestRunningResults& runningResults)
    {
        runningResults.getRunningResultsInformation(stream);
        return stream;
    }
}

#endif // I_UNIT_TEST_RUNNING_RESULTS_H_734c32ec_0eca_47c0_97c7_7a9f849037b7
