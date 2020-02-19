package problems.core;

import base.core.ArrayLists;
import base.core.Interval;
import base.core.ListIterator;
import base.interfaces.IInterval;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import problems.interfaces.IMergingIntervals;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import java.util.List;

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
     * Initialize the tests.
     */
    @Before
    public void setUp() {
    }

    /**
     * Un-Initializes the tests.
     */
    @After
    public void tearDown() {
    }

    /**
     * Tests the logic for merging intervals.
     */
    @Test
    public void mergingIntervalsTest() {
        List<IInterval<Integer>> intervals1 = ArrayLists.empty();
        List<IInterval<Integer>> result1 = ArrayLists.empty();

        List<IInterval<Integer>> intervals2 = ArrayLists.of(
            Interval.of(3, 5),
            Interval.of(1, 2),
            Interval.of(6, 7)
        );

        List<IInterval<Integer>> result2 = ArrayLists.of(
            Interval.of(1, 2),
            Interval.of(3, 5),
            Interval.of(6, 7)
        );

        List<IInterval<Integer>> intervals3 = ArrayLists.of(
            Interval.of(2, 4),
            Interval.of(1, 2),
            Interval.of(4, 7)
        );

        List<IInterval<Integer>> result3 = ArrayLists.of(
            Interval.of(1, 7)
        );

        List<IInterval<Integer>> intervals4 = ArrayLists.of(
            Interval.of(2, 3),
            Interval.of(1, 2),
            Interval.of(4, 7),
            Interval.of(2, 4)
        );

        List<IInterval<Integer>> result4 = ArrayLists.of(
            Interval.of(1, 7)
        );

        List<IInterval<Integer>> intervals5 = ArrayLists.of(
            Interval.of(1, 3),
            Interval.of(1, 2),
            Interval.of(4, 5),
            Interval.of(10, 12)
        );

        List<IInterval<Integer>> result5 = ArrayLists.of(
            Interval.of(1, 3),
            Interval.of(4, 5),
            Interval.of(10, 12)
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
        List<IInterval<Integer>> intervals1 = ArrayLists.of(
            Interval.of(1,3),
            Interval.of(6,9)
        );

        IInterval<Integer> interval1 = Interval.of(2,5);

        List<IInterval<Integer>> result1 = ArrayLists.of(
            Interval.of(1,5),
            Interval.of(6,9)
        );

        List<IInterval<Integer>> intervals2 = ArrayLists.of(
            Interval.of(1,2),
            Interval.of(3,5),
            Interval.of(6,7),
            Interval.of(8,10),
            Interval.of(12,16)
        );

        IInterval<Integer> interval2 = Interval.of(4,8);

        List<IInterval<Integer>> result2 = ArrayLists.of(
            Interval.of(1,2),
            Interval.of(3,10),
            Interval.of(12,16)
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
            ListIterator.of(result),
            ListIterator.of(expectedResult),
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
            ListIterator.of(result),
            ListIterator.of(expectedResult),
            "Incorrect logic for inserting an interval.");
    }
}
