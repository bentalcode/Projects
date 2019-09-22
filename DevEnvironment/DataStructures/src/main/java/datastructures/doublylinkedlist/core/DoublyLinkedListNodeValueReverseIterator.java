package datastructures.doublylinkedlist.core;

import base.core.Conditions;
import base.interfaces.IReverseIterator;
import datastructures.collections.interfaces.IValueReverseIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;

/**
 * The DoublyLinkedListNodeValueReverseIterator class implements a reverse iterator
 * of values of a doubly linked list.
 */
public final class DoublyLinkedListNodeValueReverseIterator<TValue extends Comparable<TValue>> implements IValueReverseIterator<TValue> {
    private final IReverseIterator<IDoublyLinkedListNode<TValue>> iterator;

    /**
     * The NodeValueIterator constructor.
     */
    public DoublyLinkedListNodeValueReverseIterator(IReverseIterator<IDoublyLinkedListNode<TValue>> iterator) {
        Conditions.validateNotNull(
            iterator,
            "The reverse iterator of a doubly linked list node.");

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
