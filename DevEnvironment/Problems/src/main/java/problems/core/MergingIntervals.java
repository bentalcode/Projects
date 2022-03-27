package problems.core;

import base.core.Base;
import base.core.Conditions;
import base.core.Interval;
import base.core.Stacks;
import base.interfaces.IInterval;
import problems.interfaces.IMergingIntervals;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * The MergingIntervals class implements the merging intervals problem.
 */
public final class MergingIntervals<Type extends Comparable<Type>> implements IMergingIntervals<Type> {

    /**
     * Merges intervals.
     */
    @Override
    public List<IInterval<Type>> merge(List<IInterval<Type>> intervals) {
        Conditions.validateNotNull(
            intervals,
            "The intervals");

        if (intervals.size() <= 1) {
            return intervals;
        }

        List<IInterval<Type>> sortedIntervals = Interval.sort(intervals);

        Stack<IInterval<Type>> stack = new Stack<>();
        stack.push(sortedIntervals.get(0));

        for (int index = 1; index < sortedIntervals.size(); ++index) {
            IInterval<Type> currInterval = sortedIntervals.get(index);
            IInterval<Type> prevInterval = stack.pop();

            this.merge(prevInterval, currInterval, stack);
        }

        return Stacks.toArrayInReverseOrder(stack);
    }

    /**
     * Inserts a new interval into sorted intervals.
     */
    @Override
    public List<IInterval<Type>> insert(
        List<IInterval<Type>> sortedIntervals,
        IInterval<Type> interval) {

        Conditions.validateNotNull(
            sortedIntervals,
            "The sorted intervals.");

        Conditions.validateNotNull(
            interval,
            "The new interval for inserting.");

        int insertIndex = this.findInsertIndex(sortedIntervals, interval);

        if (insertIndex == -1) {
            List<IInterval<Type>> result = new ArrayList<>(sortedIntervals.size() + 1);

            result.add(interval);
            result.addAll(sortedIntervals);

            return result;
        }
        else if (insertIndex == sortedIntervals.size() - 1) {
            List<IInterval<Type>> result = new ArrayList<>(sortedIntervals.size() + 1);

            result.addAll(sortedIntervals);
            result.add(interval);

            return result;
        }

        Stack<IInterval<Type>> stack = new Stack<>();

        int index = 0;

        while (index <= insertIndex) {
            IInterval<Type> currInterval = sortedIntervals.get(index);
            stack.push(currInterval);

            ++index;
        }

        IInterval<Type> prevInterval = stack.pop();
        IInterval<Type> currInterval = interval;

        this.merge(prevInterval, currInterval, stack);

        while (index < sortedIntervals.size()) {
            currInterval = sortedIntervals.get(index);
            prevInterval = stack.pop();

            this.merge(prevInterval, currInterval, stack);

            ++index;
        }

        return Stacks.toArrayInReverseOrder(stack);
    }

    /**
     * Finds the insert index relatively to the previous item.
     */
    private int findInsertIndex(List<IInterval<Type>> sortedIntervals, IInterval<Type> interval) {
        if (sortedIntervals.isEmpty()) {
            return -1;
        }

        int startIndex = 0;
        int endIndex = sortedIntervals.size() - 1;

        return this.findInsertIndex(sortedIntervals, startIndex, endIndex, interval);
    }

    /**
     * Finds the insert index relatively to the previous item.
     */
    private int findInsertIndex(
        List<IInterval<Type>> intervals,
        int startIndex,
        int endIndex,
        IInterval<Type> interval) {

        if (startIndex > endIndex) {
            return -1;
        }

        int midIndex = startIndex + ((endIndex - startIndex) >> 1);

        IInterval<Type> midInterval = intervals.get(midIndex);

        int compareStatus = midInterval.compareTo(interval);

        if (compareStatus == 0) {
            return midIndex;
        }
        else if (compareStatus < 0) {
            if (midIndex == endIndex) {
                return endIndex;
            }

            int afterMidIndex = midIndex + 1;
            IInterval<Type> afterMidInterval = intervals.get(afterMidIndex);
            int nextCompareStatus = interval.compareTo(afterMidInterval);

            if (nextCompareStatus == 0) {
                return afterMidIndex;
            }
            else if (nextCompareStatus == -1) {
                return midIndex;
            }
            else {
                return this.findInsertIndex(
                    intervals,
                    afterMidIndex,
                    endIndex,
                    interval);
            }
        }
        else {
            return this.findInsertIndex(
                intervals,
                startIndex,
                midIndex - 1,
                interval);
        }
    }

    /**
     * Merges the intervals.
     */
    private void merge(
        IInterval<Type> prevInterval,
        IInterval<Type> currInterval,
        Stack<IInterval<Type>> stack) {

        if (Interval.overlap(prevInterval, currInterval)) {
            IInterval<Type> mergedInterval = Interval.make(
                prevInterval.start(),
                Base.max(prevInterval.end(), currInterval.end()));

            stack.push(mergedInterval);
        }
        else {
            stack.push(prevInterval);
            stack.push(currInterval);
        }
    }
}
