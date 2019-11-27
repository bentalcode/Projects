package problems.core;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import problems.interfaces.IMultiplication;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

/**
 * The MultiplicationTest class implements tests for multiplication.
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
     * Tests the logic for multiplying strings.
     */
    @Test
    public void multiplyStringsTest() {
        String left1 = "123";
        String right1 = "456";
        String result1 = "56088";

        this.testMultiplyStrings(left1, right1, result1);
    }

    private void testMultiplyStrings(String left, String right, String expectedResult) {
        IMultiplication multiplication = new Multiplication();
        String result = multiplication.multiply(left, right);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Invalid logic for multiplying strings.");
    }
}
