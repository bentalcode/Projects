package datastructures.graph.core;

import base.core.Conditions;
import base.interfaces.IBinaryComparator;
import datastructures.graph.interfaces.IAdjacencyMatrix;
import datastructures.graph.interfaces.IEdge;
import datastructures.graph.interfaces.IGraph;
import datastructures.graph.interfaces.IGraphBuilder;
import datastructures.graph.interfaces.IGraphDefinition;
import datastructures.graph.interfaces.IVertex;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
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
     * Creates a new graph from it's data.
     */
    public static <TKey extends Comparable<TKey>, TValue> IGraph<TKey, TValue> make(
        IGraphDefinition<TKey, TValue> graphData) {

        IGraphBuilder<TKey, TValue> graphBuilder = new GraphBuilder<>();

        graphBuilder.addGraphData(graphData);
        return graphBuilder.build();
    }

    /**
     * The GraphBuilder constructor.
     */
    public GraphBuilder() {
    }

    /**
     * Adds data of a graph.
     */
    @Override
    public IGraphBuilder<TKey, TValue> addGraphData(IGraphDefinition<TKey, TValue> graphData) {
        Conditions.validateNotNull(
            graphData,
            "The data for adding to the graph.");

        this.addEdges(graphData.edges());
        this.addVertices(graphData.vertices());

        return this;
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
     * Adds vertices.
     */
    @Override
    public IGraphBuilder<TKey, TValue> addVertices(List<IVertex<TKey, TValue>> vertices) {
        Conditions.validateNotNull(
            vertices,
            "The vertices for adding to the graph.");

        for (IVertex<TKey, TValue> vertex : vertices) {
            this.addVertex(vertex);
        }

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
        this.addConnection(sourceVertex, destinationVertex);

        if (!edge.directed()) {
            this.addConnection(destinationVertex, sourceVertex);
        }

        return this;
    }

    /**
     * Adds an edge by vertices.
     */
    @Override
    public IGraphBuilder<TKey, TValue> addEdge(
        IVertex<TKey, TValue> source,
        IVertex<TKey, TValue> destination) {

        IEdge<TKey, TValue> edge = Edge.newEdge(source, destination);
        return this.addEdge(edge);
    }

    /**
     * Adds a directed edge by vertices.
     */
    @Override
    public IGraphBuilder<TKey, TValue> addDirectedEdge(
        IVertex<TKey, TValue> source,
        IVertex<TKey, TValue> destination) {

        IEdge<TKey, TValue> edge = Edge.newDirectedEdge(source, destination);
        return this.addEdge(edge);
    }

    /**
     * Adds edges.
     */
    @Override
    public IGraphBuilder<TKey, TValue> addEdges(List<IEdge<TKey, TValue>> edges) {
        Conditions.validateNotNull(
            edges,
            "The edges for adding to the graph.");

        for (IEdge<TKey, TValue> edge : edges) {
            this.addEdge(edge);
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
     * Builds the graph.
     */
    @Override
    public IGraph<TKey, TValue> build() {
        IAdjacencyMatrix<TKey, TValue> adjacencyMatrix = new AdjacencyMatrix<>(this.connections);

        if (this.comparator == null) {
            this.comparator = Graph.defaultComparator();
        }

        return new Graph<>(
            this.vertices,
            this.edges,
            adjacencyMatrix,
            this.comparator);
    }

    /**
     * Adds a connection to the adjacency matrix.
     */
    private void addConnection(
        IVertex<TKey, TValue> sourceVertex, IVertex<TKey, TValue> destinationVertex)
    {
        this.connections.get(sourceVertex).add(destinationVertex);
    }

    /**
     * Adds a vertex if not defined.
     */
    private void addVertexIfNotExist(IVertex<TKey, TValue> vertex) {
        if (!this.vertices.contains(vertex)) {
            this.vertices.add(vertex);
            this.connections.put(vertex, new HashSet<>());
        }
    }
}
