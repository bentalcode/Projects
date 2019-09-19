package datastructures.node.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.collections.interfaces.IKeyIterator;
import datastructures.collections.interfaces.IValueIterator;
import datastructures.node.interfaces.IKeyValueNode;

/**
 * The KeyValueNodeKeyIterator class implements an iterator of keys of key-value nodes.
 */
public final class KeyValueNodeKeyIterator<TKey extends Comparable<TKey>, TValue> implements IKeyIterator<TKey> {
    private final IIterator<IKeyValueNode<TKey, TValue>> iterator;

    /**
     * Creates a new key iterator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IKeyIterator<TKey> of(
        IIterator<IKeyValueNode<TKey, TValue>> iterator) {

        return new KeyValueNodeKeyIterator<>(iterator);
    }

    /**
     * The KeyValueNodeKeyIterator constructor.
     */
    private KeyValueNodeKeyIterator(IIterator<IKeyValueNode<TKey, TValue>> iterator) {
        Conditions.validateNotNull(
            iterator,
            "The iterator of a key-value node.");

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
