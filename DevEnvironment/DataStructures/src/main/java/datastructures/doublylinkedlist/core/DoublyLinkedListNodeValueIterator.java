package datastructures.doublylinkedlist.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.collections.interfaces.IValueIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNodeIterator;

/**
 * The DoublyLinkedListNodeValueIterator class implements an iterator of values of a doubly linked list.
 */
public final class DoublyLinkedListNodeValueIterator<TValue> implements IValueIterator<TValue> {
    private final IDoublyLinkedListNodeIterator<TValue> iterator;

    /**
     * The NodeValueIterator constructor.
     */
    public DoublyLinkedListNodeValueIterator(IDoublyLinkedListNodeIterator<TValue> iterator) {
        Conditions.validateNotNull(
            iterator,
            "The iterator of a node of a doubly linked list.");

        this.iterator = iterator;

        this.reset();
    }

    /**
     * Gets an iterator for iterating over values.
     */
    @Override
    public IIterator<TValue> iterator() {
        this.reset();
        return this;
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
