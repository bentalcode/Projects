package datastructures.doublylinkedlist.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterable;
import base.interfaces.IReverseIterator;
import base.interfaces.IUnaryComparator;
import base.interfaces.ISizableCollection;
import datastructures.collections.interfaces.IValueIterable;
import datastructures.collections.interfaces.IValueReverseIterable;

/**
 * The IDoublyLinkedList interface defines a doubly linked list.
 */
public interface IDoublyLinkedList<T extends Comparable<T>> extends
    ISizableCollection,
    IIterable<IDoublyLinkedListNode<T>>,
    IReverseIterable<IDoublyLinkedListNode<T>>,
    IValueIterable<T>,
    IValueReverseIterable<T>,
    IUnaryComparator<IDoublyLinkedList<T>> {

    /**
     * Gets the head node of the list.
     */
    IDoublyLinkedListNode<T> getHead();

    /**
     * Gets the tail node of the list.
     */
    IDoublyLinkedListNode<T> getTail();

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
    void addAfter(IDoublyLinkedListNode<T> currNode, T valueToAdd);

    /**
     * Adds a new value before a specific node of the list.
     */
    void addBefore(IDoublyLinkedListNode<T> currNode, T valueToAdd);

    /**
     * Adds a new node to the front of the list.
     */
    void addToFront(IDoublyLinkedListNode<T> node);

    /**
     * Adds a new node to the back of the list.
     */
    void addToBack(IDoublyLinkedListNode<T> node);

    /**
     * Adds a new node after a specific node of the list.
     */
    void addAfter(IDoublyLinkedListNode<T> currNode, IDoublyLinkedListNode<T> nodeToAdd);

    /**
     * Adds a new node before a specific node of the list.
     */
    void addBefore(IDoublyLinkedListNode<T> currNode, IDoublyLinkedListNode<T> nodeToAdd);

    /**
     * Removes the front node from the list.
     * Returns the removed node or null if the list is empty.
     */
    IDoublyLinkedListNode<T> removeFromFront();

    /**
     * Removes the back node from the list.
     * Returns the removed node or null if the list is empty.
     */
    IDoublyLinkedListNode<T> removeFromBack();

    /**
     * Removes the a node from the list.
     */
    void remove(IDoublyLinkedListNode<T> nodeToRemove);

    /**
     * Clears the list.
     */
    void clear();

    /**
     * Gets an iterator of values of a list.
     */
    IIterator<T> getValueIterator();

    /**
     * Gets a reverse iterator of values of a list.
     */
    IReverseIterator<T> getValueReverseIterator();

    /**
     * Gets a specific node by index. Index: [0, 1, 2, ... , size -1]
     */
    IDoublyLinkedListNode<T> getNode(int index);
}