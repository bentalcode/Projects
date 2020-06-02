package datastructures.multileveldoublylinkedlist.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.multileveldoublylinkedlist.interfaces.IMultiLevelDoublyLinkedListNode;

/**
 * The MultiLevelDoublyLinkedListNodeValueIterator class implements an iterator of
 * values of a multi-level doubly linked list.
 */
public final class MultiLevelDoublyLinkedListNodeValueIterator<T extends Comparable<T>> implements IIterator<T> {
    private final IIterator<IMultiLevelDoublyLinkedListNode<T>> iterator;

    /**
     * The MultiLevelDoublyLinkedListNodeValueIterator constructor.
     */
    public MultiLevelDoublyLinkedListNodeValueIterator(IIterator<IMultiLevelDoublyLinkedListNode<T>> iterator) {
        Conditions.validateNotNull(
            iterator,
            "The iterator of nodes of a multi-level doubly linked list.");

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
