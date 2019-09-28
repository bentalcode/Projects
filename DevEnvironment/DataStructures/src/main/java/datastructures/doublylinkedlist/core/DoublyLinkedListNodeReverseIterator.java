package datastructures.doublylinkedlist.core;

import base.interfaces.IReverseIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;

/**
 * The DoublyLinkedListNodeReverseIterator class implements a reverse iterator of nodes of a doubly linked list.
 */
public final class DoublyLinkedListNodeReverseIterator<T extends Comparable<T>> implements
    IReverseIterator<IDoublyLinkedListNode<T>> {

    private final IDoublyLinkedListNode<T> tailNode;
    private IDoublyLinkedListNode<T> currentNode;

    /**
     * The DoublyLinkedListNodeIterator constructor.
     */
    public DoublyLinkedListNodeReverseIterator(IDoublyLinkedListNode<T> tailNode) {
        this.tailNode = tailNode;

        this.reset();
    }

    /**
     * Checks whether there is a next node.
     */
    @Override
    public boolean hasNext() {
        return this.currentNode != null;
    }

    /**
     * Gets the next node.
     */
    @Override
    public IDoublyLinkedListNode<T> next() {
        assert(this.hasNext());

        IDoublyLinkedListNode<T> currentNode = this.currentNode;
        this.currentNode = this.currentNode.previous();

        return currentNode;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.currentNode = this.tailNode;
    }
}
