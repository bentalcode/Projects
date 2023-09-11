package base.interfaces;

/**
 * The IToString interface defines a string conversion.
 */
public interface IToString<T> {
    /**
     * Converts an object to a string.
     */
    String toString(T obj);
}
