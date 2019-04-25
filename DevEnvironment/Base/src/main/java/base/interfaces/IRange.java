package base.interfaces;

/**
 * The IRange interface defines a range.
 */
public interface IRange<T> {
    /**
     * Gets the first value.
     */
    T start();

    /**
     * Gets the end value.
     */
    T end();
}
