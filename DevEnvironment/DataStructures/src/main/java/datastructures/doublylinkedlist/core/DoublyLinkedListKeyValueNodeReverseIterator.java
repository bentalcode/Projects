package datastructures.doublylinkedlist.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;
import datastructures.node.interfaces.IKeyValueNode;

/**
 * The DoublyLinkedListKeyValueNodeReverseIterator class implements an iterator of key-value nodes of a doubly linked list.
 */
public final class DoublyLinkedListKeyValueNodeReverseIterator<TKey extends Comparable<TKey>, TValue>
    implements IReverseIterator<IKeyValueNode<TKey, TValue>> {

    private final IReverseIterator<IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>>> iterator;

    /**
     * Creates a reverse iterator of a key-value node.
     */
    public static <TKey extends Comparable<TKey>, TValue> IReverseIterator<IKeyValueNode<TKey, TValue>> of(
        IReverseIterator<IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>>> iterator) {

        return new DoublyLinkedListKeyValueNodeReverseIterator<>(iterator);
    }

    /**
     * The DoublyLinkedListKeyValueNodeReverseIterator constructor.
     */
    private DoublyLinkedListKeyValueNodeReverseIterator(
        IReverseIterator<IDoublyLinkedListNode<IKeyValueNode<TKey, TValue>>> iterator) {

        Conditions.validateNotNull(
            iterator,
            "The reverse iterator of a doubly linked list node of a key-value node.");

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
