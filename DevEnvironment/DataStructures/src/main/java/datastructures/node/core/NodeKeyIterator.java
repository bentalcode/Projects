package datastructures.node.core;

import base.core.Conditions;
import datastructures.node.interfaces.IKeyValueNodeIterator;
import datastructures.collections.interfaces.IKeyIterator;
import java.util.Iterator;

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
    }

    /**
     * Gets an iterator for iterating over keys.
     */
    @Override
    public Iterator<TKey> iterator() {
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
}
