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
    private final Boolean isHorizontalOrVertical;
    private final IBinaryComparator<ILine> lineComparator;

    /**
     * The Line constructor.
     */
    public Line(IPoint point1, IPoint point2) {
        this(
            point1,
            point2,
            Line.defaultComparator(),
            Point.defaultComparator());
    }

    /**
     * The Line constructor.
     */
    public Line(
        IPoint point1,
        IPoint point2,
        IBinaryComparator<ILine> lineComparator,
        IBinaryComparator<IPoint> pointComparator) {

        Conditions.validateNotNull(
            point1,
            "The first point of a line.");

        Conditions.validateNotNull(
            point2,
            "The second point of a line.");

        Conditions.validateNotNull(
            lineComparator,
            "The comparator of a line.");

        Conditions.validateNotNull(
            pointComparator,
            "The comparator of a point.");

        int compareStatus = pointComparator.compareTo(point1, point2);

        if (compareStatus <= 0) {
            this.start = point1;
            this.end = point2;
        }
        else {
            this.start = point2;
            this.end = point1;
        }

        this.lineComparator = lineComparator;

        if (this.start.getY() == this.end.getY()) {
            this.slope = 0;
            this.yIntercept = this.start.getY();
            this.isHorizontalOrVertical = Boolean.TRUE;
        }
        else if (this.start.getX() == this.end.getX()) {
            this.slope = Double.POSITIVE_INFINITY;
            this.yIntercept = Double.POSITIVE_INFINITY;
            this.isHorizontalOrVertical = Boolean.FALSE;
        }
        else {
            this.slope = (this.end.getY() - this.start.getY()) / (this.end.getX() - this.start.getX());
            this.yIntercept = this.start.getY() - this.slope * this.start.getX();
            this.isHorizontalOrVertical = null;
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
    public boolean horizontal() {
        return this.isHorizontalOrVertical != null && this.isHorizontalOrVertical;
    }

    /**
     * Returns whether a line is vertical.
     */
    @Override
    public boolean vertical() {
        return this.isHorizontalOrVertical != null && !this.isHorizontalOrVertical;
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
            return new HashCodeBuilder(397, 401)
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

            int status = this.pointComparator.compareTo(lhs.getStart() , rhs.getStart());

            if (status != 0) {
                return status;
            }

            return this.pointComparator.compareTo(lhs.getEnd() , rhs.getEnd());
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

        if (line1.horizontal() && line2.horizontal()) {
            if (line1.getStart().getY() != line2.getStart().getY()) {
                return null;
            }
            else {
                return this.intersectionOfContinuesLines(line1, line2);
            }
        }
        else if (line1.vertical() && line2.vertical()) {
            if (line1.getStart().getX() != line2.getStart().getX()) {
                return null;
            }
            else {
                return this.intersectionOfContinuesLines(line1, line2);
            }
        } else if (line1.getSlope() == line2.getSlope()) {
            if (line1.getYIntercept() != line2.getYIntercept()) {
                return null;
            }
            else {
                return this.intersectionOfContinuesLines(line1, line2);
            }
        }

        assert(!(line1.horizontal() && line2.horizontal()));
        assert(!(line1.vertical() && line2.vertical()));

        double xIntersection;
        double yIntersection;

        if (line1.vertical()) {
            xIntersection = line1.getStart().getX();
            yIntersection = line2.getYFromX(xIntersection);
        }
        else if (line2.vertical()) {
            xIntersection = line2.getStart().getX();
            yIntersection = line1.getYFromX(xIntersection);
        }
        else {
            xIntersection = line2.getYIntercept() - line1.getYIntercept() / line1.getSlope() - line2.getSlope();
            yIntersection = line1.getYFromX(xIntersection);
        }

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
