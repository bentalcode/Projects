package datastructures.graph.core;

import base.core.Conditions;
import base.interfaces.IIterator;
import datastructures.graph.interfaces.IEdge;
import datastructures.graph.interfaces.IGraphData;
import datastructures.graph.interfaces.IVertex;

/**
 * The GraphData class implements data of a graph.
 */
public final class GraphData<TKey extends Comparable<TKey>, TValue> implements IGraphData<TKey, TValue> {
    private final IIterator<IVertex<TKey, TValue>> vertices;
    private final IIterator<IEdge<TKey, TValue>> edges;

    /**
     * Creates new graph data.
     */
    public static <TKey extends Comparable<TKey>, TValue> IGraphData<TKey, TValue> of(
        IIterator<IVertex<TKey, TValue>> vertices,
        IIterator<IEdge<TKey, TValue>> edges) {

        return new GraphData<>(vertices, edges);
    }

    /**
     * Gets the vertices of the graph.
     */
    public GraphData(
        IIterator<IVertex<TKey, TValue>> vertices,
        IIterator<IEdge<TKey, TValue>> edges) {

        Conditions.validateNotNull(
            vertices,
            "The iterator of vertices.");

        Conditions.validateNotNull(
            edges,
            "The iterator of edges.");

        this.vertices = vertices;
        this.edges = edges;
    }

    /**
     * Gets the vertices of the graph.
     */
    @Override
    public IIterator<IVertex<TKey, TValue>> vertices() {
        return this.vertices;
    }

    /**
     * Gets the edges of the graph.
     */
    @Override
    public IIterator<IEdge<TKey, TValue>> edges() {
        return this.edges;
    }
}
