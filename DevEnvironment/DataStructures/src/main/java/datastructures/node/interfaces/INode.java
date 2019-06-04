package datastructures.node.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The INode interface defines a generic node.
 */
public interface INode<TKey extends Comparable<TKey>, TValue> extends IUnaryComparator<INode<TKey, TValue>> {
    /**
     * Gets a key of a node.
     */
    TKey getKey();

    /**
     * Gets a value of a node.
     */
    TValue getValue();
}
