package base.interfaces;

/**
 * The IToString interface defines a to string.
 */
public interface IToString<T> {
    /**
     * Converts the object to a string.
     */
    String toString(T obj);
}
