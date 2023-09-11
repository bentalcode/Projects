package problems.core;

import problems.interfaces.IInterleavingStrings;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The InterleavingStringsTest class implements tests for interleaving strings problem.
 */
public final class InterleavingStringsTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The InterleavingStringsTest constructor.
     */
    public InterleavingStringsTest() {
    }

    /**
     * Tests the logic for interleaving strings.
     */
    @Test
    public void interleavingStringsTest() {
        this.testInterleavingStrings("", "abc", "abc", true);
        this.testInterleavingStrings("a", "abc", "abc", false);

        this.testInterleavingStrings("a", "abc", "aabc", true);
        this.testInterleavingStrings("a", "abc", "abac", true);
        this.testInterleavingStrings("a", "abc", "abca", true);

        this.testInterleavingStrings("abcd", "", "abcd", true);

        this.testInterleavingStrings("abcd", "a", "abcd", false);
        this.testInterleavingStrings("abcd", "a", "aabdc", false);

        this.testInterleavingStrings("abcd", "a", "aabcd", true);
        this.testInterleavingStrings("abcd", "a", "abacd", true);
        this.testInterleavingStrings("abcd", "a", "abcad", true);
        this.testInterleavingStrings("abcd", "a", "abcad", true);

        this.testInterleavingStrings("abcd", "ef", "eabcfd", true);
        this.testInterleavingStrings("abcd", "efh", "aebfcdh", true);

        this.testInterleavingStrings("abcde", "fgh", "fabghcde", true);
        this.testInterleavingStrings("abcde", "fgh", "abcdfegh", true);

        this.testInterleavingStrings("abcde", "fgh", "afbchdge", false);
        this.testInterleavingStrings("abcde", "fgh", "fagbehcd", false);
    }

    /**
     * Tests the logic for interleaving strings.
     */
    private void testInterleavingStrings(
        String str1,
        String str2,
        String interleaving,
        boolean expectedResult) {

        IInterleavingStrings interleavingStrings = new InterleavingStrings();
        boolean result1 = interleavingStrings.interleaving1(str1, str2, interleaving);

        this.assertion.assertEquals(
            result1,
            expectedResult,
            "Incorrect logic1 for determining interleaving strings.");

        boolean result2 = interleavingStrings.interleaving2(str1, str2, interleaving);

        this.assertion.assertEquals(
            result2,
            expectedResult,
            "Incorrect logic2 for determining interleaving strings.");
    }
}
