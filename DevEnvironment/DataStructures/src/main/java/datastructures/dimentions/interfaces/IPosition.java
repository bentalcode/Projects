package datastructures.dimentions.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The Position interface defines a position in 2D.
 */
public interface IPosition extends IUnaryComparator<IPosition> {
    /**
     * Gets the X coordinate.
     */
    int getX();

    /**
     * Gets the Y coordinate.
     */
    int getY();

    /**
     * Sets the X coordinate.
     */
    void setX(int x);

    /**
     * Sets the Y coordinate.
     */
    void setY(int y);

    /**
     * Moves left.
     */
    void moveLeft();

    /**
     * Moves right.
     */
    void moveRight();

    /**
     * Moves up.
     */
    void moveUp();

    /**
     * Moves down.
     */
    void moveDown();

    /**
     * Adds to a position.
     */
    IPosition add(IPosition position);

    /**
     * Subtracts from a position.
     */
    IPosition subtract(IPosition position);

    /**
     * Adds to a position.
     */
    IPosition add(int xSize, int ySize);

    /**
     * Subtracts from a position.
     */
    IPosition subtract(int xSize, int ySize);
}
