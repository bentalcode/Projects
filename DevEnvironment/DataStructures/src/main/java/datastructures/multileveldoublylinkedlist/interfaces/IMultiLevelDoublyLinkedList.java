package datastructures.multileveldoublylinkedlist.interfaces;

import base.interfaces.IIterable;
import base.interfaces.ISizableCollection;
import base.interfaces.IUnaryComparator;
import base.interfaces.IValueIterable;

/**
 * The IMultiLevelDoublyLinkedList interface defines a multi-level doubly linked list.
 */
public interface IMultiLevelDoublyLinkedList<T extends Comparable<T>> extends
    ISizableCollection,
    IIterable<IMultiLevelDoublyLinkedListNode<T>>,
    IValueIterable<T>,
    IUnaryComparator<IMultiLevelDoublyLinkedList<T>> {

    /**
     * Gets the head node of the list.
     */
    IMultiLevelDoublyLinkedListNode<T> getHead();

    /**
     * Adds a new value to the front of the list.
     */
    void addToFront(T value);

    /**
     * Adds a new value after a specific node of the list.
     */
    void addAfter(IMultiLevelDoublyLinkedListNode<T> currNode, T valueToAdd);

    /**
     * Adds a new value before a specific node of the list.
     */
    void addBefore(IMultiLevelDoublyLinkedListNode<T> currNode, T valueToAdd);

    /**
     * Adds a new value bellow a specific node of the list.
     */
    void addBellow(IMultiLevelDoublyLinkedListNode<T> currNode, T valueToAdd);

    /**
     * Adds a new value above a specific node of the list.
     */
    void addAbove(IMultiLevelDoublyLinkedListNode<T> currNode, T valueToAdd);

    /**
     * Adds a new node to the front of the list.
     */
    void addToFront(IMultiLevelDoublyLinkedListNode<T> node);

    /**
     * Adds a new node after a specific node of the list.
     */
    void addAfter(IMultiLevelDoublyLinkedListNode<T> currNode, IMultiLevelDoublyLinkedListNode<T> nodeToAdd);

    /**
     * Adds a new node before a specific node of the list.
     */
    void addBefore(IMultiLevelDoublyLinkedListNode<T> currNode, IMultiLevelDoublyLinkedListNode<T> nodeToAdd);

    /**
     * Adds a new node bellow a specific node of the list.
     */
    void addBellow(IMultiLevelDoublyLinkedListNode<T> currNode, IMultiLevelDoublyLinkedListNode<T> nodeToAdd);

    /**
     * Adds a new node above a specific node of the list.
     */
    void addAbove(IMultiLevelDoublyLinkedListNode<T> currNode, IMultiLevelDoublyLinkedListNode<T> nodeToAdd);

    /**
     * Clears the list.
     */
    void clear();
}