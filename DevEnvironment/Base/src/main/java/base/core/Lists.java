package base.core;

import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import java.util.ArrayList;
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

        list.sort(comparator.toComparator());
    }

    /**
     * Creates a list from an array.
     */
    public static <T> List<T> fromArray(T[] array) {
        return new ArrayList<>(java.util.Arrays.asList(array));
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

        List<T> result = new ArrayList<>(list.size());

        int currIndex = list.size() - 1;

        while (currIndex >= 0) {
            T currValue = list.get(currIndex);
            result.add(currValue);

            --currIndex;
        }

        return result;
    }

    /**
     * Reverses the list in place.
     */
    public static <T> void reverseInPlace(List<T> list) {
        Conditions.validateNotNull(
            list,
            "The list to reverse.");

        int startIndex = 0;
        int endIndex = list.size() - 1;

        while (startIndex < endIndex) {
            T temp = list.get(startIndex);
            list.set(startIndex, list.get(endIndex));
            list.set(endIndex, temp);

            ++startIndex;
            --endIndex;
        }
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private Lists() {
    }
}
