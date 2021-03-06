#ifndef I_MERGING_INTERVALS_H_71ae779d_5d65_4965_9226_1b4216b9ccca
#define I_MERGING_INTERVALS_H_71ae779d_5d65_4965_9226_1b4216b9ccca

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

#endif // I_MERGING_INTERVALS_H_71ae779d_5d65_4965_9226_1b4216b9ccca
