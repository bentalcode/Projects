package datastructures.doublylinkedlist.interfaces;

import base.interfaces.IIterator;

/**
 * The IDoublyLinkedListNodeIterator interface defines an iterator of nodes of a doubly linked list.
 */
public interface IDoublyLinkedListNodeIterator<TValue extends Comparable<TValue>> extends IIterator<IDoublyLinkedListNode<TValue>> {
}
