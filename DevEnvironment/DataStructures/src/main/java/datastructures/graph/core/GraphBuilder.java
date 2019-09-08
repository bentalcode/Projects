package datastructures.graph.core;

import base.core.Conditions;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import datastructures.graph.interfaces.IAdjacencyMatrix;
import datastructures.graph.interfaces.IEdge;
import datastructures.graph.interfaces.IGraph;
import datastructures.graph.interfaces.IGraphBuilder;
import datastructures.graph.interfaces.IGraphData;
import datastructures.graph.interfaces.IVertex;
import java.util.ArrayList;
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
    public static <TKey extends Comparable<TKey>, TValue> IGraph<TKey, TValue> create(
        IGraphData<TKey, TValue> graphData) {

        IGraphBuilder<TKey, TValue> graphBuilder = new GraphBuilder<>();

        graphBuilder.addGraphData(graphData);
        IGraph<TKey, TValue> graph = graphBuilder.build();

        return graph;
    }

    /**
     * Creates new graphs from it's data.
     */
    public static <TKey extends Comparable<TKey>, TValue> List<IGraph<TKey, TValue>> create(
        IIterator<IGraphData<TKey, TValue>> dataIIterator) {

        List<IGraph<TKey, TValue>> graphs = new ArrayList<>();

        while (dataIIterator.hasNext()) {
            IGraphData<TKey, TValue> graphData = dataIIterator.next();
            IGraph<TKey, TValue> graph = GraphBuilder.create(graphData);
            graphs.add(graph);
        }

        return graphs;
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
    public IGraphBuilder<TKey, TValue> addGraphData(IGraphData<TKey, TValue> graphData) {
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
    public IGraphBuilder<TKey, TValue> addVertices(IIterator<IVertex<TKey, TValue>> vertices) {
        Conditions.validateNotNull(
            vertices,
            "The vertices for adding to the graph.");

        while (vertices.hasNext()) {
            IVertex<TKey, TValue> currVertex = vertices.next();
            this.addVertex(currVertex);
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
        this.connections.get(sourceVertex).add(destinationVertex);

        if (!edge.directed()) {
            this.connections.get(destinationVertex).add(sourceVertex);
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
    public IGraphBuilder<TKey, TValue> addEdges(IIterator<IEdge<TKey, TValue>> edges) {
        Conditions.validateNotNull(
            edges,
            "The edges for adding to the graph.");

        while (edges.hasNext()) {
            IEdge<TKey, TValue> currEdge = edges.next();
            this.addEdge(currEdge);
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
            this.comparator = Graph.DefaultComparator();
        }

        return new Graph<>(
            this.vertices,
            this.edges,
            adjacencyMatrix,
            this.comparator);
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
