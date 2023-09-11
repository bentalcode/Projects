package datastructures.dimentions.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.Conditions;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import datastructures.dimentions.interfaces.IPosition;

/**
 * The Position class implements a 2D position.
 */
public final class Position implements IPosition {
    private int x;
    private int y;
    private final IBinaryComparator<IPosition> comparator;

    /**
     * Creates an origin position (0, 0).
     */
    public static IPosition origin() {
        return new Position();
    }

    /**
     * Creates a position.
     */
    public static IPosition make(int x, int y) {
        return new Position(x, y);
    }

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
     * The Position constructor.
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
     * Sets the X coordinate.
     */
    @Override
    public void setX(int x) {
        this.x = x;
    }

    /**
     * Sets the Y coordinate.
     */
    @Override
    public void setY(int y) {
        this.y = y;
    }

    /**
     * Moves left.
     */
    @Override
    public void moveLeft() {
        --this.x;
    }

    /**
     * Moves right.
     */
    @Override
    public void moveRight() {
        ++this.x;
    }

    /**
     * Moves up.
     */
    @Override
    public void moveUp() {
        ++this.y;
    }

    /**
     * Moves down.
     */
    @Override
    public void moveDown() {
        --this.y;
    }

    /**
     * Adds to a position.
     */
    @Override
    public IPosition add(IPosition position) {
        Conditions.validateNotNull(
            position,
            "The position for adding.");

        return this.add(position.getX(), position.getY());
    }

    /**
     * Subtracts from a position.
     */
    @Override
    public IPosition subtract(IPosition position) {
        Conditions.validateNotNull(
            position,
            "The position for subtracting.");

        return this.subtract(position.getX(), position.getY());
    }

    /**
     * Adds to a position.
     */
    @Override
    public IPosition add(int xSize, int ySize) {
        this.x += xSize;
        this.y += ySize;

        return this;
    }

    /**
     * Subtracts from a position.
     */
    @Override
    public IPosition subtract(int xSize, int ySize) {
        this.x -= xSize;
        this.y -= ySize;

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
            return new HashCodeBuilder(421, 431)
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

            int status = Integer.compare(lhs.getX(), rhs.getX());

            if (status != 0) {
                return status;
            }

            return Integer.compare(lhs.getY(), rhs.getY());
        }
    }

    /**
     * Adds positions.
     */
    public static IPosition add(IPosition leftPosition, IPosition rightPosition) {
        Conditions.validateNotNull(
            leftPosition,
            "The left position.");

        Conditions.validateNotNull(
            rightPosition,
            "The right position.");

        return new Position(
            leftPosition.getX() + rightPosition.getX(),
            leftPosition.getY() + rightPosition.getY());
    }

    /**
     * Subtracts positions.
     */
    public static IPosition subtract(IPosition leftPosition, IPosition rightPosition) {
        Conditions.validateNotNull(
            leftPosition,
            "The left position.");

        Conditions.validateNotNull(
            rightPosition,
            "The right position.");

        return new Position(
            leftPosition.getX() - rightPosition.getX(),
            leftPosition.getY() - rightPosition.getY());
    }

    /**
     * Adds to a position.
     */
    public static IPosition add(IPosition position, int x, int y) {
        Conditions.validateNotNull(
            position,
            "The origin position.");

        return new Position(
            position.getX() + x,
            position.getY() + y);
    }

    /**
     * Subtracts from a position.
     */
    public static IPosition subtract(IPosition position, int x, int y) {
        Conditions.validateNotNull(
            position,
            "The origin position.");

        return new Position(
            position.getX() - x,
            position.getY() - y);
    }
}
