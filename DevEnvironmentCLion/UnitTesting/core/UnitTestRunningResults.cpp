#include "PreCompiled.h"

#include "UnitTestRunningResults.h"
#include "UnitTestRunningResult.h"
#include "IUnitTest.h"

using namespace unit_testing;

/**
 * The UnitTestRunningResults constructor.
 */
UnitTestRunningResults::UnitTestRunningResults() :
    m_numberOfSuccessfulTests(0),
    m_numberOfFailedTests(0)
{
}

/**
 * The UnitTestRunningResults destructor.
 */
UnitTestRunningResults::~UnitTestRunningResults()
{
}

/**
 * Sets a successful running result of a unit test.
 */
void UnitTestRunningResults::setSuccessfulRunningResult(const std::string& testName)
{
    IUnitTestRunningResultPtr runningResultPtr(new UnitTestRunningResult(
        testName,
        true,
        ""));

    m_runningResults.push_back(runningResultPtr);

    ++m_numberOfSuccessfulTests;
}

/**
 * Sets a failed running result of a unit test.
 */
void UnitTestRunningResults::setFailedRunningResult(
    const std::string& testName,
    const std::string& errorMessage)
{
    IUnitTestRunningResultPtr runningResultPtr(new UnitTestRunningResult(
        testName,
        false,
        errorMessage));

    m_runningResults.push_back(runningResultPtr);

    ++m_numberOfFailedTests;
}

/**
 * Gets the results.
 */
const IUnitTestRunningResultList& UnitTestRunningResults::getResults() const
{
    return m_runningResults;
}

/**
 * Gets the information of the running results.
 */
void UnitTestRunningResults::getRunningResultsInformation(std::ostream& stream) const
{
    stream << std::endl << "Running Results: " << std::endl;

    int index = 0;

    for (IUnitTestRunningResultList::const_iterator i = m_runningResults.begin(); i != m_runningResults.end(); ++i)
    {
        ++index;
        IUnitTestRunningResultPtr runningResultPtr = *i;
        stream << "[" << index << "] " << *runningResultPtr << std::endl;
    }

    stream << std::endl;
    stream << "Summary: " <<std::endl;
    stream << "Number of tests: " << m_runningResults.size() << std::endl;
    stream << "Number of passed tests: " << m_numberOfSuccessfulTests << std::endl;
    stream << "Number of failed tests: " << m_numberOfFailedTests << std::endl;
}

/**
 * Adds new running results.
 */
void UnitTestRunningResults::add(const IUnitTestRunningResults& results)
{
    const IUnitTestRunningResultList& runningResults = results.getResults();
    m_runningResults.insert(m_runningResults.end(), runningResults.begin(), runningResults.end());
}