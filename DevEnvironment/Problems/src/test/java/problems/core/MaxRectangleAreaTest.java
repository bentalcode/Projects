package problems.core;

import base.interfaces.ICalculator;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

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
