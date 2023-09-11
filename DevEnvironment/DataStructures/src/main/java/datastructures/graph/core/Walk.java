package datastructures.graph.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.core.ListIterator;
import base.core.ListReverseIterator;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import base.core.Collections;
import datastructures.graph.interfaces.IVertex;
import datastructures.graph.interfaces.IWalk;
import java.util.ArrayList;
import java.util.List;

/**
 * The Walk class implements a walk in a graph.
 * A walk is a finite or infinite sequence of edges which joins a sequence of vertices.
 */
public final class Walk<TKey extends Comparable<TKey>, TValue> implements IWalk<TKey, TValue> {
    private final List<IVertex<TKey, TValue>> vertices;
    private final IBinaryComparator<IWalk<TKey, TValue>> comparator;

    /**
     * Creates a new walk.
     */
    public static <TKey extends Comparable<TKey>, TValue> IWalk<TKey, TValue> make(List<IVertex<TKey, TValue>> vertices) {
        return new Walk<>(vertices);
    }

    /**
     * Creates a new list of walks.
     */
    public static <TKey extends Comparable<TKey>, TValue> List<IWalk<TKey, TValue>> createWalks(
        List<List<IVertex<TKey, TValue>>> verticesList) {

        Conditions.validateNotNull(
            verticesList,
            "The list of vertices.");

        List<IWalk<TKey, TValue>> walks = new ArrayList<>();

        for (List<IVertex<TKey, TValue>> vertices : verticesList) {
            IWalk<TKey, TValue> walk = Walk.make(vertices);
            walks.add(walk);
        }

        return walks;
    }

    /**
     * Creates a new walk.
     */
    public static <TKey extends Comparable<TKey>, TValue> IWalk<TKey, TValue> newWalk(IWalk<TKey, TValue> walk) {
        return new Walk<>(walk);
    }

    /**
     * The Walk constructor.
     */
    public Walk() {
        this(
            new ArrayList<>(),
            Walk.defaultComparator());
    }

    /**
     * The Walk constructor.
     */
    public Walk(IBinaryComparator<IWalk<TKey, TValue>> comparator) {
        this(
            new ArrayList<>(),
            comparator);
    }

    /**
     * The Walk constructor.
     */
    public Walk(List<IVertex<TKey, TValue>> vertices) {
        this(
            vertices,
            Walk.defaultComparator());
    }

    /**
     * The Walk constructor.
     */
    public Walk(
        List<IVertex<TKey, TValue>> vertices,
        IBinaryComparator<IWalk<TKey, TValue>> comparator) {

        Conditions.validateNotNull(
            comparator,
            "The list of vertices of a walk.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a walk.");

        this.vertices = vertices;
        this.comparator = comparator;
    }

    /**
     * The Walk copy constructor.
     */
    public Walk(IWalk<TKey, TValue> walk) {
        this(
            walk,
            Walk.defaultComparator());
    }

    /**
     * The Walk copy constructor.
     */
    public Walk(
        IWalk<TKey, TValue> walk,
        IBinaryComparator<IWalk<TKey, TValue>> comparator) {

        Conditions.validateNotNull(
            walk,
            "The walk to copy.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a walk.");

        this.vertices = new ArrayList<>(walk.getVertices());
        this.comparator = comparator;
    }

    /**
     * Adds a vertex.
     */
    @Override
    public void addVertex(IVertex<TKey, TValue> vertex) {
        Conditions.validateNotNull(
            vertex,
            "The vertex for adding to this walk.");

        this.vertices.add(vertex);
    }

    /**
     * Removes the last vertex.
     */
    @Override
    public void removeLastVertex() {
        this.vertices.remove(this.vertices.size() - 1);
    }

    /**
     * Gets the vertices.
     */
    @Override
    public List<IVertex<TKey, TValue>> getVertices() {
        return this.vertices;
    }

    /**
     * Checks whether a vertex has been visited before.
     */
    public boolean visited(IVertex<TKey, TValue> vertex) {
        return this.vertices.contains(vertex);
    }

    /**
     * Gets the number of steps.
     */
    @Override
    public int size() {
        return this.vertices.size();
    }

    /**
     * Checks whether a walk is empty.
     */
    @Override
    public boolean empty() {
        return this.size() == 0;
    }

    /**
     * Gets the iterator.
     */
    @Override
    public IIterator<IVertex<TKey, TValue>> getIterator() {
        return ListIterator.make(this.vertices);
    }

    /**
     * Gets the reverse iterator.
     */
    @Override
    public IReverseIterator<IVertex<TKey, TValue>> getReverseIterator() {
        return ListReverseIterator.make(this.vertices);
    }

    /**
     * Gets string representation of this instance.
     */
    @Override
    public String toString() {
        return Collections.toString(this.getIterator());
    }

    /**
     * Gets the hash code.
     */
    @Override
    public int hashCode() {
        return this.comparator.getHashCode(this);
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
    public boolean isEqual(IWalk<TKey, TValue> other) {
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
    public int compareTo(IWalk<TKey, TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<IWalk<TKey, TValue>> defaultComparator() {
        IBinaryComparator<IVertex<TKey, TValue>> vertexComparator = base.core.Comparator.make();
        return new Comparator<>(vertexComparator);
    }

    /**
     * The Comparator class implements a comparator of a walk.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue>
        extends AbstractBinaryComparator<IWalk<TKey, TValue>> {

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
        public int getHashCode(IWalk<TKey, TValue> obj) {
            return new HashCodeBuilder(521, 523)
                .withIterable(obj, this.vertexComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IWalk<TKey, TValue> lhs, IWalk<TKey, TValue> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withIterable(lhs, rhs, this.vertexComparator)
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
        public int compareTo(IWalk<TKey, TValue> lhs, IWalk<TKey, TValue> rhs) {
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
                .withIterable(lhs, rhs, this.vertexComparator)
                .build();
        }
    }
}
