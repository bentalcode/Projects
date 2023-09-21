#ifndef DURATION_H_a70cdfb1_0685_4640_8d58_c0b94eadc8f5
#define DURATION_H_a70cdfb1_0685_4640_8d58_c0b94eadc8f5

#include <chrono>
#include <memory>
#include "TimeUtils.h"

namespace base {

    class DateTime;

    /**
     * The Duration class implements a duration.
     */
    template <typename ArithmeticType, typename PeriodType = std::ratio<1>>
    class DurationType final {
    public:
        typedef std::chrono::duration<long double, std::ratio<1, 1000000>> MicroSecondTick;
        typedef std::chrono::duration<long double, std::ratio<1, 1000>> MilliSecondTick;
        typedef std::chrono::duration<long double> SecondTick;
        typedef std::chrono::duration<double, std::ratio<60>> MinuteTick;
        typedef std::chrono::duration<double, std::ratio<60 * 60>> HourTick;
        typedef std::chrono::duration<double, std::ratio<60 * 60 * 24>> DayTick;
        typedef std::chrono::duration<double, std::ratio<60 * 60 * 24 * 365>> YearTick;

        /**
         * Creates a duration.
         */
        static std::shared_ptr<DurationType<ArithmeticType, PeriodType>> Make(
            const std::chrono::system_clock::time_point& timePoint);

        /**
         * The DurationType Constructor.
         */
        explicit DurationType(const std::chrono::duration<ArithmeticType, PeriodType>& duration);

        /**
         * The DurationType Destructor.
         */
        ~DurationType();

        /**
         * The DurationType Copy/Move Constructors.
         */
        DurationType(const DurationType&) = default;
        DurationType(DurationType&&) = delete;

        /**
         * The DurationType Copy/Move Assignment Operators.
         */
        DurationType& operator=(const DurationType&) = default;
        DurationType& operator=(DurationType&&) = delete;

        /**
         * Gets a duration.
         */
        inline const std::chrono::duration<ArithmeticType, PeriodType>& GetDuration() const;

        /**
         * Gets an information of duration.
         */
        void GetDurationInformation(std::ostream& stream) const;

        /**
         * Gets microseconds of duration.
         */
        ArithmeticType ToMicroseconds() const;

        /**
         * Gets milliseconds of duration.
         */
        ArithmeticType ToMilliseconds() const;

        /**
         * Gets seconds of duration.
         */
        ArithmeticType ToSeconds() const;

        /**
         * Gets minutes of duration.
         */
        ArithmeticType ToMinutes() const;

        /**
         * Gets hours of duration.
         */
        ArithmeticType ToHours() const;

        /**
         * Gets days of duration.
         */
        ArithmeticType ToDays() const;

        /**
         * Gets years of duration.
         */
        ArithmeticType ToYears() const;

        /**
         * Gets a string representation of a duration.
         */
        std::wstring ToString() const;

        /**
         * Parses a string to duration.
         */
        static std::shared_ptr<DurationType<ArithmeticType, PeriodType>> Parse(const std::wstring& str);

        /**
         * Creates duration from microseconds.
         */
        static std::shared_ptr<DurationType<ArithmeticType, PeriodType>> FromMicroseconds(long double microseconds);

        /**
         * Creates duration from milliseconds.
         */
        static std::shared_ptr<DurationType<ArithmeticType, PeriodType>> FromMilliseconds(long double milliseconds);

        /**
         * Creates duration from seconds.
         */
        static std::shared_ptr<DurationType<ArithmeticType, PeriodType>> FromSeconds(long double seconds);

        /**
         * Creates duration from minutes.
         */
        static std::shared_ptr<DurationType<ArithmeticType, PeriodType>> FromMinutes(long double minutes);

        /**
         * Creates duration from hours.
         */
        static std::shared_ptr<DurationType<ArithmeticType, PeriodType>> FromHours(long double hours);

        /**
         * Creates duration from days.
         */
        static std::shared_ptr<DurationType<ArithmeticType, PeriodType>> FromDays(long double days);

        /**
         * Creates duration from years.
         */
        static std::shared_ptr<DurationType<ArithmeticType, PeriodType>> FromYears(long double years);

    private:
        std::chrono::duration<ArithmeticType, PeriodType> m_duration;
    };

    /**
     * Defines the Shared Ptr of Duration.
     */
    using Duration = DurationType<double>;
    using DurationSharedPtr = std::shared_ptr<Duration>;

