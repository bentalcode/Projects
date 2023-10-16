#include "TestRunningResult.h"
#include <sstream>

using namespace unit_testing;

/**
 * The TestRunningResult constructor.
 */
TestRunningResult::TestRunningResult(
    const std::wstring& name,
    const base::DateTime& startTime,
    const base::DateTime& endTime,
    bool resultStatus,
    const std::wstring& errorMessage) :
    m_name(name),
    m_startTime(startTime),
    m_endTime(endTime),
    m_duration(endTime.GetTimePoint() - startTime.GetTimePoint()),
    m_resultStatus(resultStatus),
    m_errorMessage(errorMessage)
{

}

/**
 * The TestRunningResult destructor.
 */
TestRunningResult::~TestRunningResult()
{
}

/**
 * Gets the string representation of this instance.
 */
std::wstring TestRunningResult::ToString() const
{
    std::wstringstream stream;

    stream
        << L"Name: " << m_name
        << L", StartTime: " << m_startTime
        << L", EndTime: " << m_endTime
        << L", Duration: " << m_duration.ToString()
        << L", ResultStatus: ";

    if (m_resultStatus)
    {
        stream << L"Passed";
    }
    else
    {
        stream << L"Failed" << L", ErrorMessage: " << m_errorMessage;
    }

    return stream.str();
}

const std::wstring& TestRunningResult::GetName() const
{
    return m_name;
}

/**
 * Gets the start time of a test.
 */
const base::DateTime& TestRunningResult::GetStartTime() const
{
    return m_startTime;
}

/**
 * Gets the end time of a test.
 */
const base::DateTime& TestRunningResult::GetEndTime() const
{
    return m_endTime;
}

/**
 * Gets the duration of a test.
 */
const base::Duration& TestRunningResult::GetDuration() const
{
    return m_duration;
}

/**
 * Gets the result status a test.
 */
bool TestRunningResult::GetResultStatus() const
{
    return m_resultStatus;
}

/**
 * Gets the error message of a test.
 */
const std::wstring& TestRunningResult::GetErrorMessage() const
{
    return m_errorMessage;
}
