#ifndef TIME_UNIT_H_ec231f76_73b4_4db2_a54b_3de1ff1f60ef
#define TIME_UNIT_H_ec231f76_73b4_4db2_a54b_3de1ff1f60ef

#include "Duration.h"
#include <memory>
#include <functional>
#include <map>

namespace base {

    /**
     * The TimeUnit class implements a time unit.
     */
    class TimeUnit final {
    public:
        //
        // Defines a SharedPtr of Unit Functor...
        //
        using IUnitFunctor = std::function<double(double)>;
        using IUnitFunctorSharedPtr = std::shared_ptr<IUnitFunctor>;

        enum class Unit {
            MILLISECONDS,
            CENTISECONDS,
            DECISECONDS,
            SECONDS,
            MINUTES,
            HOURS,
            DAYS
        };

        //
        // Defines a unit functor mapping between a time unit to it's functor...
        //
        using UnitFunctorMap = std::map<TimeUnit::Unit, TimeUnit::IUnitFunctorSharedPtr>;
        using UnitFunctorMapSharedPtr = std::shared_ptr<UnitFunctorMap>;

        /**
         * Creates a new time unit.
         */
        static std::shared_ptr<TimeUnit> Make(Unit unit = Unit::MILLISECONDS);

        /**
         * Creates a new time unit of type milliseconds.
         */
        static std::shared_ptr<TimeUnit> MakeMilliseconds();

        /**
         * Creates a new time unit of type centiseconds.
         */
        static std::shared_ptr<TimeUnit> MakeCentiseconds();

        /**
         * Creates a new time unit of type deciseconds.
         */
        static std::shared_ptr<TimeUnit> MakeDeciseconds();

        /**
         * Creates a new time unit of type seconds.
         */
        static std::shared_ptr<TimeUnit> MakeSeconds();

        /**
         * Creates a new time unit of type minutes.
         */
        static std::shared_ptr<TimeUnit> MakeMinutes();

        /**
         * Creates a new time unit of type hours.
         */
        static std::shared_ptr<TimeUnit> MakeHours();

        /**
         * Creates a new time unit of type days.
         */
        static std::shared_ptr<TimeUnit> MakeDays();

        /**
         * The TimeUnit Constructor.
         */
        explicit TimeUnit(Unit unit = Unit::MILLISECONDS);

        /**
         * The TimeUnit Destructor.
         */
        ~TimeUnit();

        /**
         * Gets unit.
         */
        void SetUnit(Unit unit);

        /**
         * Gets unit.
         */
        Unit GetUnit() const;

        /**
         * Gets time unit in milliseconds.
         */
        double InMilliSeconds(double scalar) const;

        /**
         * Gets time unit in centiseconds.
         */
        double InCentiSeconds(double scalar) const;

        /**
         * Gets time unit in deciseconds.
         */
        double InDeciSeconds(double scalar) const;

        /**
         * Gets time unit in seconds.
         */
        double InSeconds(double scalar) const;

        /**
         * Gets time unit in minutes.
         */
        double InMinutes(double scalar) const;

        /**
         * Gets time unit in hours.
         */
        double InHours(double scalar) const;

        /**
         * Gets time unit in days.
         */
        double InDays(double scalar) const;

        /**
         * Gets number of units.
         */
        double InUnits(const Duration& duration) const;

        /**
         * Creates a unit functor map.
         */
        static UnitFunctorMapSharedPtr CreateUnitFunctors(const TimeUnit& timeUnit);

    private:
        /**
         * Handles an unsupported unit.
         */
        static void UnsupportedUnit();

        Unit m_unit;
    };

    /**
     * Defines the Shared Ptr of Time Unit.
     */
    using TimeUnitSharedPtr = std::shared_ptr<TimeUnit>;

    /**
     * The MillisecondsTimeUnitFunctor class implements a functor of a time unit of milliseconds.
     */
    class MillisecondsTimeUnitFunctor final {
    public:
        /**
         * The functor constructor.
         */
        MillisecondsTimeUnitFunctor(const TimeUnit& m_timeUnit) : m_timeUnit(m_timeUnit) {}

        /**
         * The functor logic.
         */
        double operator()(double scalar) { return static_cast<double>(m_timeUnit.InMilliSeconds(scalar)); }

    private:
        const TimeUnit& m_timeUnit;
    };

    /**
     * The CentisecondsTimeUnitFunctor class implements a functor of a time unit of centiseconds.
     */
    class CentisecondsTimeUnitFunctor final {
    public:
        /**
         * The functor constructor.
         */
        CentisecondsTimeUnitFunctor(const TimeUnit& m_timeUnit) : m_timeUnit(m_timeUnit) {}

        /**
         * The functor logic.
         */
        double operator()(double scalar) { return m_timeUnit.InCentiSeconds(scalar); }

    private:
        const TimeUnit& m_timeUnit;
    };

    /**
     * The DecisecondsTimeUnitFunctor class implements a functor of a time unit of deciseconds.
     */
    class DecisecondsTimeUnitFunctor final {
    public:
        /**
         * The functor constructor.
         */
        DecisecondsTimeUnitFunctor(const TimeUnit& m_timeUnit) : m_timeUnit(m_timeUnit) {}

        /**
         * The functor logic.
         */
        double operator()(double scalar) { return m_timeUnit.InDeciSeconds(scalar); }

    private:
        const TimeUnit& m_timeUnit;
    };

    /**
     * The SecondsTimeUnitFunctor class implements a functor of a time unit of seconds.
     */
    class SecondsTimeUnitFunctor final {
    public:
        /**
         * The functor constructor.
         */
        SecondsTimeUnitFunctor(const TimeUnit& m_timeUnit) : m_timeUnit(m_timeUnit) {}

        /**
         * The functor logic.
         */
        double operator()(double scalar) { return m_timeUnit.InSeconds(scalar); }

    private:
        const TimeUnit& m_timeUnit;
    };

    /**
     * The MinutesTimeUnitFunctor class implements a functor of a time unit of minutes.
     */
    class MinutesTimeUnitFunctor final {
    public:
        /**
         * The functor constructor.
         */
        MinutesTimeUnitFunctor(const TimeUnit& m_timeUnit) : m_timeUnit(m_timeUnit) {}

        /**
         * The functor logic.
         */
        double operator()(double scalar) { return m_timeUnit.InMinutes(scalar); }

    private:
        const TimeUnit& m_timeUnit;
    };

    /**
     * The HoursTimeUnitFunctor class implements a functor of a time unit of hours.
     */
    class HoursTimeUnitFunctor final {
    public:
        /**
         * The functor constructor.
         */
        HoursTimeUnitFunctor(const TimeUnit& m_timeUnit) : m_timeUnit(m_timeUnit) {}

        /**
         * The functor logic.
         */
        double operator()(double scalar) { return m_timeUnit.InHours(scalar); }

    private:
        const TimeUnit& m_timeUnit;
    };

    /**
     * The DaysTimeUnitFunctor class implements a functor of a time unit of days.
     */
    class DaysTimeUnitFunctor final {
    public:
        /**
         * The functor constructor.
         */
        DaysTimeUnitFunctor(const TimeUnit& m_timeUnit) : m_timeUnit(m_timeUnit) {}

        /**
         * The functor logic.
         */
        double operator()(double scalar) { return m_timeUnit.InDays(scalar); }

    private:
        const TimeUnit& m_timeUnit;
    };

} // namespace base

#endif // TIME_UNIT_H_ec231f76_73b4_4db2_a54b_3de1ff1f60ef