package datastructures.doublylinkedlist.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The IDoublyLinkedListKeyValueNode interface defines a node of a doubly linked list.
 */
public interface IDoublyLinkedListNode<TValue extends Comparable<TValue>> extends IUnaryComparator<IDoublyLinkedListNode<TValue>> {
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
    IDoublyLinkedListNode<TValue> next();

    /**
     * Sets a next node.
     */
    void setNext(IDoublyLinkedListNode<TValue> node);

    /**
     * Gets a previous node.
     */
    IDoublyLinkedListNode<TValue> previous();

    /**
     * Sets a previous node.
     */
    void setPrevious(IDoublyLinkedListNode<TValue> node);
}
