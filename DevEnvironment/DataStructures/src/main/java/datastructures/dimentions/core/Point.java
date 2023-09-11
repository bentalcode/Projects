package datastructures.dimentions.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.Conditions;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import datastructures.dimentions.interfaces.IPoint;
import java.util.List;

/**
 * The Point class implements a 2D point.
 */
public final class Point implements IPoint {
    private double x;
    private double y;
    private final IBinaryComparator<IPoint> comparator;

    /**
     * The Point constructor.
     */
    public Point() {
        this(0.0, 0.0, Point.defaultComparator());
    }

    /**
     * The Point constructor.
     */
    public Point(double x, double y) {
        this(x, y, Point.defaultComparator());
    }

    /**
     * The Point constructor.
     */
    public Point(double x, double y, IBinaryComparator<IPoint> comparator) {
        Conditions.validateNotNull(
            comparator,
            "The comparator of a point.");

        this.x = x;
        this.y = y;
        this.comparator = comparator;
    }

    /**
     * Gets the X coordinate.
     */
    @Override
    public double getX() {
        return this.x;
    }

    /**
     * Gets the Y coordinate.
     */
    @Override
    public double getY() {
        return this.y;
    }

    /**
     * Adds a new point.
     */
    @Override
    public IPoint add(IPoint point) {
        Conditions.validateNotNull(
            point,
            "The point for adding.");

        this.x += point.getX();
        this.y += point.getY();

        return this;
    }

    /**
     * Subtracts from a point.
     */
    @Override
    public IPoint subtract(IPoint point) {
        Conditions.validateNotNull(
            point,
            "The point for subtracting.");

        this.x -= point.getX();
        this.y -= point.getY();

        return this;
    }

    /**
     * Adds new points.
     */
    @Override
    public IPoint add(List<IPoint> points) {
        Conditions.validateNotNull(
            points,
            "The list of point for adding.");

        for (IPoint point : points) {
            this.x += point.getX();
            this.y += point.getY();
        }

        return this;
    }

    /**
     * Subtracts points.
     */
    public IPoint subtract(List<IPoint> points) {
        Conditions.validateNotNull(
            points,
            "The list of point for subtracting.");

        for (IPoint point : points) {
            this.x -= point.getX();
            this.y -= point.getY();
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
    public boolean isEqual(IPoint other) {
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
    public int compareTo(IPoint other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<IPoint> defaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of a point.
     */
    public static final class Comparator extends AbstractBinaryComparator<IPoint> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IPoint point) {
            return new HashCodeBuilder(409, 419)
                .withDouble(point.getX())
                .withDouble(point.getY())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IPoint lhs, IPoint rhs) {
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
        public int compareTo(IPoint lhs, IPoint rhs) {
            if (lhs == null && rhs == null) {
                return 0;
            }

            if (lhs == null) {
                return -1;
            }

            if (rhs == null) {
                return 1;
            }

            int status = Double.compare(lhs.getX(), rhs.getX());

            if (status != 0) {
                return status;
            }

            return Double.compare(lhs.getY(), rhs.getY());
        }
    }

    /**
     * Checks whether this point is before the specified one.
     */
    @Override
    public boolean isBefore(IPoint point) {
        Conditions.validateNotNull(
            point,
            "The point.");

        return this.getX() < point.getX();
    }

    /**
     * Checks whether this point is after the specified one.
     */
    @Override
    public boolean isAfter(IPoint point) {
        Conditions.validateNotNull(
            point,
            "The point.");

        return this.getX() > point.getX();
    }

    /**
     * Checks whether this point is above the specified one.
     */
    @Override
    public boolean isAbove(IPoint point) {
        Conditions.validateNotNull(
            point,
            "The point.");

        return this.getY() > point.getY();
    }

    /**
     * Checks whether this point is bellow the specified one.
     */
    @Override
    public boolean isBelow(IPoint point) {
        Conditions.validateNotNull(
            point,
            "The point.");

        return this.getY() < point.getY();
    }

    /**
     * Checks whether a point is between two points.
     */
    @Override
    public boolean between(IPoint point1, IPoint point2) {
        Conditions.validateNotNull(
            point1,
            "The first point.");

        Conditions.validateNotNull(
            point2,
            "The second point.");

        IPoint bottomLeftPoint;
        IPoint upperRightPoint;

        int compareStatus = this.comparator.compareTo(point1, point2);

        if (compareStatus <= 0) {
            bottomLeftPoint = point1;
            upperRightPoint = point2;
        }
        else {
            bottomLeftPoint = point2;
            upperRightPoint = point1;
        }
        return
            this.getX() >= bottomLeftPoint.getX() && this.getX() <= upperRightPoint.getX() ||
            this.getY() >= bottomLeftPoint.getY() && this.getY() <= upperRightPoint.getY();
    }
}
