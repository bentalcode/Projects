package datastructures.doublylinkedlist.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNodeReverseIterator;
import datastructures.node.interfaces.IKeyValueNode;

/**
 * The DoublyLinkedListKeyValueNodeReverseIterator class implements a reverse iterator
 * of key-value nodes of a doubly linked list.
 */
public final class DoublyLinkedListKeyValueNodeReverseIterator<TKey extends Comparable<TKey>, TValue>
    implements IIterator<IKeyValueNode<TKey, TValue>> {

    private final IDoublyLinkedListNodeReverseIterator<IKeyValueNode<TKey, TValue>> iterator;

    /**
     * The DoublyLinkedListNodeIterator constructor.
     */
    public DoublyLinkedListKeyValueNodeReverseIterator(
        IDoublyLinkedListNodeReverseIterator<IKeyValueNode<TKey, TValue>> iterator) {

        Conditions.validateNotNull(
            iterator,
            "The reverse iterator of a key-value node of a doubly linked list.");

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
