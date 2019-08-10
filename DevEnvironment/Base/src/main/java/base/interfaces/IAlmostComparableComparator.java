package base.interfaces;

/**
 * The IAlmostComparableComparator interface defines an almost comparable comparator,
 * for determining an almost comparable order between two instances.
 */
public interface IAlmostComparableComparator<T> {
    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    int almostCompareTo(T lhs, T rhs);
}
