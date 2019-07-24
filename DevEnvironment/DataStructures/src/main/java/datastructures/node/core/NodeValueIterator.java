package datastructures.node.core;

import testbase.core.Conditions;
import datastructures.node.interfaces.IKeyValueNodeIterator;
import datastructures.collections.interfaces.IValueIterator;
import java.util.Iterator;

/**
 * The NodeValueIterator class implements an iterator of values of generic nodes.
 */
public final class NodeValueIterator<TKey extends Comparable<TKey>, TValue> implements IValueIterator<TValue> {
    private final IKeyValueNodeIterator<TKey, TValue> iterator;

    /**
     * The NodeValueIterator constructor.
     */
    public NodeValueIterator(IKeyValueNodeIterator<TKey, TValue> iterator) {
        Conditions.validateNotNull(
            iterator,
            "The iterator of a node.");

        this.iterator = iterator;
    }

    /**
     * Gets an iterator for iterating over values.
     */
    @Override
    public Iterator<TValue> iterator() {
        return this;
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
        return this.iterator.next().getValue();
    }
}
