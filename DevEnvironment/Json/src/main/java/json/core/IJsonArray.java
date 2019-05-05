package json.core;

/**
 * The IJsonArray interface defines a json array.
 */
public interface IJsonArray<T> {
    /**
     * Gets an element of an array at a specified index.
     */
    T get(int index);

    /**
     * Gets the size of an array.
     */
    int size();

    /**
     * Checks whether an array is empty.
     */
    boolean empty();
}
