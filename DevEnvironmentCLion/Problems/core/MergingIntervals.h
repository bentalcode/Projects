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
        virtual std::vector<base::IntervalPtr<T>> merge(const std::vector<base::IntervalPtr<T>>& intervals);

    private:
        /**
         * Tries to merge the left and right sorted intervals.
         */
        base::IntervalPtr<T> tryMerge(const base::Interval<T>& left, const base::Interval<T>& right);

        /**
         * Creates the results.
         */
        std::vector<base::IntervalPtr<T>> createResults(std::stack<base::IntervalPtr<T>>& stack);
    };

    template <typename T>
    std::vector<base::IntervalPtr<T>> MergingIntervals<T>::merge(const std::vector<base::IntervalPtr<T>>& intervals)
    {
        std::vector<base::IntervalPtr<T>> result;

        if (intervals.empty())
        {
            return result;
        }

        std::vector<base::IntervalPtr<T>> sortedIntervals(intervals.begin(), intervals.end());
        base::Sorting::dereferenceSort(sortedIntervals);

        std::stack<base::IntervalPtr<T>> stack;
        stack.push(sortedIntervals[0]);

        for (int i = 1; i < sortedIntervals.size(); ++i)
        {
            base::IntervalPtr<T> currInterval = sortedIntervals[i];
            base::IntervalPtr<T> prevInterval = stack.top();
            stack.pop();

            base::IntervalPtr<T> mergedInterval = tryMerge(*prevInterval, *currInterval);

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
    base::IntervalPtr<T> MergingIntervals<T>::tryMerge(const base::Interval<T>& left, const base::Interval<T>& right)
    {
        base::IntervalPtr<T> mergedInterval = nullptr;

        if (base::Interval<T>::overlap(left, right))
        {
            mergedInterval.reset(new base::Interval<T>(left.getStart(), std::max(left.getEnd(), right.getEnd())));
        }

        return mergedInterval;
    }

    template <typename T>
    std::vector<base::IntervalPtr<T>> MergingIntervals<T>::createResults(std::stack<base::IntervalPtr<T>>& stack)
    {
        std::vector<base::IntervalPtr<T>> result(stack.size());

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
