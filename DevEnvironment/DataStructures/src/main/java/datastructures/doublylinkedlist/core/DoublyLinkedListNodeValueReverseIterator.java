package datastructures.doublylinkedlist.core;

import base.core.Conditions;
import base.interfaces.IReverseIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;

/**
 * The DoublyLinkedListNodeValueReverseIterator class implements a reverse iterator
 * of values of a doubly linked list.
 */
public final class DoublyLinkedListNodeValueReverseIterator<TValue extends Comparable<TValue>> implements IReverseIterator<TValue> {
    private final IReverseIterator<IDoublyLinkedListNode<TValue>> reverseIterator;

    /**
     * The NodeValueIterator constructor.
     */
    public DoublyLinkedListNodeValueReverseIterator(IReverseIterator<IDoublyLinkedListNode<TValue>> reverseIterator) {
        Conditions.validateNotNull(
            reverseIterator,
            "The reverse iterator of nodes of a doubly linked list.");

        this.reverseIterator = reverseIterator;

        this.reset();
    }

    /**
     * Checks whether there is a next value.
     */
    @Override
    public boolean hasNext() {
        return this.reverseIterator.hasNext();
    }

    /**
     * Gets the next value.
     */
    @Override
    public TValue next() {
        return this.reverseIterator.next().getValue();
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.reverseIterator.reset();
    }
}
