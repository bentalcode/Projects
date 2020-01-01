package problems.core;

import base.core.Base;
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
        List<IInterval<Type>> result = new ArrayList<>();

        if (intervals.isEmpty()) {
            return result;
        }

        List<IInterval<Type>> sortedIntervals = Interval.sort(intervals);

        Stack<IInterval<Type>> stack = new Stack<>();
        stack.push(sortedIntervals.get(0));

        for (int index = 1; index < sortedIntervals.size(); ++index) {
            IInterval<Type> currInterval = sortedIntervals.get(index);
            IInterval<Type> prevInterval = stack.pop();

            if (Interval.overlap(prevInterval, currInterval)) {
                IInterval<Type> mergedInterval = Interval.of(
                    prevInterval.start(),
                    Base.max(prevInterval.end(), currInterval.end()));

                stack.push(mergedInterval);
            }
            else {
                stack.push(prevInterval);
                stack.push(currInterval);
            }
        }

        result = Stacks.toArrayInReverseOrder(stack);

        return result;
    }
}
