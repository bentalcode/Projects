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
     * Subtracts from points.
     */
    IPoint subtract(List<IPoint> points);
}
