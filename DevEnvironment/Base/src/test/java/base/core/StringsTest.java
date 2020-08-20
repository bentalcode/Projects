package base.core;

import base.interfaces.IIterator;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import java.util.Arrays;

/**
 * The StringsTest class implements tests for strings.
 */
public final class StringsTest {
    private final IAssertion assertion = new Assertion();

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
     * Tests the logic whether a string is null or empty.
     */
    @Test
    public void isNullOrEmptyTest() {
        String[] strings = {"abc", "", null};
        Boolean[] expectedResults = {false, true, true};

        IIterator<String> stringIterator = ArrayIterator.of(strings);
        IIterator<Boolean> expectedResultIterator = ArrayIterator.of(expectedResults);

        while (stringIterator.hasNext() && expectedResultIterator.hasNext()) {
            String value = stringIterator.next();
            boolean expectedResult = expectedResultIterator.next();

            this.testStringIsNullOrEmpty(value, expectedResult);
        }
    }

    /**
     * Tests the logic of splitting a string.
     */
    @Test
    public void splitStringTest() {
        String str1 = "///a/b///c//d///e";
        String regexSeparator1 = "/";
        String[] expectedTokens1 = {"", "", "", "a", "b", "", "", "c", "", "d", "", "", "e"};

        testSplitString(str1, regexSeparator1, expectedTokens1);
    }

    /**
     * Tests the logic whether a string is null or empty.
     */
    private void testStringIsNullOrEmpty(String value, boolean expectedResult) {
        boolean result = Strings.isNullOrEmpty(value);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic of finding sub string with KMP Algorithm.");
    }

    /**
     * Tests the logic of splitting a string.
     */
    private void testSplitString(String value, String regexSeparator, String[] expectedResult) {
        String[] result = value.split(regexSeparator);

        this.assertion.assertTrue(
            Arrays.deepEquals(result, expectedResult),
            "Incorrect logic of splitting strings.");
    }
}
