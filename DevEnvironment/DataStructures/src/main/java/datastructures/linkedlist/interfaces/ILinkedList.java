package datastructures.linkedlist.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IUnaryComparator;
import datastructures.collections.interfaces.ISizableCollection;
import datastructures.collections.interfaces.IValueIterable;

/**
 * The ILinkedList interface defines a linked list.
 */
public interface ILinkedList<T extends Comparable<T>> extends
    ISizableCollection,
    IIterable<ILinkedListNode<T>>,
    IValueIterable<T>,
    IUnaryComparator<ILinkedList<T>> {

    /**
     * Gets the head node of the list.
     */
    ILinkedListNode<T> getHead();

    /**
     * Gets the tail node of the list.
     */
    ILinkedListNode<T> getTail();

    /**
     * Adds a new value to the front of the list.
     */
    void addToFront(T value);

    /**
     * Adds a new value to the back of the list.
     */
    void addToBack(T value);

    /**
     * Adds a new value after a specific node of the list.
     */
    void addAfter(ILinkedListNode<T> currNode, T valueToAdd);

    /**
     * Adds a new node to the front of the list.
     */
    void addToFront(ILinkedListNode<T> node);

    /**
     * Adds a new node to the back of the list.
     */
    void addToBack(ILinkedListNode<T> node);

    /**
     * Adds a new node after a specific node of the list.
     */
    void addAfter(ILinkedListNode<T> currNode, ILinkedListNode<T> nodeToAdd);

    /**
     * Removes the front node from the list.
     * Returns the removed node or null if the list is empty.
     */
    ILinkedListNode<T> removeFromFront();

    /**
     * Removes a node after a specific node of the list.
     */
    void removeAfter(ILinkedListNode<T> currNode);

    /**
     * Clears the list.
     */
    void clear();

    /**
     * Gets a specific node by index. Index: [0, 1, 2, ... , size -1]
     */
    ILinkedListNode<T> getNode(int index);
}