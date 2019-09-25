package datastructures.linkedlist.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The ILinkedListNode interface defines a node of a linked list.
 */
public interface ILinkedListNode<TValue extends Comparable<TValue>> extends IUnaryComparator<ILinkedListNode<TValue>> {
    /**
     * Gets a value of a node.
     */
    TValue getValue();

    /**
     * Sets a value of a node.
     */
    void setValue(TValue value);

    /**
     * Gets a next node.
     */
    ILinkedListNode<TValue> next();

    /**
     * Sets a next node.
     */
    void setNext(ILinkedListNode<TValue> node);

    /**
     * Unlinked the node.
     */
    void unlinked();
}
