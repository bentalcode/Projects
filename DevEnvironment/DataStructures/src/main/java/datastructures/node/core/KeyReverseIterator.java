package datastructures.node.core;

import base.core.Conditions;
import base.interfaces.IReverseIterator;
import datastructures.node.interfaces.IKeyValueNode;

/**
 * The KeyReverseIterator class implements a reverse iterator of keys from key-value nodes.
 */
public final class KeyReverseIterator<TKey extends Comparable<TKey>, TValue> implements IReverseIterator<TKey> {
    private final IReverseIterator<IKeyValueNode<TKey, TValue>> reverseIterator;

    /**
     * Creates a new reverse iterator of keys from key-value nodes.
     */
    public static <TKey extends Comparable<TKey>, TValue> IReverseIterator<TKey> make(
        IReverseIterator<IKeyValueNode<TKey, TValue>> reverseIterator) {

        return new KeyReverseIterator<>(reverseIterator);
    }

    /**
     * The KeyReverseIterator constructor.
     */
    private KeyReverseIterator(IReverseIterator<IKeyValueNode<TKey, TValue>> reverseIterator) {
        Conditions.validateNotNull(
            reverseIterator,
            "The reverse iterator of of key-value nodes.");

        this.reverseIterator = reverseIterator;

        this.reset();
    }

    /**
     * Checks whether there is a next key.
     */
    @Override
    public boolean hasNext() {
        return this.reverseIterator.hasNext();
    }

    /**
     * Gets the next key.
     */
    @Override
    public TKey next() {
        assert(this.hasNext());

        return this.reverseIterator.next().getKey();
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.reverseIterator.reset();
    }
}
