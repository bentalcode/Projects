package datastructures.node.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The INode interface defines a generic node.
 */
public interface INode<TValue extends Comparable<TValue>> extends IUnaryComparator<INode<TValue>> {
    /**
     * Gets a value of a node.
     */
    TValue getValue();

    /**
     * Sets a value of a node.
     */
    void setValue(TValue value);
}
