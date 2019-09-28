package datastructures.linkedlist.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The ILinkedListNode interface defines a node of a linked list.
 */
public interface ILinkedListNode<T extends Comparable<T>> extends IUnaryComparator<ILinkedListNode<T>> {
    /**
     * Gets a value of a node.
     */
    T getValue();

    /**
     * Sets a value of a node.
     */
    void setValue(T value);

    /**
     * Gets a next node.
     */
    ILinkedListNode<T> next();

    /**
     * Sets a next node.
     */
    void setNext(ILinkedListNode<T> node);

    /**
     * Unlinked the node.
     */
    void unlinked();
}
