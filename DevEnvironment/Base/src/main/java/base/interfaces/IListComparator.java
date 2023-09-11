package base.interfaces;

import java.util.List;

/**
 * The IListComparator interface defines a comparator for generic list.
 */
public interface IListComparator<T> extends IBinaryComparator<List<T>> {
    /**
     * Checks whether the collections are equals with an element comparator.
     */
    boolean isEqual(List<T> lhs, List<T> rhs, IEquatableComparator<T> comparator);

    /**
     * Determines the relative order of collections with an element comparator.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    int compareTo(List<T> lhs, List<T> rhs, IComparableComparator<T> comparator);
}
