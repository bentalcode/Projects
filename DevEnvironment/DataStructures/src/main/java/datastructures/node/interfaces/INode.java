package datastructures.node.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The INode interface defines a generic node.
 */
public interface INode<T extends Comparable<T>> extends IUnaryComparator<INode<T>> {
    /**
     * Gets a value of a node.
     */
    T getValue();

    /**
     * Sets a value of a node.
     */
    void setValue(T value);
}
