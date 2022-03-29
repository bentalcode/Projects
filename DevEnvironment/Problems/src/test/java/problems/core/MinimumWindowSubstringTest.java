package problems.core;

import base.interfaces.ICalculator;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The MinimumWindowSubstringTest class implements tests for a minimum windows substring problem.
 */
public final class MinimumWindowSubstringTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The MinimumWindowSubstringTest constructor.
     */
    public MinimumWindowSubstringTest() {
    }

    /**
     * Tests the logic of a minimum window substring.
     */
    @Test
    public void minimumWindowSubstringTest() {
        this.testMinimumWindowSubstringTest("", "a", null);
        this.testMinimumWindowSubstringTest("a", "b", null);
        this.testMinimumWindowSubstringTest("a", "", null);
        this.testMinimumWindowSubstringTest("hashtable", "hash", "has");
        this.testMinimumWindowSubstringTest("hashtable", "hash", "has");
        this.testMinimumWindowSubstringTest("datastructures", "struct", "struc");
        this.testMinimumWindowSubstringTest("transformation", "on", "on");
        this.testMinimumWindowSubstringTest("abdefbcdad", "abc", "bcda");
        this.testMinimumWindowSubstringTest("dataandmusic", "musicand", "andmusic");
    }

    /**
     * Tests the logic of a minimum window substring.
     */
    private void testMinimumWindowSubstringTest(
        String s,
        String t,
        String expectedResult) {

        ICalculator<String> minimumWindowSubstring = new MinimumWindowSubstring(s, t);
        String result = minimumWindowSubstring.calculate();

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Invalid logic of calculating a minimum window.");
    }
}

