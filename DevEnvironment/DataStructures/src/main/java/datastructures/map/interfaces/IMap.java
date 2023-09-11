package datastructures.map.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.IKeyIterable;
import base.interfaces.IKeyReverseIterable;
import base.interfaces.ISizableCollection;
import base.interfaces.IValueIterable;
import base.interfaces.IValueReverseIterable;
import datastructures.node.interfaces.IKeyValueNode;
import java.util.List;

/**
 * The IMap interface defines a map.
 */
public interface IMap<TKey extends Comparable<TKey>, TValue> extends
    ISizableCollection,
    IIterable<IKeyValueNode<TKey, TValue>>,
    IReverseIterable<IKeyValueNode<TKey, TValue>>,
    IKeyIterable<TKey>,
    IKeyReverseIterable<TKey>,
    IValueIterable<TValue>,
    IValueReverseIterable<TValue> {

    /**
     * Gets the corresponding value of the specified key.
     */
    TValue get(TKey key);

    /**
     * Tries getting the corresponding value of the specified key.
     * Returns null if the key was not found.
     */
    TValue tryGet(TKey key);

    /**
     * Sets a value for a specific key.
     *
     * Returns true for a creation of a key-value pair.
     * Returns false for an update of a key-value pair.
     */
    boolean set(TKey key, TValue value);

    /**
     * Removes a key from the map.
     * Returns the corresponding removed node, or null if the key was not found.
     */
    IKeyValueNode<TKey, TValue> remove(TKey key);

    /**
     * Checks whether a key exists in the map.
     */
    boolean containsKey(TKey key);

    /**
     * Checks whether a value exists in the map.
     */
    boolean containsValue(TValue Value);

    /**
     * Gets the values.
     */
    List<TValue> getValues();

    /**
     * Clears the map.
     */
    void clear();
}
