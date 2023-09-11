package datastructures.node.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.node.interfaces.IKeyValueNode;

/**
 * The ValueIterator class implements an iterator of values from key-value nodes.
 */
public final class ValueIterator<TKey extends Comparable<TKey>, TValue> implements IIterator<TValue> {
    private final IIterator<IKeyValueNode<TKey, TValue>> iterator;

    /**
     * Creates a new iterator of values from key-value nodes.
     */
    public static <TKey extends Comparable<TKey>, TValue> IIterator<TValue> make(
        IIterator<IKeyValueNode<TKey, TValue>> iterator) {

        return new ValueIterator<>(iterator);
    }

    /**
     * The ValueIterator constructor.
     */
    private ValueIterator(IIterator<IKeyValueNode<TKey, TValue>> iterator) {
        Conditions.validateNotNull(
            iterator,
            "The iterator of key-value nodes.");

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
