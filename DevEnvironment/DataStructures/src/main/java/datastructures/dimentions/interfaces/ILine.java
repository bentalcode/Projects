package datastructures.dimentions.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The ILine interface defines a 2D line.
 */
public interface ILine extends IUnaryComparator<ILine> {
    /**
     * Gets the start point of a line.
     */
    IPoint getStart();

    /**
     * Gets the end point of a line.
     */
    IPoint getEnd();

    /**
     * Gets the slope of a line.
     */
    double getSlope();

    /**
     * Gets the y-intercept of a line.
     */
    double getYIntercept();

    /**
     * Returns whether a line is horizontal.
     */
    boolean horizontal();

    /**
     * Returns whether a line is vertical.
     */
    boolean vertical();

    /**
     * Gets Y value from X.
     */
    double getYFromX(double x);

    /**
     * Checks the intersection of two lines.
     */
    IPoint intersection(ILine line1, ILine line2);
}
