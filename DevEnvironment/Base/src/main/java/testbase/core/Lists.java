package testbase.core;

import java.util.ArrayList;
import java.util.List;

/**
 * The Lists class implements complementary APIs for lists.
 */
public final class Lists {
    /**
     * Converts a list from an array.
     */
    public static <T> List<T> fromArray(T[] array) {
        Conditions.validateNotNull(
            array,
            "The array.");

        List<T> result = new ArrayList<>();

        for (T item : array) {
            result.add(item);
        }

        return result;
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private Lists() {
    }
}
