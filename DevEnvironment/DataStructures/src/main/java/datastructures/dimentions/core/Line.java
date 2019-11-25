package datastructures.dimentions.core;

import base.core.AbstractBinaryComparator;
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
            Line.defaultComparator(),
            Point.defaultComparator());
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

        int compareStatus = pointComparator.compareTo(start, end);

        if (compareStatus <= 0) {
            this.start = start;
            this.end = end;
        }
        else {
            this.start = end;
            this.end = start;
        }

        this.lineComparator = lineComparator;
        this.pointComparator = pointComparator;

        if (this.start.getX() == this.end.getX()) {
            this.slope = Double.POSITIVE_INFINITY;
            this.yIntercept = Double.POSITIVE_INFINITY;
        }
        else {
            this.slope = (this.end.getY() - this.start.getY()) / (this.end.getX() - this.start.getX());
            this.yIntercept = this.start.getY() - this.slope * this.start.getX();
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
    public static IBinaryComparator<ILine> defaultComparator() {
        IBinaryComparator<IPoint> pointComparator = Point.defaultComparator();
        return new Comparator(pointComparator);
    }

    /**
     * The Comparator class implements a comparator of a point.
     */
    public static final class Comparator extends AbstractBinaryComparator<ILine> {
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
        @Override
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

    /**
     * Checks the intersection of two lines.
     */
    @Override
    public IPoint intersection(ILine line1, ILine line2) {
        Conditions.validateNotNull(
            line1,
            "The first line.");

        Conditions.validateNotNull(
            line2,
            "The second line.");

        if (line1.vertical() && line2.vertical()) {
            if (line1.getStart().getX() != line2.getStart().getX()) {
                return null;
            }
            else {
                return this.intersectionOfContinuesLines(line1, line2);
            }
        }

        if (line1.getSlope() == line2.getSlope()) {
            if (line1.getYIntercept() != line2.getYIntercept()) {
                return null;
            }
            else {
                return this.intersectionOfContinuesLines(line1, line2);
            }
        }

        double xIntersection;

        if (line1.vertical() || line2.vertical()) {
            xIntersection = line1.vertical() ? line1.getStart().getX() : line2.getStart().getX();
        }
        else {
            xIntersection = line2.getYIntercept() - line1.getYIntercept() / line1.getSlope() - line2.getSlope();
        }

        double yIntersection = line1.vertical() ? line2.getYFromX(xIntersection) : line1.getYFromX(xIntersection);

        Point intersection = new Point(xIntersection, yIntersection);

        if (intersection.between(line1.getStart(), line1.getEnd()) &&
            intersection.between(line2.getStart(), line2.getEnd())) {

            return intersection;
        }
        else {
            return null;
        }
    }

    /**
     * Gets the intersection of continues lines.
     */
    private IPoint intersectionOfContinuesLines(ILine line1, ILine line2) {
        if (line1.getStart().between(line2.getStart(), line2.getEnd())) {
            return line1.getStart();
        }
        else if (line1.getEnd().between(line2.getStart(), line2.getEnd())) {
            return line1.getEnd();
        }
        if (line2.getStart().between(line1.getStart(), line1.getEnd())) {
            return line2.getStart();
        }
        else if (line2.getEnd().between(line1.getStart(), line1.getEnd())) {
            return line2.getEnd();
        }
        else {
            return null;
        }
    }
}
