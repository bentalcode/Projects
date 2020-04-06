package problems.core;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import problems.interfaces.IMultiplication;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

/**
 * The MultiplicationTest class implements tests for the multiplication problem.
 */
public final class MultiplicationTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The MultiplicationTest constructor.
     */
    public MultiplicationTest() {
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
     * Tests the logic for multiplying numbers.
     */
    @Test
    public void multiplyTest() {
        int[] left1 = {0};
        int[] right1 = {4, 5, 6};
        int[] result1 = {0};

        int[] left2 = {4, 5, 6};
        int[] right2 = {1};
        int[] result2 = {4, 5, 6};

        int[] left3 = {2, 3};
        int[] right3 = {4, 5, 6};
        int[] result3 = {1, 0, 4, 8, 8};

        int[] left4 = {2, 3};
        int[] right4 = {4, 5, 6};
        int[] result4 = {1, 0, 4, 8, 8};

        int[] left5 = {1, 2, 3};
        int[] right5 = {4, 5, 6};
        int[] result5 = {5, 6, 0, 8, 8};

        int[] left6 = {9, 1, 2, 3};
        int[] right6 = {8, 4, 7, 9};
        int[] result6 = {7, 7, 3, 5, 3, 9, 1, 7};

        int[] left7 = {6, 1, 8, 3};
        int[] right7 = {9, 4, 9, 9, 0};
        int[] result7 = {5, 8, 7, 3, 2, 3, 1, 7, 0};

        int[] left8 = {6, 1, 8, 3};
        int[] right8 = {9, 4, 9, 9, 0, 3, 2};
        int[] result8 = {5, 8, 7, 3, 2, 5, 1, 4, 8, 5, 6};

        int[] left9 = {6, 1, 8, 3, 1, 1};
        int[] right9 = {9, 4, 9, 9, 0, 3, 2, 9, 8};
        int[] result9 = {5, 8, 7, 3, 3, 5, 6, 5, 8, 0, 8, 9, 6, 7, 8};

        int[] left10 = {6, 1, 8, 3, 1, 1};
        int[] right10 = {9, 4, 9, 9, 7, 0, 2, 9, 8};
        int[] result10 = {5, 8, 7, 3, 7, 7, 0, 8, 4, 9, 2, 6, 6, 7, 8};

        this.testMultiply(left1, right1, result1);
        this.testMultiply(left2, right2, result2);
        this.testMultiply(left3, right3, result3);
        this.testMultiply(left4, right4, result4);
        this.testMultiply(left5, right5, result5);
        this.testMultiply(left6, right6, result6);
        this.testMultiply(left7, right7, result7);
        this.testMultiply(left8, right8, result8);
        this.testMultiply(left9, right9, result9);
        this.testMultiply(left10, right10, result10);
    }

    /**
     * Tests the logic for multiplying numbers.
     */
    private void testMultiply(int[] left, int[] right, int[] expectedResult) {
        IMultiplication multiplication = new Multiplication();
        int[] result = multiplication.multiply(left, right);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic for multiplying strings.");
    }
}
