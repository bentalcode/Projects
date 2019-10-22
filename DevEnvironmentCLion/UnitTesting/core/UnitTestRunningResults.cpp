#include "PreCompiled.h"

#include "UnitTestRunningResults.h"
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
void UnitTestRunningResults::setSuccessfulRunningResult(IUnitTest& unitTest)
{
    UnitTestRunningResultPtr runningResultPtr(new UnitTestRunningResult(
        unitTest.getName(),
        true,
        ""));

    m_runningResults.push_back(runningResultPtr);

    ++m_numberOfSuccessfulTests;
}

/**
 * Sets a failed running result of a unit test.
 */
void UnitTestRunningResults::setFailedRunningResult(
    IUnitTest& unitTest,
    const std::string& errorMessage)
{
    UnitTestRunningResultPtr runningResultPtr(new UnitTestRunningResult(
        unitTest.getName(),
        false,
        errorMessage));

    m_runningResults.push_back(runningResultPtr);

    ++m_numberOfFailedTests;
}

/**
 * Gets the information of the running results.
 */
void UnitTestRunningResults::getRunningResultsInformation(std::ostream& stream) const
{
    stream << std::endl << "Running Results: " << std::endl;

    int index = 0;

    for (UnitTestRunningResultList::const_iterator i = m_runningResults.begin(); i != m_runningResults.end(); ++i)
    {
        ++index;
        UnitTestRunningResultPtr runningResultPtr = *i;
        stream << "[" << index << "] " << *runningResultPtr << std::endl;
    }

    stream << std::endl;
    stream << "Summary: " <<std::endl;
    stream << "Number of tests: " << m_runningResults.size() << std::endl;
    stream << "Number of passed tests: " << m_numberOfSuccessfulTests << std::endl;
    stream << "Number of failed tests: " << m_numberOfFailedTests << std::endl;
}

/**
 * Gets the information of the running results.
 */
std::ostream& unit_testing::operator<<(std::ostream& stream, const UnitTestRunningResults& runningResults)
{
    runningResults.getRunningResultsInformation(stream);
    return stream;
}

