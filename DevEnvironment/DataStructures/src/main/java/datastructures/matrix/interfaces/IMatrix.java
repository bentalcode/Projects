package datastructures.matrix.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.ISizableCollection;
import base.interfaces.IUnaryComparator;
import datastructures.dimentions.interfaces.IPosition;
import datastructures.dimentions.interfaces.IRectanglePositions;
import java.util.List;

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
     * Gets a frame of the matrix.
     */
    IRectanglePositions getFrame();

    /**
     * Gets a sub-matrix of the matrix.
     */
    IMatrix getSubMatrix(IPosition bottomLeftPosition, IPosition upperRightPosition);

    /**
     * Gets a sub-matrix.
     */
    IMatrix getSubMatrix(IPosition bottomLeftPosition, int xSize, int ySize);

    /**
     * Checks whether the matrix contains a specific position.
     */
    boolean contains(IPosition position);

    /**
     * Gets the data of the matrix.
     */
    List<List<T>> getData();

    /**
     * Converts the matrix to a native array.
     */
    T[][] toArray();
}
