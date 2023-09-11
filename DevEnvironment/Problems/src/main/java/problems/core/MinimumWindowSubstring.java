package problems.core;

import base.core.Conditions;
import base.core.Indexes;
import base.interfaces.ICalculator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * The MinimumWindowSubstring class implements a minimum windows substring.
 */
public final class MinimumWindowSubstring implements ICalculator<String> {
    private final char[] src;
    private final Set<Character> characters;

    /**
     * The MinimumWindowSubstring constructor.
     */
    public MinimumWindowSubstring(String s, String t) {
        Conditions.validateNotNull(
            s,
            "The s string.");

        Conditions.validateNotNull(
            t,
            "The t string.");

        this.src = s.toCharArray();
        this.characters = MinimumWindowSubstring.createCharacterSet(t);
    }

    /**
     * Given a string S and a string T, find the minimum window in S,
     * which will contain all the characters in T in complexity O(n).
     */
    @Override
    public String calculate() {
        if (this.characters.isEmpty() || this.src.length < this.characters.size()) {
            return null;
        }

        Map<Character, Integer> characterCounter = new HashMap<>();

        int endIndex = this.coverSourceString(
            this.src,
            0,
            this.src.length - 1,
            characterCounter);

        if (endIndex == -1) {
            return null;
        }

        int startIndex = this.shrinkSubString(
            this.src,
            0,
            endIndex,
            characterCounter);

        int minStartIndex = startIndex;
        int minLength = Indexes.size(startIndex, endIndex);

        for (int currIndex = endIndex + 1; currIndex < this.src.length; ++currIndex) {
            char currValue = this.src[currIndex];

            if (!this.characters.contains(currValue)) {
                continue;
            }

            updateCharacterCounter(
                characterCounter,
                currValue,
                1);

            startIndex = this.shrinkSubString(
                this.src,
                startIndex,
                currIndex,
                characterCounter);

            int currLength = Indexes.size(startIndex, currIndex);

            if (currLength < minLength) {
                minStartIndex = startIndex;
                minLength = currLength;
            }
        }

        return new String(this.src, minStartIndex, minLength);
    }

    /**
     * Covers the source string.
     * Returns -1 if the string is not able to be covered.
     */
    private int coverSourceString(
        char[] src,
        int startIndex,
        int endIndex,
        Map<Character, Integer> characterCounter) {

        for (int i = startIndex; i <= endIndex; ++i) {
            char currValue = src[i];

            if (this.characters.contains(currValue)) {
                updateCharacterCounter(characterCounter, currValue, 1);

                if (characterCounter.size() == this.characters.size()) {
                    return i;
                }
            }
        }

        return -1;
    }

    /**
     * Shrinks a sub-string.
     */
    private int shrinkSubString(
        char[] src,
        int startIndex,
        int endIndex,
        Map<Character, Integer> characterCounter) {

        int currIndex = startIndex;

        while (currIndex <= endIndex) {
            char currValue = src[currIndex];

            if (this.characters.contains(currValue)) {
                int currValueCount = characterCounter.get(currValue);
                assert(currValueCount >= 1);

                if (currValueCount == 1) {
                    break;
                }

                characterCounter.put(currValue, currValueCount - 1);
            }

            ++currIndex;
        }

        return currIndex;
    }

    /**
     * Updates the character counter.
     */
    private static void updateCharacterCounter(
        Map<Character, Integer> characterCounter,
        char value,
        int delta) {

        int currCount = characterCounter.getOrDefault(value, 0);
        currCount += delta;
        characterCounter.put(value, currCount);
    }

    /**
     * Creates a character set.
     */
    private static Set<Character> createCharacterSet(String str) {
        Set<Character> characters = new HashSet<>();

        for (char character : str.toCharArray()) {
            characters.add(character);
        }

        return characters;
    }
}
