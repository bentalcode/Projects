package datastructures.matrix.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.ISizableCollection;
import base.interfaces.IUnaryComparator;
import datastructures.dimentions.interfaces.IPosition;
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
     * Gets the origin.
     */
    T origin();

    /**
     * Gets the x size.
     */
    int xSize();

    /**
     * Gets the y size.
     */
    int ySize();

    /**
     * Gets an element at a specified position.
     */
    T get(int x, int y);

    /**
     * Sets an element at a specified position.
     */
    void set(int x, int y, T element);

    /**
     * Gets an element at a specified position.
     */
    T get(IPosition position);

    /**
     * Sets an element at a specified position.
     */
    void set(IPosition position, T element);

    /**
     * Gets all elements.
     */
    List<List<T>> getData();

    /**
     * Gets an X row.
     */
    List<T> getX(int y);

    /**
     * Sets an X row.
     */
    void setX(int y, List<T> data);

    /**
     * Checks if a specific position is inbound.
     */
    boolean inbound(int xIndex, int yIndex);

    /**
     * Checks if a specific position is inbound.
     */
    boolean inbound(IPosition position);
}
