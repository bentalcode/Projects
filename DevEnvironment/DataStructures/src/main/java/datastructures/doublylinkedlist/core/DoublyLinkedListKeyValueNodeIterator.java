package datastructures.doublylinkedlist.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNodeIterator;
import datastructures.node.interfaces.IKeyValueNode;

/**
 * The DoublyLinkedListKeyValueNodeIterator class implements an iterator of key-value nodes of a doubly linked list.
 */
public final class DoublyLinkedListKeyValueNodeIterator<TKey extends Comparable<TKey>, TValue>
    implements IIterator<IKeyValueNode<TKey, TValue>> {

    private final IDoublyLinkedListNodeIterator<IKeyValueNode<TKey, TValue>> iterator;

    /**
     * The DoublyLinkedListNodeIterator constructor.
     */
    public DoublyLinkedListKeyValueNodeIterator(IDoublyLinkedListNodeIterator<IKeyValueNode<TKey, TValue>> iterator) {
        Conditions.validateNotNull(
            iterator,
            "The iterator of a key-value node of doubly linked list.");

        this.iterator = iterator;

        this.reset();
    }

    /**
     * Checks whether there is a next node.
     */
    @Override
    public boolean hasNext() {
        return this.iterator.hasNext();
    }

    /**
     * Gets the next node.
     */
    @Override
    public IKeyValueNode<TKey, TValue> next() {
        Conditions.validate(
            this.hasNext(),
            "The iterator has already reached the end of list.");

        IKeyValueNode<TKey, TValue> node = this.iterator.next().getValue();

        return node;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.iterator.reset();
    }
}
