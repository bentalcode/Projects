package problems.core;

import base.core.TwoDimensionalArrayIterator;
import base.core.TwoDimensionalListIterator;
import java.util.List;
import problems.interfaces.IPermutation;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The PermutationTest class implements tests for the permutations problem.
 */
public final class PermutationTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The PermutationTest constructor.
     */
    public PermutationTest() {
    }

    /**
     * Tests the logic for calculating permutations.
     */
    @Test
    public void permuteTest() {
        Integer[] values1 = {1, 2, 3};

        Integer[][] result1 = {
            {1, 2, 3},
            {1, 3, 2},
            {2, 1, 3},
            {2, 3, 1},
            {3, 2, 1},
            {3, 1, 2}
        };

        this.testPermute(values1, result1);
    }

    /**
     * Tests the logic for calculating unique permutations.
     */
    @Test
    public void permuteUniqueTest() {
        Integer[] values1 = {1, 2, 3};

        Integer[][] result1 = {
            {1, 2, 3},
            {1, 3, 2},
            {2, 1, 3},
            {2, 3, 1},
            {3, 2, 1},
            {3, 1, 2}
        };

        Integer[] values2 = {1, 1, 2};

        Integer[][] result2 = {
            {1, 1, 2},
            {1, 2, 1},
            {2, 1, 1}
        };

        this.testUniquePermute(values1, result1);
        this.testUniquePermute(values2, result2);
    }

    private <T extends Comparable<T>> void testPermute(T[] values, T[][] expectedResult) {
        IPermutation permutation = new Permutation();
        List<List<T>> result = permutation.permute(values);

        this.assertion.assertEqualsWithIterators(
            TwoDimensionalListIterator.make(result),
            TwoDimensionalArrayIterator.make(expectedResult),
            "Incorrect logic for calculating permutations.");
    }

    private <T extends Comparable<T>> void testUniquePermute(T[] values, T[][] expectedResult) {
        IPermutation permutation = new Permutation();
        List<List<T>> result = permutation.permuteUnique(values);

        this.assertion.assertEqualsWithIterators(
            TwoDimensionalListIterator.make(result),
            TwoDimensionalArrayIterator.make(expectedResult),
            "Incorrect logic for calculating unique permutations.");
    }
}
