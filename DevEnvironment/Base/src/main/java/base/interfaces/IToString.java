package base.interfaces;

/**
 * The IToString interface defines a to string transformer.
 */
public interface IToString<T> {
    /**
     * Transforms an object to a string.
     */
    String toString(T obj);
}
