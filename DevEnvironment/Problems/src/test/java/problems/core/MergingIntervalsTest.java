package problems.core;

import base.core.ArrayLists;
import base.core.Interval;
import base.core.ListIterator;
import base.interfaces.IInterval;
import java.util.List;
import problems.interfaces.IMergingIntervals;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The MergingIntervalsTest class implements tests for the merging intervals problem.
 */
public final class MergingIntervalsTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The MergingIntervalsTest constructor.
     */
    public MergingIntervalsTest() {
    }

    /**
     * Tests the logic for merging intervals.
     */
    @Test
    public void mergingIntervalsTest() {
        List<IInterval<Integer>> intervals1 = ArrayLists.make();
        List<IInterval<Integer>> result1 = ArrayLists.make();

        List<IInterval<Integer>> intervals2 = ArrayLists.make(
            Interval.make(3, 5),
            Interval.make(1, 2),
            Interval.make(6, 7)
        );

        List<IInterval<Integer>> result2 = ArrayLists.make(
            Interval.make(1, 2),
            Interval.make(3, 5),
            Interval.make(6, 7)
        );

        List<IInterval<Integer>> intervals3 = ArrayLists.make(
            Interval.make(2, 4),
            Interval.make(1, 2),
            Interval.make(4, 7)
        );

        List<IInterval<Integer>> result3 = ArrayLists.make(
            Interval.make(1, 7)
        );

        List<IInterval<Integer>> intervals4 = ArrayLists.make(
            Interval.make(2, 3),
            Interval.make(1, 2),
            Interval.make(4, 7),
            Interval.make(2, 4)
        );

        List<IInterval<Integer>> result4 = ArrayLists.make(
            Interval.make(1, 7)
        );

        List<IInterval<Integer>> intervals5 = ArrayLists.make(
            Interval.make(1, 3),
            Interval.make(1, 2),
            Interval.make(4, 5),
            Interval.make(10, 12)
        );

        List<IInterval<Integer>> result5 = ArrayLists.make(
            Interval.make(1, 3),
            Interval.make(4, 5),
            Interval.make(10, 12)
        );

        this.testMergingIntervals(intervals1, result1);
        this.testMergingIntervals(intervals2, result2);
        this.testMergingIntervals(intervals3, result3);
        this.testMergingIntervals(intervals4, result4);
        this.testMergingIntervals(intervals5, result5);
    }

    /**
     * Tests the logic for inserting an interval.
     */
    @Test
    public void insertIntervalTest() {
        List<IInterval<Integer>> intervals1 = ArrayLists.make(
            Interval.make(1,3),
            Interval.make(6,9)
        );

        IInterval<Integer> interval1 = Interval.make(2,5);

        List<IInterval<Integer>> result1 = ArrayLists.make(
            Interval.make(1,5),
            Interval.make(6,9)
        );

        List<IInterval<Integer>> intervals2 = ArrayLists.make(
            Interval.make(1,2),
            Interval.make(3,5),
            Interval.make(6,7),
            Interval.make(8,10),
            Interval.make(12,16)
        );

        IInterval<Integer> interval2 = Interval.make(4,8);

        List<IInterval<Integer>> result2 = ArrayLists.make(
            Interval.make(1,2),
            Interval.make(3,10),
            Interval.make(12,16)
        );

        this.testInsertInterval(intervals1, interval1, result1);
        this.testInsertInterval(intervals2, interval2, result2);
    }

    /**
     * Tests the logic for merging intervals.
     */
    private <Type extends Comparable<Type>> void testMergingIntervals(
        List<IInterval<Type>> intervals,
        List<IInterval<Type>> expectedResult) {

        IMergingIntervals<Type> mergingIntervals = new MergingIntervals<>();
        List<IInterval<Type>> result = mergingIntervals.merge(intervals);

        this.assertion.assertEqualsWithIterators(
            ListIterator.make(result),
            ListIterator.make(expectedResult),
            "Incorrect logic for merging intervals.");
    }

    /**
     * Tests the logic for inserting an interval.
     */
    private <Type extends Comparable<Type>> void testInsertInterval(
        List<IInterval<Type>> intervals,
        IInterval<Type> interval,
        List<IInterval<Type>> expectedResult) {

        IMergingIntervals<Type> mergingIntervals = new MergingIntervals<>();
        List<IInterval<Type>> result = mergingIntervals.insert(intervals, interval);

        this.assertion.assertEqualsWithIterators(
            ListIterator.make(result),
            ListIterator.make(expectedResult),
            "Incorrect logic for inserting an interval.");
    }
}
