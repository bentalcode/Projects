package problems.core;

import base.core.Conditions;
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

        Map<Character, Integer> valueCounterMap = new HashMap<>();

        int endIndex = this.coverSourceString(
            this.src,
            0,
            this.src.length - 1,
            valueCounterMap);

        if (endIndex == -1) {
            return null;
        }

        int startIndex = this.tryShrinkSubString(
            this.src,
            0,
            endIndex,
            valueCounterMap);

        int minStartIndex = startIndex;
        int minEndIndex = endIndex;
        int minLength = minEndIndex - minStartIndex + 1;

        for (int currIndex = endIndex + 1; currIndex < this.src.length; ++currIndex) {
            char currValue = this.src[currIndex];

            if (!this.characters.contains(currValue)) {
                continue;
            }

            MinimumWindowSubstring.updateValueCounterMap(
                valueCounterMap,
                currValue,
                1);

            startIndex = this.tryShrinkSubString(
                this.src,
                startIndex,
                currIndex,
                valueCounterMap);

            int currLength = currIndex - startIndex + 1;

            if (currLength < minLength) {
                minStartIndex = startIndex;
                minEndIndex = currIndex;
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
        Map<Character, Integer> valueCounterMap) {

        for (int i = startIndex; i <= endIndex; ++i) {
            char currValue = src[i];

            if (this.characters.contains(currValue)) {
                MinimumWindowSubstring.updateValueCounterMap(valueCounterMap, currValue, 1);

                if (valueCounterMap.size() == this.characters.size()) {
                    return i;
                }
            }
        }

        return -1;
    }

    /**
     * Tries to shrink the sub-string.
     */
    private int tryShrinkSubString(
        char[] src,
        int startIndex,
        int endIndex,
        Map<Character, Integer> valueCounterMap) {

        int currIndex = startIndex;

        while (currIndex <= endIndex) {
            char currValue = src[currIndex];

            if (this.characters.contains(currValue)) {
                int currValueCount = valueCounterMap.get(currValue);
                assert(currValueCount >= 1);

                if (currValueCount == 1) {
                    break;
                }

                valueCounterMap.put(currValue, currValueCount - 1);
            }

            ++currIndex;
        }

        return currIndex;
    }

    /**
     * Updates the value counter map.
     */
    private static void updateValueCounterMap(
        Map<Character, Integer> map,
        char value,
        int delta) {

        int currCount = map.getOrDefault(value, 0);
        currCount += delta;
        map.put(value, currCount);
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
