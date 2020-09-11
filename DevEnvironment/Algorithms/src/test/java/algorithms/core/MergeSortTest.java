package algorithms.core;

import algorithms.interfaces.ISort;
import base.core.ArrayIterator;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

/**
 * The MergeSortTest class implements tests for a merge sort.
 */
public final class MergeSortTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The MergeSortTest constructor.
     */
    public MergeSortTest() {
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
     * Tests the logic of a merge sort.
     */
    @Test
    public void mergeSortTest() {
        Integer[] input1 = {};
        Integer[] result1 = {};

        Integer[] input2 = {2};
        Integer[] result2 = {2};

        Integer[] input3 = {1, 5, 5, 2, 7, 9};
        Integer[] result3 = {1, 2, 5, 5, 7, 9};

        Integer[] input4 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        Integer[] result4 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        Integer[] input5 = {10, 8, 8, 7, 6, 5, 5, 3, 2, 1};
        Integer[] result5 = {1, 2, 3, 5, 5, 6, 7, 8, 8, 10};

        Class<Integer> classType = Integer.class;

        this.testMergeSort(
            input1,
            classType,
            result1);

        this.testMergeSort(
            input2,
            classType,
            result2);

        this.testMergeSort(
            input3,
            classType,
            result3);

        this.testMergeSort(
            input4,
            classType,
            result4);

        this.testMergeSort(
            input5,
            classType,
            result5);
    }

    /**
     * Tests the logic of a merge sort.
     */
    private <T extends Comparable<T>> void testMergeSort(
        T[] arr,
        Class<T> classType,
        T[] expectedResult) {

        ISort<T> mergeSort = new MergeSort<>(
            classType,
            base.core.Comparator.make());

        mergeSort.sort(arr);

        this.assertion.assertEqualsWithIterators(
            ArrayIterator.make(arr),
            ArrayIterator.make(expectedResult),
            "Invalid logic for performing a merge sort.");
    }
}
