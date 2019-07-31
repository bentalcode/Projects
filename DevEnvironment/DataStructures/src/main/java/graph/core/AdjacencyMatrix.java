package graph.core;

import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import graph.interfaces.IAdjacencyMatrix;

/**
 * The AdjacencyMatrix class implements an adjacency matrix of a graph.
 */
public final class AdjacencyMatrix implements IAdjacencyMatrix {
    private final boolean[][] connections;
    private IBinaryComparator<IAdjacencyMatrix> comparator;
    private final int hashCode;

    /**
     * The AdjacencyMatrix constructor.
     */
    public AdjacencyMatrix(boolean[][] connections) {
        this(
            connections,
            AdjacencyMatrix.DefaultComparator());
    }

    /**
     * The AdjacencyMatrix constructor.
     */
    public AdjacencyMatrix(
        boolean[][] connections,
        IBinaryComparator<IAdjacencyMatrix> comparator) {

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
    public boolean[][] connections() {
        return this.connections;
    }

    /**
     * Checks whether two vertices are connected.
     */
    @Override
    public boolean connected(int row, int column) {
        Conditions.validate(
            row >= 0 && row < this.connections.length,
            "The row index is out of range.");

        Conditions.validate(
            column >= 0 && column < this.connections[0].length,
            "The column index is out of range.");

        return this.connections[row][column];
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
    public boolean isEqual(IAdjacencyMatrix other) {
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
    public int compareTo(IAdjacencyMatrix other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<IAdjacencyMatrix> DefaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of an adjacency matrix.
     */
    public static final class Comparator implements IBinaryComparator<IAdjacencyMatrix> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IAdjacencyMatrix obj) {
            return new HashCodeBuilder(3, 5)
                .withBooleanArray(obj.connections())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        public boolean isEqual(IAdjacencyMatrix lhs, IAdjacencyMatrix rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withBooleanArray(lhs.connections(), rhs.connections())
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
        public int compareTo(IAdjacencyMatrix lhs, IAdjacencyMatrix rhs) {
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
                .withBooleanArray(lhs.connections(), rhs.connections())
                .build();
        }
    }
}
