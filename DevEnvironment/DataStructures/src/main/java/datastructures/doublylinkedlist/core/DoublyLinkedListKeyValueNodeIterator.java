package datastructures.doublylinkedlist.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;
import datastructures.node.interfaces.IKeyValueNode;

/**
 * The DoublyLinkedListKeyValueNodeIterator class implements an iterator of key-value nodes of a doubly linked list.
 */
public final class DoublyLinkedListKeyValueNodeIterator<TKey extends Comparable<TKey>, TValue>
    implements IIterator<IKeyValueNode<TKey, TValue>> {

    private final IIterator<IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>>> iterator;

    /**
     * Creates an iterator of a key-value node.
     */
    public static <TKey extends Comparable<TKey>, TValue> IIterator<IKeyValueNode<TKey, TValue>> of(
        IIterator<IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>>> iterator) {

        return new DoublyLinkedListKeyValueNodeIterator<>(iterator);
    }

    /**
     * The DoublyLinkedListKeyValueNodeIterator constructor.
     */
    private DoublyLinkedListKeyValueNodeIterator(IIterator<IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>>> iterator) {
        Conditions.validateNotNull(
            iterator,
            "The iterator of a doubly linked list node of a key-value node.");

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
        assert(this.hasNext());

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
