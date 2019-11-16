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
     * Adds a new position.
     */
    IPosition add(IPosition position);

    /**
     * Subtracts from a position.
     */
    IPosition subtract(IPosition position);

    /**
     * Adds new positions.
     */
    IPosition add(List<IPosition> positions);

    /**
     * Subtracts positions.
     */
    IPosition subtract(List<IPosition> positions);
}
