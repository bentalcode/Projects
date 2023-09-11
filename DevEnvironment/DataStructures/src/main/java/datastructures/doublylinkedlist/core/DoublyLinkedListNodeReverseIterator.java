package datastructures.doublylinkedlist.core;

import base.interfaces.IReverseIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;

/**
 * The DoublyLinkedListNodeReverseIterator class implements a reverse iterator of nodes of a doubly linked list.
 */
public final class DoublyLinkedListNodeReverseIterator<T extends Comparable<T>> implements
    IReverseIterator<IDoublyLinkedListNode<T>> {

    private final IDoublyLinkedListNode<T> tail;
    private IDoublyLinkedListNode<T> currNode;

    /**
     * Creates a new reverse iterator of a doubly linked list.
     */
    public static <T extends Comparable<T>> IReverseIterator<IDoublyLinkedListNode<T>> make(IDoublyLinkedListNode<T> tail) {
        return new DoublyLinkedListNodeReverseIterator<>(tail);
    }

    /**
     * The DoublyLinkedListNodeIterator constructor.
     */
    private DoublyLinkedListNodeReverseIterator(IDoublyLinkedListNode<T> tail) {
        this.tail = tail;

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
        this.currNode = this.currNode.previous();

        return currNode;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.currNode = this.tail;
    }
}
