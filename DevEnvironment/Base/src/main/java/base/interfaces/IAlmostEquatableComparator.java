package base.interfaces;

/**
 * The IAlmostEquatableComparator interface defines an almost equatable comparator,
 * for determining an almost equality between two instances.
 */
public interface IAlmostEquatableComparator<T> {
    /**
     * Checks whether two instances are almost equals.
     */
    boolean isAlmostEqual(T lhs, T rhs);
}
