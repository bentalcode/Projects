#include "DateTime.h"

using namespace base;

/**
 * Creates a new date-time.
 */
DateTimeSharedPtr DateTime::Make(const std::chrono::system_clock::time_point& timePoint)
{
    return std::make_shared<DateTime>(timePoint);
}

/**
 * The DateTime default constructor.
 */
DateTime::DateTime(const std::chrono::system_clock::time_point& timePoint) :
        m_timePoint(timePoint)
{
}

/**
 * The DateTime destructor.
 */
DateTime::~DateTime()
{
}

/**
 * Gets the current time.
 */
DateTimeSharedPtr DateTime::Now()
{
    return DateTime::Make(GetCurrentTimePoint());
}

/**
 * Gets the current time point.
 */
std::chrono::system_clock::time_point DateTime::GetCurrentTimePoint()
{
    return std::chrono::high_resolution_clock::now();
}

/**
 * Gets the information of the date-time.
 */
void DateTime::GetDateTimeInformation(std::wostream& stream) const
{
    std::time_t time = std::chrono::system_clock::to_time_t(m_timePoint);
    //stream << std::ctime(&time);
}

