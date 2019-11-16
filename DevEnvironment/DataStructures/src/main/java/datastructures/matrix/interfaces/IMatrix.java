package datastructures.matrix.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.ISizableCollection;
import base.interfaces.IUnaryComparator;
import datastructures.dimentions.interfaces.IPosition;

/**
 * The IMatrix interface defines a matrix.
 */
public interface IMatrix<T extends Comparable<T>> extends
    ISizableCollection,
    IIterable<T>,
    IReverseIterable<T>,
    IUnaryComparator<IMatrix<T>> {

    /**
     * Gets the x size.
     */
    int xSize();

    /**
     * Gets the y size.
     */
    int ySize();

    /**
     * Gets a sub-matrix.
     */
    IMatrix getSubMatrix(IPosition bottomLeftPosition, IPosition upperRightPosition);

    /**
     * Gets a sub-matrix.
     */
    IMatrix getSubMatrix(IPosition bottomLeftPosition, int xSize, int ySize);

    /**
     * Converts the list to a native array.
     */
    T[][] toArray();
}
