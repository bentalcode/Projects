package datastructures.node.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.node.interfaces.IKeyValueNodeIterator;
import datastructures.collections.interfaces.IKeyIterator;

/**
 * The NodeKeyIterator class implements an iterator of keys of generic nodes.
 */
public final class NodeKeyIterator<TKey extends Comparable<TKey>, TValue> implements IKeyIterator<TKey> {
    private final IKeyValueNodeIterator<TKey, TValue> iterator;

    /**
     * The NodeKeyIterator constructor.
     */
    public NodeKeyIterator(IKeyValueNodeIterator<TKey, TValue> iterator) {
        Conditions.validateNotNull(
            iterator,
            "The iterator of a node.");

        this.iterator = iterator;

        this.reset();
    }

    /**
     * Gets an iterator for iterating over keys.
     */
    @Override
    public IIterator<TKey> iterator() {
        this.reset();
        return this;
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
