package datastructures.cache.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.IUnaryComparator;
import datastructures.collections.interfaces.IKeyIterable;
import datastructures.collections.interfaces.IKeyReverseIterable;
import datastructures.collections.interfaces.IValueIterable;
import datastructures.collections.interfaces.IValueReverseIterable;
import datastructures.node.interfaces.IKeyValueNode;

/**
 * The ICache interface defines a cache.
 */
public interface ICache<TKey extends Comparable<TKey>, TValue> extends
    IUnaryComparator<ICache<TKey, TValue>>,
    IIterable<IKeyValueNode<TKey, TValue>>,
    IReverseIterable<IKeyValueNode<TKey, TValue>>,
    IKeyIterable<TKey>,
    IKeyReverseIterable<TKey>,
    IValueIterable<TValue>,
    IValueReverseIterable<TValue> {

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
     * Gets the size of a cache.
     */
    int size();

    /**
     * Checks whether the cache is empty.
     */
    boolean empty();
}
