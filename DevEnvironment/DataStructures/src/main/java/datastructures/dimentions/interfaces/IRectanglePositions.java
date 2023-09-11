package datastructures.dimentions.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The IRectanglePositions interface defines a rectangle of positions.
 * In Euclidean plane geometry, a rectangle is a quadrilateral with four right angles.
 * A rectangle is a special case of both parallelogram and trapezoid.
 */
public interface IRectanglePositions extends IUnaryComparator<IRectanglePositions> {
    /**
     * Gets the upper left position.
     */
    IPosition getUpperLeftPosition();

    /**
     * Gets the upper right position.
     */
    IPosition getUpperRightPosition();

    /**
     * Gets the bottom left position.
     */
    IPosition getBottomLeftPosition();

    /**
     * Gets the bottom right position.
     */
    IPosition getBottomRightPosition();
}
