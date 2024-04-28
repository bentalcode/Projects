package problems.core;

import problems.interfaces.IMedianOfSortedArrays;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The MedianOfSortedArraysTest class implements tests for the median of sorted arrays' problem.
 */
public final class MedianOfSortedArraysTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The MedianOfSortedArraysTest constructor.
     */
    public MedianOfSortedArraysTest() {
    }

    /**
     * Tests the logic for median of sorted arrays.
     */
    @Test
    public void medianOfSortedArraysTest() {
        int[] a1 = {900};
        int[] b1 = {5, 8, 10, 20};

        double result1 = 10;

        int[] a2 = {-5, 900};
        int[] b2 = {5, 8, 10, 20};

        double result2 = 9;

        int[] a3 = {-5, 3, 6, 12, 15};
        int[] b3 = {-12, -10, -6, -3, 4, 10};

        // Merged: {-12, -10, -6, -5, -3, 3, 4, 6, 10, 12, 15}
        double result3 = 3.0;

        int[] a4 = {2, 3, 5, 8};
        int[] b4 = {10, 12, 14, 16, 18, 20};

        // Merged: {2, 3, 5, 8, 10, 12, 14, 16, 18, 20}
        double result4 = 11.0;

        int[] a5 = {2, 3, 5, 8};
        int[] b5 = {10, 12, 14, 16, 18, 20, 21};

        // Merged: {2, 3, 5, 8, 10, 12, 14, 16, 18, 20, 21}
        double result5 = 12.0;

        int[] a6 = {1, 2, 3, 4, 5};
        int[] b6 = {6, 7, 8, 9, 10, 11, 12};

        // Merged: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}
        double result6 = 6.5;

        int[] a7 = {1, 4, 5, 6};
        int[] b7 = {2, 3, 7, 8};
        double result7 = 4.5;

        this.testMedianOfSortedArrays(a1, b1, result1);
        this.testMedianOfSortedArrays(b1, a1, result1);

        this.testMedianOfSortedArrays(a2, b2, result2);
        this.testMedianOfSortedArrays(b2, a2, result2);

        this.testMedianOfSortedArrays(a3, b3, result3);
        this.testMedianOfSortedArrays(b3, a3, result3);

        this.testMedianOfSortedArrays(a4, b4, result4);
        this.testMedianOfSortedArrays(b4, a4, result4);

        this.testMedianOfSortedArrays(a6, b6, result6);
        this.testMedianOfSortedArrays(b6, a6, result6);

        this.testMedianOfSortedArrays(a7, b7, result7);
        this.testMedianOfSortedArrays(b7, a7, result7);
    }

    /**
     * Tests the logic for median of sorted arrays.
     */
    private void testMedianOfSortedArrays(
        int[] a,
        int[] b,
        double expectedResult) {

        IMedianOfSortedArrays medianOfSortedArrays = new MedianOfSortedArrays();
        double result = medianOfSortedArrays.median(a, b);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic for calculating the median of sorted arrays.");
    }
}
