package datastructures.node.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The IKeyValueNode interface defines a generic key-value node.
 */
public interface IKeyValueNode<TKey extends Comparable<TKey>, TValue>
    extends IUnaryComparator<IKeyValueNode<TKey, TValue>> {

    /**
     * Gets a key of a node.
     */
    TKey getKey();

    /**
     * Gets a value of a node.
     */
    TValue getValue();

    /**
     * Sets a value of a node.
     */
    void setValue(TValue value);
}
