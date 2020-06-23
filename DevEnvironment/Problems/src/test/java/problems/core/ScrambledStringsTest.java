package problems.core;

import base.interfaces.IDetector;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

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
     * Tests the logic for detecting scrambled strings.
     */
    @Test
    public void detectScrambledStringsTestTest() {
        String first1 = null;
        String second1 = null;
        boolean result1 = true;

        String first2 = "";
        String second2 = "";
        boolean result2 = true;

        String first3 = "a";
        String second3 = "a";
        boolean result3 = true;

        String first4 = "snowboard";
        String second4 = "nsowboard";
        boolean result4 = true;

        String first5 = "snowboard";
        String second5 = "nswoboard";
        boolean result5 = true;

        String first6 = "snowboard";
        String second6 = "wonsboard";
        boolean result6 = true;

        String first7 = "snowboard";
        String second7 = "rdabosnow";
        boolean result7 = true;

        String first8 = "snowboard";
        String second8 = "snowboadr";
        boolean result8 = true;

        String first9 = "snowboard";
        String second9 = "snowbodra";
        boolean result9 = true;

        String first10 = "snowboard";
        String second10 = "snowobdra";
        boolean result10 = true;

        String first11 = "snowboard";
        String second11 = "wosnboard";
        boolean result11 = true;

        String first12 = "snowboard";
        String second12 = "sonwboard";
        boolean result12 = false;

        String first13 = "snowboard";
        String second13 = "snowrdboa";
        boolean result13 = false;

        String first14 = "snowboard";
        String second14 = "snowbdaro";
        boolean result14 = false;

        String first15 = "snowboard";
        String second15 = "snowardbo";
        boolean result15 = true;

        String first16 = "snowboard";
        String second16 = "boardsnow";
        boolean result16 = true;

        this.testDetectScrambledStrings(first1, second1, result1);
        this.testDetectScrambledStrings(first2, second2, result2);
        this.testDetectScrambledStrings(first3, second3, result3);
        this.testDetectScrambledStrings(first4, second4, result4);
        this.testDetectScrambledStrings(first5, second5, result5);
        this.testDetectScrambledStrings(first6, second6, result6);
        this.testDetectScrambledStrings(first7, second7, result7);
        this.testDetectScrambledStrings(first8, second8, result8);
        this.testDetectScrambledStrings(first9, second9, result9);
        this.testDetectScrambledStrings(first10, second10, result10);
        this.testDetectScrambledStrings(first11, second11, result11);
        this.testDetectScrambledStrings(first12, second12, result12);
        this.testDetectScrambledStrings(first13, second13, result13);
        this.testDetectScrambledStrings(first14, second14, result14);
        this.testDetectScrambledStrings(first15, second15, result15);
        this.testDetectScrambledStrings(first16, second16, result16);
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
