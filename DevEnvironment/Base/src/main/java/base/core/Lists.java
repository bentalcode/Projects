package base.core;

import base.interfaces.IIterator;

import java.util.ArrayList;
import java.util.List;

/**
 * The Lists class implements complementary APIs for lists.
 */
public final class Lists {
    /**
     * Creates a list from an array.
     */
    public static <T> List<T> fromArray(T[] array) {
        Conditions.validateNotNull(
            array,
            "The array for creating a list.");

        List<T> result = new ArrayList<>();

        for (T item : array) {
            result.add(item);
        }

        return result;
    }

    /**
     * Creates a list from an iterator.
     */
    public static <T> List<T> fromIterator(IIterator<T> iterator) {
        Conditions.validateNotNull(
            iterator,
            "The iterator for creating a list.");

        List<T> result = new ArrayList<>();

        while (iterator.hasNext()) {
            result.add(iterator.next());
        }

        return result;
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private Lists() {
    }
}
