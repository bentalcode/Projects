package base.core;

/**
 * The IFromString interface of a from string.
 */
public interface IFromString<T> {
    /**
     * Converts the object from a string.
     */
    T fromString(String value);
}
