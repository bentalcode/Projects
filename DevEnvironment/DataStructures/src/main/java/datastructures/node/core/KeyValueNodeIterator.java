package datastructures.node.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.node.interfaces.IKeyValueNode;
import java.util.List;

/**
 * The KeyValueNodeIterator class implements an iterator of generic key-value nodes.
 */
public final class KeyValueNodeIterator<TKey extends Comparable<TKey>, TValue>
    implements IIterator<IKeyValueNode<TKey, TValue>> {

    private final List<IKeyValueNode<TKey, TValue>> nodes;
    private int currentIndex;

    /**
     * Creates a new iterator for a key-value node.
     */
    public static <TKey extends Comparable<TKey>, TValue> IIterator<IKeyValueNode<TKey, TValue>> make(
        List<IKeyValueNode<TKey, TValue>> nodes) {

        return new KeyValueNodeIterator<>(nodes);
    }

    /**
     * The KeyValueNodeIterator constructor.
     */
    private KeyValueNodeIterator(List<IKeyValueNode<TKey, TValue>> nodes) {
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
        return this.currentIndex < this.nodes.size();
    }

    /**
     * Gets the next node.
     */
    @Override
    public IKeyValueNode<TKey, TValue> next() {
        assert(this.hasNext());

        IKeyValueNode<TKey, TValue> currNodeData = this.nodes.get(this.currentIndex);
        ++this.currentIndex;

        return currNodeData;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.currentIndex = 0;
    }
}
