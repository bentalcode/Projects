package datastructures.cache.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.IUnaryComparator;
import base.interfaces.IKeyIterable;
import base.interfaces.IKeyReverseIterable;
import base.interfaces.ISizableCollection;
import base.interfaces.IValueIterable;
import base.interfaces.IValueReverseIterable;
import datastructures.node.interfaces.IKeyValueNode;

/**
 * The ICache interface defines a cache.
 */
public interface ICache<TKey extends Comparable<TKey>, TValue> extends
    ISizableCollection,
    IIterable<IKeyValueNode<TKey, TValue>>,
    IReverseIterable<IKeyValueNode<TKey, TValue>>,
    IKeyIterable<TKey>,
    IKeyReverseIterable<TKey>,
    IValueIterable<TValue>,
    IValueReverseIterable<TValue>,
    IUnaryComparator<ICache<TKey, TValue>> {

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
     * Deletes a key, and it's associated value from the cache.
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
}
