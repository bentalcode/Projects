#include "TimeUnit.h"
#include "BaseException.h"

using namespace base;

/**
 * Creates a new time unit.
 */
TimeUnitSharedPtr TimeUnit::Make(Unit unit)
{
    return std::make_shared<TimeUnit>(unit);
}

/**
 * Creates a new time unit of type milliseconds.
 */
TimeUnitSharedPtr TimeUnit::MakeMilliseconds()
{
    return std::make_shared<TimeUnit>(Unit::MILLISECONDS);
}

/**
 * Creates a new time unit of type centiseconds.
 */
TimeUnitSharedPtr TimeUnit::MakeCentiseconds()
{
    return std::make_shared<TimeUnit>(Unit::CENTISECONDS);
}

/**
 * Creates a new time unit of type deciseconds.
 */
TimeUnitSharedPtr TimeUnit::MakeDeciseconds()
{
    return std::make_shared<TimeUnit>(Unit::DECISECONDS);
}

/**
 * Creates a new time unit of type seconds.
 */
TimeUnitSharedPtr TimeUnit::MakeSeconds()
{
    return std::make_shared<TimeUnit>(Unit::SECONDS);
}

/**
 * Creates a new time unit of type minutes.
 */
TimeUnitSharedPtr TimeUnit::MakeMinutes()
{
    return std::make_shared<TimeUnit>(Unit::MINUTES);
}

/**
 * Creates a new time unit of type hours.
 */
TimeUnitSharedPtr TimeUnit::MakeHours()
{
    return std::make_shared<TimeUnit>(Unit::HOURS);
}

/**
 * Creates a new time unit of type days.
 */
TimeUnitSharedPtr TimeUnit::MakeDays()
{
    return std::make_shared<TimeUnit>(Unit::DAYS);
}

/**
 * The TimeUnit Constructor.
 */
TimeUnit::TimeUnit(Unit unit) :
    m_unit(unit)
{
}

/**
 * The TimeUnit Destructor.
 */
TimeUnit::~TimeUnit()
{
}

/**
 * Gets unit.
 */
void TimeUnit::SetUnit(Unit unit)
{
    m_unit = unit;
}

/**
 * Gets time unit.
 */
TimeUnit::Unit TimeUnit::GetUnit() const 
{
    return m_unit;
}

/**
 * Gets time unit in milliseconds.
 */
double TimeUnit::InMilliSeconds(double scalar) const
{
    double result = scalar;

    if (m_unit == Unit::CENTISECONDS) {
        result *= 10;
    } 
    else if (m_unit == Unit::DECISECONDS) {
        result *= 100;
    } 
    else if (m_unit == Unit::SECONDS) {
        result *= 1000;
    } 
    else if (m_unit == Unit::MINUTES) {
        result *= (1000 * 60);
    } 
    else if (m_unit == Unit::HOURS) {
        result *= (1000 * 60 * 60);
    } 
    else if (m_unit == Unit::DAYS) {
        result *= (1000 * 60 * 60 * 24);
    } 
    else if (m_unit != Unit::MILLISECONDS) {
        UnsupportedUnit();
    }

    return result;
}

/**
 * Gets time unit in centiseconds.
 */
double TimeUnit::InCentiSeconds(double scalar) const
{
    double result = scalar;

    if (m_unit == Unit::MILLISECONDS) {
        result /= 10;
    }
    else if (m_unit == Unit::DECISECONDS) {
        result *= 10;
    } else if (m_unit == Unit::SECONDS) {
        result *= 100;
    } else if (m_unit == Unit::MINUTES) {
        result *= (100 * 60);
    } else if (m_unit == Unit::HOURS) {
        result *= (100 * 60 * 60);
    } else if (m_unit == Unit::DAYS) {
        result *= (100 * 60 * 60 * 24);
    } else if (m_unit != Unit::CENTISECONDS) {
        UnsupportedUnit();
    }

    return result;
}

/**
 * Gets time unit in deciseconds.
 */
