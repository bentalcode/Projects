package base.interfaces;

/**
 * The IIterableComparator interface defines a comparator for iterables.
 */
public interface IIterableComparator<T> {
    /**
     * Checks whether the iterables are equals with an element comparator.
     */
    boolean isEqual(IIterable<T> lhs, IIterable<T> rhs, IEquatableComparator<T> comparator);

    /**
     * Determines the relative order of iterables with an element comparator.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    int compareTo(IIterable<T> lhs, IIterable<T> rhs, IComparableComparator<T> comparator);
}
