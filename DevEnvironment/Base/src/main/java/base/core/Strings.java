package base.core;

import base.interfaces.IPair;
import java.util.ArrayList;
import java.util.List;

/**
 * The Strings class implements complementary APIs for strings.
 */
public final class Strings {
    /**
     * Determines whether a string is not null or empty.
     */
    public static boolean isNullOrEmpty(String str) {
        return str == null || str.isEmpty();
    }

    /**
     * Calculates all possible sequences of sub strings of a string.
     */
    public static List<List<String>> calculateSequenceSubStringsOfString(String str) {
        Conditions.validateNotNull(
            str,
            "The input string.");

        List<List<String>> result = new ArrayList<>();

        if (str.isEmpty()) {
            return result;
        }

        List<IPair<List<String>, Integer>> sequences = new ArrayList<>();
        Strings.calculateSequenceSubStringsOfString(
            str,
            sequences);

        for (IPair<List<String>, Integer> sequence : sequences) {
            List<String> currSequenceResult = sequence.first();
            int currSequenceSize = sequence.second();

            if (currSequenceSize == str.length()) {
                result.add(currSequenceResult);
            }
        }

        return result;
    }

    /**
     * Calculates all possible sequences of sub strings of a string.
     */
    private static void calculateSequenceSubStringsOfString(
        String str,
        List<IPair<List<String>, Integer>> result) {

        for (int startIndex = 0; startIndex < str.length(); ++startIndex) {
            for (int endIndex = startIndex; endIndex < str.length(); ++endIndex) {

                int currSubStringSize = endIndex - startIndex + 1;
                String currSubString = str.substring(startIndex, startIndex + currSubStringSize);

                if (startIndex == 0) {
                    List<String> newSequenceResult = new ArrayList<>();
                    newSequenceResult.add(currSubString);
                    int newSequenceSize = currSubString.length();

                    result.add(Pair.of(newSequenceResult, newSequenceSize));
                }
                else {
                    int currNumberOfResults = result.size();

                    for (int i = 0; i < currNumberOfResults; ++i) {
                        IPair<List<String>, Integer> currResult = result.get(i);

                        List<String> currSequenceResult = currResult.first();
                        int currSequenceSize = currResult.second();

                        if (startIndex == currSequenceSize) {
                            List<String> newSequenceResult = new ArrayList<>(currSequenceResult);
                            newSequenceResult.add(currSubString);
                            int newSequenceSize = currSequenceSize + currSubString.length();

                            result.add(Pair.of(newSequenceResult, newSequenceSize));
                        }
                    }
                }
            }
        }
    }

    /**
     * The Strings constructor - Disables the default constructor.
     */
    private Strings() {
    }
}
