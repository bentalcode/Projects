package datastructures.dimentions.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.Conditions;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import datastructures.dimentions.interfaces.IPosition;
import java.util.List;

/**
 * The Position class implements a 2D position.
 */
public final class Position implements IPosition {
    private int x;
    private int y;
    private final IBinaryComparator<IPosition> comparator;

    /**
     * The Position constructor.
     */
    public Position() {
        this(0, 0, Position.defaultComparator());
    }

    /**
     * The Position constructor.
     */
    public Position(int x, int y) {
        this(x, y, Position.defaultComparator());
    }

    /**
     * The Point constructor.
     */
    public Position(int x, int y, IBinaryComparator<IPosition> comparator) {
        Conditions.validateNotNull(
            comparator,
            "The comparator of a position.");

        this.x = x;
        this.y = y;
        this.comparator = comparator;
    }

    /**
     * Gets the X coordinate.
     */
    @Override
    public int getX() {
        return this.x;
    }

    /**
     * Gets the Y coordinate.
     */
    @Override
    public int getY() {
        return this.y;
    }

    /**
     * Adds a new position.
     */
    @Override
    public IPosition add(IPosition position) {
        Conditions.validateNotNull(
            position,
            "The position for adding.");

        this.x += position.getX();
        this.y += position.getY();

        return this;
    }

    /**
     * Subtracts from a position.
     */
    @Override
    public IPosition subtract(IPosition position) {
        Conditions.validateNotNull(
            position,
            "The position for subtracting.");

        this.x -= position.getX();
        this.y -= position.getY();

        return this;
    }

    /**
     * Adds new positions.
     */
    @Override
    public IPosition add(List<IPosition> positions) {
        Conditions.validateNotNull(
                positions,
            "The list of positions for adding.");

        for (IPosition position : positions) {
            this.x += position.getX();
            this.y += position.getY();
        }

        return this;
    }

    /**
     * Subtracts positions.
     */
    public IPosition subtract(List<IPosition> positions) {
        Conditions.validateNotNull(
            positions,
            "The list of positions for subtracting.");

        for (IPosition position : positions) {
            this.x -= position.getX();
            this.y -= position.getY();
        }

        return this;
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
    public boolean isEqual(IPosition other) {
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
    public int compareTo(IPosition other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<IPosition> defaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of a position.
     */
    public static final class Comparator extends AbstractBinaryComparator<IPosition> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IPosition position) {
            return new HashCodeBuilder(3, 5)
                .withInteger(position.getX())
                .withInteger(position.getY())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IPosition lhs, IPosition rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY();
        }

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        @Override
        public int compareTo(IPosition lhs, IPosition rhs) {
            if (lhs == null && rhs == null) {
                return 0;
            }

            if (lhs == null) {
                return -1;
            }

            if (rhs == null) {
                return 1;
            }

            if (lhs.getX() < rhs.getX()) {
                return -1;
            }

            if (lhs.getX() > rhs.getX()) {
                return 1;
            }

            if (lhs.getY() < rhs.getY()) {
                return -1;
            }

            if (lhs.getY() > rhs.getY()) {
                return 1;
            }

            return 0;
        }
    }
}
