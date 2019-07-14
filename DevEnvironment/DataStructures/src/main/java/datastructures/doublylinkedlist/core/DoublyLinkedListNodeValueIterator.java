package datastructures.doublylinkedlist.core;

import base.core.Conditions;
import datastructures.collections.interfaces.IValueIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNodeIterator;
import java.util.Iterator;

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
    }

    /**
     * Gets an iterator for iterating over values.
     */
    @Override
    public Iterator<TValue> iterator() {
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
}
