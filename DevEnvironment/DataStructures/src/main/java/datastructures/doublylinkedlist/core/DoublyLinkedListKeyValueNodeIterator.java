package datastructures.doublylinkedlist.core;

import testbase.core.Conditions;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNodeIterator;
import datastructures.node.interfaces.IKeyValueNode;
import datastructures.node.interfaces.IKeyValueNodeIterator;
import datastructures.node.interfaces.IKeyValueNodeReverseIterator;
import java.util.Iterator;

/**
 * The DoublyLinkedListKeyValueNodeIterator class implements an iterator of key-value nodes of a doubly linked list.
 */
public final class DoublyLinkedListKeyValueNodeIterator<TKey extends Comparable<TKey>, TValue>
    implements IKeyValueNodeIterator<TKey, TValue>, IKeyValueNodeReverseIterator<TKey, TValue> {

    private final IDoublyLinkedListNodeIterator<IKeyValueNode<TKey, TValue>> iterator;

    /**
     * The DoublyLinkedListNodeIterator constructor.
     */
    public DoublyLinkedListKeyValueNodeIterator(IDoublyLinkedListNodeIterator<IKeyValueNode<TKey, TValue>> iterator) {
        Conditions.validateNotNull(
            iterator,
            "The iterator of a key-value node of doubly linked list.");

        this.iterator = iterator;
    }

    /**
     * Gets an iterator for iterating over nodes.
     */
    @Override
    public Iterator<IKeyValueNode<TKey, TValue>> iterator() {
        return this;
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
     * Checks whether there is a previous node.
     */
    @Override
    public boolean hasPrevious() {
        return iterator.hasPrevious();
    }

    /**
     * Gets the previous node.
     */
    @Override
    public IKeyValueNode<TKey, TValue> previous() {
        Conditions.validate(
            this.hasPrevious(),
            "The iterator has already reached the start of list.");

        IKeyValueNode<TKey, TValue> node = this.iterator.previous().getValue();

        return node;
    }
}
