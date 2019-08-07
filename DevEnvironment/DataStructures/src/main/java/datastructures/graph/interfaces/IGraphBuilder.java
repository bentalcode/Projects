package datastructures.graph.interfaces;

import base.interfaces.IBinaryComparator;
import base.interfaces.IBuilder;
import java.util.List;

/**
 * The IGraph interface defines a builder of a graph.
 */
public interface IGraphBuilder<TKey extends Comparable<TKey>, TValue> extends IBuilder<IGraph<TKey, TValue>> {
    /**
     * Adds a vertex.
     */
    IGraphBuilder<TKey, TValue> addVertex(IVertex<TKey, TValue> vertex);

    /**
     * Adds vertices.
     */
    IGraphBuilder<TKey, TValue> addVertices(List<IVertex<TKey, TValue>> vertices);

    /**
     * Adds an edge.
     */
    IGraphBuilder<TKey, TValue> addEdge(IEdge<TKey, TValue> edge);

    /**
     * Adds edges.
     */
    IGraphBuilder<TKey, TValue> addEdges(List<IEdge<TKey, TValue>> edges);

    /**
     * Sets the comparator of a graph.
     */
    IGraphBuilder<TKey, TValue> setComparator(IBinaryComparator<IGraph<TKey, TValue>> comparator);
}
