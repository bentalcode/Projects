package base.interfaces;

/**
 * The IRange interface defines a range.
 */
public interface IRange<T extends Comparable<T>> extends IUnaryComparator<IRange<T>> {
    /**
     * Gets start value.
     */
    T start();

    /**
     * Gets end value.
     */
    T end();

    /**
     * Checks whether a value is in the defined range.
     */
    boolean inRange(T value);
}
