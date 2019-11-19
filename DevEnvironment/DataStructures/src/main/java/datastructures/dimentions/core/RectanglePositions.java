package datastructures.dimentions.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import datastructures.dimentions.interfaces.IPosition;
import datastructures.dimentions.interfaces.IRectanglePositions;

/**
 * The RectanglePositions class implements a rectangle of positions.
 */
public final class RectanglePositions implements IRectanglePositions {
    private final IPosition upperLeftPosition;
    private final IPosition upperRightPosition;
    private final IPosition bottomLeftPosition;
    private final IPosition bottomRightPosition;
    private final IBinaryComparator<IRectanglePositions> comparator;
    private final int hashCode;

    /**
     * Creates a new rectangle positions.
     */
    public static IRectanglePositions create(
        IPosition upperLeftPosition,
        IPosition upperRightPosition,
        IPosition bottomLeftPosition,
        IPosition bottomRightPosition) {

        return new RectanglePositions(
            upperLeftPosition,
            upperRightPosition,
            bottomLeftPosition,
            bottomRightPosition,
            RectanglePositions.defaultComparator());
    }

    /**
     * Creates a new rectangle positions from a positions and x and y.
     */
    public static IRectanglePositions create(
        IPosition bottomLeftPosition,
        int xSize,
        int ySize) {

        IPosition upperLeftPosition = Position.add(bottomLeftPosition, 0, ySize - 1);
        IPosition upperRightPosition = Position.add(bottomLeftPosition, xSize - 1, ySize - 1);
        IPosition bottomRightPosition = Position.add(bottomLeftPosition, xSize - 1, 0);

        return new RectanglePositions(
            upperLeftPosition,
            upperRightPosition,
            bottomLeftPosition,
            bottomRightPosition);
    }

    /**
     * The RectanglePositions constructor.
     */
    public RectanglePositions(
        IPosition upperLeftPosition,
        IPosition upperRightPosition,
        IPosition bottomLeftPosition,
        IPosition bottomRightPosition) {

        this(
            upperLeftPosition,
            upperRightPosition,
            bottomLeftPosition,
            bottomRightPosition,
            RectanglePositions.defaultComparator());
    }

    /**
     * The RectanglePositions constructor.
     */
    public RectanglePositions(
        IPosition upperLeftPosition,
        IPosition upperRightPosition,
        IPosition bottomLeftPosition,
        IPosition bottomRightPosition,
        IBinaryComparator<IRectanglePositions> comparator) {

        Conditions.validateNotNull(
            upperLeftPosition,
            "The upper left position.");

        Conditions.validateNotNull(
            upperRightPosition,
            "The upper right position.");

        Conditions.validateNotNull(
            bottomLeftPosition,
            "The bottom left position.");

        Conditions.validateNotNull(
            bottomRightPosition,
            "The bottom right position.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a rectangle of positions.");

        this.upperLeftPosition = upperLeftPosition;
        this.upperRightPosition = upperRightPosition;
        this.bottomLeftPosition = bottomLeftPosition;
        this.bottomRightPosition = bottomRightPosition;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * Gets the upper left position.
     */
    @Override
    public IPosition getUpperLeftPosition() {
        return this.upperLeftPosition;
    }

    /**
     * Gets the upper right position.
     */
    @Override
    public IPosition getUpperRightPosition() {
        return this.upperRightPosition;
    }

    /**
     * Gets the bottom left position.
     */
    @Override
    public IPosition getBottomLeftPosition() {
        return this.bottomLeftPosition;
    }

    /**
     * Gets the bottom right position.
     */
    @Override
    public IPosition getBottomRightPosition() {
        return this.bottomRightPosition;
    }

    /**
     * Gets string representation of this instance.
     */
    @Override
    public String toString() {
        return
            "{" +
            this.upperLeftPosition +
            ", " +
            this.upperRightPosition +
            ", " +
            this.bottomLeftPosition +
            ", " +
            this.bottomRightPosition +
            "}";
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
    public boolean isEqual(IRectanglePositions other) {
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
    public int compareTo(IRectanglePositions other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<IRectanglePositions> defaultComparator() {
        IBinaryComparator<IPosition> positionComparator = Position.defaultComparator();
        return new Comparator(positionComparator);
    }

    /**
     * The Comparator class implements a comparator of a rectangle positions.
     */
    public static final class Comparator extends AbstractBinaryComparator<IRectanglePositions> {
        private final IBinaryComparator<IPosition> positionComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<IPosition> positionComparator) {
            Conditions.validateNotNull(
                positionComparator,
                "The comparator of a position.");

            this.positionComparator = positionComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IRectanglePositions obj) {
            return new HashCodeBuilder(3, 5)
                .withObject(obj.getUpperLeftPosition(), this.positionComparator)
                .withObject(obj.getUpperRightPosition(), this.positionComparator)
                .withObject(obj.getBottomLeftPosition(), this.positionComparator)
                .withObject(obj.getBottomRightPosition(), this.positionComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IRectanglePositions lhs, IRectanglePositions rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withObject(lhs.getUpperLeftPosition(), rhs.getUpperLeftPosition(), this.positionComparator)
                .withObject(lhs.getUpperRightPosition(), rhs.getUpperRightPosition(), this.positionComparator)
                .withObject(lhs.getBottomLeftPosition(), rhs.getBottomLeftPosition(), this.positionComparator)
                .withObject(lhs.getBottomRightPosition(), rhs.getBottomRightPosition(), this.positionComparator)
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
        public int compareTo(IRectanglePositions lhs, IRectanglePositions rhs) {
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
                .withObject(lhs.getUpperLeftPosition(), rhs.getUpperLeftPosition(), this.positionComparator)
                .withObject(lhs.getUpperRightPosition(), rhs.getUpperRightPosition(), this.positionComparator)
                .withObject(lhs.getBottomLeftPosition(), rhs.getBottomLeftPosition(), this.positionComparator)
                .withObject(lhs.getBottomRightPosition(), rhs.getBottomRightPosition(), this.positionComparator)
                .build();
        }
    }
}
