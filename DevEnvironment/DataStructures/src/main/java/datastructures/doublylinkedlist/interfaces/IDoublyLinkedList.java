package datastructures.doublylinkedlist.interfaces;

import datastructures.collections.interfaces.IValueIterator;

/**
 * The IDoublyLinkedList interface defines a doubly linked list.
 */
public interface IDoublyLinkedList<TValue> {
    /**
     * Gets the head node of the list.
     */
    IDoublyLinkedListNode<TValue> getHead();

    /**
     * Gets the tail node of the list.
     */
    IDoublyLinkedListNode<TValue> getTail();

    /**
     * Gets the size of the list.
     */
    int size();

    /**
     * Checks whether the list is empty.
     */
    boolean empty();

    /**
     * Adds a new value to the front of the list.
     */
    void addToFront(TValue value);

    /**
     * Adds a new value to the back of the list.
     */
    void addToBack(TValue value);

    /**
     * Adds a new value after a specific node of the list.
     */
    void addAfter(IDoublyLinkedListNode<TValue> currNode, TValue valueToAdd);

    /**
     * Adds a new value before a specific node of the list.
     */
    void addBefore(IDoublyLinkedListNode<TValue> currNode, TValue valueToAdd);

    /**
     * Adds a new node to the front of the list.
     */
    void addToFront(IDoublyLinkedListNode<TValue> node);

    /**
     * Adds a new node to the back of the list.
     */
    void addToBack(IDoublyLinkedListNode<TValue> node);

    /**
     * Adds a new node after a specific node of the list.
     */
    void addAfter(IDoublyLinkedListNode<TValue> currNode, IDoublyLinkedListNode<TValue> nodeToAdd);

    /**
     * Adds a new node before a specific node of the list.
     */
    void addBefore(IDoublyLinkedListNode<TValue> currNode, IDoublyLinkedListNode<TValue> nodeToAdd);

    /**
     * Removes the front node from the list.
     */
    void removeFromFront();

    /**
     * Removes the back node from the list.
     */
    void removeFromBack();

    /**
     * Removes the a node from the list.
     */
    void remove(IDoublyLinkedListNode<TValue> nodeToRemove);

    /**
     * Gets an iterator of nodes of a list.
     */
    IDoublyLinkedListNodeIterator<TValue> getIterator();

    /**
     * Gets a reverse iterator of nodes of a list.
     */
    IDoublyLinkedListNodeIterator<TValue> getReverseIterator();

    /**
     * Gets an iterator of values of a list.
     */
    IValueIterator<TValue> getValueIterator();
}