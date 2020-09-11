package algorithms.core;

import algorithms.interfaces.SortingOrder;
import base.core.Comparator;
import base.core.Conditions;
import base.interfaces.IBinaryComparator;
import java.util.Collection;

/**
 * The Sorting class implements complementary APIs for sorting.
 */
public final class Sorting {
    /**
     * Checks that the collection is sorted.
     */
    public static <T extends Comparable<T>> boolean isSorted(Collection<T> collection) {
        return isSorted(
            collection,
            Comparator.make(),
            SortingOrder.Ascending);
    }

    /**
     * Checks that the collection is sorted.
     */
    public static <T extends Comparable<T>> boolean isSorted(
        Collection<T> collection,
        SortingOrder sortingOrder) {

        return isSorted(
            collection,
            Comparator.make(),
            sortingOrder);
    }

    /**
     * Checks that the collection is sorted.
     */
    public static <T extends Comparable<T>> boolean isSorted(
        Collection<T> collection,
        IBinaryComparator<T> comparator) {

        return isSorted(collection, comparator, SortingOrder.Ascending);
    }

    /**
     * Checks that the collection is sorted.
     */
    public static <T extends Comparable<T>> boolean isSorted(
        Collection<T> collection,
        IBinaryComparator<T> comparator,
        SortingOrder sortingOrder) {

        Conditions.validateNotNull(
            collection,
            "The collection.");

        if (collection.isEmpty()) {
            return true;
        }

        T prevElement = null;

        int index = 0;
        for (T currElement : collection) {
            if (index > 0) {
                int compareStatus = comparator.compareTo(prevElement, currElement);

                if ((sortingOrder == SortingOrder.Ascending && compareStatus >= 1) || compareStatus <= -1) {
                    return false;
                }
            }

            prevElement = currElement;

            ++index;
        }

        return true;
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private Sorting() {
    }
}
