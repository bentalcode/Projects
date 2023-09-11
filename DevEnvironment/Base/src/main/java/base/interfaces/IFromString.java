package base.interfaces;

/**
 * The IFromString interface of a from string transformer.
 */
public interface IFromString<T> {
    /**
     * Transforms a string to an object.
     */
    T fromString(String value);
}
