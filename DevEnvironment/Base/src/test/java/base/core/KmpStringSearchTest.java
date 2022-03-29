package base.core;

import java.util.List;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The KmpStringSearchTest class implements tests for string search
 * by using an algorithm for KMP (Knuth Morris Pratt) Pattern Searching.
 */
public final class KmpStringSearchTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The KmpStringSearchTest constructor.
     */
    public KmpStringSearchTest() {
    }

    /**
     * Tests the logic of finding sub string with KMP Algorithm.
     */
    @Test
    public void findSubStringTest() {
        this.testSubString("AAACAAAAC", null, -1);
        this.testSubString("AAACAAAAC", "", -1);
        this.testSubString("AAACAAAAC", "A", 0);
        this.testSubString("AAACAAAAC", "AAC", 1);
        this.testSubString("AAACAAAAC", "AAAA", 4);
        this.testSubString("AAACAAAAC", "AAAE", -1);
        this.testSubString("AAACAAAAC", "CA", 3);
        this.testSubString("AAACAAAAC", "AAAAA", -1);
        this.testSubString("AAACAAAAC", "AAAAC", 4);
    }

    /**
     * Tests the logic of finding sub character array with KMP Algorithm.
     */
    @Test
    public void findSubCharacterArrayTest() {
        this.testSubString(
            "CBAAACAAAACFH", 2, 10,
            null, 0, 0,
            -1);

        this.testSubString(
            "CBAAACAAAACFH", 2, 10,
            "", 0, 0,
            -1);

        this.testSubString(
            "CBAAACAAAACFH", 2, 10,
            "A", 0, 0,
            2);

        this.testSubString(
            "CBAAACAAAACFH", 2, 10,
            "BAACB", 1, 3,
            3);

        this.testSubString(
            "CBAAACAAAACFH", 2, 10,
            "ZZAAAAZZ", 2, 5,
            6);

        this.testSubString(
            "CBAAACAAAACFH", 2, 10,
            "ZAAAEZ", 1, 4,
            -1);

        this.testSubString(
            "ACBAAACAAAACFHA", 3, 11,
            "ZZCA", 2, 3,
            6);

        this.testSubString(
            "ACBAAACAAAACFHA", 3, 11,
            "ZAAAAAZ", 1, 5,
            -1);

        this.testSubString(
            "ACBAAACAAAACFHA", 3, 11,
            "ZAAAACZ", 1, 5,
            7);
    }

    /**
     * Tests the logic of finding all sub string with KMP Algorithm.
     */
    @Test
    public void findAllSubStringTest() {
        this.testAllSubString("AAACAAAAC", null, ArrayLists.make());
        this.testAllSubString("AAACAAAAC", "", ArrayLists.make());
        this.testAllSubString("AAACAAAAC", "A", ArrayLists.make(0, 1, 2, 4, 5, 6, 7));
        this.testAllSubString("AAACAAAAC", "AAC", ArrayLists.make(1, 6));
        this.testAllSubString("AAACAAAAC", "AAAA", ArrayLists.make(4));
        this.testAllSubString("AAACAAAAC", "AAAE", ArrayLists.make());
        this.testAllSubString("AAACAAAAC", "CA", ArrayLists.make(3));
        this.testAllSubString("AAACAAAAC", "AAAAA", ArrayLists.make());
        this.testAllSubString("AAACAAAAC", "AAAAC", ArrayLists.make(4));
    }

    /**
     * Tests the logic of finding all sub character array with KMP Algorithm.
     */
    @Test
    public void findAllSubCharacterArrayTest() {
        this.testAllSubString(
            "CBAAACAAAACFH", 2, 10,
            null, 0, 0,
            ArrayLists.make());

        this.testAllSubString(
            "CBAAACAAAACFH", 2, 10,
            "", 0, 0,
            ArrayLists.make());

        this.testAllSubString(
            "CBAAACAAAACFH", 2, 10,
            "A", 0, 0,
            ArrayLists.make(2, 3, 4, 6, 7, 8, 9));

        this.testAllSubString(
            "CBAAACAAAACFH", 2, 10,
            "BAACB", 1, 3,
            ArrayLists.make(3, 8));

        this.testAllSubString(
            "CBAAACAAAACFH", 2, 10,
            "ZZAAAAZZ", 2, 5,
            ArrayLists.make(6));

        this.testAllSubString(
            "CBAAACAAAACFH", 2, 10,
            "ZAAAEZ", 1, 4,
            ArrayLists.make());

        this.testAllSubString(
            "ACBAAACAAAACFHA", 3, 11,
            "ZZCA", 2, 3,
            ArrayLists.make(6));

        this.testAllSubString(
            "ACBAAACAAAACFHA", 3, 11,
            "ZAAAAAZ", 1, 5,
            ArrayLists.make());

        this.testAllSubString(
            "ACBAAACAAAACFHA", 3, 11,
            "ZAAAACZ", 1, 5,
            ArrayLists.make(7));
    }

    /**
     * Tests the logic of finding sub string with KMP Algorithm.
     */
    private void testSubString(
        String str,
        String subString,
        int expectedResult) {

        int result = KmpStringSearch.findSubString(str, subString);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic of finding sub string with KMP Algorithm.");
    }

    /**
     * Tests the logic of finding sub string with KMP Algorithm.
     */
    private void testSubString(
        String str, int strStartIndex, int strEndIndex,
        String subString, int subStringStartIndex, int subStringEndIndex,
        int expectedResult) {

        int result = KmpStringSearch.findSubString(
            str, strStartIndex, strEndIndex,
            subString, subStringStartIndex, subStringEndIndex);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic of finding sub string with KMP Algorithm.");
    }

    /**
     * Tests the logic of finding all sub string with KMP Algorithm.
     */
    private void testAllSubString(
        String str,
        String subString,
        List<Integer> expectedResult) {

        List<Integer> result = KmpStringSearch.findAllSubString(str, subString);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic of finding all sub string with KMP Algorithm.");
    }

    /**
     * Tests the logic of finding all sub string with KMP Algorithm.
     */
    private void testAllSubString(
        String str, int strStartIndex, int strEndIndex,
        String subString, int subStringStartIndex, int subStringEndIndex,
        List<Integer> expectedResult) {

        List<Integer> result = KmpStringSearch.findAllSubString(
            str, strStartIndex, strEndIndex,
            subString, subStringStartIndex, subStringEndIndex);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic of finding all sub string with KMP Algorithm.");
    }
}
