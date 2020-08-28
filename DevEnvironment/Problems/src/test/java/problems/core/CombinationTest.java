package problems.core;

import base.core.TwoDimensionalIntegerArrayIterator;
import base.core.TwoDimensionalListIterator;
import base.interfaces.ICalculator;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import java.util.List;

/**
 * The CombinationTest class implements tests for a combination problem.
 */
public final class CombinationTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The CombinationTest constructor.
     */
    public CombinationTest() {
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
     * Tests the logic for combination.
     */
    @Test
    public void combinationTest() {
        int n = 4;
        int k = 2;
        int[][] result1 = {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};

        this.testCombination(n, k, result1);
    }

    /**
     * Tests the logic for combination.
     */
    private void testCombination(
        int n,
        int k,
        int[][] expectedResult) {

        ICalculator<List<List<Integer>>> combination = new Combination(n, k);

        List<List<Integer>> result = combination.calculate();

        this.assertion.assertEqualsWithIterators(
            TwoDimensionalListIterator.make(result),
            TwoDimensionalIntegerArrayIterator.make(expectedResult),
            "Incorrect logic for calculating the combination.");
    }
}