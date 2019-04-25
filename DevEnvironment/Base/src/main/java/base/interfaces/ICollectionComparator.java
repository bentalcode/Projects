package base.interfaces;

import java.util.Collection;

/**
 * The ICollectionComparator interface defines a comparator for generic collection.
 */
public interface ICollectionComparator<T> {
    /**
     * Checks whether the sets are equals with an element comparator.
     */
    boolean isEqual(Collection<T> lhs, Collection<T> rhs, IBinaryComparator<T> comparator);

    /**
     * Determines the relative order of sets with an element comparator.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    int compareTo(Collection<T> lhs, Collection<T> rhs, IBinaryComparator<T> comparator);
}
