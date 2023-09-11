package datastructures.dimentions.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The IDirection interface defines a 2D direction.
 */
public interface IDirection extends IUnaryComparator<IDirection> {
    /**
     * Gets an angle.
     */
    double getAngle();
}
