#include "PreCompiled.h"

#include "TestRunningResults.h"
#include "TestRunningResult.h"
#include "UnitTestingConsts.h"

using namespace unit_testing;

/**
 * The TestRunningResults constructor.
 */
TestRunningResults::TestRunningResults() :
    m_numberOfSuccessfulTests(0),
    m_numberOfFailedTests(0)
{
}

/**
 * The TestRunningResults destructor.
 */
TestRunningResults::~TestRunningResults()
{
}

/**
 * Gets the number of successful tests.
 */
size_t TestRunningResults::numberOfSuccessfulTests() const
{
    return m_numberOfSuccessfulTests;
}

/**
 * Gets the number of failed tests.
 */
size_t TestRunningResults::numberOfFailedTests() const
{
    return m_numberOfFailedTests;
}

/**
 * Gets the start time of the tests.
 */
base::DateTimePtr TestRunningResults::getStartTime() const
{
    return m_startTime;
}

/**
 * Gets the end time of the tests.
 */
base::DateTimePtr TestRunningResults::getEndTime() const
{
    return m_endTime;
}

/**
 * Gets the duration of the tests.
 */
base::DurationPtr TestRunningResults::getDuration() const
{
    if (!m_startTime || !m_endTime)
    {
        return nullptr;
    }

    return base::Duration::between(*m_startTime, *m_endTime);
}

/**
 * Gets the results.
 */
const ITestRunningResultList& TestRunningResults::getResults() const
{
    return m_runningResults;
}

/**
 * Sets the start time of the tests.
 */
void TestRunningResults::setStartTime()
{
    m_startTime.reset(new base::DateTime(base::DateTime::currentTimePoint()));
}

/**
 * Sets the end time of the tests.
 */
void TestRunningResults::setEndTime()
{
    m_endTime.reset(new base::DateTime(base::DateTime::currentTimePoint()));
}

/**
 * Sets a successful running result of a unit test.
 */
void TestRunningResults::setSuccessfulRunningResult(
    const std::string& testName,
    const base::DateTime& startTime,
    const base::DateTime& endTime)
{
    ITestRunningResultPtr runningResultPtr(new TestRunningResult(
        testName,
        startTime,
        endTime,
        true,
        ""));

    m_runningResults.push_back(runningResultPtr);

    ++m_numberOfSuccessfulTests;
}

/**
 * Sets a failed running result of a unit test.
 */
void TestRunningResults::setFailedRunningResult(
    const std::string& testName,
    const base::DateTime& startTime,
    const base::DateTime& endTime,
    const std::string& errorMessage)
{
    ITestRunningResultPtr runningResultPtr(new TestRunningResult(
        testName,
        startTime,
        endTime,
        false,
        errorMessage));

    m_runningResults.push_back(runningResultPtr);

    ++m_numberOfFailedTests;
}

/**
 * Adds new running results.
 */
void TestRunningResults::add(const ITestRunningResults& results)
{
    const ITestRunningResultList& runningResults = results.getResults();
    m_runningResults.insert(m_runningResults.end(), runningResults.begin(), runningResults.end());

    m_numberOfSuccessfulTests += results.numberOfSuccessfulTests();
    m_numberOfFailedTests += results.numberOfFailedTests();
}

/**
 * Gets the string representation of this instance.
 */
std::string TestRunningResults::toString() const
{
    std::stringstream stream;

    stream << "Running Results: " << std::endl;

    size_t index = 0;

    for (ITestRunningResultPtr runningResultPtr : m_runningResults)
    {
        ++index;
        stream << "[" << index << "] " << *runningResultPtr << std::endl << std::endl;
    }

    stream << "Summary: " << std::endl;
    stream << "Number of tests: " << m_runningResults.size() << std::endl;
    stream << "Number of passed tests: " << m_numberOfSuccessfulTests << std::endl;
    stream << "Number of failed tests: " << m_numberOfFailedTests << std::endl;

    if (m_startTime && m_endTime)
    {
        stream << "Start Time: " << *m_startTime << std::endl;
        stream << "End Time: " << *m_endTime << std::endl;
        stream << "Duration Time: " << *getDuration() << std::endl;
    }

    return stream.str();
}

/**
 * Writes the console color handler.
 */
void TestRunningResults::write(base::IMessageWriter& messageWriter) const
{
    std::stringstream testResultsStartStream;
    testResultsStartStream
        << UnitTestingConsts::testResultsStart << std::endl
        << "Running Results: ";

    messageWriter.writeInformationalMessage(testResultsStartStream.str());

    size_t index = 0;

    for (ITestRunningResultPtr testRunningResultPtr : m_runningResults)
    {
        ++index;
        std::stringstream testResultStream;
        testResultStream << "[" << index << "] " << testRunningResultPtr->toString() << std::endl;

        std::string testResult = testResultStream.str();

        if (testRunningResultPtr->getResultStatus())
        {
            messageWriter.writeInformationalMessage(testResult);
        }
        else
        {
            messageWriter.writeErrorMessage(testResult);
        }
    }

    std::stringstream testResultsEndStream;
    testResultsEndStream << std::endl;
    testResultsEndStream << "Summary: " << std::endl;
    testResultsEndStream << "Number of tests: " << m_runningResults.size() << std::endl;
    testResultsEndStream << "Number of passed tests: " << m_numberOfSuccessfulTests << std::endl;
    testResultsEndStream << "Number of failed tests: " << m_numberOfFailedTests << std::endl;

    if (m_startTime && m_endTime)
    {
        testResultsEndStream << "Start Time: " << *m_startTime << std::endl;
        testResultsEndStream << "End Time: " << *m_endTime << std::endl;
        testResultsEndStream << "Duration Time: " << *getDuration() << std::endl;
    }

    testResultsEndStream << UnitTestingConsts::testResultsEnd << std::endl;

    messageWriter.writeInformationalMessage(testResultsEndStream.str());
}
