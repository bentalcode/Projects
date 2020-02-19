package base.core;

import java.util.ArrayList;
import java.util.Collection;
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
     * Converts the string to a list of characters.
     */
    public static List<Character> toList(String str) {
        Conditions.validateNotNull(
            str,
            "The input string for converting to a list.");

        List<Character> result = new ArrayList<>();

        for (int i = 0; i < str.length(); ++i) {
            result.add(str.charAt(i));
        }

        return result;
    }

    /**
     * Creates a string from a collection of values and a separator.
     */
    public static String create(
        Collection<String> values,
        char separator) {

        Conditions.validateNotNull(
            values,
            "The values.");

        StringBuilder stringBuilder = new StringBuilder();

        for (String value : values) {
            if (stringBuilder.length() > 0) {
                stringBuilder.append(separator);
            }

            stringBuilder.append(value);
        }

        return stringBuilder.toString();
    }

    /**
     * The Strings constructor - Disables the default constructor.
     */
    private Strings() {
    }
}
