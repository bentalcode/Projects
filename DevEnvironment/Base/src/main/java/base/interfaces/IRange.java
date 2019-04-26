package base.interfaces;

/**
 * The IRange interface defines a range.
 */
public interface IRange<T extends Comparable<T>> extends IUnaryComparator<IRange<T>> {
    /**
     * Gets the first value.
     */
    T start();

    /**
     * Gets the end value.
     */
    T end();

    /**
     * Checks whether a value is in the defined range.
     */
    boolean inRange(T value);
}
