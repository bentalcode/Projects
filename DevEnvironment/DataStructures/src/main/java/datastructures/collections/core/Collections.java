package datastructures.collections.core;

import base.core.Conditions;
import base.interfaces.IIterator;

/**
 * The Collections class implements complementary APIs for collections.
 */
public final class Collections {
    private static final String DefaultPrefix = "{";
    private static final String DefaultPostfix = "}";
    private static final String DefaultDelimiter = ", ";

    /**
     * Converts a collection of values into a string.
     */
    public static <T> String toString(IIterator<T> iterator) {
        String prefix = Collections.DefaultPrefix;
        String postfix = Collections.DefaultPostfix;
        String delimiter = Collections.DefaultDelimiter;

        return Collections.toString(
            prefix,
            postfix,
            iterator,
            delimiter);
    }

    /**
     * Converts a collection of values into a string.
     */
    public static <T> String toString(
        String prefix,
        String postfix,
        IIterator<T> iterator,
        String delimiter) {

        Conditions.validateNotNull(
            iterator,
            "The iterator of values.");

        StringBuilder result = new StringBuilder();

        if (prefix != null) {
            result.append(prefix);
        }

        int index = 0;
        while (iterator.hasNext()) {

            if (delimiter != null && index > 0) {
                result.append(delimiter);
            }

            T value = iterator.next();

            result.append(value);

            ++index;
        }

        if (postfix != null) {
            result.append(postfix);
        }

        return result.toString();
    }

    /**
     * The Collections constructor - Disables the default constructor.
     */
    private Collections() {
    }
}
