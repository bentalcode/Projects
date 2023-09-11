package datastructures.graph.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import datastructures.graph.interfaces.IRoute;
import datastructures.graph.interfaces.IVertex;

/**
 * The Route class implements a way or course taken in getting
 * from a starting vertex to a destination vertex in a graph.
 */
public final class Route<TKey extends Comparable<TKey>, TValue> implements IRoute<TKey, TValue> {
    private final IVertex<TKey, TValue> source;
    private final IVertex<TKey, TValue> destination;
    private final IBinaryComparator<IRoute<TKey, TValue>> comparator;
    private final int hashCode;

    /**
     * Creates a new instance of a route.
     */
    public static <TKey extends Comparable<TKey>, TValue> IRoute<TKey, TValue> make(
        IVertex<TKey, TValue> source,
        IVertex<TKey, TValue> destination) {

        return new Route<>(
            source,
            destination,
            Route.defaultComparator());
    }

    /**
     * Copies a route.
     */
    public static <TKey extends Comparable<TKey>, TValue> IRoute<TKey, TValue> copy(IRoute<TKey, TValue> route) {
        Conditions.validateNotNull(
            route,
            "The route for copying.");

        return new Route<>(
            Vertex.copy(route.source()),
            Vertex.copy(route.destination()),
            Route.defaultComparator());
    }

    /**
     * The Route constructor.
     */
    private Route(
        IVertex<TKey, TValue> source,
        IVertex<TKey, TValue> destination,
        IBinaryComparator<IRoute<TKey, TValue>> comparator) {

        Conditions.validateNotNull(
            source,
            "The source vertex.");

        Conditions.validateNotNull(
            destination,
            "The destination vertex.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a route.");

        this.source = source;
        this.destination = destination;
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
     * Gets the comparator.
     */
    public IBinaryComparator<IRoute<TKey, TValue>> getComparator() {
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
    public boolean isEqual(IRoute<TKey, TValue> other) {
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
    public int compareTo(IRoute<TKey, TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<IRoute<TKey, TValue>> defaultComparator() {
        IBinaryComparator<IVertex<TKey, TValue>> vertexComparator = Vertex.defaultComparator();
        return new Comparator<>(vertexComparator);
    }

    /**
     * The Comparator class implements a comparator of a route.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue>
        extends AbstractBinaryComparator<IRoute<TKey, TValue>> {

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
        public int getHashCode(IRoute<TKey, TValue> obj) {
            return new HashCodeBuilder(503, 509)
                .withObject(obj.source(), this.vertexComparator)
                .withObject(obj.destination(), this.vertexComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IRoute<TKey, TValue> lhs, IRoute<TKey, TValue> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withObject(lhs.source(), rhs.source(), this.vertexComparator)
                .withObject(lhs.destination(), rhs.destination(), this.vertexComparator)
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
        public int compareTo(IRoute<TKey, TValue> lhs, IRoute<TKey, TValue> rhs) {
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
                .build();
        }
    }
}
