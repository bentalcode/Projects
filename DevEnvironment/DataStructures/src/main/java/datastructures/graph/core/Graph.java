package datastructures.graph.core;

import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import datastructures.graph.interfaces.IAdjacencyMatrix;
import datastructures.graph.interfaces.IEdge;
import datastructures.graph.interfaces.IGraph;
import datastructures.graph.interfaces.IGraphLogic;
import datastructures.graph.interfaces.IGraphTraversal;
import datastructures.graph.interfaces.IVertex;
import java.util.Set;

/**
 * The Graph class implements a graph.
 */
public final class Graph<TKey extends Comparable<TKey>, TValue> implements IGraph<TKey, TValue> {
    private final Set<IVertex<TKey, TValue>> vertices;
    private final Set<IEdge<TKey, TValue>> edges;
    private final IAdjacencyMatrix<TKey, TValue> adjacencyMatrix;

    private final IBinaryComparator<IGraph<TKey, TValue>> comparator;
    private final int hashCode;

    /**
     * The Graph constructor.
     */
    public Graph(
        Set<IVertex<TKey, TValue>> vertices,
        Set<IEdge<TKey, TValue>> edges,
        IAdjacencyMatrix<TKey, TValue> adjacencyMatrix) {
        this(
            vertices,
            edges,
            adjacencyMatrix,
            Graph.DefaultComparator());
    }

    /**
     * The Graph constructor.
     */
    public Graph(
        Set<IVertex<TKey, TValue>> vertices,
        Set<IEdge<TKey, TValue>> edges,
        IAdjacencyMatrix<TKey, TValue> adjacencyMatrix,
        IBinaryComparator<IGraph<TKey, TValue>> comparator) {

        Conditions.validateNotNull(
            vertices,
            "The vertices of the graph.");

        Conditions.validateNotNull(
            edges,
            "The edges of the graph.");

        Conditions.validateNotNull(
            adjacencyMatrix,
            "The adjacency matrix of the graph.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of the graph.");

        this.vertices = vertices;
        this.edges = edges;
        this.adjacencyMatrix = adjacencyMatrix;

        this.comparator = comparator;
        this.hashCode = this.comparator.getHashCode(this);
    }

    /**
     * Gets the vertices of the graph.
     */
    @Override
    public Set<IVertex<TKey, TValue>> vertices() {
        return this.vertices;
    }

    /**
     * Gets the edges of the graph.
     */
    @Override
    public Set<IEdge<TKey, TValue>> edges() {
        return this.edges;
    }

    /**
     * Gets the adjacency matrix.
     */
    @Override
    public IAdjacencyMatrix<TKey, TValue> getAdjacencyMatrix() {
        return this.adjacencyMatrix;
    }

    /**
     * Gets the number of vertices in the graph.
     * The order is equal to |V(G)|.
     */
    @Override
    public int getOrder() {
        return this.vertices.size();
    }

    /**
     * Gets the degree.
     * A vertex degree is the number of edges incident to a vertex. Notated as d(V).
     */
    @Override
    public int getDegree(IVertex<TKey, TValue> vertex) {
        Set<IVertex<TKey, TValue>> adjacentVertices = this.adjacencyMatrix.getAdjacentVertices(vertex);
        return adjacentVertices.size();
    }

    /**
     * Gets an interface of a graph traversal.
     */
    @Override
    public IGraphTraversal<TKey, TValue> getGraphTraversal() {
        return new GraphTraversal<>(this);
    }

    /**
     * Gets an interface of a graph logic.
     */
    @Override
    public IGraphLogic<TKey, TValue> getGraphLogic() {
        return new GraphLogic<>(this);
    }

    /**
     * Gets the hash code.
     */
    @Override
    public int hashCode() {
        return this.hashCode;
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean equals(Object other) {
        if (other == null) {
            return false;
        }

        if (this == other) {
            return true;
        }

        if (!this.getClass().isInstance(other)) {
            return false;
        }

        return this.isEqual(Casting.cast(other));
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean isEqual(IGraph<TKey, TValue> other) {
        return this.comparator.isEqual(this, other);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(IGraph<TKey, TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<IGraph<TKey, TValue>> DefaultComparator() {
        IBinaryComparator<IVertex<TKey, TValue>> vertexComparator = Vertex.DefaultComparator();
        IBinaryComparator<IEdge<TKey, TValue>> edgeComparator = Edge.DefaultComparator();
        IBinaryComparator<IAdjacencyMatrix<TKey, TValue>> adjacencyMatrixComparator = AdjacencyMatrix.DefaultComparator();

        return new Comparator<>(
            vertexComparator,
            edgeComparator,
            adjacencyMatrixComparator);
    }

    /**
     * The Comparator class implements a comparator of a graph.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue> implements IBinaryComparator<IGraph<TKey, TValue>> {
        private final IBinaryComparator<IVertex<TKey, TValue>> vertexComparator;
        private final IBinaryComparator<IEdge<TKey, TValue>> edgeComparator;
        private final IBinaryComparator<IAdjacencyMatrix<TKey, TValue>> adjacencyMatrixComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(
            IBinaryComparator<IVertex<TKey, TValue>> vertexComparator,
            IBinaryComparator<IEdge<TKey, TValue>> edgeComparator,
            IBinaryComparator<IAdjacencyMatrix<TKey, TValue>> adjacencyMatrixComparator) {

            Conditions.validateNotNull(
                vertexComparator,
                "The comparator of a vertex.");

            Conditions.validateNotNull(
                edgeComparator,
                "The comparator of an edge.");

            Conditions.validateNotNull(
                edgeComparator,
                "The comparator of an adjacency matrix.");

            this.vertexComparator = vertexComparator;
            this.edgeComparator = edgeComparator;
            this.adjacencyMatrixComparator = adjacencyMatrixComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IGraph<TKey, TValue> obj) {
            return new HashCodeBuilder(3, 5)
                .withCollection(obj.vertices(), this.vertexComparator)
                .withCollection(obj.edges(), this.edgeComparator)
                .withObject(obj.getAdjacencyMatrix(), this.adjacencyMatrixComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        public boolean isEqual(IGraph<TKey, TValue> lhs, IGraph<TKey, TValue> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withCollection(lhs.vertices(), rhs.vertices(), this.vertexComparator)
                .withCollection(lhs.edges(), rhs.edges(), this.edgeComparator)
                .withObject(lhs.getAdjacencyMatrix(), rhs.getAdjacencyMatrix(), this.adjacencyMatrixComparator)
                .build();
        }

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        @Override
        public int compareTo(IGraph<TKey, TValue> lhs, IGraph<TKey, TValue> rhs) {
            if (lhs == null && rhs == null) {
                return 0;
            }

            if (lhs == null) {
                return -1;
            }

            if (rhs == null) {
                return 1;
            }

            return new CompareToBuilder()
                .withCollection(lhs.vertices(), rhs.vertices(), this.vertexComparator)
                .withCollection(lhs.edges(), rhs.edges(), this.edgeComparator)
                .withObject(lhs.getAdjacencyMatrix(), rhs.getAdjacencyMatrix(), this.adjacencyMatrixComparator)
                .build();
        }
    }
}
