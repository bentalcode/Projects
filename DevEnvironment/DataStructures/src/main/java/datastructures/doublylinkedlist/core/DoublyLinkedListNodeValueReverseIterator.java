package datastructures.doublylinkedlist.core;

import base.core.Conditions;
import base.interfaces.IReverseIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;

/**
 * The DoublyLinkedListNodeValueReverseIterator class implements a reverse iterator
 * of values of a doubly linked list.
 */
public final class DoublyLinkedListNodeValueReverseIterator<T extends Comparable<T>> implements IReverseIterator<T> {
    private final IReverseIterator<IDoublyLinkedListNode<T>> reverseIterator;

    /**
     * Creates a new reverse iterator of values of a doubly linked list.
     */
    public static <T extends Comparable<T>> IReverseIterator<T> make(
        IReverseIterator<IDoublyLinkedListNode<T>> reverseIterator) {

        return new DoublyLinkedListNodeValueReverseIterator<>(reverseIterator);
    }

    /**
     * The DoublyLinkedListNodeValueReverseIterator constructor.
     */
    private DoublyLinkedListNodeValueReverseIterator(IReverseIterator<IDoublyLinkedListNode<T>> reverseIterator) {
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
    public T next() {
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
