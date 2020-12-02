package problems.core;

import base.core.Indexes;
import base.core.StringEquality;
import base.interfaces.IDetector;
import java.util.HashMap;
import java.util.Map;

/**
 * The ScrambledStringsDetector class implements a detector for a scrambled string.
 */
public final class ScrambledStringsDetector implements IDetector {
    private final String s1;
    private final String s2;

    /**
     * The ScrambledStringsDetector constructor.
     */
    public ScrambledStringsDetector(String s1, String s2) {
        this.s1 = s1;
        this.s2 = s2;
    }

    /**
     * Detects whether two strings are scrambled based on the following algorithm:
     * Construct a binary tree with the first string. Each leaf of the binary tree contains a single character.
     * Size(leftChild) == Size(rightChild) || Size(leftChild) == Size(rightChild) - 1
     *
     * A scrambled string is created by swapping child nodes in any level.
     *
     *         snowboard
     *          /   \
     *      snow    board
     *     /   \       /\
     *    sn   ow     bo ard
     *   /\   / \    /\    /\
     *  s  n o  w   b  o  a rd
     *                      /\
     *                     r d
     *
     *         boardsnow
     *          /     \
     *       board    snow
     *       /   \       /\
     *      bo  ard     sn ow
     *     /\   / \    /\  /\
     *    b o  a  rd  s n o w
     *            /\
     *           r d
     *
     */
    @Override
    public boolean detect() {
        if (this.s1 == null && this.s2 == null) {
            return true;
        }

        if (this.s1 == null || this.s2 == null) {
            return false;
        }

        return scrambledStrings(
            s1.toCharArray(),
            s2.toCharArray());
    }

    /**
     * Detects whether two strings are scrambled.
     */
    private static boolean scrambledStrings(
        char[] s1,
        char[] s2) {

        assert(s1 != null);
        assert(s2 != null);

        if (s1.length != s2.length) {
            return false;
        }

        if (s1.length == 0 && s2.length == 0) {
            return true;
        }

        int startIndex1 = 0;
        int endIndex1 = s1.length - 1;
        int startIndex2 = 0;
        int endIndex2 = s2.length - 1;

        if (!palindromes(s1, startIndex1, endIndex1, s2, startIndex2, endIndex2)) {
            return false;
        }

        return scrambledStrings(s1, startIndex1, endIndex1, s2, startIndex2, endIndex2);
    }

    /**
     * Detects whether two strings are scrambled.
     */
    private static boolean scrambledStrings(
        char[] s1,
        int startIndex1, int endIndex1,
        char[] s2,
        int startIndex2, int endIndex2) {

        assert(s1 != null);
        assert(s2 != null);
        assert(startIndex1 >= 0 && startIndex1 < s1.length);
        assert(endIndex1 >= startIndex1 && endIndex1 < s1.length);
        assert(startIndex2 >= 0 && startIndex2 < s2.length);
        assert(endIndex2 >= startIndex2 && endIndex2 < s2.length);

        int length1 = Indexes.size(startIndex1, endIndex1);
        int length2 = Indexes.size(startIndex2, endIndex2);

        if (length1 != length2) {
            return false;
        }

        int length = length1;
        assert(length > 0);

        if (StringEquality.equals(s1, startIndex1, s2, startIndex2, length)) {
            return true;
        }

        if (length <= 1) {
            return false;
        }

        int subLength = length / 2;

        int leftStartIndex1 = startIndex1;
        int leftEndIndex1 = startIndex1 + subLength - 1;

        int rightStartIndex1 = leftEndIndex1 + 1;
        int rightEndIndex1 = endIndex1;

        int leftStartIndex2 = startIndex2;
        int leftEndIndex2 = startIndex2 + subLength - 1;

        int rightStartIndex2 = leftEndIndex2 + 1;
        int rightEndIndex2 = endIndex2;

        if (scrambledStrings(
                s1, leftStartIndex1, leftEndIndex1,
                s2, leftStartIndex2, leftEndIndex2) &&
            scrambledStrings(
                s1, rightStartIndex1, rightEndIndex1,
                s2, rightStartIndex2, rightEndIndex2)) {

            return true;
        }

        leftStartIndex2 = endIndex2 - subLength + 1;
        leftEndIndex2 = endIndex2;

        rightStartIndex2 = startIndex2;
        rightEndIndex2 = leftStartIndex2 - 1;

        if (scrambledStrings(
                s1, leftStartIndex1, leftEndIndex1,
                s2, leftStartIndex2, leftEndIndex2) &&
            scrambledStrings(
                s1, rightStartIndex1, rightEndIndex1,
                s2, rightStartIndex2, rightEndIndex2)) {

            return true;
        }

        return false;
    }

    /**
     * Detects whether two strings are palindromes.
     */
    private static boolean palindromes(
        char[] s1,
        int startIndex1, int endIndex1,
        char[] s2,
        int startIndex2, int endIndex2) {

        assert(s1 != null);
        assert(s2 != null);
        assert(startIndex1 >= 0 && startIndex1 < s1.length);
        assert(endIndex1 >= startIndex1 && endIndex1 < s1.length);
        assert(startIndex2 >= 0 && startIndex2 < s2.length);
        assert(endIndex2 >= startIndex2 && endIndex2 < s2.length);

        if (s1 == null && s2 == null) {
            return true;
        }

        if (s1 == null || s2 == null) {
            return false;
        }

        int length1 = Indexes.size(startIndex1, endIndex1);
        int length2 = Indexes.size(startIndex2, endIndex2);

        if (length1 != length2) {
            return false;
        }

        Map<Character, Integer> characters = new HashMap<>();

        for (int i = startIndex1; i <= endIndex1; ++i) {
            char currCharacter = s1[i];

            int counter = characters.getOrDefault(currCharacter, 0);
            ++counter;

            characters.put(currCharacter, counter);
        }

        for (int i = startIndex2; i <= endIndex2; ++i) {
            char currCharacter = s2[i];

            if (!characters.containsKey(currCharacter)) {
                return false;
            }

            int counter = characters.get(currCharacter);
            --counter;

            if (counter == 0) {
                characters.remove(currCharacter);
            }
            else {
                characters.put(currCharacter, counter);
            }
        }

        return characters.isEmpty();
    }
}
