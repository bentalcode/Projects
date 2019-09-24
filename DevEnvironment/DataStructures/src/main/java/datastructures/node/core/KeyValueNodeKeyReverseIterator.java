package datastructures.node.core;

import base.core.Conditions;
import base.interfaces.IReverseIterator;
import datastructures.node.interfaces.IKeyValueNode;

/**
 * The KeyValueNodeKeyReverseIterator class implements a reverse iterator of keys of key-value nodes.
 */
public final class KeyValueNodeKeyReverseIterator<TKey extends Comparable<TKey>, TValue> implements IReverseIterator<TKey> {
    private final IReverseIterator<IKeyValueNode<TKey, TValue>> reverseIterator;

    /**
     * Creates a new reverse iterator of keys of key-value nodes.
     */
    public static <TKey extends Comparable<TKey>, TValue> IReverseIterator<TKey> of(
        IReverseIterator<IKeyValueNode<TKey, TValue>> reverseIterator) {

        return new KeyValueNodeKeyReverseIterator<>(reverseIterator);
    }

    /**
     * The KeyValueNodeKeyReverseIterator constructor.
     */
    private KeyValueNodeKeyReverseIterator(IReverseIterator<IKeyValueNode<TKey, TValue>> reverseIterator) {
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
