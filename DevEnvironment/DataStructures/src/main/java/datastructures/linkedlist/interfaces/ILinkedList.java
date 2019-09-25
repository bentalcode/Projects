package datastructures.linkedlist.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IUnaryComparator;
import datastructures.collections.interfaces.IValueIterable;

/**
 * The ILinkedList interface defines a linked list.
 */
public interface ILinkedList<TValue extends Comparable<TValue>> extends
    IUnaryComparator<ILinkedList<TValue>>,
    IIterable<ILinkedListNode<TValue>>,
    IValueIterable<TValue> {

    /**
     * Gets the head node of the list.
     */
    ILinkedListNode<TValue> getHead();

    /**
     * Gets the tail node of the list.
     */
    ILinkedListNode<TValue> getTail();

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
    void addAfter(ILinkedListNode<TValue> currNode, TValue valueToAdd);

    /**
     * Adds a new node to the front of the list.
     */
    void addToFront(ILinkedListNode<TValue> node);

    /**
     * Adds a new node to the back of the list.
     */
    void addToBack(ILinkedListNode<TValue> node);

    /**
     * Adds a new node after a specific node of the list.
     */
    void addAfter(ILinkedListNode<TValue> currNode, ILinkedListNode<TValue> nodeToAdd);

    /**
     * Removes the front node from the list.
     * Returns the removed node or null if the list is empty.
     */
    ILinkedListNode<TValue> removeFromFront();

    /**
     * Removes a node after a specific node of the list.
     */
    void removeAfter(ILinkedListNode<TValue> currNode);

    /**
     * Clears the list.
     */
    void clear();

    /**
     * Gets a specific node by index. Index: [0, 1, 2, ... , size -1]
     */
    ILinkedListNode<TValue> getNode(int index);
}