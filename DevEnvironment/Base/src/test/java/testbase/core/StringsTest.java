package testbase.core;

import base.core.ArrayIterator;
import base.core.Strings;
import base.interfaces.IIterator;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.interfaces.IAssertion;

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
     * Tests the logic whether a string is null or empty.
     */
    private void testStringIsNullOrEmpty(String value, boolean expectedResult) {
        boolean result = Strings.isNullOrEmpty(value);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic for determining whether a string is null or empty.");
    }
}
