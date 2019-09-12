package datastructures.hashmap.interfaces;

import base.interfaces.IBuilder;
import base.interfaces.IIterator;
import datastructures.node.interfaces.IKeyValueNode;

/**
 * The IHashMapBuilder interface defines a builder of a hash-map.
 */
public interface IHashMapBuilder<TKey extends Comparable<TKey>, TValue> extends IBuilder<IHashMap<TKey, TValue>> {

    /**
     * Sets a key value pair.
     */
    IHashMapBuilder<TKey, TValue> set(TKey key, TValue value);

    /**
     * Sets a key value node.
     */
    IHashMapBuilder<TKey, TValue> set(IKeyValueNode<TKey, TValue> node);

    /**
     * Sets an key-value nodes with an iterator.
     */
    IHashMapBuilder<TKey, TValue> set(IIterator<IKeyValueNode<TKey, TValue>> iterator);
}
