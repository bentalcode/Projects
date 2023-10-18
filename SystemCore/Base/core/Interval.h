#ifndef INTERVAL_H_a1a25086_de91_44c6_9219_767e45bae8e0
#define INTERVAL_H_a1a25086_de91_44c6_9219_767e45bae8e0

#include "ErrorCodes.h"
#include "BaseException.h"
#include <memory>

namespace base
{
    /**
     * The Interval class template implements an interval.
     */
    template <typename T>
    class Interval final
    {
    public:
        /**
         * Creates an interval.
         */
        static Interval<T> Make(const T& start, const T& end);

        /**
         * The constructor.
         */
        Interval(const T& start, const T& end);

        /**
         * The destructor.
         */
        ~Interval();

        /**
         * The Copy/move constructors.
         */
        Interval(const Interval&) = default;
        Interval(Interval&&) = default;

        /**
         * The Copy/move assignment operators.
         */
        Interval& operator=(const Interval&) = default;
        Interval& operator=(Interval&&) = default;

        /**
         * Gets the start point of an interval.
         */
        const T& GetStart() const;

        /**
         * Gets the End point of an interval.
         */
        const T& GetEnd() const;

        /**
         * Determines whether the sorted intervals Overlap.
         */
        static bool Overlap(const base::Interval<T>& left, const base::Interval<T>& right);

    private:
        /**
         * Validates the interval start and End points.
         */
        static void Validate(const T& start, const T& end);

        T m_start;
        T m_end;
    };

    //
    // Define the SharedPtr of Interval...
    //
    template <typename T>
    using IntervalSharedPtr = std::shared_ptr<Interval<T>>;

    /**
     * Creates an interval.
     */
    template <typename T>
    Interval<T> Interval<T>::Make(const T& start, const T& end)
    {
        return Interval<T>(start, end);
    }

    /**
     * The Interval constructor.
     */
    template <typename T>
    Interval<T>::Interval(const T& start, const T& end) :
        m_start(start),
        m_end(end)
    {
        Validate(start, end);
    }

    /**
     * The Interval destructor.
     */
    template <typename T>
    Interval<T>::~Interval()
    {
    }

    /**
     * Gets the start point of an interval.
     */
    template <typename T>
    const T& Interval<T>::GetStart() const
    {
        return m_start;
    }

    /**
     * Gets the End point of an interval.
     */
    template <typename T>
    const T& Interval<T>::GetEnd() const
    {
        return m_end;
    }

    /**
     * Defines operator less ofintervals.
     */
    template <typename T>
    bool operator<(const Interval<T>& left, const Interval<T>& right)
    {
        if (left.GetStart() < right.GetStart())
        {
            return true;
        }

        if (left.GetStart() > right.GetStart())
        {
            return false;
        }

        return left.GetEnd() < right.GetEnd();
    }

    /**
     * Determines whether the sorted intervals Overlap.
     */
    template <typename T>
    bool Interval<T>::Overlap(const base::Interval<T>& left, const base::Interval<T>& right)
    {
        assert(left <= right);

        return (right.GetStart() <= left.GetEnd());
    }

    /**
     * Validates the interval start and End points.
     */
    template <typename T>
    void Interval<T>::Validate(const T& start, const T& end)
    {
        if (start > end)
        {
            long statusCode = ErrorCodes::OUT_OF_RANGE;
            std::wstring errorMessage = L"Invalid interval start and End points.";
            throw BaseException(statusCode, errorMessage);
        }
    }

    /**
     * Implements an operator equals for intervals.
     */
    template<typename T>
    inline bool operator==(
        const Interval<T>& lhs,
        const Interval<T>& rhs)
    {
        return lhs.GetStart() == rhs.GetStart() && lhs.GetEnd() == rhs.GetEnd();
    }

    /**
     * Implements an operator not equals for intervals.
     */
    template<typename T>
    inline bool operator!=(
        const Interval<T>& lhs,
        const Interval<T>& rhs)
    {
        return !(lhs == rhs);
    }
}

#endif // INTERVAL_H_a1a25086_de91_44c6_9219_767e45bae8e0
