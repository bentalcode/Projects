package datastructures.dimentions.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.Conditions;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import datastructures.dimentions.interfaces.IDirection;

/**
 * The Direction class implements a 2d direction.
 */
public final class Direction implements IDirection {
    private static final double MIN_ANGLE = 0.0;
    private static final double MAX_ANGLE = 360.0;

    private final double angle; // 0-360
    private final IBinaryComparator<IDirection> comparator;
    private final int hashCode;

    /**
     * The Direction constructor.
     */
    public Direction() {
        this(0, Direction.defaultComparator());
    }

    /**
     * The Direction constructor.
     */
    public Direction(double angle) {
        this(angle, Direction.defaultComparator());
    }

    /**
     * The Direction constructor.
     */
    public Direction(double angle, IBinaryComparator<IDirection> comparator) {
        Conditions.validate(
            angle >= Direction.MIN_ANGLE && angle <= Direction.MAX_ANGLE,
            "The angle is out of allowed range: 0-360.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a direction.");

        this.angle = angle;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * Gets the angle.
     */
    @Override
    public double getAngle() {
        return this.angle;
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
    public boolean isEqual(IDirection other) {
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
    public int compareTo(IDirection other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<IDirection> defaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of a direction.
     */
    public static final class Comparator extends AbstractBinaryComparator<IDirection> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IDirection direction) {
            return new HashCodeBuilder(383, 389)
                .withDouble(direction.getAngle())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IDirection lhs, IDirection rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return lhs.getAngle() == rhs.getAngle();
        }

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        @Override
        public int compareTo(IDirection lhs, IDirection rhs) {
            if (lhs == null && rhs == null) {
                return 0;
            }

            if (lhs == null) {
                return -1;
            }

            if (rhs == null) {
                return 1;
            }

            return Double.compare(lhs.getAngle(), rhs.getAngle());
        }
    }
}
