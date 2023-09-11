package datastructures.doublylinkedlist.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;

/**
 * The DoublyLinkedListNodeValueIterator class implements an iterator of values of a doubly linked list.
 */
public final class DoublyLinkedListNodeValueIterator<T extends Comparable<T>> implements IIterator<T> {
    private final IIterator<IDoublyLinkedListNode<T>> iterator;

    /**
     * Creates a new iterator of values of a doubly linked list.
     */
    public static <T extends Comparable<T>> IIterator<T> make(IIterator<IDoublyLinkedListNode<T>> iterator) {
        return new DoublyLinkedListNodeValueIterator<>(iterator);
    }

    /**
     * The DoublyLinkedListNodeValueIterator constructor.
     */
    private DoublyLinkedListNodeValueIterator(IIterator<IDoublyLinkedListNode<T>> iterator) {
        Conditions.validateNotNull(
            iterator,
            "The iterator of nodes of a doubly linked list.");

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
