package datastructures.node.core;

import base.core.Conditions;
import datastructures.node.interfaces.IKeyValueNode;
import datastructures.node.interfaces.IKeyValueNodeReverseIterator;
import java.util.List;

/**
 * The KeyValueNodeReverseIterator class implements a reverse iterator of generic key-value nodes.
 */
public final class KeyValueNodeReverseIterator<TKey extends Comparable<TKey>, TValue>
    implements IKeyValueNodeReverseIterator<TKey, TValue> {

    private final List<IKeyValueNode<TKey, TValue>> nodes;
    private int currentIndex;

    /**
     * The KeyValueNodeReverseIterator constructor.
     */
    public KeyValueNodeReverseIterator(List<IKeyValueNode<TKey, TValue>> nodes) {
        Conditions.validateNotNull(
            nodes,
            "The list of nodes.");

        this.nodes = nodes;

        this.reset();
    }

    /**
     * Checks whether there is a next node.
     */
    @Override
    public boolean hasNext() {
        return this.currentIndex >= 0;
    }

    /**
     * Gets the next node.
     */
    @Override
    public IKeyValueNode<TKey, TValue> next() {
        Conditions.validate(
            this.hasNext(),
            "The iterator has already reached the start of list.");

        IKeyValueNode<TKey, TValue> currNodeData = this.nodes.get(this.currentIndex);
        --this.currentIndex;

        return currNodeData;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.currentIndex = this.nodes.size() - 1;
    }
}
