#ifndef MERGING_INTERVALS_H_f2c78749_ad4f_466d_8654_06cb81f98301
#define MERGING_INTERVALS_H_f2c78749_ad4f_466d_8654_06cb81f98301

#include "IMergingIntervals.h"
#include "Sorting.h"

namespace problems
{
    /**
     * The MergingIntervals class implements the merging intervals problem.
     */
    template <typename T>
    class MergingIntervals final : public IMergingIntervals<T> {
    public:
        /**
         * The constructor.
         */
        MergingIntervals() = default;

        /**
         * The destructor.
         */
        virtual ~MergingIntervals() = default;

        /**
         * The copy/move constructors.
         */
        MergingIntervals(const MergingIntervals&) = delete;
        MergingIntervals(MergingIntervals&&) = delete;

        /**
         * The copy/move assignment operators.
         */
        MergingIntervals &operator=(const MergingIntervals&) = delete;
        MergingIntervals &operator=(MergingIntervals&&) = delete;

        /**
         * Merges the intervals.
         */
        virtual std::vector<base::IntervalSharedPtr<T>> merge(const std::vector<base::IntervalSharedPtr<T>>& intervals);

    private:
        /**
         * Tries to merge the left and right sorted intervals.
         */
        base::IntervalSharedPtr<T> tryMerge(const base::Interval<T>& left, const base::Interval<T>& right);

        /**
         * Creates the results.
         */
        std::vector<base::IntervalSharedPtr<T>> createResults(std::stack<base::IntervalSharedPtr<T>>& stack);
    };

    template <typename T>
    std::vector<base::IntervalSharedPtr<T>> MergingIntervals<T>::merge(const std::vector<base::IntervalSharedPtr<T>>& intervals)
    {
        std::vector<base::IntervalSharedPtr<T>> result;

        if (intervals.empty())
        {
            return result;
        }

        std::vector<base::IntervalSharedPtr<T>> sortedIntervals(intervals.begin(), intervals.end());
        base::Sorting::dereferenceSort(sortedIntervals);

        std::stack<base::IntervalSharedPtr<T>> stack;
        stack.push(sortedIntervals[0]);

        for (int i = 1; i < sortedIntervals.size(); ++i)
        {
            base::IntervalSharedPtr<T> currInterval = sortedIntervals[i];
            base::IntervalSharedPtr<T> prevInterval = stack.top();
            stack.pop();

            base::IntervalSharedPtr<T> mergedInterval = tryMerge(*prevInterval, *currInterval);

            if (mergedInterval)
            {
                stack.push(mergedInterval);
            }
            else
            {
                stack.push(prevInterval);
                stack.push(currInterval);
            }
        }

        result = createResults(stack);

        return result;
    }

    template <typename T>
    base::IntervalSharedPtr<T> MergingIntervals<T>::tryMerge(const base::Interval<T>& left, const base::Interval<T>& right)
    {
        base::IntervalSharedPtr<T> mergedInterval = nullptr;

        if (base::Interval<T>::overlap(left, right))
        {
            mergedInterval.reset(new base::Interval<T>(left.getStart(), std::max(left.getEnd(), right.getEnd())));
        }

        return mergedInterval;
    }

    template <typename T>
    std::vector<base::IntervalSharedPtr<T>> MergingIntervals<T>::createResults(std::stack<base::IntervalSharedPtr<T>>& stack)
    {
        std::vector<base::IntervalSharedPtr<T>> result(stack.size());

        size_t insertIndex = stack.size() - 1;

        while (!stack.empty() && insertIndex >= 0)
        {
            result[insertIndex] = stack.top();

            stack.pop();
            --insertIndex;
        }

        return result;
    }
}

#endif // MERGING_INTERVALS_H_f2c78749_ad4f_466d_8654_06cb81f98301
