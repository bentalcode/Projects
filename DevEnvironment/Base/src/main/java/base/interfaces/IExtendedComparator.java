package base.interfaces;

/**
 * The IExtendedComparator interface defines an extended comparator.
 */
public interface IExtendedComparator<T> extends IBinaryComparator<T> {
    /**
     * Checks whether the collections are equals with an element comparator.
     */
    boolean isEqual(T lhs, T rhs, IEquatableComparator<T> comparator);

    /**
     * Determines the relative order of collections with an element comparator.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    int compareTo(T lhs, T rhs, IComparableComparator<T> comparator);
}
