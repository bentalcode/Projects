package base.interfaces;

/**
 * The IEquatableComparator interface defines an equatable comparator,
 * for determining equality between two instances.
 */
public interface IEquatableComparator<T> {
    /**
     * Checks whether two instances are equals.
     */
    boolean isEqual(T lhs, T rhs);
}
