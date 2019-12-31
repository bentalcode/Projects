#ifndef INTERVALS_H_4dad83d8_355f_4e29_8c37_346b95c46e39
#define INTERVALS_H_4dad83d8_355f_4e29_8c37_346b95c46e39

#include "Interval.h"

namespace base
{

    /**
     * The Intervals class template implements complimentary APIs for intervals.
     */
    template <typename Type>
    class Intervals final
    {
    public:
        /**
         * The constructor.
         */
        Intervals() = delete;

        /**
         * The destructor.
         */
        ~Intervals() = delete;

        /**
         * The copy/move constructors.
         */
        Intervals(const Intervals&) = delete;
        Intervals(Intervals&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        Intervals& operator=(const Intervals&) = delete;
        Intervals& operator=(Intervals&&) = delete;

        /**
         * Sorts the intervals.
         */
        static std::vector<IntervalPtr<Type>> sort(const std::vector<IntervalPtr<Type>>& intervals);

    private:
        struct SortedIntervalFunctor : public std::binary_function<IntervalPtr<Type>, IntervalPtr<Type>, bool>
        {
            bool operator() (IntervalPtr<Type> left, IntervalPtr<Type> right)
            {
                return *left < *right;
            }
        };
    };

    template <typename Type>
    std::vector<IntervalPtr<Type>> Intervals<Type>::sort(const std::vector<IntervalPtr<Type>>& intervals)
    {
        std::vector<base::IntervalPtr<Type>> sortedIntervals(intervals.begin(), intervals.end());
        std::sort(sortedIntervals.begin(), sortedIntervals.end(), SortedIntervalFunctor());
        return sortedIntervals;
    }
}

#endif // INTERVALS_H_4dad83d8_355f_4e29_8c37_346b95c46e39
