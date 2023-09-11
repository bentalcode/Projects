package problems.core;

import base.interfaces.IDetector;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The ScrambledStringsTest class implements tests for detecting scrambled strings.
 */
public final class ScrambledStringsTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The ScrambledStringsTest constructor.
     */
    public ScrambledStringsTest() {
    }

    /**
     * Tests the logic for detecting scrambled strings.
     */
    @Test
    public void detectScrambledStringsTestTest() {
        this.testDetectScrambledStrings(null, null, true);
        this.testDetectScrambledStrings("", "", true);
        this.testDetectScrambledStrings("a", "a", true);
        this.testDetectScrambledStrings("snowboard", "nsowboard", true);
        this.testDetectScrambledStrings("snowboard", "nswoboard", true);
        this.testDetectScrambledStrings("snowboard", "wonsboard", true);
        this.testDetectScrambledStrings("snowboard", "rdabosnow", true);
        this.testDetectScrambledStrings("snowboard", "snowboadr", true);
        this.testDetectScrambledStrings("snowboard", "snowbodra", true);
        this.testDetectScrambledStrings("snowboard", "snowobdra", true);
        this.testDetectScrambledStrings("snowboard", "wosnboard", true);
        this.testDetectScrambledStrings("snowboard", "sonwboard", false);
        this.testDetectScrambledStrings("snowboard", "snowrdboa", false);
        this.testDetectScrambledStrings("snowboard", "snowbdaro", false);
        this.testDetectScrambledStrings("snowboard", "snowardbo", true);
        this.testDetectScrambledStrings("snowboard", "boardsnow", true);
    }

    /**
     * Tests the logic for detecting scrambled strings.
     */
    private void testDetectScrambledStrings(String s1, String s2, boolean expectedResult) {
        IDetector detector = new ScrambledStringsDetector(s1, s2);

        boolean result = detector.detect();

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic for detecting scrambled strings.");
    }
}
