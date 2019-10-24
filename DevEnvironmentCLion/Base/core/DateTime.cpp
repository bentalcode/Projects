#include "PreCompiled.h"

#include "DateTime.h"

using namespace base;

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
DateTime DateTime::now()
{
    return DateTime(DateTime::currentTimePoint());
}

/**
 * Gets the current time point.
 */
std::chrono::system_clock::time_point DateTime::currentTimePoint()
{
    return std::chrono::high_resolution_clock::now();
}

/**
 * Gets the information of the date-time.
 */
void DateTime::getDateTimeInformation(std::ostream& stream) const
{
    std::time_t time = std::chrono::system_clock::to_time_t(m_timePoint);
    stream << std::ctime(&time);
}

