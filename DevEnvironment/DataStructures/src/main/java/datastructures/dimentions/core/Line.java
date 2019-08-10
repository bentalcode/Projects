package datastructures.dimentions.core;

import base.core.Casting;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import datastructures.dimentions.interfaces.ILine;
import datastructures.dimentions.interfaces.IPoint;

/**
 * The Line class implements a 2D line.
 */
public final class Line implements ILine {
    private final IPoint start;
    private final IPoint end;
    private final double slope;
    private final double yIntercept;

    private final IBinaryComparator<ILine> lineComparator;
    private final IBinaryComparator<IPoint> pointComparator;

    /**
     * The Line constructor.
     */
    public Line(IPoint start, IPoint end) {
        this(
            start,
            end,
            Line.DefaultComparator(),
            Point.DefaultComparator());
    }

    /**
     * The Line constructor.
     */
    public Line(
        IPoint start,
        IPoint end,
        IBinaryComparator<ILine> lineComparator,
        IBinaryComparator<IPoint> pointComparator) {

        Conditions.validateNotNull(
            start,
            "The start point of a line.");

        Conditions.validateNotNull(
            end,
            "The end point of a line.");

        Conditions.validateNotNull(
            lineComparator,
            "The comparator of a line.");

        Conditions.validateNotNull(
            pointComparator,
            "The comparator of a point.");

        this.start = start;
        this.end = end;
        this.lineComparator = lineComparator;
        this.pointComparator = pointComparator;

        if (start.isEqual(end)) {
            this.slope = Double.POSITIVE_INFINITY;
            this.yIntercept = Double.POSITIVE_INFINITY;
        }
        else {
            this.slope = (end.getY() - start.getY()) / (end.getX() - start.getX());
            this.yIntercept = start.getY() - this.slope * start.getX();
        }
    }

    /**
     * Gets the start point of a line.
     */
    @Override
    public IPoint getStart() {
        return this.start;
    }

    /**
     * Gets the end point of a line.
     */
    @Override
    public IPoint getEnd() {
        return this.end;
    }

    /**
     * Gets the slope of a line.
     */
    @Override
    public double getSlope() {
        return this.slope;
    }

    /**
     * Gets the y-intercept of a line.
     */
    @Override
    public double getYIntercept() {
        return this.yIntercept;
    }

    /**
     * Returns whether a line is vertical.
     */
    @Override
    public boolean vertical() {
        return this.slope == Double.POSITIVE_INFINITY;
    }

    /**
     * Gets Y value from X.
     */
    @Override
    public double getYFromX(double x) {
        if (this.vertical()) {
            return Double.POSITIVE_INFINITY;
        }

        return this.slope * x + this.yIntercept;
    }

    /**
     * Gets the hash code.
     */
    @Override
    public int hashCode() {
        return this.lineComparator.getHashCode(this);
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
    public boolean isEqual(ILine other) {
        return this.lineComparator.isEqual(this, other);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(ILine other) {
        return this.lineComparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<ILine> DefaultComparator() {
        IBinaryComparator<IPoint> pointComparator = Point.DefaultComparator();
        return new Comparator(pointComparator);
    }

    /**
     * The Comparator class implements a comparator of a point.
     */
    public static final class Comparator implements IBinaryComparator<ILine> {
        private final IBinaryComparator<IPoint> pointComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<IPoint> pointComparator) {
            Conditions.validateNotNull(
                pointComparator,
                "The comparator of a point.");

            this.pointComparator = pointComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ILine line) {
            return new HashCodeBuilder(3, 5)
                .withObject(line.getStart(), this.pointComparator)
                .withObject(line.getEnd(), this.pointComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        public boolean isEqual(ILine lhs, ILine rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withObject(lhs.getStart(), rhs.getStart(), this.pointComparator)
                .withObject(lhs.getEnd(), rhs.getEnd(), this.pointComparator)
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
        public int compareTo(ILine lhs, ILine rhs) {
            if (lhs == null && rhs == null) {
                return 0;
            }

            if (lhs == null) {
                return -1;
            }

            if (rhs == null) {
                return 1;
            }

            if (this.pointComparator.compareTo(lhs.getStart() , rhs.getStart()) < 0) {
                return -1;
            }

            if (this.pointComparator.compareTo(lhs.getStart() , rhs.getStart()) > 0) {
                return 1;
            }

            if (this.pointComparator.compareTo(lhs.getEnd() , rhs.getEnd()) < 0) {
                return -1;
            }

            if (this.pointComparator.compareTo(lhs.getEnd() , rhs.getEnd()) > 0) {
                return 1;
            }

            return 0;
        }
    }
}
