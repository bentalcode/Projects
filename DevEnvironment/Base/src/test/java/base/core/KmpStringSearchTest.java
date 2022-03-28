package base.core;

import java.util.List;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The KmpStringSearchTest class implements tests for string search string search
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
        String str1 = "AAACAAAAC";
        String subString1 = null;
        List<Integer> expectedResult1 = ArrayLists.make();

        String str2 = "AAACAAAAC";
        String subString2 = "";
        List<Integer> expectedResult2 = ArrayLists.make();

        String str3 = "AAACAAAAC";
        String subString3 = "A";
        List<Integer> expectedResult3 = ArrayLists.make(0, 1, 2, 4, 5, 6, 7);

        String str4 = "AAACAAAAC";
        String subString4 = "AAC";
        List<Integer> expectedResult4 = ArrayLists.make(1, 6);

        String str5 = "AAACAAAAC";
        String subString5 = "AAAA";
        List<Integer> expectedResult5 = ArrayLists.make(4);

        String str6 = "AAACAAAAC";
        String subString6 = "AAAE";
        List<Integer> expectedResult6 = ArrayLists.make();

        String str7 = "AAACAAAAC";
        String subString7 = "CA";
        List<Integer> expectedResult7 = ArrayLists.make(3);

        String str8 = "AAACAAAAC";
        String subString8 = "AAAAA";
        List<Integer> expectedResult8 = ArrayLists.make();

        String str9 = "AAACAAAAC";
        String subString9 = "AAAAC";
        List<Integer> expectedResult9 = ArrayLists.make(4);

        this.testAllSubString(str1, subString1, expectedResult1);
        this.testAllSubString(str2, subString2, expectedResult2);
        this.testAllSubString(str3, subString3, expectedResult3);
        this.testAllSubString(str4, subString4, expectedResult4);
        this.testAllSubString(str5, subString5, expectedResult5);
        this.testAllSubString(str6, subString6, expectedResult6);
        this.testAllSubString(str7, subString7, expectedResult7);
        this.testAllSubString(str8, subString8, expectedResult8);
        this.testAllSubString(str9, subString9, expectedResult9);
    }

    /**
     * Tests the logic of finding all sub character array with KMP Algorithm.
     */
    @Test
    public void findAllSubCharacterArrayTest() {
        String str1 = "CBAAACAAAACFH";
        int strStartIndex1 = 2;
        int strEndIndex1 = 10;
        String subString1 = null;
        int subStringStartIndex1 = 0;
        int subStringEndIndex1 = 0;
        List<Integer> expectedResult1 = ArrayLists.make();

        String str2 = "CBAAACAAAACFH";
        int strStartIndex2 = 2;
        int strEndIndex2 = 10;
        String subString2 = "";
        int subStringStartIndex2 = 0;
        int subStringEndIndex2 = 0;
        List<Integer> expectedResult2 = ArrayLists.make();

        String str3 = "CBAAACAAAACFH";
        int strStartIndex3 = 2;
        int strEndIndex3 = 10;
        String subString3 = "A";
        int subStringStartIndex3 = 0;
        int subStringEndIndex3 = 0;
        List<Integer> expectedResult3 = ArrayLists.make(2, 3, 4, 6, 7, 8, 9);

        String str4 = "CBAAACAAAACFH";
        int strStartIndex4 = 2;
        int strEndIndex4 = 10;
        String subString4 = "BAACB";
        int subStringStartIndex4 = 1;
        int subStringEndIndex4 = 3;
        List<Integer> expectedResult4 = ArrayLists.make(3, 8);

        String str5 = "CBAAACAAAACFH";
        int strStartIndex5 = 2;
        int strEndIndex5 = 10;
        String subString5 = "ZZAAAAZZ";
        int subStringStartIndex5 = 2;
        int subStringEndIndex5 = 5;
        List<Integer> expectedResult5 = ArrayLists.make(6);

        String str6 = "CBAAACAAAACFH";
        int strStartIndex6 = 2;
        int strEndIndex6 = 10;
        String subString6 = "ZAAAEZ";
        int subStringStartIndex6 = 1;
        int subStringEndIndex6 = 4;
        List<Integer> expectedResult6 = ArrayLists.make();

        String str7 = "ACBAAACAAAACFHA";
        int strStartIndex7 = 3;
        int strEndIndex7 = 11;
        String subString7 = "ZZCA";
        int subStringStartIndex7 = 2;
        int subStringEndIndex7 = 3;
        List<Integer> expectedResult7 = ArrayLists.make(6);

        String str8 = "ACBAAACAAAACFHA";
        int strStartIndex8 = 3;
        int strEndIndex8 = 11;
        String subString8 = "ZAAAAAZ";
        int subStringStartIndex8 = 1;
        int subStringEndIndex8 = 5;
        List<Integer> expectedResult8 = ArrayLists.make();

        String str9 = "ACBAAACAAAACFHA";
        int strStartIndex9 = 3;
        int strEndIndex9 = 11;
        String subString9 = "ZAAAACZ";
        int subStringStartIndex9 = 1;
        int subStringEndIndex9 = 5;
        List<Integer> expectedResult9 = ArrayLists.make(7);

        this.testAllSubString(
            str1, strStartIndex1, strEndIndex1,
            subString1, subStringStartIndex1, subStringEndIndex1,
            expectedResult1);

        this.testAllSubString(
            str2, strStartIndex2, strEndIndex2,
            subString2, subStringStartIndex2, subStringEndIndex2,
            expectedResult2);

        this.testAllSubString(
            str3, strStartIndex3, strEndIndex3,
            subString3, subStringStartIndex3, subStringEndIndex3,
            expectedResult3);

        this.testAllSubString(
            str4, strStartIndex4, strEndIndex4,
            subString4, subStringStartIndex4, subStringEndIndex4,
            expectedResult4);

        this.testAllSubString(
            str5, strStartIndex5, strEndIndex5,
            subString5, subStringStartIndex5, subStringEndIndex5,
            expectedResult5);

        this.testAllSubString(
            str6, strStartIndex6, strEndIndex6,
            subString6, subStringStartIndex6, subStringEndIndex6,
            expectedResult6);

        this.testAllSubString(
            str7, strStartIndex7, strEndIndex7,
            subString7, subStringStartIndex7, subStringEndIndex7,
            expectedResult7);

        this.testAllSubString(
            str8, strStartIndex8, strEndIndex8,
            subString8, subStringStartIndex8, subStringEndIndex8,
            expectedResult8);

        this.testAllSubString(
            str9, strStartIndex9, strEndIndex9,
            subString9, subStringStartIndex9, subStringEndIndex9,
            expectedResult9);
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
