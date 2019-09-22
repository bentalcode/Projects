package datastructures.doublylinkedlist.core;

import base.interfaces.IReverseIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;

/**
 * The DoublyLinkedListNodeReverseIterator class implements a reverse iterator of nodes of a doubly linked list.
 */
public final class DoublyLinkedListNodeReverseIterator<TValue extends Comparable<TValue>> implements
    IReverseIterator<IDoublyLinkedListNode<TValue>> {

    private final IDoublyLinkedListNode<TValue> tailNode;
    private IDoublyLinkedListNode<TValue> currentNode;

    /**
     * The DoublyLinkedListNodeIterator constructor.
     */
    public DoublyLinkedListNodeReverseIterator(IDoublyLinkedListNode<TValue> tailNode) {
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
    public IDoublyLinkedListNode<TValue> next() {
        assert(this.hasNext());

        IDoublyLinkedListNode<TValue> currentNode = this.currentNode;
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