    /**
     * Creates a duration.
     */
    template <typename ArithmeticType, typename PeriodType>
    std::shared_ptr<DurationType<double>> Make(const std::chrono::system_clock::time_point& timePoint)
    {
        return std::make_shared<DurationType<ArithmeticType, PeriodType>>(timePoint);
    }

    /**
     * The DurationType Constructor.
     */
    template <typename ArithmeticType, typename PeriodType>
    DurationType<ArithmeticType, PeriodType>::DurationType(
        const std::chrono::duration<ArithmeticType, PeriodType>& duration) :
        m_duration(duration)
    {
    }

    /**
     * The DurationType Destructor.
     */
    template <typename ArithmeticType, typename PeriodType>
    DurationType<ArithmeticType, PeriodType>::~DurationType()
    {
    }

    /**
     * Gets a duration.
     */
    template <typename ArithmeticType, typename PeriodType>
    inline const std::chrono::duration<ArithmeticType, PeriodType>& DurationType<ArithmeticType, PeriodType>::GetDuration() const
    {
        return m_duration;
    }

    /**
     * Gets an information of duration.
     */
    template <typename ArithmeticType, typename PeriodType>
    inline void DurationType<ArithmeticType, PeriodType>::GetDurationInformation(std::ostream& stream) const
    {
        stream << m_duration.count();
    }

    /**
     * Gets microseconds of duration.
     */
    template <typename ArithmeticType, typename PeriodType>
    ArithmeticType DurationType<ArithmeticType, PeriodType>::ToMicroseconds() const
    {
        MicroSecondTick durationMicroseconds(m_duration);
        return durationMicroseconds.count();
    }

    /**
     * Gets milliseconds of duration.
     */
    template <typename ArithmeticType, typename PeriodType>
    ArithmeticType DurationType<ArithmeticType, PeriodType>::ToMilliseconds() const
    {
        MilliSecondTick durationMilliseconds(m_duration);
        return durationMilliseconds.count();
    }

    /**
     * Gets seconds of duration.
     */
    template <typename ArithmeticType, typename PeriodType>
    ArithmeticType DurationType<ArithmeticType, PeriodType>::ToSeconds() const
    {
        SecondTick durationSeconds(m_duration);
        return durationSeconds.count();
    }

    /**
     * Gets minutes of duration.
     */
    template <typename ArithmeticType, typename PeriodType>
    ArithmeticType DurationType<ArithmeticType, PeriodType>::ToMinutes() const
    {
        MinuteTick durationMinutes(m_duration);
        return durationMinutes.count();
    }

    /**
     * Gets hours of duration.
     */
    template <typename ArithmeticType, typename PeriodType>
    ArithmeticType DurationType<ArithmeticType, PeriodType>::ToHours() const
    {
        HourTick durationHours(m_duration);
        return durationHours.count();
    }

    /**
     * Gets days of duration.
     */
    template <typename ArithmeticType, typename PeriodType>
    ArithmeticType DurationType<ArithmeticType, PeriodType>::ToDays() const
    {
        DayTick durationDays(m_duration);
        return durationDays.count();
    }

    /**
     * Gets years of duration.
     */
    template <typename ArithmeticType, typename PeriodType>
    ArithmeticType DurationType<ArithmeticType, PeriodType>::ToYears() const
    {
        YearTick durationYears(m_duration);
        return durationYears.count();
    }

    /**
     * Gets a string representation of a duration.
     */
    template <typename ArithmeticType, typename PeriodType>
    std::wstring DurationType<ArithmeticType, PeriodType>::ToString() const
    {
        size_t milliseconds = static_cast<size_t>(ToMilliseconds());
        return TimeUtils::DurationToString(milliseconds);
    }

    /**
     * Parses a string to duration.
     */
    template <typename ArithmeticType, typename PeriodType>
    std::shared_ptr<DurationType<ArithmeticType, PeriodType>>
    DurationType<ArithmeticType, PeriodType>::Parse(const std::wstring& str)
    {
        size_t milliseconds = TimeUtils::ParseDuration(str);
        return FromMilliseconds(static_cast<long double>(milliseconds));
    }

    /**
     * Creates duration from microseconds.
     */
    template <typename ArithmeticType, typename PeriodType>
    std::shared_ptr<DurationType<ArithmeticType, PeriodType>>
    DurationType<ArithmeticType, PeriodType>::FromMicroseconds(long double microseconds)
    {
        MicroSecondTick durationMicroseconds(microseconds);
        return std::make_shared<Duration>(durationMicroseconds);
    }

