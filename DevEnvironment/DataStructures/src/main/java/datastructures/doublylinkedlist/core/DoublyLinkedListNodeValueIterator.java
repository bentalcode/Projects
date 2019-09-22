package datastructures.doublylinkedlist.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.collections.interfaces.IValueIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;

/**
 * The DoublyLinkedListNodeValueIterator class implements an iterator of values of a doubly linked list.
 */
public final class DoublyLinkedListNodeValueIterator<TValue extends Comparable<TValue>> implements IValueIterator<TValue> {
    private final IIterator<IDoublyLinkedListNode<TValue>> iterator;

    /**
     * The NodeValueIterator constructor.
     */
    public DoublyLinkedListNodeValueIterator(IIterator<IDoublyLinkedListNode<TValue>> iterator) {
        Conditions.validateNotNull(
            iterator,
            "The iterator of a node of a doubly linked list node.");

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
    public TValue next() {
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
