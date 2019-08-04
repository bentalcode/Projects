package datastructures.graph.interfaces;

import base.interfaces.IBinaryComparator;
import base.interfaces.IBuilder;

/**
 * The IGraph interface defines a graph.
 */
public interface IGraphBuilder<TKey extends Comparable<TKey>, TValue> extends IBuilder<IGraph<TKey, TValue>> {
    /**
     * Adds a vertex.
     */
    IGraphBuilder<TKey, TValue> addVertex(IVertex<TKey, TValue> vertex);

    /**
     * Adds an edge.
     */
    IGraphBuilder<TKey, TValue> addEdge(IEdge<TKey, TValue> edge);

    /**
     * Sets the comparator of a graph.
     */
    IGraphBuilder<TKey, TValue> setComparator(IBinaryComparator<IGraph<TKey, TValue>> comparator);
}
