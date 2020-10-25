#include "PreCompiled.h"

#include "TestRunningResult.h"

using namespace unit_testing;

/**
 * The TestRunningResult constructor.
 */
TestRunningResult::TestRunningResult(
    const std::string& name,
    const base::DateTime& startTime,
    const base::DateTime& endTime,
    bool resultStatus,
    const std::string& errorMessage) :
    m_name(name),
    m_startTime(startTime),
    m_endTime(endTime),
    m_duration(endTime.getTimePoint() - startTime.getTimePoint()),
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
std::string TestRunningResult::toString() const
{
    std::stringstream stream;

    stream
        << "Name: " << m_name
        << ", StartTime: " << m_startTime
        << ", EndTime: " << m_endTime
        << ", Duration: " << m_duration
        << ", ResultStatus: ";

    if (m_resultStatus)
    {
        stream << "Passed";
    }
    else
    {
        stream << "Failed" << ", ErrorMessage: " << m_errorMessage;
    }

    return stream.str();
}

const std::string& TestRunningResult::getName() const
{
    return m_name;
}

/**
 * Gets the start time of a test.
 */
const base::DateTime& TestRunningResult::getStartTime() const
{
    return m_startTime;
}

/**
 * Gets the end time of a test.
 */
const base::DateTime& TestRunningResult::getEndTime() const
{
    return m_endTime;
}

/**
 * Gets the duration of a test.
 */
const base::Duration& TestRunningResult::getDuration() const
{
    return m_duration;
}

/**
 * Gets the result status a test.
 */
bool TestRunningResult::getResultStatus() const
{
    return m_resultStatus;
}

/**
 * Gets the error message of a test.
 */
const std::string& TestRunningResult::getErrorMessage() const
{
    return m_errorMessage;
}
