package datastructures.hashmap.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IIterator;
import base.interfaces.IUnaryComparator;
import datastructures.node.interfaces.IKeyValueNode;

/**
 * The IHashMap interface defines a hash map.
 */
public interface IHashMap<TKey extends Comparable<TKey>, TValue>
    extends IUnaryComparator<IHashMap<TKey, TValue>>,
    IIterable<IKeyValueNode<TKey, TValue>> {

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
     * Returns the corresponding removed value, or null if the key was not found.
     */
    TValue remove(TKey key);

    /**
     * Checks whether a key exists in the map.
     */
    boolean containsKey(TKey key);

    /**
     * Checks whether a value exists in the map.
     */
    boolean containsValue(TValue Value);

    /**
     * Clears the map.
     */
    void clear();

    /**
     * Returns a size of the map.
     */
    int size();

    /**
     * Checks whether the map is empty.
     */
    boolean isEmpty();

    /**
     * Gets an iterator of the hash map.
     */
    IIterator<IKeyValueNode<TKey, TValue>> getIterator();

    /**
     * Gets a key iterator of the hash map.
     */
    IIterator<TKey> getKeyIterator();

    /**
     * Gets a value iterator of the hash map.
     */
    IIterator<TValue> getValueIterator();
}
