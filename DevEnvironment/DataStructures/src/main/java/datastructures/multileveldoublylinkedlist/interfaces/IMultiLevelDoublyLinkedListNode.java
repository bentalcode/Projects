package datastructures.multileveldoublylinkedlist.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The IMultiLevelDoublyLinkedListNode interface defines a node of a multi-level doubly linked list.
 */
public interface IMultiLevelDoublyLinkedListNode<T extends Comparable<T>> extends
    IUnaryComparator<IMultiLevelDoublyLinkedListNode<T>> {

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
    IMultiLevelDoublyLinkedListNode<T> next();

    /**
     * Sets a next node.
     */
    void setNext(IMultiLevelDoublyLinkedListNode<T> node);

    /**
     * Gets a previous node.
     */
    IMultiLevelDoublyLinkedListNode<T> previous();

    /**
     * Sets a previous node.
     */
    void setPrevious(IMultiLevelDoublyLinkedListNode<T> node);

    /**
     * Gets a child node.
     */
    IMultiLevelDoublyLinkedListNode<T> child();

    /**
     * Sets a child node.
     */
    void setChild(IMultiLevelDoublyLinkedListNode<T> node);

    /**
     * Unlinked the node.
     */
    void unlinked();
}
