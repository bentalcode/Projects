package datastructures.graph.core;

import base.core.Conditions;
import base.interfaces.IBinaryComparator;
import datastructures.graph.interfaces.IAdjacencyMatrix;
import datastructures.graph.interfaces.IEdge;
import datastructures.graph.interfaces.IGraph;
import datastructures.graph.interfaces.IGraphBuilder;
import datastructures.graph.interfaces.IVertex;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * The GraphBuilder class implements a builder for a graph.
 */
public final class GraphBuilder<TKey extends Comparable<TKey>, TValue> implements IGraphBuilder<TKey, TValue> {
    private final Set<IVertex<TKey, TValue>> vertices = new HashSet<>();
    private final Set<IEdge<TKey, TValue>> edges = new HashSet<>();
    private final Map<IVertex<TKey, TValue>, Set<IVertex<TKey, TValue>>> connections = new HashMap<>();
    private IBinaryComparator<IGraph<TKey, TValue>> comparator;

    /**
     * The Graph constructor.
     */
    public GraphBuilder() {
    }

    /**
     * Adds a vertex.
     */
    @Override
    public IGraphBuilder<TKey, TValue> addVertex(IVertex<TKey, TValue> vertex) {
        Conditions.validateNotNull(
            vertex,
            "The vertex for adding to the graph.");

        this.vertices.add(vertex);

        return this;
    }

    /**
     * Adds an edge.
     */
    @Override
    public IGraphBuilder<TKey, TValue> addEdge(IEdge<TKey, TValue> edge) {
        Conditions.validateNotNull(
            edge,
            "The edge for adding to the graph.");

        IVertex<TKey, TValue> sourceVertex = edge.source();
        IVertex<TKey, TValue> destinationVertex = edge.destination();

        //
        // Add the new vertices if required...
        //
        this.addVertexIfNotExist(sourceVertex);
        this.addVertexIfNotExist(destinationVertex);

        //
        // Add the new edge...
        //
        this.edges.add(edge);

        //
        // Add the connections to the adjacency matrix...
        //
        this.connections.get(sourceVertex).add(destinationVertex);

        if (!edge.directed()) {
            this.connections.get(destinationVertex).add(sourceVertex);
        }

        return this;
    }

    /**
     * Sets the comparator of a graph.
     */
    @Override
    public IGraphBuilder<TKey, TValue> setComparator(IBinaryComparator<IGraph<TKey, TValue>> comparator) {
        Conditions.validateNotNull(
            comparator,
            "The comparator of a graph.");

        this.comparator = comparator;

        return this;
    }

    /**
     * Adds an edge.
     */
    @Override
    public IGraph<TKey, TValue> build() {
        IAdjacencyMatrix<TKey, TValue> adjacencyMatrix = new AdjacencyMatrix<>(this.connections);

        if (this.comparator == null) {
            this.comparator = Graph.DefaultComparator();
        }

        return new Graph<>(
            this.vertices,
            this.edges,
            adjacencyMatrix,
            comparator);
    }

    /**
     * Adds an vertex if not defined.
     */
    private void addVertexIfNotExist(IVertex<TKey, TValue> vertex) {
        if (!this.vertices.contains(vertex)) {
            this.vertices.add(vertex);
            this.connections.put(vertex, new HashSet<>());
        }
    }
}
