package testbase.core;

import base.core.ArrayIterator;
import base.core.Strings;
import base.interfaces.IIterator;
import base.interfaces.ITestData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.interfaces.IAssertion;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

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

    class Pair<T> {
        private final T first;
        private final T second;

        public Pair(T first, T second) {
            this.first = first;
            this.second = second;
        }

        public T getFirst() {
            return this.first;
        }

        public T getSecond() {
            return this.second;
        }
    };

    class Triple<T> {
        private final T first;
        private final T second;
        private final T third;

        public Triple(T first, T second, T third) {
            this.first = first;
            this.second = second;
            this.third = third;
        }

        public T getFirst() {
            return this.first;
        }

        public T getSecond() {
            return this.second;
        }

        public T getThird() {
            return this.third;
        }

        public boolean isEquals(Triple<T> rhs) {
            if (rhs == null) {
                return false;
            }

            if (this == rhs) {
                return true;
            }

            return
                    this.getFirst().equals(rhs.getFirst()) &&
                            this.getSecond().equals(rhs.getSecond()) &&
                            this.getThird().equals(rhs.getThird());
        }
    };

    /**
     * Tests the logic whether a string is null or empty.
     */
    @Test
    public void test() {
        Map<Integer, char[]> mappings = new HashMap<>();
        char a = 0;
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
            expectedResult, "Invalid logic for determining whether a string is null or empty.");
    }
}
