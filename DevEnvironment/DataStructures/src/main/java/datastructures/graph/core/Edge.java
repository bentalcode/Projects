package datastructures.graph.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IBuilder;
import datastructures.graph.interfaces.IEdge;
import datastructures.graph.interfaces.IVertex;

/**
 * The Edge class implements an edge of a graph.
 */
public final class Edge<TKey extends Comparable<TKey>, TValue> implements IEdge<TKey, TValue> {
    private final IVertex<TKey, TValue> source;
    private final IVertex<TKey, TValue> destination;
    private final boolean directed;
    private final IBinaryComparator<IEdge<TKey, TValue>> comparator;
    private final int hashCode;

    /**
     * Creates a new instance of an edge.
     */
    public static <TKey extends Comparable<TKey>, TValue> IEdge<TKey, TValue> newEdge(
        IVertex<TKey, TValue> source,
        IVertex<TKey, TValue> destination) {

        return new Edge<>(source, destination, false, Edge.defaultComparator());
    }

    /**
     * Creates a new instance of a directed edge.
     */
    public static <TKey extends Comparable<TKey>, TValue> IEdge<TKey, TValue> newDirectedEdge(
        IVertex<TKey, TValue> source,
        IVertex<TKey, TValue> destination) {

        return new Edge<>(source, destination, true, Edge.defaultComparator());
    }

    /**
     * Creates a new instance of a directed edge.
     */
    public static <TKey extends Comparable<TKey>, TValue> IEdge<TKey, TValue> copy(IEdge<TKey, TValue> other) {
        Conditions.validateNotNull(
            other,
            "The edge for copying.");

        Vertex.copy(other.source());
        return new Edge<>(
            Vertex.copy(other.source()),
            Vertex.copy(other.destination()),
            other.directed(),
            other.getComparator());
    }

    /**
     * The Edge constructor.
     */
    private Edge(
        IVertex<TKey, TValue> source,
        IVertex<TKey, TValue> destination,
        boolean directed,
        IBinaryComparator<IEdge<TKey, TValue>> comparator) {

        Conditions.validateNotNull(
            source,
            "The source vertex.");

        Conditions.validateNotNull(
            destination,
            "The destination vertex.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of an edge.");

        this.source = source;
        this.destination = destination;
        this.directed = directed;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * Gets a source vertex.
     */
    @Override
    public IVertex<TKey, TValue> source() {
        return this.source;
    }

    /**
     * Gets a destination vertex.
     */
    @Override
    public IVertex<TKey, TValue> destination() {
        return this.destination;
    }

    /**
     * Returns whether an edge is directed.
     */
    @Override
    public boolean directed() {
        return this.directed;
    }

    /**
     * Gets the comparator.
     */
    public IBinaryComparator<IEdge<TKey, TValue>> getComparator() {
        return this.comparator;
    }

    /**
     * Gets string representation of this instance.
     */
    @Override
    public String toString() {
        return this.source + "->" + this.destination;
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
    public boolean isEqual(IEdge<TKey, TValue> other) {
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
    public int compareTo(IEdge<TKey, TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<IEdge<TKey, TValue>> defaultComparator() {
        IBinaryComparator<IVertex<TKey, TValue>> vertexComparator = Vertex.defaultComparator();
        return new Comparator<>(vertexComparator);
    }

    /**
     * The Comparator class implements a comparator of an edge.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue>
        extends AbstractBinaryComparator<IEdge<TKey, TValue>> {

        private final IBinaryComparator<IVertex<TKey, TValue>> vertexComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<IVertex<TKey, TValue>> vertexComparator) {
            Conditions.validateNotNull(
                vertexComparator,
                "The comparator of a vertex.");

            this.vertexComparator = vertexComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IEdge<TKey, TValue> obj) {
            return new HashCodeBuilder(479, 487)
                .withObject(obj.source(), this.vertexComparator)
                .withObject(obj.destination(), this.vertexComparator)
                .withBoolean(obj.directed())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IEdge<TKey, TValue> lhs, IEdge<TKey, TValue> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withObject(lhs.source(), rhs.source(), this.vertexComparator)
                .withObject(lhs.destination(), rhs.destination(), this.vertexComparator)
                .withBoolean(lhs.directed(), rhs.directed())
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
        public int compareTo(IEdge<TKey, TValue> lhs, IEdge<TKey, TValue> rhs) {
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
                .withObject(lhs.source(), rhs.source(), this.vertexComparator)
                .withObject(lhs.destination(), rhs.destination(), this.vertexComparator)
                .withBoolean(lhs.directed(), rhs.directed())
                .build();
        }
    }

    /**
     * The Builder class implements a builder for creating an edge.
     */
    public static final class Builder<TKey extends Comparable<TKey>, TValue> implements IBuilder<IEdge<TKey, TValue>> {
        private IVertex<TKey, TValue> source;
        private IVertex<TKey, TValue> destination;
        private boolean directed;

        /**
         * The Builder constructor.
         */
        public Builder() {
        }

        /**
         * Sets the source vertex.
         */
        public Builder<TKey, TValue> setSourceVertex(IVertex<TKey, TValue> source) {
            Conditions.validateNotNull(
                source,
                "The source vertex.");

            this.source = source;

            return this;
        }

        /**
         * Sets the destination vertex.
         */
        public Builder<TKey, TValue> setDestinationVertex(IVertex<TKey, TValue> destination) {
            Conditions.validateNotNull(
                destination,
                "The destination vertex.");

            this.destination = destination;

            return this;
        }

        /**
         * Sets a directed edge.
         */
        public Builder<TKey, TValue> setDirected() {
            this.directed = true;

            return this;
        }

        /**
         * Builds an edge.
         */
        @Override
        public IEdge<TKey, TValue> build() {
            return new Edge<>(
                this.source,
                this.destination,
                this.directed,
                Edge.defaultComparator());
        }
    }
}
