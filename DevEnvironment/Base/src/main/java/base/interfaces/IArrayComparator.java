package base.interfaces;

/**
 * The IArrayComparator interface defines a comparator of generic arrays.
 */
public interface IArrayComparator<T> extends IBinaryComparator<T[]> {
    /**
     * Checks whether arrays are equals with an element comparator.
     */
    boolean isEqual(T[] lhs, T[] rhs, IEquatableComparator<T> comparator);

    /**
     * Determines the relative order of arrays with an element comparator.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    int compareTo(T[] lhs, T[] rhs, IComparableComparator<T> comparator);
}
