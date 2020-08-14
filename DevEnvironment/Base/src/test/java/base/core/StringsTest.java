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
     * Tests the logic of finding sub string with KMP Algorithm.
     */
    @Test
    public void findSubStringKmpTest() {
        String str1 = "AAACAAAAC";
        String subString1 = null;
        int expectedResult1 = -1;

        String str2 = "AAACAAAAC";
        String subString2 = "";
        int expectedResult2 = -1;

        String str3 = "AAACAAAAC";
        String subString3 = "A";
        int expectedResult3 = 0;

        String str4 = "AAACAAAAC";
        String subString4 = "AAC";
        int expectedResult4 = 1;

        String str5 = "AAACAAAAC";
        String subString5 = "AAAA";
        int expectedResult5 = 4;

        String str6 = "AAACAAAAC";
        String subString6 = "AAAE";
        int expectedResult6 = -1;

        String str7 = "AAACAAAAC";
        String subString7 = "CA";
        int expectedResult7 = 3;

        String str8 = "AAACAAAAC";
        String subString8 = "AAAAA";
        int expectedResult8 = -1;

        String str9 = "AAACAAAAC";
        String subString9 = "AAAAC";
        int expectedResult9 = 4;

        this.testSubStringKmp(str1, subString1, expectedResult1);
        this.testSubStringKmp(str2, subString2, expectedResult2);
        this.testSubStringKmp(str3, subString3, expectedResult3);
        this.testSubStringKmp(str4, subString4, expectedResult4);
        this.testSubStringKmp(str5, subString5, expectedResult5);
        this.testSubStringKmp(str6, subString6, expectedResult6);
        this.testSubStringKmp(str7, subString7, expectedResult7);
        this.testSubStringKmp(str8, subString8, expectedResult8);
        this.testSubStringKmp(str9, subString9, expectedResult9);
    }

    /**
     * Tests the logic of finding sub character array with KMP Algorithm.
     */
    @Test
    public void findSubCharacterArrayKmpTest() {
        String str1 = "CBAAACAAAACFH";
        int strStartIndex1 = 2;
        int strEndIndex1 = 10;
        String subString1 = null;
        int subStringStartIndex1 = 0;
        int subStringEndIndex1 = 0;
        int expectedResult1 = -1;

        String str2 = "CBAAACAAAACFH";
        int strStartIndex2 = 2;
        int strEndIndex2 = 10;
        String subString2 = "";
        int subStringStartIndex2 = 0;
        int subStringEndIndex2 = 0;
        int expectedResult2 = -1;

        String str3 = "CBAAACAAAACFH";
        int strStartIndex3 = 2;
        int strEndIndex3 = 10;
        String subString3 = "A";
        int subStringStartIndex3 = 0;
        int subStringEndIndex3 = 0;
        int expectedResult3 = 2;

        String str4 = "CBAAACAAAACFH";
        int strStartIndex4 = 2;
        int strEndIndex4 = 10;
        String subString4 = "BAACB";
        int subStringStartIndex4 = 1;
        int subStringEndIndex4 = 3;
        int expectedResult4 = 3;

        String str5 = "CBAAACAAAACFH";
        int strStartIndex5 = 2;
        int strEndIndex5 = 10;
        String subString5 = "ZZAAAAZZ";
        int subStringStartIndex5 = 2;
        int subStringEndIndex5 = 5;
        int expectedResult5 = 6;

        String str6 = "CBAAACAAAACFH";
        int strStartIndex6 = 2;
        int strEndIndex6 = 10;
        String subString6 = "ZAAAEZ";
        int subStringStartIndex6 = 1;
        int subStringEndIndex6 = 4;
        int expectedResult6 = -1;

        String str7 = "ACBAAACAAAACFHA";
        int strStartIndex7 = 3;
        int strEndIndex7 = 11;
        String subString7 = "ZZCA";
        int subStringStartIndex7 = 2;
        int subStringEndIndex7 = 3;
        int expectedResult7 = 6;

        String str8 = "ACBAAACAAAACFHA";
        int strStartIndex8 = 3;
        int strEndIndex8 = 11;
        String subString8 = "ZAAAAAZ";
        int subStringStartIndex8 = 1;
        int subStringEndIndex8 = 5;
        int expectedResult8 = -1;

        String str9 = "ACBAAACAAAACFHA";
        int strStartIndex9 = 3;
        int strEndIndex9 = 11;
        String subString9 = "ZAAAACZ";
        int subStringStartIndex9 = 1;
        int subStringEndIndex9 = 5;
        int expectedResult9 = 7;

        this.testSubStringKmp(
            str1, strStartIndex1, strEndIndex1,
            subString1, subStringStartIndex1, subStringEndIndex1,
            expectedResult1);

        this.testSubStringKmp(
            str2, strStartIndex2, strEndIndex2,
            subString2, subStringStartIndex2, subStringEndIndex2,
            expectedResult2);

        this.testSubStringKmp(
            str3, strStartIndex3, strEndIndex3,
            subString3, subStringStartIndex3, subStringEndIndex3,
            expectedResult3);

        this.testSubStringKmp(
            str4, strStartIndex4, strEndIndex4,
            subString4, subStringStartIndex4, subStringEndIndex4,
            expectedResult4);

        this.testSubStringKmp(
            str5, strStartIndex5, strEndIndex5,
            subString5, subStringStartIndex5, subStringEndIndex5,
            expectedResult5);

        this.testSubStringKmp(
            str6, strStartIndex6, strEndIndex6,
            subString6, subStringStartIndex6, subStringEndIndex6,
            expectedResult6);

        this.testSubStringKmp(
            str7, strStartIndex7, strEndIndex7,
            subString7, subStringStartIndex7, subStringEndIndex7,
            expectedResult7);

        this.testSubStringKmp(
            str8, strStartIndex8, strEndIndex8,
            subString8, subStringStartIndex8, subStringEndIndex8,
            expectedResult8);

        this.testSubStringKmp(
            str9, strStartIndex9, strEndIndex9,
            subString9, subStringStartIndex9, subStringEndIndex9,
            expectedResult9);
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
     * Tests the logic of finding sub string with KMP Algorithm.
     */
    private void testSubStringKmp(
        String str,
        String subString,
        int expectedResult) {

        int result = StringSearch.findSubStringKmp(str, subString);

        this.assertion.assertEquals(
            result,
            expectedResult,
            "Incorrect logic of finding sub string with KMP Algorithm.");
    }

    /**
     * Tests the logic of finding sub string with KMP Algorithm.
     */
    private void testSubStringKmp(
        String str, int strStartIndex, int strEndIndex,
        String subString, int subStringStartIndex, int subStringEndIndex,
        int expectedResult) {

        int result = StringSearch.findSubStringKmp(
            str, strStartIndex, strEndIndex,
            subString, subStringStartIndex, subStringEndIndex);

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
