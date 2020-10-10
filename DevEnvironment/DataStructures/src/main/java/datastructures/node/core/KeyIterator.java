package datastructures.node.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.node.interfaces.IKeyValueNode;

/**
 * The KeyIterator class implements an iterator of keys from key-value nodes.
 */
public final class KeyIterator<TKey extends Comparable<TKey>, TValue> implements IIterator<TKey> {
    private final IIterator<IKeyValueNode<TKey, TValue>> iterator;

    /**
     * Creates a new iterator of keys from key value nodes.
     */
    public static <TKey extends Comparable<TKey>, TValue> IIterator<TKey> make(
        IIterator<IKeyValueNode<TKey, TValue>> iterator) {

        return new KeyIterator<>(iterator);
    }

    /**
     * The KeyIterator constructor.
     */
    private KeyIterator(IIterator<IKeyValueNode<TKey, TValue>> iterator) {
        Conditions.validateNotNull(
            iterator,
            "The iterator of key-value nodes.");

        this.iterator = iterator;

        this.reset();
    }

    /**
     * Checks whether there is a next key.
     */
    @Override
    public boolean hasNext() {
        return this.iterator.hasNext();
    }

    /**
     * Gets the next key.
     */
    @Override
    public TKey next() {
        assert(this.hasNext());

        return this.iterator.next().getKey();
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.iterator.reset();
    }
}