    /**
     * Creates duration from milliseconds.
     */
    template <typename ArithmeticType, typename PeriodType>
    std::shared_ptr<DurationType<ArithmeticType, PeriodType>>
    DurationType<ArithmeticType, PeriodType>::FromMilliseconds(long double milliseconds)
    {
        MilliSecondTick durationMilliseconds(milliseconds);
        return std::make_shared<Duration>(durationMilliseconds);
    }

    /**
     * Creates duration from seconds.
     */
    template <typename ArithmeticType, typename PeriodType>
    std::shared_ptr<DurationType<ArithmeticType, PeriodType>>
    DurationType<ArithmeticType, PeriodType>::FromSeconds(long double seconds)
    {
        SecondTick durationSeconds(seconds);
        return std::make_shared<Duration>(durationSeconds);
    }

    /**
     * Creates duration from minutes.
     */
    template <typename ArithmeticType, typename PeriodType>
    std::shared_ptr<DurationType<ArithmeticType, PeriodType>>
    DurationType<ArithmeticType, PeriodType>::FromMinutes(long double minutes)
    {
        MinuteTick durationMinutes(minutes);
        return std::make_shared<Duration>(durationMinutes);
    }

    /**
     * Creates duration from hours.
     */
    template <typename ArithmeticType, typename PeriodType>
    std::shared_ptr<DurationType<ArithmeticType, PeriodType>>
    DurationType<ArithmeticType, PeriodType>::FromHours(long double hours)
    {
        HourTick durationHours(hours);
        return std::make_shared<Duration>(durationHours);
    }

    /**
     * Creates duration from days.
     */
    template <typename ArithmeticType, typename PeriodType>
    std::shared_ptr<DurationType<ArithmeticType, PeriodType>>
    DurationType<ArithmeticType, PeriodType>::FromDays(long double days)
    {
        DayTick durationDays(days);
        return std::make_shared<Duration>(durationDays);
    }

    /**
     * Creates duration from years.
     */
    template <typename ArithmeticType, typename PeriodType>
    std::shared_ptr<DurationType<ArithmeticType, PeriodType>>
    DurationType<ArithmeticType, PeriodType>::FromYears(long double years)
    {
        YearTick durationYears(years);
        return std::make_shared<Duration>(durationYears);
    }

    /**
     * Writes information of a duration to an output stream.
     */
    template <typename ArithmeticType, typename PeriodType>
    inline std::ostream& operator<<(
        std::ostream& stream,
        const DurationType<ArithmeticType, PeriodType>& duration)
    {
        duration.GetDurationInformation(stream);
        return stream;
    }

    /**
     * Implements an operator equal for duration.
     */
    template <typename ArithmeticType, typename PeriodType>
    inline bool operator==(
        const DurationType<ArithmeticType, PeriodType>& lhs,
        const DurationType<ArithmeticType, PeriodType>& rhs)
    {
        return lhs.GetDuration() == rhs.GetDuration();
    }

    /**
     * Implements an operator not equal for duration.
     */
    template <typename ArithmeticType, typename PeriodType>
    inline bool operator!=(
        const DurationType<ArithmeticType, PeriodType>& lhs,
        const DurationType<ArithmeticType, PeriodType>& rhs)
    {
        return !(lhs == rhs);
    }

    /**
     * Implements an operator less than for duration.
     */
    template <typename ArithmeticType, typename PeriodType>
    inline bool operator<(
        const DurationType<ArithmeticType, PeriodType>& lhs,
        const DurationType<ArithmeticType, PeriodType>& rhs)
    {
        return lhs.GetDuration() < rhs.GetDuration();
    }

    /**
     * Implements an operator less or equal than for duration.
     */
    template <typename ArithmeticType, typename PeriodType>
    inline bool operator<=(
        const DurationType<ArithmeticType, PeriodType>& lhs,
        const DurationType<ArithmeticType, PeriodType>& rhs)
    {
        return !(rhs < lhs);
    }

    /**
     * Implements an operator greater than for duration.
     */
    template <typename ArithmeticType, typename PeriodType>
    inline bool operator>(
        const DurationType<ArithmeticType, PeriodType>& lhs,
        const DurationType<ArithmeticType, PeriodType>& rhs)
    {
        return rhs < lhs;
    }

    /**
     * Implements an operator greater than or equal for duration.
     */
    template <typename ArithmeticType, typename PeriodType>
    inline bool operator>=(
        const DurationType<ArithmeticType, PeriodType>& lhs,
        const DurationType<ArithmeticType, PeriodType>& rhs)
    {
        return !(lhs < rhs);
    }

}  // namespace base

#endif // DURATION_H_a70cdfb1_0685_4640_8d58_c0b94eadc8f5
