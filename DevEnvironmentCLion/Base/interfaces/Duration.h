#ifndef DURATION_H_b4a151bc_6f7a_4a2e_9d44_95df4e17d5c2
#define DURATION_H_b4a151bc_6f7a_4a2e_9d44_95df4e17d5c2

#include <chrono>

namespace base
{
    /**
     * The Duration class implements a duration.
     */
    template <typename ArithmeticType, typename PeriodType = std::ratio<1>>
    class Duration final
    {
    public:
        /**
         * The constructor.
         */
        explicit Duration(const std::chrono::duration<ArithmeticType, PeriodType>& duration);

        /**
         * The destructor.
         */
        ~Duration();

        /**
         * The copy/move constructors.
         */
        Duration(const Duration&) = delete;
        Duration(Duration&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        Duration& operator=(const Duration&) = delete;
        Duration& operator=(Duration&&) = delete;

        /**
         * Gets the duration.
         */
        inline const std::chrono::duration<ArithmeticType, PeriodType>& getDuration() const;

        /**
         * Gets the information of the duration.
         */
        void getDurationInformation(std::ostream& stream) const;

    private:
        std::chrono::duration<ArithmeticType, PeriodType> m_duration;
    };

    template <typename ArithmeticType, typename PeriodType>
    Duration<ArithmeticType, PeriodType>::Duration(const std::chrono::duration<ArithmeticType, PeriodType>& duration) :
        m_duration(duration)
    {
    }

    template <typename ArithmeticType, typename PeriodType>
    Duration<ArithmeticType, PeriodType>::~Duration()
    {
    }

    template <typename ArithmeticType, typename PeriodType>
    inline const std::chrono::duration<ArithmeticType, PeriodType>& Duration<ArithmeticType, PeriodType>::getDuration() const
    {
        return m_duration;
    }

    /**
     * Gets the information of the duration.
     */
    template <typename ArithmeticType, typename PeriodType>
    inline void Duration<ArithmeticType, PeriodType>::getDurationInformation(std::ostream& stream) const
    {
        stream << m_duration.count();
    }

    template <typename ArithmeticType, typename PeriodType>
    inline std::ostream& operator<<(std::ostream& stream, const Duration<ArithmeticType, PeriodType>& duration)
    {
        duration.getDurationInformation(stream);
        return stream;
    }
}

#endif // DURATION_H_b4a151bc_6f7a_4a2e_9d44_95df4e17d5c2
