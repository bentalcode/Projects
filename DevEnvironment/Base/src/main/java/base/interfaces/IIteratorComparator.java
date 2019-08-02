package base.interfaces;

/**
 * The IArrayComparator interface defines a comparator for generic arrays.
 */
public interface IIteratorComparator<T> {
    /**
     * Checks whether the iterators are equals with an element comparator.
     */
    boolean isEqual(IIterator<T> lhs, IIterator<T> rhs, IEquatableComparator<T> comparator);

    /**
     * Determines the relative order of arrays with an element comparator.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    int compareTo(IIterator<T> lhs, IIterator<T> rhs, IComparableComparator<T> comparator);
}
