package base.core;

import java.util.ArrayList;
import java.util.List;

/**
 * The KmpStringSearch class implements string search by using an algorithm
 * for KMP (Knuth Morris Pratt) Pattern Searching.
 */
public final class KmpStringSearch {
    /**
     * Finds an index of a substring in a string with KMP Algorithm.
     * Returns -1 if the subString is not found.
     */
    public static int findSubString(String str, String subString) {
        if (str == null || str.isEmpty() ||
            subString == null || subString.isEmpty()) {

            return -1;
        }

        return findSubString(
            str.toCharArray(), 0, str.length() - 1,
            subString.toCharArray(), 0, subString.length() - 1);
    }

    /**
     * Finds an index of a substring in a string with KMP Algorithm.
     * Returns -1 if the subString is not found.
     */
    public static int findSubString(
        String str, int strStartIndex, int strEndIndex,
        String subString, int subStringStartIndex, int subStringEndIndex) {

        if (str == null || str.isEmpty() || subString == null || subString.isEmpty()) {
            return -1;
        }

        return findSubString(
            str.toCharArray(), strStartIndex, strEndIndex,
            subString.toCharArray(), subStringStartIndex, subStringEndIndex);
    }

    /**
     * Finds an index of a substring in a string with KMP Algorithm.
     * Returns an empty array if the subString is not found.
     */
    public static List<Integer> findAllSubString(String str, String subString) {
        if (str == null || str.isEmpty() ||
            subString == null || subString.isEmpty()) {

            return new ArrayList<>();
        }

        return findAllSubString(
            str.toCharArray(), 0, str.length() - 1,
            subString.toCharArray(), 0, subString.length() - 1);
    }

    /**
     * Finds an index of a substring in a string with KMP Algorithm.
     * Returns an empty array if the subString is not found.
     */
    public static List<Integer> findAllSubString(
        String str, int strStartIndex, int strEndIndex,
        String subString, int subStringStartIndex, int subStringEndIndex) {

        if (str == null || str.isEmpty() || subString == null || subString.isEmpty()) {
            return new ArrayList<>();
        }

        return findAllSubString(
            str.toCharArray(), strStartIndex, strEndIndex,
            subString.toCharArray(), subStringStartIndex, subStringEndIndex);
    }

    /**
     * Finds an index of a substring in a string with KMP Algorithm.
     * Returns -1 if the subString is not found.
     */
    public static int findSubString(
        char[] str, int strStartIndex, int strEndIndex,
        char[] subString, int subStringStartIndex, int subStringEndIndex) {

        assert(str != null);
        assert(strStartIndex >= 0 && strStartIndex < str.length);
        assert(strEndIndex >= strStartIndex && strEndIndex < str.length);
        assert(subString != null);
        assert(subStringStartIndex >= 0 && subStringStartIndex < subString.length);
        assert(subStringEndIndex >= subStringStartIndex && subStringEndIndex < subString.length);

        int strLength = Dimensions.length(strStartIndex, strEndIndex);
        int subStringLength = Dimensions.length(subStringStartIndex, subStringEndIndex);

        if (subStringLength > strLength) {
            return -1;
        }

        //
        // Create the longest prefix suffix...
        //
        int[] lps = createLongestPrefixSuffix(subString, subStringStartIndex, subStringEndIndex);

        int strIndex = strStartIndex;
        int subStringIndex = subStringStartIndex;

        while (strIndex <= strEndIndex && subStringIndex <= subStringEndIndex) {
            char strCharacter = str[strIndex];
            char subStringCharacter = subString[subStringIndex];

            if (strCharacter == subStringCharacter) {
                if (subStringIndex == subStringEndIndex) {
                    return strIndex - subStringLength + 1;
                }

                ++strIndex;
                ++subStringIndex;
            }
            else {
                if (subStringIndex == subStringStartIndex) {
                    ++strIndex;
                }
                else {
                    int lpsIndex = subStringIndex - subStringStartIndex;
                    subStringIndex = subStringStartIndex + lps[lpsIndex - 1];
                }
            }
        }

        return -1;
    }

