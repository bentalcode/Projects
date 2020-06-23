package problems.core;

import base.interfaces.ICalculator;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

/**
 * The MaxRectangleAreaTest class implements tests for a max rectangle area problem.
 */
public final class MaxRectangleAreaTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The MaxRectangleAreaTest constructor.
     */
    public MaxRectangleAreaTest() {
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
     * Tests the logic for calculating the max rectangle area.
     */
    @Test
    public void maxRectangleAreaTest() {
        int[][] data1 =
        {
            {1, 0, 1, 0, 0},
            {1, 0, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 0, 0, 1, 0}
        };

        int result1 = 6;

        this.testMaxRectangleArea(data1, result1);
    }

    /**
     * Tests the logic for calculating the max rectangle area.
     */
    private void testMaxRectangleArea(int[][] data, int expectedResult) {
        ICalculator<Integer> maxRectangleArea = new MaxRectangleArea(data);
        int result = maxRectangleArea.calculate();

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic for calculating the max rectangle area.");
    }
}
