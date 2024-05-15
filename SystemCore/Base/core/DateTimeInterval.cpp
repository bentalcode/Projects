#include "DateTimeInterval.h"
#include "SmartPointers.h"

using namespace base;

/**
 * Creates a datetime interval.
 */
std::shared_ptr<DateTimeInterval> DateTimeInterval::Make(
    const DateTimeSharedPtr startTime,
    const DateTimeSharedPtr endTime)
{
    return std::make_shared<DateTimeInterval>(startTime, endTime);
}

/**
 * The DateTimeInterval Constructor.
 */
DateTimeInterval::DateTimeInterval(
    const DateTimeSharedPtr startTime,
    const DateTimeSharedPtr endTime)
{
    Validate(startTime, endTime);
    m_startTime = startTime;
    m_endTime = endTime;
}

/**
 * The DateTimeInterval Destructor.
 */
DateTimeInterval::~DateTimeInterval()
{
}

/**
 * Sets a start time of an interval.
 */
void DateTimeInterval::SetStartIntervalTime(DateTimeSharedPtr time)
{
    base::SmartPointers::Validate(time);
    m_startTime = time;
}

/**
 * Gets a start time of an interval.
 */
DateTimeSharedPtr DateTimeInterval::GetStartTime()
{
    return m_startTime;
}

/**
 * Gets a start time of an interval.
 */
const DateTimeSharedPtr DateTimeInterval::GetStartTime() const
{
    return m_startTime;
}

/**
 * Sets an End time of an interval.
 */
void DateTimeInterval::SetEndTime(DateTimeSharedPtr time)
{
    base::SmartPointers::Validate(time);
    m_endTime = time;
}

/**
 * Gets an End time of an interval.
 */
DateTimeSharedPtr DateTimeInterval::GetEndTime()
{
    return m_endTime;
}

/**
 * Gets an End time of an interval.
 */
const DateTimeSharedPtr DateTimeInterval::GetEndTime() const
{
    return m_endTime;
}

/**
 * Gets duration of an interval.
 */
const DurationSharedPtr DateTimeInterval::GetDuration() const
{
    DurationSharedPtr duration = *m_endTime - *m_startTime;
    return duration;
}

/**
 * Validates an interval.
 */
void DateTimeInterval::Validate(
    const DateTimeSharedPtr startTime,
    const DateTimeSharedPtr endTime)
{
    SmartPointers::Validate(startTime);
    SmartPointers::Validate(endTime);

    long errorCode = ErrorCodes::OUT_OF_RANGE;

    std::wstringstream errorMessageStream;
    errorMessageStream
        << L"The date-time interval is invalid since start time is after end time."
        << ErrorMessages::GetErrorCodeMessage(errorCode);

    std::wstring errorMessage = errorMessageStream.str();
    throw BaseException(errorCode, errorMessage);
}
