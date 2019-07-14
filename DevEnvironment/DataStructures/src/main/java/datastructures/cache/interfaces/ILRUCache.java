package datastructures.cache.interfaces;

import datastructures.node.interfaces.IKeyValueNode;
import datastructures.node.interfaces.IKeyValueNodeIterator;
import datastructures.collections.interfaces.IKeyIterator;
import datastructures.collections.interfaces.IValueIterator;

/**
 * The ILRUCache interface defines a least recently used cache.
 */
public interface ILRUCache<TKey extends Comparable<TKey>, TValue> {
    /**
     * Gets properties of a cache.
     */
    ICacheProperties getProperties();

    /**
     * Set a new key in the cache.
     * Complexity: O(1)
     */
    void set(TKey key, TValue value);

    /**
     * Gets a value of a specific key in the cache.
     * Complexity: O(1)
     */
    TValue get(TKey key);

    /**
     * Deletes a key and it's associated value from the cache.
     *
     * Returns true if the key has been removed successfully from the cache.
     * Returns false if the key is not in the cache.
     *
     * Complexity: O(1)
     */
    boolean delete(TKey key);

    /**
     * Checks whether a key is set in the cache.
     * Complexity: O(1)
     */
    boolean has(TKey key);

    /**
     * Gets an iterator of keys of a cache.
     * Complexity: O(1)
     */
    IKeyIterator<TKey> getKeyIterator();

    /**
     * Gets an iterator of values of a cache.
     * Complexity: O(1)
     */
    IValueIterator<TValue> getValueIterator();

    /**
     * Gets an iterator of data of a cache.
     * Complexity: O(1)
     */
    IKeyValueNodeIterator<TKey, TValue> getDataIterator();

    /**
     * Gets the size of a cache.
     */
    int size();

    /**
     * Checks whether the cache is empty.
     */
    boolean empty();
}
