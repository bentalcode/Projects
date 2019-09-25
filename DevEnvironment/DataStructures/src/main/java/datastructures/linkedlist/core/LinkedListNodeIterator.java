package datastructures.linkedlist.core;

import base.interfaces.IIterator;
import datastructures.linkedlist.interfaces.ILinkedListNode;

/**
 * The LinkedListNodeIterator class implements an iterator of nodes of a linked list.
 */
public final class LinkedListNodeIterator<TValue extends Comparable<TValue>>
    implements IIterator<ILinkedListNode<TValue>> {

    private final ILinkedListNode<TValue> headNode;
    private ILinkedListNode<TValue> currentNode;

    /**
     * Creates a new iterator of a linked list.
     */
    public static <TValue extends Comparable<TValue>> IIterator<ILinkedListNode<TValue>> of(ILinkedListNode<TValue> headNode) {
        return new LinkedListNodeIterator<>(headNode);
    }

    /**
     * The LinkedListNodeIterator constructor.
     */
    public LinkedListNodeIterator(ILinkedListNode<TValue> headNode) {
        this.headNode = headNode;

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
    public ILinkedListNode<TValue> next() {
        assert(this.hasNext());


        ILinkedListNode<TValue> currentNode = this.currentNode;
        this.currentNode = this.currentNode.next();

        return currentNode;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.currentNode = this.headNode;
    }
}
