package datastructures.graph.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.ClassTypes;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IComparableComparator;
import base.interfaces.IEquatableComparator;
import base.interfaces.IHashCodeProvider;
import datastructures.graph.GraphException;
import datastructures.graph.interfaces.IAdjacencyMatrix;
import datastructures.graph.interfaces.IEdge;
import datastructures.graph.interfaces.IVertex;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The AdjacencyMatrix class implements an adjacency matrix of a graph.
 */
public final class AdjacencyMatrix<TKey extends Comparable<TKey>, TValue> implements IAdjacencyMatrix<TKey, TValue> {
    private final Map<IVertex<TKey, TValue>, Set<IVertex<TKey, TValue>>> connections;

    private final IBinaryComparator<IAdjacencyMatrix<TKey, TValue>> comparator;
    private final int hashCode;
    private final Logger log = LoggerFactory.getLogger(ClassTypes.class);

    /**
     * The AdjacencyMatrix constructor.
     */
    public AdjacencyMatrix(Map<IVertex<TKey, TValue>, Set<IVertex<TKey, TValue>>> connections) {
        this(
            connections,
            AdjacencyMatrix.defaultComparator());
    }

    /**
     * The AdjacencyMatrix constructor.
     */
    public AdjacencyMatrix(
        Map<IVertex<TKey, TValue>, Set<IVertex<TKey, TValue>>> connections,
        IBinaryComparator<IAdjacencyMatrix<TKey, TValue>> comparator) {

        Conditions.validateNotNull(
            connections,
            "The connections of an adjacency matrix.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an adjacency matrix.");

        this.connections = connections;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * Gets the connections of an adjacency matrix.
     */
    @Override
    public Map<IVertex<TKey, TValue>, Set<IVertex<TKey, TValue>>> connections() {
        return this.connections;
    }

    /**
     * Checks whether two vertices are connected.
     */
    @Override
    public boolean connected(IVertex<TKey, TValue> sourceVertex, IVertex<TKey, TValue> destinationVertex) {
        return
            this.connections.containsKey(sourceVertex) &&
            this.connections.get(sourceVertex).contains(destinationVertex);
    }

    /**
     * Gets the adjacent vertices of a vertex.
     */
    @Override
    public Set<IVertex<TKey, TValue>> getAdjacentVertices(IVertex<TKey, TValue> vertex) {
        return this.getVertexConnections(vertex);
    }

    /**
     * Gets the adjacent edges of a vertex.
     */
    @Override
    public Set<IEdge<TKey, TValue>> getAdjacentEdges(IVertex<TKey, TValue> vertex) {
        Set<IVertex<TKey, TValue>> adjacentVertices = this.getVertexConnections(vertex);

        Set<IEdge<TKey, TValue>> edges = new HashSet<>();

        for (IVertex<TKey, TValue> adjacentVertex : adjacentVertices) {
            IEdge<TKey, TValue> edge = this.connected(adjacentVertex, vertex) ?
                Edge.newEdge(vertex, adjacentVertex) :
                Edge.newDirectedEdge(vertex, adjacentVertex);

            edges.add(edge);
        }

        return edges;
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
    public boolean isEqual(IAdjacencyMatrix<TKey, TValue> other) {
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
    public int compareTo(IAdjacencyMatrix<TKey, TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<IAdjacencyMatrix<TKey, TValue>> defaultComparator() {
        IBinaryComparator<IVertex<TKey, TValue>> vertexComparator = Vertex.defaultComparator();
        return new Comparator<>(vertexComparator);
    }

    /**
     * The Comparator class implements a comparator of an adjacency matrix.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue>
        extends AbstractBinaryComparator<IAdjacencyMatrix<TKey, TValue>> {

        private final IBinaryComparator<IVertex<TKey, TValue>> vertexComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<IVertex<TKey, TValue>> vertexComparator) {
            this.vertexComparator = vertexComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IAdjacencyMatrix<TKey, TValue> obj) {
            IHashCodeProvider<Set<IVertex<TKey, TValue>>> valueProvider =
                (vertices) -> { return new HashCodeBuilder(457, 461).withCollection(vertices, this.vertexComparator).build(); };

            return new HashCodeBuilder(463, 467)
                .withMap(
                    obj.connections(),
                    this.vertexComparator,
                    valueProvider)
                    .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IAdjacencyMatrix<TKey, TValue> lhs, IAdjacencyMatrix<TKey, TValue> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            IEquatableComparator<Set<IVertex<TKey, TValue>>> valueComparator =
                (vertices1, vertices2) -> {
                    return new EqualBuilder().withCollection(vertices1, vertices2, this.vertexComparator).build();
                };

            return new EqualBuilder()
                .withMap(
                    lhs.connections(),
                    rhs.connections(),
                    this.vertexComparator,
                    valueComparator)
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
        public int compareTo(IAdjacencyMatrix<TKey, TValue> lhs, IAdjacencyMatrix<TKey, TValue> rhs) {
            if (lhs == null && rhs == null) {
                return 0;
            }

            if (lhs == null) {
                return -1;
            }

            if (rhs == null) {
                return 1;
            }

            IComparableComparator<Set<IVertex<TKey, TValue>>> valueComparator =
                (vertices1, vertices2) -> {
                    return new CompareToBuilder().withCollection(vertices1, vertices2, this.vertexComparator).build();
                };

            return new CompareToBuilder()
                .withMap(
                    lhs.connections(),
                    rhs.connections(),
                    this.vertexComparator,
                    valueComparator)
                .build();
        }
    }

    /**
     * Gets the connections of a vertex.
     */
    private Set<IVertex<TKey, TValue>> getVertexConnections(IVertex<TKey, TValue> vertex) {
        if (!this.connections.containsKey(vertex)) {
            String errorMessage = "The vertex: " + vertex.toString() + " is not defined in the adjacency matrix.";

            this.log.error(errorMessage);
            throw new GraphException(errorMessage);
        }

        return this.connections.get(vertex);
    }
}
