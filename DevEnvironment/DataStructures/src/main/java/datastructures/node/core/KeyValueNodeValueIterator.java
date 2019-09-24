package datastructures.node.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.node.interfaces.IKeyValueNode;

/**
 * The KeyValueNodeValueIterator class implements an iterator of values of key-value nodes.
 */
public final class KeyValueNodeValueIterator<TKey extends Comparable<TKey>, TValue> implements IIterator<TValue> {
    private final IIterator<IKeyValueNode<TKey, TValue>> iterator;

    /**
     * Creates a new value iterator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IIterator<TValue> of(
        IIterator<IKeyValueNode<TKey, TValue>> iterator) {

        return new KeyValueNodeValueIterator<>(iterator);
    }

    /**
     * The KeyValueNodeValueIterator constructor.
     */
    private KeyValueNodeValueIterator(IIterator<IKeyValueNode<TKey, TValue>> iterator) {
        Conditions.validateNotNull(
            iterator,
            "The iterator of a key-value node.");

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
        assert(this.hasNext());

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
