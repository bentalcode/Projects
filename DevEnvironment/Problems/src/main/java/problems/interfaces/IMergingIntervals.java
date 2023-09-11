package problems.interfaces;

import base.interfaces.IInterval;
import java.util.List;

/**
 * The IMergingIntervals interface defines a merging intervals problem.
 */
public interface IMergingIntervals<Type extends Comparable<Type>> {
    /**
     * Merges intervals.
     */
     List<IInterval<Type>> merge(List<IInterval<Type>> intervals);

    /**
     * Inserts a new interval into sorted intervals.
     */
    List<IInterval<Type>> insert(List<IInterval<Type>> sortedIntervals, IInterval<Type> interval);
}
