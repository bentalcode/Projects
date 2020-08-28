package datastructures.doublylinkedlist.core;

import base.interfaces.IIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;

/**
 * The DoublyLinkedListNodeIterator class implements an iterator of nodes of a doubly linked list.
 */
public final class DoublyLinkedListNodeIterator<T extends Comparable<T>>
    implements IIterator<IDoublyLinkedListNode<T>> {

    private final IDoublyLinkedListNode<T> head;
    private IDoublyLinkedListNode<T> currNode;

    /**
     * Creates a new iterator of a doubly linked list.
     */
    public static <T extends Comparable<T>> IIterator<IDoublyLinkedListNode<T>> make(IDoublyLinkedListNode<T> head) {
        return new DoublyLinkedListNodeIterator<>(head);
    }

    /**
     * The DoublyLinkedListNodeIterator constructor.
     */
    private DoublyLinkedListNodeIterator(IDoublyLinkedListNode<T> head) {
        this.head = head;

        this.reset();
    }

    /**
     * Checks whether there is a next node.
     */
    @Override
    public boolean hasNext() {
        return this.currNode != null;
    }

    /**
     * Gets the next node.
     */
    @Override
    public IDoublyLinkedListNode<T> next() {
        assert(this.hasNext());

        IDoublyLinkedListNode<T> currNode = this.currNode;
        this.currNode = this.currNode.next();

        return currNode;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.currNode = this.head;
    }
}
