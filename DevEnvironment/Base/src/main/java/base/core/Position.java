package base.core;

import base.interfaces.IBinaryComparator;
import base.interfaces.IPosition;

/**
 * The Position class implements a 2D position.
 */
public final class Position implements IPosition {
    private int row;
    private int col;
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
    public static IPosition make(int row, int col) {
        return new Position(row, col);
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
    public Position(int row, int col) {
        this(row, col, Position.defaultComparator());
    }

    /**
     * The Position constructor.
     */
    public Position(int row, int col, IBinaryComparator<IPosition> comparator) {
        Conditions.validateNotNull(
            comparator,
            "The comparator of a position.");

        this.row = row;
        this.col = col;
        this.comparator = comparator;
    }

    /**
     * Gets the index of a row.
     */
    @Override
    public int getRow() {
        return this.row;
    }

    /**
     * Gets the index of a column.
     */
    @Override
    public int getColumn() {
        return this.col;
    }

    /**
     * Sets the index of a row.
     */
    @Override
    public void setRow(int row) {
        this.row = row;
    }

    /**
     * Sets the index of a column.
     */
    @Override
    public void setColumn(int col) {
        this.col = col;
    }

    /**
     * Moves left.
     */
    @Override
    public void moveLeft() {
        --this.col;
    }

    /**
     * Moves right.
     */
    @Override
    public void moveRight() {
        ++this.col;
    }

    /**
     * Moves up.
     */
    @Override
    public void moveUp() {
        ++this.row;
    }

    /**
     * Moves down.
     */
    @Override
    public void moveDown() {
        --this.row;
    }

    /**
     * Adds to a position.
     */
    @Override
    public IPosition add(IPosition position) {
        Conditions.validateNotNull(
            position,
            "The position for adding.");

        return this.add(position.getRow(), position.getColumn());
    }

    /**
     * Subtracts from a position.
     */
    @Override
    public IPosition subtract(IPosition position) {
        Conditions.validateNotNull(
            position,
            "The position for subtracting.");

        return this.subtract(position.getRow(), position.getColumn());
    }

    /**
     * Adds to a position.
     */
    @Override
    public IPosition add(int rowSize, int colSize) {
        this.row += rowSize;
        this.col += colSize;

        return this;
    }

    /**
     * Subtracts from a position.
     */
    @Override
    public IPosition subtract(int rowSize, int colSize) {
        this.row -= rowSize;
        this.col -= colSize;

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
            return new HashCodeBuilder(37, 41)
                .withInteger(position.getRow())
                .withInteger(position.getColumn())
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

            return lhs.getRow() == rhs.getRow() && lhs.getColumn() == rhs.getColumn();
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

            if (lhs.getRow() < rhs.getRow()) {
                return -1;
            }

            if (lhs.getRow() > rhs.getRow()) {
                return 1;
            }

            if (lhs.getColumn() < rhs.getColumn()) {
                return -1;
            }

            if (lhs.getColumn() > rhs.getColumn()) {
                return 1;
            }

            return 0;
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
            leftPosition.getRow() + rightPosition.getRow(),
            leftPosition.getColumn() + rightPosition.getColumn());
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
            leftPosition.getRow() - rightPosition.getRow(),
            leftPosition.getColumn() - rightPosition.getColumn());
    }

    /**
     * Adds to a position.
     */
    public static IPosition add(IPosition position, int row, int col) {
        Conditions.validateNotNull(
            position,
            "The origin position.");

        return new Position(
            position.getRow() + row,
            position.getColumn() + col);
    }

    /**
     * Subtracts from a position.
     */
    public static IPosition subtract(IPosition position, int row, int col) {
        Conditions.validateNotNull(
            position,
            "The origin position.");

        return new Position(
            position.getRow() - row,
            position.getColumn() - col);
    }
}
