package testbase.core;

import base.core.Conversion;
import base.interfaces.IPair;
import base.interfaces.ITestData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.interfaces.IAssertion;
import java.util.List;

/**
 * The IntegerConversionTest class implements tests for integer-conversions.
 */
public final class IntegerConversionTest {
    private final IAssertion assertion = new Assertion();
    private final ITestData testData = new TestData();

    /**
     * The IntegerConversionTest constructor.
     */
    public IntegerConversionTest() {
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
     * Tests conversions.
     */
    @Test
    public void testConversion() {
        List<IPair<Integer, String>> values = this.testData.getIntegerStrings();

        for (IPair<Integer, String> value : values) {
            this.testConversion(value.second(), value.first());
        }
    }

    /**
     * Tests a conversion of a string to an integer.
     */
    private void testConversion(String value, int expectedResult) {
        int result = Conversion.integerConversion().parse(value);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Invalid integer-String conversion logic.");
    }
}
