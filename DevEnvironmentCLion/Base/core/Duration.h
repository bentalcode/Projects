#ifndef DURATION_H_b4a151bc_6f7a_4a2e_9d44_95df4e17d5c2
#define DURATION_H_b4a151bc_6f7a_4a2e_9d44_95df4e17d5c2

#include <chrono>
#include "DateTime.h"

namespace base
{
    /**
     * The Duration class implements a duration.
     */
    template <typename ArithmeticType, typename PeriodType = std::ratio<1>>
    class DurationType final
    {
    public:
        typedef std::chrono::duration<long double,std::ratio<1,1000000>> MicroSecondTick;
        typedef std::chrono::duration<long double,std::ratio<1,1000>> MilliSecondTick;
        typedef std::chrono::duration<long double> SecondTick;
        typedef std::chrono::duration<double, std::ratio<60>> MinuteTick;
        typedef std::chrono::duration<double, std::ratio<60*60>> HourTick;
        typedef std::chrono::duration<double, std::ratio<60*60*24*365>> YearTick;

        /**
         * The constructor.
         */
        explicit DurationType(const std::chrono::duration<ArithmeticType, PeriodType>& duration);

        /**
         * The destructor.
         */
        ~DurationType();

        /**
         * The copy/move constructors.
         */
        DurationType(const DurationType&) = default;
        DurationType(DurationType&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        DurationType& operator=(const DurationType&) = default;
        DurationType& operator=(DurationType&&) = delete;

        /**
         * Gets the duration.
         */
        inline const std::chrono::duration<ArithmeticType, PeriodType>& getDuration() const;

        /**
         * Gets the information of the duration.
         */
        void getDurationInformation(std::ostream& stream) const;

        /**
         * Gets the seconds of the duration.
         */
        size_t toSeconds() const;

        /**
         * Gets the milliseconds of the duration.
         */
        size_t toMilliseconds() const;

        /**
         * Creates the duration from seconds.
         */
        static std::shared_ptr<DurationType<ArithmeticType, PeriodType>> fromSeconds(size_t milliseconds);

        /**
         * Creates the duration from milliseconds.
         */
        static std::shared_ptr<DurationType<ArithmeticType, PeriodType>> fromMilliseconds(size_t milliseconds);

        /**
         * Gets the duration between two date-time points.
         */
        static std::shared_ptr<DurationType<ArithmeticType, PeriodType>> between(
            const DateTime& start,
            const DateTime& end);

    private:
        std::chrono::duration<ArithmeticType, PeriodType> m_duration;
    };

    using Duration = base::DurationType<double>;
    using DurationSharedPtr = std::shared_ptr<Duration>;

    template <typename ArithmeticType, typename PeriodType>
    DurationType<ArithmeticType, PeriodType>::DurationType(const std::chrono::duration<ArithmeticType, PeriodType>& duration) :
        m_duration(duration)
    {
    }

    template <typename ArithmeticType, typename PeriodType>
    DurationType<ArithmeticType, PeriodType>::~DurationType()
    {
    }

    template <typename ArithmeticType, typename PeriodType>
    inline const std::chrono::duration<ArithmeticType, PeriodType>& DurationType<ArithmeticType, PeriodType>::getDuration() const
    {
        return m_duration;
    }

    /**
     * Gets the seconds of the duration.
     */
    template <typename ArithmeticType, typename PeriodType>
    size_t DurationType<ArithmeticType, PeriodType>::toSeconds() const
    {
        SecondTick durationSeconds(m_duration);
        return durationSeconds.count();
    }

    /**
     * Gets the milliseconds of the duration.
     */
    template <typename ArithmeticType, typename PeriodType>
    size_t DurationType<ArithmeticType, PeriodType>::toMilliseconds() const
    {
        MilliSecondTick durationMilliseconds(m_duration);
        return durationMilliseconds.count();
    }

    /**
     * Creates the duration from seconds.
     */
    template <typename ArithmeticType, typename PeriodType>
    std::shared_ptr<DurationType<ArithmeticType, PeriodType>> DurationType<ArithmeticType, PeriodType>::fromSeconds(size_t seconds)
    {
        SecondTick durationSeconds(seconds);
        return std::make_shared<Duration>(durationSeconds);
    }

    /**
     * Creates the duration from milliseconds.
     */
    template <typename ArithmeticType, typename PeriodType>
    std::shared_ptr<DurationType<ArithmeticType, PeriodType>> DurationType<ArithmeticType, PeriodType>::fromMilliseconds(size_t milliseconds)
    {
        MilliSecondTick durationMilliseconds(milliseconds);
        return std::make_shared<Duration>(durationMilliseconds);
    }

    /**
     * Gets the information of the duration.
     */
    template <typename ArithmeticType, typename PeriodType>
    inline void DurationType<ArithmeticType, PeriodType>::getDurationInformation(std::ostream& stream) const
    {
        stream << m_duration.count();
    }

    /**
     * Gets the duration between two date-time points.
     */
    template <typename ArithmeticType, typename PeriodType>
    std::shared_ptr<DurationType<ArithmeticType, PeriodType>> DurationType<ArithmeticType, PeriodType>::between(
        const base::DateTime& start,
        const base::DateTime& end)
    {
        return std::make_shared<DurationType<ArithmeticType, PeriodType>>(end.getTimePoint() - start.getTimePoint());
    }

    template <typename ArithmeticType, typename PeriodType>
    inline std::ostream& operator<<(std::ostream& stream, const DurationType<ArithmeticType, PeriodType>& duration)
    {
        duration.getDurationInformation(stream);
        return stream;
    }

    template <typename ArithmeticType, typename PeriodType>
    inline bool operator==(const DurationType<ArithmeticType, PeriodType>& lhs, const DurationType<ArithmeticType, PeriodType>& rhs)
    {
        return lhs.getDuration() == rhs.getDuration();
    }

    template <typename ArithmeticType, typename PeriodType>
    inline bool operator!=(const DurationType<ArithmeticType, PeriodType>& lhs, const DurationType<ArithmeticType, PeriodType>& rhs)
    {
        return !(lhs.getDuration() == rhs.getDuration());
    }

    template <typename ArithmeticType, typename PeriodType>
    inline bool operator<(const DurationType<ArithmeticType, PeriodType>& lhs, const DurationType<ArithmeticType, PeriodType>& rhs)
    {
        return lhs.getDuration() < rhs.getDuration();
    }

    template <typename ArithmeticType, typename PeriodType>
    inline bool operator<=(const DurationType<ArithmeticType, PeriodType>& lhs, const DurationType<ArithmeticType, PeriodType>& rhs)
    {
        return lhs.getDuration() <= rhs.getDuration();
    }

    template <typename ArithmeticType, typename PeriodType>
    inline bool operator>(const DurationType<ArithmeticType, PeriodType>& lhs, const DurationType<ArithmeticType, PeriodType>& rhs)
    {
        return lhs.getDuration() > rhs.getDuration();
    }

    template <typename ArithmeticType, typename PeriodType>
    inline bool operator>=(const DurationType<ArithmeticType, PeriodType>& lhs, const DurationType<ArithmeticType, PeriodType>& rhs)
    {
        return lhs.getDuration() >= rhs.getDuration();
    }

}

#endif // DURATION_H_b4a151bc_6f7a_4a2e_9d44_95df4e17d5c2