double TimeUnit::InDeciSeconds(double scalar) const
{
    double result = scalar;

    if (m_unit == Unit::MILLISECONDS) {
        result /= 100;
    } else if (m_unit == Unit::CENTISECONDS) {
        result /= 10;
    } else if (m_unit == Unit::SECONDS) {
        result *= 10;
    } else if (m_unit == Unit::MINUTES) {
        result *= (10 * 60);
    } else if (m_unit == Unit::HOURS) {
        result *= (10 * 60 * 60);
    } else if (m_unit == Unit::DAYS) {
        result *= (10 * 60 * 60 * 24);
    } else if (m_unit != Unit::DECISECONDS) {
        UnsupportedUnit();
    }

    return result;
}

/**
 * Gets time unit in seconds.
 */
double TimeUnit::InSeconds(double scalar) const
{
    double result = scalar;

    if (m_unit == Unit::MILLISECONDS) {
        result /= 1000;
    }
    else if (m_unit == Unit::CENTISECONDS) {
        result /= 100;
    } 
    else if (m_unit == Unit::DECISECONDS) {
        result /= 10;
    }
    else if (m_unit == Unit::MINUTES) {
        result *= 60;
    } 
    else if (m_unit == Unit::HOURS) {
        result *= (60 * 60);
    } 
    else if (m_unit == Unit::DAYS) {
        result *= (60 * 60 * 24);
    } 
    else if (m_unit != Unit::SECONDS) {
        UnsupportedUnit();
    }

    return result;
}

/**
 * Gets time unit in minutes.
 */
double TimeUnit::InMinutes(double scalar) const
{
    double result = scalar;

    if (m_unit == Unit::MILLISECONDS) {
        result /= (1000 * 60);
    } 
    else if (m_unit == Unit::CENTISECONDS) {
        result /= (100 * 60);
    } 
    else if (m_unit == Unit::DECISECONDS) {
        result /= (10 * 60);
    } 
    else if (m_unit == Unit::SECONDS) {
        result /= 60;
    } 
    else if (m_unit == Unit::HOURS) {
        result *= 60;
    } 
    else if (m_unit == Unit::DAYS) {
        result *= (60 * 24);
    } 
    else if (m_unit != Unit::MINUTES) {
        UnsupportedUnit();
    }

    return result;
}

/**
 * Gets time unit in hours.
 */
double TimeUnit::InHours(double scalar) const
{
    double result = scalar;

    if (m_unit == Unit::MILLISECONDS) {
        result /= (1000 * 60 * 60);
    } 
    else if (m_unit == Unit::CENTISECONDS) {
        result /= (100 * 60 * 60);
    } 
    else if (m_unit == Unit::DECISECONDS) {
        result /= (10 * 60 * 60);
    }
    else if (m_unit == Unit::SECONDS) {
        result /= (60 * 60);
    } 
    else if (m_unit == Unit::MINUTES) {
        result /= 60;
    } 
    else if (m_unit == Unit::DAYS) {
        result *= 24;
    } 
    else if (m_unit != Unit::HOURS) {
        UnsupportedUnit();
    }

    return result;
}

/**
 * Gets time unit in days.
 */
double TimeUnit::InDays(double scalar) const
{
    double result = scalar;

    if (m_unit == Unit::MILLISECONDS) {
        result /= (1000 * 60 * 60 * 24);
    } else if (m_unit == Unit::CENTISECONDS) {
        result /= (100 * 60 * 60 * 24);
    } else if (m_unit == Unit::DECISECONDS) {
        result /= (10 * 60 * 60 * 24);
    } else if (m_unit == Unit::SECONDS) {
        result /= (60 * 60 * 24);
    } else if (m_unit == Unit::MINUTES) {
        result /= (60 * 24);
    } else if (m_unit == Unit::HOURS) {
        result /= 24;
    } else if (m_unit != Unit::DAYS) {
        UnsupportedUnit();
    }

    return result;
}

/**
 * Handles an unsupported unit.
 */
