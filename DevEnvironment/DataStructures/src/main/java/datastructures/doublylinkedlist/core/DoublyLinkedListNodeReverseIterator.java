package datastructures.doublylinkedlist.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNodeIterator;

/**
 * The DoublyLinkedListNodeReverseIterator class implements a reverse iterator of nodes of a doubly linked list.
 */
public final class DoublyLinkedListNodeReverseIterator<TValue> implements IDoublyLinkedListNodeIterator<TValue> {

    private final IDoublyLinkedListNode<TValue> tailNode;
    private IDoublyLinkedListNode<TValue> currentNode;

    /**
     * The DoublyLinkedListNodeIterator constructor.
     */
    public DoublyLinkedListNodeReverseIterator(IDoublyLinkedListNode<TValue> tailNode) {
        Conditions.validateNotNull(
            tailNode,
            "The tail node of a doubly linked list.");

        this.tailNode = tailNode;

        this.reset();
    }

    /**
     * Gets an iterator for iterating over nodes.
     */
    @Override
    public IIterator<IDoublyLinkedListNode<TValue>> iterator() {
        this.reset();
        return this;
    }

    /**
     * Checks whether there is a next node.
     */
    @Override
    public boolean hasNext() {
        return this.currentNode.previous() != null;
    }

    /**
     * Gets the next node.
     */
    @Override
    public IDoublyLinkedListNode<TValue> next() {
        Conditions.validate(
            this.hasNext(),
            "The iterator has already reached the start of list.");

        this.currentNode = this.currentNode.previous();

        return currentNode;
    }

    /**
     * Checks whether there is a previous node.
     */
    @Override
    public boolean hasPrevious() {
        return this.currentNode.next() != null;
    }

    /**
     * Gets the previous node.
     */
    @Override
    public IDoublyLinkedListNode<TValue> previous() {
        Conditions.validate(
            this.hasPrevious(),
            "The iterator has already reached the end of list.");

        this.currentNode = this.currentNode.next();

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