    /**
     * Finds an index of a substring in a string with KMP Algorithm.
     * Returns an empty array if no sub string is found.
     */
    public static List<Integer> findAllSubString(
        char[] str, int strStartIndex, int strEndIndex,
        char[] subString, int subStringStartIndex, int subStringEndIndex) {

        assert(str != null);
        assert(strStartIndex >= 0 && strStartIndex < str.length);
        assert(strEndIndex >= strStartIndex && strEndIndex < str.length);
        assert(subString != null);
        assert(subStringStartIndex >= 0 && subStringStartIndex < subString.length);
        assert(subStringEndIndex >= subStringStartIndex && subStringEndIndex < subString.length);

        List<Integer> resultIndexes = new ArrayList<>();

        int strLength = Dimensions.length(strStartIndex, strEndIndex);
        int subStringLength = Dimensions.length(subStringStartIndex, subStringEndIndex);

        if (subStringLength > strLength) {
            return resultIndexes;
        }

        //
        // Create the longest prefix suffix...
        //
        int[] lps = createLongestPrefixSuffix(subString, subStringStartIndex, subStringEndIndex);

        int strIndex = strStartIndex;
        int subStringIndex = subStringStartIndex;

        while (strIndex <= strEndIndex && subStringIndex <= subStringEndIndex) {
            char strCharacter = str[strIndex];
            char subStringCharacter = subString[subStringIndex];

            if (strCharacter == subStringCharacter) {
                if (subStringIndex == subStringEndIndex) {
                    int resultIndex = strIndex - subStringLength + 1;
                    resultIndexes.add(resultIndex);

                    int lpsIndex = subStringIndex - subStringStartIndex;
                    subStringIndex = subStringStartIndex + lps[lpsIndex];
                }
                else {
                    ++subStringIndex;
                }

                ++strIndex;
            }
            else {
                if (subStringIndex == subStringStartIndex) {
                    ++strIndex;
                }
                else {
                    int lpsIndex = subStringIndex - subStringStartIndex;
                    subStringIndex = subStringStartIndex + lps[lpsIndex - 1];
                }
            }
        }

        return resultIndexes;
    }

    /**
     * Creates the longest prefix suffix (lps) of a string.
     *
     * For instance,
     * String str = "AAACAAAAAC";
     * Prefixes = {{}, {A}, {AA}, {AAA}, {AAAC}, {AAACA}, {AAACAA}, {AAACAAA}, {AAACAAAA}, {AAACAAAAA}, {AAACAAAAAC}};
     * Postfixes = {{}, {C}, {AC}, {AAC}, {AAAC}, {AAAAC}, {AAAAAC}, {CAAAAAC}, {ACAAAAAC}, {AACAAAAAC}, {AAACAAAAAC}};
     *
     * In this case, Prefix{AAAC} == Postfix{AAAC}, Therefore, lps[9] = 4;
     *
     * lps = {0, 1, 2, 0, 1, 2, 3, 3, 3, 4}
     */
    private static int[] createLongestPrefixSuffix(char[] str, int startIndex, int endIndex) {
        assert(str != null);
        assert(startIndex >= 0 && startIndex < str.length);
        assert(endIndex >= startIndex && endIndex < str.length);

        int strLength = Dimensions.length(startIndex, endIndex);

        int[] lps = new int[strLength];
        lps[0] = 0;

        int index = 1;
        int length = 0;

        while (index < strLength) {
            char currCharacter = str[startIndex + index];
            char patternCharacter = str[startIndex + length];

            if (currCharacter == patternCharacter) {
                ++length;
                lps[index] = length;
                ++index;
            }
            else {
                if (length == 0) {
                    lps[index] = 0;
                    ++index;
                }
                else {
                    length = lps[length - 1];
                }
            }
        }

        return lps;
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private KmpStringSearch() {
    }
}
