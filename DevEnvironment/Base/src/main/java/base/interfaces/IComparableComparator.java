package base.interfaces;

/**
 * The IComparableComparator interface defines a comparable comparator,
 * for determining comparable order between two instances.
 */
public interface IComparableComparator<T> {
    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    int compareTo(T lhs, T rhs);
}
