package problems.core;

import org.junit.Test;
import problems.interfaces.IPow;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

/**
 * The PowTest class implements tests for a pow function.
 */
public final class PowTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The PowTest constructor.
     */
    public PowTest() {
    }

    /**
     * Tests the logic of a pow function.
     */
    @Test
    public void powTest() {
        double value1 = 5.0;
        int pow1 = 0;
        double expectedResult1 = 1.0;

        double value2 = 5.0;
        int pow2 = 1;
        double expectedResult2 = 5.0;

        double value3 = 2.0;
        int pow3 = 5;
        double expectedResult3 = 32.0;

        double value4 = 2.0;
        int pow4 = -2;
        double expectedResult4 = 0.25;

        double value5 = -2.0;
        int pow5 = -2;
        double expectedResult5 = 0.25;

        double value6 = 2.0;
        int pow6 = -3;
        double expectedResult6 = 0.125;

        double value7 = -2.0;
        int pow7 = -3;
        double expectedResult7 = -0.125;

        double value8 = 2.0;
        int pow8 = 10;
        double expectedResult8 = 1024.0;

        this.testPow(value1, pow1, expectedResult1);
        this.testPow(value2, pow2, expectedResult2);
        this.testPow(value3, pow3, expectedResult3);
        this.testPow(value4, pow4, expectedResult4);
        this.testPow(value5, pow5, expectedResult5);
        this.testPow(value6, pow6, expectedResult6);
        this.testPow(value7, pow7, expectedResult7);
        this.testPow(value8, pow8, expectedResult8);
    }

    /**
     * Tests the logic of pow.
     */
    private void testPow(double value, int pow, double expectedResult) {
        IPow function = new Pow();
        double result = function.pow(value, pow);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic for a pow function.");
    }
}
