package datastructures.doublylinkedlist.interfaces;

import base.interfaces.IIterator;

/**
 * The IDoublyLinkedListNodeIterator interface defines an iterator of nodes of a doubly linked list.
 */
public interface IDoublyLinkedListNodeIterator<TValue> extends IIterator<IDoublyLinkedListNode<TValue>> {

    /**
     * Checks whether there is a next node.
     */
    boolean hasNext();

    /**
     * Gets the next node.
     */
    IDoublyLinkedListNode<TValue> next();

    /**
     * Checks whether there is a previous node.
     */
    boolean hasPrevious();

    /**
     * Gets the previous node.
     */
    IDoublyLinkedListNode<TValue> previous();
}
