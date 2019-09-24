package testbase.core;

import base.core.Strings;
import base.core.TwoDimensionalListIterator;
import base.interfaces.IPair;
import base.interfaces.ITestData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.interfaces.IAssertion;
import java.util.List;

/**
 * The StringsTest class implements tests for strings.
 */
public final class StringsTest {
    private final IAssertion assertion = new Assertion();
    private final ITestData testData = new TestData();

    /**
     * The StringsTest constructor.
     */
    public StringsTest() {
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
     * Tests the logic of calculating all possible sequences of sub strings of a string.
     */
    @Test
    public void calculateSequenceSubStringsOfStringTest() {
        List<IPair<String, List<List<String>>>> result = this.testData.getAllSequenceSubStringsOfString();

        for (IPair<String, List<List<String>>> sequenceResult : result) {
            this.testCalculateSequenceSubStringsOfString(
                sequenceResult.first(),
                sequenceResult.second());
        }
    }

    /**
     * Tests the logic of calculating all possible sequences of sub strings of a string.
     */
    private void testCalculateSequenceSubStringsOfString(String value, List<List<String>> expectedResult) {
        List<List<String>> result = Strings.calculateSequenceSubStringsOfString(value);

        this.assertion.assertEquals(
            TwoDimensionalListIterator.of(result),
            TwoDimensionalListIterator.of(expectedResult),
            "Invalid logic for calculating all possible sequences of sub strings of a string.");
    }
}