void TimeUnit::UnsupportedUnit() {
    long errorCode = ErrorCodes::UNEXPECTED;

    std::wstringstream errorMessageStream;
    errorMessageStream 
        << L"Time Unit has processed unknown time unit" 
        << ErrorMessages::GetErrorCodeMessage(errorCode);

    std::wstring errorMessage = errorMessageStream.str();
    throw BaseException(errorCode, errorMessage);
}

/**
 * Gets number of units.
 */
double TimeUnit::InUnits(const Duration& duration) const
{
    double numberOfUnits = duration.ToMilliseconds();

    if (m_unit == Unit::CENTISECONDS) {
        numberOfUnits /= 10;
    } else if (m_unit == Unit::DECISECONDS) {
        numberOfUnits /= 100;
    } else if (m_unit == Unit::SECONDS) {
        numberOfUnits /= 1000;
    } else if (m_unit == Unit::MINUTES) {
        numberOfUnits /= (1000 * 60);
    } else if (m_unit == Unit::HOURS) {
        numberOfUnits /= (1000 * 60 * 60);
    } else if (m_unit == Unit::DAYS) {
        numberOfUnits /= (1000 * 60 * 60 * 24);
    } else if (m_unit != Unit::MILLISECONDS) {
        UnsupportedUnit();
    }

    return numberOfUnits;
}

/**
 * Creates a unit functor map.
 */
TimeUnit::UnitFunctorMapSharedPtr TimeUnit::CreateUnitFunctors(const TimeUnit& timeUnit)
{
    UnitFunctorMapSharedPtr unitFunctors = std::make_shared<UnitFunctorMap>();

    TimeUnit::IUnitFunctorSharedPtr millisecondsUnitFunctor(
        std::make_shared<TimeUnit::IUnitFunctor>(MillisecondsTimeUnitFunctor{ timeUnit }));

    TimeUnit::IUnitFunctorSharedPtr cenisecondsUnitFunctor(
        std::make_shared<TimeUnit::IUnitFunctor>(CentisecondsTimeUnitFunctor{ timeUnit }));

    TimeUnit::IUnitFunctorSharedPtr decisecondsUnitFunctor(
        std::make_shared<TimeUnit::IUnitFunctor>(DecisecondsTimeUnitFunctor{ timeUnit }));

    TimeUnit::IUnitFunctorSharedPtr secondsUnitFunctor(
        std::make_shared<TimeUnit::IUnitFunctor>(SecondsTimeUnitFunctor{ timeUnit }));

    TimeUnit::IUnitFunctorSharedPtr minutesUnitFunctor(
        std::make_shared<TimeUnit::IUnitFunctor>(MinutesTimeUnitFunctor{ timeUnit }));

    TimeUnit::IUnitFunctorSharedPtr hoursUnitFunctor(
        std::make_shared<TimeUnit::IUnitFunctor>(HoursTimeUnitFunctor{ timeUnit }));

    TimeUnit::IUnitFunctorSharedPtr daysUnitFunctor(
        std::make_shared<TimeUnit::IUnitFunctor>(DaysTimeUnitFunctor{ timeUnit }));

    unitFunctors->insert(std::make_pair(TimeUnit::Unit::MILLISECONDS, millisecondsUnitFunctor));
    unitFunctors->insert(std::make_pair(TimeUnit::Unit::CENTISECONDS, cenisecondsUnitFunctor));
    unitFunctors->insert(std::make_pair(TimeUnit::Unit::DECISECONDS, decisecondsUnitFunctor));
    unitFunctors->insert(std::make_pair(TimeUnit::Unit::SECONDS, secondsUnitFunctor));
    unitFunctors->insert(std::make_pair(TimeUnit::Unit::MINUTES, minutesUnitFunctor));
    unitFunctors->insert(std::make_pair(TimeUnit::Unit::HOURS, hoursUnitFunctor));
    unitFunctors->insert(std::make_pair(TimeUnit::Unit::DAYS, daysUnitFunctor));

    return unitFunctors;
}