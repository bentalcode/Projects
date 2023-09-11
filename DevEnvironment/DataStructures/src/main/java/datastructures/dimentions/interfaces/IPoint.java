package datastructures.dimentions.interfaces;

import base.interfaces.IUnaryComparator;
import java.util.List;

/**
 * The IPoint interface defines a 2D point.
 */
public interface IPoint extends IUnaryComparator<IPoint> {
    /**
     * Gets the X coordinate.
     */
    double getX();

    /**
     * Gets the Y coordinate.
     */
    double getY();

    /**
     * Adds a new point.
     */
    IPoint add(IPoint point);

    /**
     * Subtracts from a point.
     */
    IPoint subtract(IPoint point);

    /**
     * Adds new points.
     */
    IPoint add(List<IPoint> points);

    /**
     * Subtracts points.
     */
    IPoint subtract(List<IPoint> points);

    /**
     * Checks whether this point is before the specified one.
     */
    boolean isBefore(IPoint point);

    /**
     * Checks whether this point is after the specified one.
     */
    boolean isAfter(IPoint point);

    /**
     * Checks whether this point is above the specified one.
     */
    boolean isAbove(IPoint point);

    /**
     * Checks whether this point is bellow the specified one.
     */
    boolean isBelow(IPoint point);

    /**
     * Checks whether a point is between two points.
     */
    boolean between(IPoint point1, IPoint point2);
}
