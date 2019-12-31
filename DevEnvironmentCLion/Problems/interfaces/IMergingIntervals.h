#ifndef I_MERGING_INTERVALS_H_913a1d60_425e_4bc4_85ed_3af83a1cbf66
#define I_MERGING_INTERVALS_H_913a1d60_425e_4bc4_85ed_3af83a1cbf66

#include "Interval.h"

namespace problems
{
    /**
     * The IMergingIntervals interface defines a merging intervals problem.
     */
    template <typename T>
    class IMergingIntervals
    {
    public:
        /**
         * The constructor.
         */
        IMergingIntervals() = default;

        /**
         * The destructor.
         */
        virtual ~IMergingIntervals() = default;

        /**
         * The copy/move constructors.
         */
        IMergingIntervals(const IMergingIntervals&) = delete;
        IMergingIntervals(IMergingIntervals&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        IMergingIntervals& operator=(const IMergingIntervals&) = delete;
        IMergingIntervals& operator=(IMergingIntervals&&) = delete;

        /**
         * Merges the intervals.
         */
        virtual std::vector<base::IntervalPtr<T>> merge(const std::vector<base::IntervalPtr<T>>& intervals) = 0;
    };

}

#endif // I_MERGING_INTERVALS_H_913a1d60_425e_4bc4_85ed_3af83a1cbf66
