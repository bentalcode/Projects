package datastructures.graph.interfaces;

import base.interfaces.IBinaryComparator;
import base.interfaces.IBuilder;
import java.util.List;

/**
 * The IGraphBuilder interface defines a builder of a graph.
 */
public interface IGraphBuilder<TKey extends Comparable<TKey>, TValue> extends IBuilder<IGraph<TKey, TValue>> {
    /**
     * Adds data of a graph.
     */
    IGraphBuilder<TKey, TValue> addGraphData(IGraphDefinition<TKey, TValue> graphData);

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
     * Adds an edge by vertices.
     */
    IGraphBuilder<TKey, TValue> addEdge(IVertex<TKey, TValue> source, IVertex<TKey, TValue> destination);

    /**
     * Adds a directed edge by vertices.
     */
    IGraphBuilder<TKey, TValue> addDirectedEdge(IVertex<TKey, TValue> source, IVertex<TKey, TValue> destination);

    /**
     * Adds edges.
     */
    IGraphBuilder<TKey, TValue> addEdges(List<IEdge<TKey, TValue>> edges);

    /**
     * Sets the comparator of a graph.
     */
    IGraphBuilder<TKey, TValue> setComparator(IBinaryComparator<IGraph<TKey, TValue>> comparator);
}
