package problems.core;

import base.core.IteratorOfIteratorCollection;
import base.core.ListIterator;
import base.core.TwoDimensionalIntegerArrayIterator;
import java.util.List;
import java.util.Set;
import problems.interfaces.ICombinationSum;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The CombinationSumTest class implements tests for a combination sum problem.
 */
public final class CombinationSumTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The CombinationSumTest constructor.
     */
    public CombinationSumTest() {
    }

    /**
     * Tests the logic for combination sum.
     */
    @Test
    public void combinationSumTest() {
        int[] values1 = {2, 3, 6, 7};
        int sum1 = 7;
        int[][] result1 = {{7}, {2, 2, 3}};

        int[] values2 = {1, 1, 1, 1, 1};
        int sum2 = 5;
        int[][] result2 = {{1, 1, 1, 1, 1}};

        int[] values3 = {1, 2, 1, 2, 1};
        int sum3 = 9;
        int[][] result3 = {
            {1, 2, 2, 2, 2},
            {1, 1, 1, 2, 2, 2},
            {1, 1, 1, 1, 1, 2, 2},
            {1, 1, 1, 1, 1, 1, 1, 2},
            {1, 1, 1, 1, 1, 1, 1, 1, 1},
        };

        this.testCombinationSum(values1, sum1, result1);
        this.testCombinationSum(values2, sum2, result2);
        this.testCombinationSum(values3, sum3, result3);
    }

    /**
     * Tests the logic for single combination sum.
     */
    @Test
    public void singleCombinationSumTest() {
        int[] values1 = {10, 1, 2, 7, 6, 1, 5};
        int sum1 = 8;
        int[][] result1 = {
            {1, 7},
            {2, 6},
            {1, 1, 6},
            {1, 2, 5},
        };

        int[] values2 = {1};
        int sum2 = 1;
        int[][] result2 = {
            {1},
        };

        int[] values3 = {1, 2};
        int sum3 = 4;
        int[][] result3 = {
            {},
        };

        this.testSingleCombinationSum(values1, sum1, result1);
        this.testSingleCombinationSum(values2, sum2, result2);
        this.testSingleCombinationSum(values3, sum3, result3);
    }

    /**
     * Tests the logic for combination sum.
     */
    private void testCombinationSum(
        int[] values,
        int sum,
        int[][] expectedResult) {

        ICombinationSum combinationSum = new CombinationSum();
        Set<List<Integer>> result = combinationSum.combinationSum(values, sum);

        this.assertion.assertEqualsWithIterators(
            IteratorOfIteratorCollection.ofObjects(result, ListIterator::make),
            TwoDimensionalIntegerArrayIterator.make(expectedResult),
            "Incorrect logic for calculating the combination sum.");
    }

    /**
     * Tests the logic for single combination sum.
     */
    private void testSingleCombinationSum(
        int[] values,
        int sum,
        int[][] expectedResult) {

        ICombinationSum combinationSum = new CombinationSum();
        Set<List<Integer>> result = combinationSum.singleCombinationSum(values, sum);

        this.assertion.assertEqualsWithIterators(
            IteratorOfIteratorCollection.ofObjects(result, ListIterator::make),
            TwoDimensionalIntegerArrayIterator.make(expectedResult),
            "Incorrect logic for calculating the single combination sum.");

    }
}
