#include "TestRunningResults.h"
#include "TestRunningResult.h"
#include "UnitTestingConsts.h"
#include <sstream>

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
size_t TestRunningResults::NumberOfSuccessfulTests() const
{
    return m_numberOfSuccessfulTests;
}

/**
 * Gets the number of failed tests.
 */
size_t TestRunningResults::NumberOfFailedTests() const
{
    return m_numberOfFailedTests;
}

/**
 * Gets the start time of the tests.
 */
base::DateTimeSharedPtr TestRunningResults::GetStartTime() const
{
    return m_startTime;
}

/**
 * Gets the end time of the tests.
 */
base::DateTimeSharedPtr TestRunningResults::GetEndTime() const
{
    return m_endTime;
}

/**
 * Gets the duration of the tests.
 */
base::DurationSharedPtr TestRunningResults::GetDuration() const
{
    if (!m_startTime || !m_endTime)
    {
        return nullptr;
    }

    return *m_endTime - *m_startTime;
}

/**
 * Gets the results.
 */
const ITestRunningResultList& TestRunningResults::GetResults() const
{
    return m_runningResults;
}

/**
 * Sets the start time of the tests.
 */
void TestRunningResults::SetStartTime()
{
    m_startTime = base::DateTime::Now();
}

/**
 * Sets the end time of the tests.
 */
void TestRunningResults::SetEndTime()
{
    m_endTime = base::DateTime::Now();
}

/**
 * Sets a successful running result of a unit test.
 */
void TestRunningResults::SetSuccessfulRunningResult(
    const std::wstring& testName,
    const base::DateTime& startTime,
    const base::DateTime& endTime)
{
    std::wstring errorMessage;

    ITestRunningResultSharedPtr runningResultPtr(new TestRunningResult(
        testName,
        startTime,
        endTime,
        true,
        errorMessage));

    m_runningResults.push_back(runningResultPtr);

    ++m_numberOfSuccessfulTests;
}

/**
 * Sets a failed running result of a unit test.
 */
void TestRunningResults::SetFailedRunningResult(
    const std::wstring& testName,
    const base::DateTime& startTime,
    const base::DateTime& endTime,
    const std::wstring& errorMessage)
{
    ITestRunningResultSharedPtr runningResultPtr(new TestRunningResult(
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
void TestRunningResults::Add(const ITestRunningResults& results)
{
    const ITestRunningResultList& runningResults = results.GetResults();
    m_runningResults.insert(m_runningResults.end(), runningResults.begin(), runningResults.end());

    m_numberOfSuccessfulTests += results.NumberOfSuccessfulTests();
    m_numberOfFailedTests += results.NumberOfFailedTests();
}

/**
 * Gets the string representation of this instance.
 */
std::wstring TestRunningResults::ToString() const
{
    std::wstringstream stream;

    stream << L"Running Results: " << std::endl;

    size_t index = 0;

    for (ITestRunningResultSharedPtr runningResultPtr : m_runningResults)
    {
        ++index;
        stream << L"[" << index << L"] " << *runningResultPtr << std::endl << std::endl;
    }

    stream << L"Summary: " << std::endl;
    stream << L"Number of tests: " << m_runningResults.size() << std::endl;
    stream << L"Number of passed tests: " << m_numberOfSuccessfulTests << std::endl;
    stream << L"Number of failed tests: " << m_numberOfFailedTests << std::endl;

    if (m_startTime && m_endTime)
    {
        stream << L"Start Time: " << *m_startTime << std::endl;
        stream << L"End Time: " << *m_endTime << std::endl;
        stream << L"Duration Time: " << GetDuration()->ToString() << std::endl;
    }

    return stream.str();
}

/**
 * Writes the console color handler.
 */
void TestRunningResults::Write(base::IMessageWriter& messageWriter) const
{
    std::wstringstream testResultsStartStream;
    testResultsStartStream
        << UnitTestingConsts::TEST_RESULTS_START << std::endl
        << L"Running Results: ";

    messageWriter.WriteInformationalMessage(testResultsStartStream.str());

    size_t index = 0;

    for (ITestRunningResultSharedPtr testRunningResultPtr : m_runningResults)
    {
        ++index;
        std::wstringstream testResultStream;
        testResultStream << L"[" << index << L"] " << testRunningResultPtr->ToString() << std::endl;

        std::wstring testResult = testResultStream.str();

        if (testRunningResultPtr->GetResultStatus())
        {
            messageWriter.WriteInformationalMessage(testResult);
        }
        else
        {
            messageWriter.WriteErrorMessage(testResult);
        }
    }

    std::wstringstream testResultsEndStream;
    testResultsEndStream << std::endl;
    testResultsEndStream << L"Summary: " << std::endl;
    testResultsEndStream << L"Number of tests: " << m_runningResults.size() << std::endl;
    testResultsEndStream << L"Number of passed tests: " << m_numberOfSuccessfulTests << std::endl;
    testResultsEndStream << L"Number of failed tests: " << m_numberOfFailedTests << std::endl;

    if (m_startTime && m_endTime)
    {
        testResultsEndStream << L"Start Time: " << *m_startTime << std::endl;
        testResultsEndStream << L"End Time: " << *m_endTime << std::endl;
        testResultsEndStream << L"Duration Time: " << GetDuration()->ToString() << std::endl;
    }

    testResultsEndStream << UnitTestingConsts::TEST_RESULTS_END << std::endl;

    messageWriter.WriteInformationalMessage(testResultsEndStream.str());
}
