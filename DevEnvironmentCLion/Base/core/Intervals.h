#ifndef INTERVALS_H_b153df21_923f_48cb_a222_e4fea8d5a001
#define INTERVALS_H_b153df21_923f_48cb_a222_e4fea8d5a001

#include "Interval.h"

namespace base
{

    /**
     * The Intervals class template implements complimentary APIs for intervals.
     */
    template <typename T>
    class Intervals final
    {
    public:
        /**
         * Sorts the intervals.
         */
        static std::vector<IntervalPtr<T>> sort(const std::vector<IntervalPtr<T>>& intervals);

    private:
        /**
         * This is a static class - Disables the default constructor and destructor.
         */
        Intervals() = delete;
        ~Intervals() = delete;

        /**
         * Defines the sort interval functor.
         */
        struct SortedIntervalFunctor final : public std::binary_function<IntervalPtr<T>, IntervalPtr<T>, bool>
        {
            bool operator() (IntervalPtr<T> left, IntervalPtr<T> right)
            {
                if (!left && !right)
                {
                    return false;
                }

                if (!left)
                {
                    return true;
                }

                if (!right)
                {
                    return false;
                }

                return *left < *right;
            }
        };
    };

    template <typename T>
    std::vector<IntervalPtr<T>> Intervals<T>::sort(const std::vector<IntervalPtr<T>>& intervals)
    {
        std::vector<base::IntervalPtr<T>> sortedIntervals(intervals.begin(), intervals.end());
        std::sort(sortedIntervals.begin(), sortedIntervals.end(), SortedIntervalFunctor());
        return sortedIntervals;
    }
}

#endif // INTERVALS_H_b153df21_923f_48cb_a222_e4fea8d5a001
