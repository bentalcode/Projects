package datastructures.graph.interfaces;

import base.interfaces.IIterator;

/**
 * The IGraphData interface defines data of graph.
 */
public interface IGraphData<TKey extends Comparable<TKey>, TValue> {
    /**
     * Gets the vertices of the graph.
     */
    IIterator<IVertex<TKey, TValue>> vertices();

    /**
     * Gets the edges of the graph.
     */
    IIterator<IEdge<TKey, TValue>> edges();
}
