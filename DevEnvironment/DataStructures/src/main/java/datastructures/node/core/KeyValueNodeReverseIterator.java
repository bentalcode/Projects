package datastructures.node.core;

import base.core.Conditions;
import base.interfaces.IReverseIterator;
import datastructures.node.interfaces.IKeyValueNode;
import java.util.List;

/**
 * The KeyValueNodeReverseIterator class implements a reverse iterator of generic key-value nodes.
 */
public final class KeyValueNodeReverseIterator<TKey extends Comparable<TKey>, TValue>
    implements IReverseIterator<IKeyValueNode<TKey, TValue>> {

    private final List<IKeyValueNode<TKey, TValue>> nodes;
    private int currentIndex;

    /**
     * Creates a new reverse iterator for a key-value node.
     */
    public static <TKey extends Comparable<TKey>, TValue> IReverseIterator<IKeyValueNode<TKey, TValue>> of(
        List<IKeyValueNode<TKey, TValue>> nodes) {

        return KeyValueNodeReverseIterator.of(nodes);
    }

    /**
     * The KeyValueNodeReverseIterator constructor.
     */
    private KeyValueNodeReverseIterator(List<IKeyValueNode<TKey, TValue>> nodes) {
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
        assert(this.hasNext());

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
