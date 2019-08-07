package datastructures.doublylinkedlist.core;

import base.core.Conditions;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNodeReverseIterator;

/**
 * The DoublyLinkedListNodeReverseIterator class implements a reverse iterator of nodes of a doubly linked list.
 */
public final class DoublyLinkedListNodeReverseIterator<TValue extends Comparable<TValue>> implements IDoublyLinkedListNodeReverseIterator<TValue> {
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
        Conditions.validate(
            this.hasNext(),
            "The reverse iterator has already reached the start of list.");

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
