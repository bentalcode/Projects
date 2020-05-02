package problems.core;

import base.interfaces.ICalculator;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

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
     * Tests the logic of a minimum window substring.
     */
    @Test
    public void minimumWindowSubstringTest() {
        String s1 = "";
        String t1 = "a";
        String result1 = null;

        String s2 = "a";
        String t2 = "b";
        String result2 = null;

        String s3 = "a";
        String t3 = "";
        String result3 = null;

        String s4 = "hashtable";
        String t4 = "hash";
        String result4 = "has";

        String s5 = "hashtable";
        String t5 = "hash";
        String result5 = "has";

        String s6 = "datastructures";
        String t6 = "struct";
        String result6 = "struc";

        String s7 = "transformation";
        String t7 = "on";
        String result7 = "on";

        String s8 = "abdefbcdad";
        String t8 = "abc";
        String result8 = "bcda";

        String s9 = "dataandmusic";
        String t9 = "musicand";
        String result9 = "andmusic";

        this.testMinimumWindowSubstringTest(s1, t1, result1);
        this.testMinimumWindowSubstringTest(s2, t2, result2);
        this.testMinimumWindowSubstringTest(s3, t3, result3);
        this.testMinimumWindowSubstringTest(s4, t4, result4);
        this.testMinimumWindowSubstringTest(s5, t5, result5);
        this.testMinimumWindowSubstringTest(s6, t6, result6);
        this.testMinimumWindowSubstringTest(s7, t7, result7);
        this.testMinimumWindowSubstringTest(s8, t8, result8);
        this.testMinimumWindowSubstringTest(s9, t9, result9);
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

