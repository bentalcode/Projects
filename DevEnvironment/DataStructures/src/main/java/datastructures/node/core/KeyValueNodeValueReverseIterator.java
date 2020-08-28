package datastructures.node.core;

import base.core.Conditions;
import base.interfaces.IReverseIterator;
import datastructures.node.interfaces.IKeyValueNode;

/**
 * The KeyValueNodeValueReverseIterator class implements a reverse iterator of values of key-value nodes.
 */
public final class KeyValueNodeValueReverseIterator<TKey extends Comparable<TKey>, TValue> implements IReverseIterator<TValue> {
    private final IReverseIterator<IKeyValueNode<TKey, TValue>> reverseIterator;

    /**
     * Creates a new reverse iterator of values of key-value nodes.
     */
    public static <TKey extends Comparable<TKey>, TValue> IReverseIterator<TValue> make(
        IReverseIterator<IKeyValueNode<TKey, TValue>> reverseIterator) {

        return new KeyValueNodeValueReverseIterator<>(reverseIterator);
    }

    /**
     * The KeyValueNodeValueReverseIterator constructor.
     */
    private KeyValueNodeValueReverseIterator(IReverseIterator<IKeyValueNode<TKey, TValue>> reverseIterator) {
        Conditions.validateNotNull(
            reverseIterator,
            "The reverse iterator of of key-value nodes.");

        this.reverseIterator = reverseIterator;

        this.reset();
    }

    /**
     * Checks whether there is a next value.
     */
    @Override
    public boolean hasNext() {
        return this.reverseIterator.hasNext();
    }

    /**
     * Gets the next value.
     */
    @Override
    public TValue next() {
        assert(this.hasNext());

        return this.reverseIterator.next().getValue();
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.reverseIterator.reset();
    }
}
