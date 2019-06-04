package datastructures.node.core;

import base.core.Conditions;
import datastructures.node.interfaces.INode;
import datastructures.node.interfaces.INodeIterator;
import java.util.Iterator;
import java.util.List;

/**
 * The NodeIterator class implements an iterator of data.
 */
public final class NodeIterator<TKey extends Comparable<TKey>, TValue> implements INodeIterator<TKey, TValue> {
    private List<INode<TKey, TValue>> nodes;
    private int currentIndex;

    /**
     * The NodeIterator constructor.
     */
    public NodeIterator(List<INode<TKey, TValue>> nodes) {
        Conditions.validateNotNull(
            nodes,
            "The list of nodes.");

        this.nodes = nodes;
    }

    /**
     * Gets an iterator for iterating over nodes.
     */
    @Override
    public Iterator<INode<TKey, TValue>> iterator() {
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
    public INode<TKey, TValue> next() {
        Conditions.validate(
            this.hasNext(),
            "The iterator has already reached the end of nodes.");

        INode<TKey, TValue> currNodeData = this.nodes.get(this.currentIndex);
        ++this.currentIndex;

        return currNodeData;
    }

    /**
     * Removes the current node.
     */
    @Override
    public void remove() {
        throw new UnsupportedOperationException("Removing node from a list is not supported.");
    }
}
