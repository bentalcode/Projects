package datastructures.linkedlist.core;

import base.interfaces.IIterator;
import datastructures.linkedlist.interfaces.ILinkedListNode;

/**
 * The LinkedListNodeIterator class implements an iterator of nodes of a linked list.
 */
public final class LinkedListNodeIterator<T extends Comparable<T>> implements IIterator<ILinkedListNode<T>> {
    private final ILinkedListNode<T> headNode;
    private ILinkedListNode<T> currentNode;

    /**
     * Creates a new iterator of a linked list.
     */
    public static <T extends Comparable<T>> IIterator<ILinkedListNode<T>> of(ILinkedListNode<T> headNode) {
        return new LinkedListNodeIterator<>(headNode);
    }

    /**
     * The LinkedListNodeIterator constructor.
     */
    public LinkedListNodeIterator(ILinkedListNode<T> headNode) {
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
    public ILinkedListNode<T> next() {
        assert(this.hasNext());


        ILinkedListNode<T> currentNode = this.currentNode;
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
