package datastructures.map.interfaces;

import base.interfaces.IIterator;
import datastructures.node.interfaces.IKeyValueNode;

/**
 * The IMapBuilder interface defines a builder of a map.
 */
public interface IMapBuilder<TKey extends Comparable<TKey>, TValue> {
    /**
     * Sets a key value pair.
     */
    void set(TKey key, TValue value);

    /**
     * Sets a key value node.
     */
    void set(IKeyValueNode<TKey, TValue> node);

    /**
     * Sets an key-value nodes with an iterator.
     */
    void set(IIterator<IKeyValueNode<TKey, TValue>> iterator);
}
