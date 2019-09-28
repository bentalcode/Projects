package datastructures.linkedlist.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.linkedlist.interfaces.ILinkedListNode;

/**
 * The LinkedListNodeValueIterator class implements an iterator of values of a linked list.
 */
public final class LinkedListNodeValueIterator<T extends Comparable<T>> implements IIterator<T> {
    private final IIterator<ILinkedListNode<T>> iterator;

    /**
     * The NodeValueIterator constructor.
     */
    public LinkedListNodeValueIterator(IIterator<ILinkedListNode<T>> iterator) {
        Conditions.validateNotNull(
            iterator,
            "The iterator of nodes of a linked list.");

        this.iterator = iterator;

        this.reset();
    }

    /**
     * Checks whether there is a next value.
     */
    @Override
    public boolean hasNext() {
        return this.iterator.hasNext();
    }

    /**
     * Gets the next value.
     */
    @Override
    public T next() {
        return this.iterator.next().getValue();
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.iterator.reset();
    }
}
