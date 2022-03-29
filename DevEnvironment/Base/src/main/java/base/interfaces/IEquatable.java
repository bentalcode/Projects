package base.interfaces;

/**
 * The IEquatable interface defines an equatable for a generic class,
 * for determining equality between this instance and another.
 */
public interface IEquatable<T> {
    /**
     * Checks whether the instances are equals.
     */
    boolean isEqual(T other);
}
