package datastructures.doublylinkedlist.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The IDoublyLinkedListNode interface defines a node of a doubly linked list.
 */
public interface IDoublyLinkedListNode<T extends Comparable<T>> extends IUnaryComparator<IDoublyLinkedListNode<T>> {
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
    IDoublyLinkedListNode<T> next();

    /**
     * Sets a next node.
     */
    void setNext(IDoublyLinkedListNode<T> node);

    /**
     * Gets a previous node.
     */
    IDoublyLinkedListNode<T> previous();

    /**
     * Sets a previous node.
     */
    void setPrevious(IDoublyLinkedListNode<T> node);

    /**
     * Unlinked the node.
     */
    void unlinked();
}
