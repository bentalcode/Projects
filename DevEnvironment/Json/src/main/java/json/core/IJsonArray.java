package json.core;

import java.util.Iterator;

/**
 * The IJsonArray interface defines a json array.
 */
public interface IJsonArray extends IJsonElement, Iterator<IJsonValue>, Iterable<IJsonValue> {
    /**
     * Gets a json value of an array at a specified index.
     */
    IJsonValue get(int index);

    /**
     * Gets the size of an array.
     */
    int size();

    /**
     * Checks whether an array is empty.
     */
    boolean empty();

    /**
     * Adds a json value to an array.
     */
    void add(IJsonValue obj);
}
