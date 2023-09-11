package datastructures.dimentions.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The IRectangle interface defines a rectangle.
 * In Euclidean plane geometry, a rectangle is a quadrilateral with four right angles.
 * A rectangle is a special case of both parallelogram and trapezoid.
 */
public interface IRectangle extends IUnaryComparator<IRectangle> {
    /**
     * Gets the upper left point.
     */
    IPoint getUpperLeftPoint();

    /**
     * Gets the upper right point.
     */
    IPoint getUpperRightPoint();

    /**
     * Gets the bottom left point.
     */
    IPoint getBottomLeftPoint();

    /**
     * Gets the bottom right point.
     */
    IPoint getBottomRightPoint();
}
