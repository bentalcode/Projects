package datastructures.dimentions.interfaces;

import base.interfaces.IUnaryComparator;

import java.util.List;

/**
 * The Position interface defines a 2D point.
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
     * Moves up.
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
