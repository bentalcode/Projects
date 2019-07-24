package datastructures.node.core;

import testbase.core.Conditions;
import datastructures.node.interfaces.IKeyValueNode;
import datastructures.node.interfaces.IKeyValueNodeIterator;

import java.util.Iterator;
import java.util.List;

/**
 * The KeyValueNodeIterator class implements an iterator of generic key-value nodes.
 */
public final class KeyValueNodeIterator<TKey extends Comparable<TKey>, TValue> implements IKeyValueNodeIterator<TKey, TValue> {
    private List<IKeyValueNode<TKey, TValue>> nodes;
    private int currentIndex;

    /**
     * The KeyValueNodeIterator constructor.
     */
    public KeyValueNodeIterator(List<IKeyValueNode<TKey, TValue>> nodes) {
        Conditions.validateNotNull(
            nodes,
            "The list of nodes.");

        this.nodes = nodes;
    }

    /**
     * Gets an iterator for iterating over nodes.
     */
    @Override
    public Iterator<IKeyValueNode<TKey, TValue>> iterator() {
        this.currentIndex = 0;
        return this;
    }

    /**
     * Checks whether there is a next node.
     */
    @Override
    public boolean hasNext() {
        return this.currentIndex < this.nodes.size();
    }

    /**
     * Gets the next node.
     */
    @Override
    public IKeyValueNode<TKey, TValue> next() {
        Conditions.validate(
            this.hasNext(),
            "The iterator has already reached the end of nodes.");

        IKeyValueNode<TKey, TValue> currNodeData = this.nodes.get(this.currentIndex);
        ++this.currentIndex;

        return currNodeData;
    }
}