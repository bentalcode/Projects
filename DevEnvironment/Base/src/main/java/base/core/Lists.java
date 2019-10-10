package base.core;

import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * The Lists class implements complementary APIs for lists.
 */
public final class Lists {
    /**
     * Sorts a collection.
     */
    public static <T> void sort(List<T> list, IBinaryComparator<T> comparator) {
        Conditions.validateNotNull(
            list,
            "The list for sorting.");

        Conditions.validateNotNull(
            comparator,
            "The comparator.");

        Collections.sort(list, comparator.toComparator());
    }

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
     * Creates a list from a reverse iterator.
     */
    public static <T> List<T> fromReverseIterator(IReverseIterator<T> reverseIterator) {
        Conditions.validateNotNull(
            reverseIterator,
            "The reverse iterator for creating a list.");

        List<T> result = new ArrayList<>();

        while (reverseIterator.hasNext()) {
            result.add(reverseIterator.next());
        }

        return result;
    }

    /**
     * Reverses the list.
     */
    public static <T> List<T> reverse(List<T> list) {
        Conditions.validateNotNull(
            list,
            "The list to reverse.");

        List<T> result = Lists.fromReverseIterator(ListReverseIterator.of(list));

        return result;
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private Lists() {
    }
}
