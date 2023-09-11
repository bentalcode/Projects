package base.interfaces;

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
     * Gets the number of rows.
     */
    int rowsSize();

    /**
     * Gets the number of columns.
     */
    int colsSize();

    /**
     * Gets an element at a specified position.
     */
    T get(int rowIndex, int colIndex);

    /**
     * Sets an element at a specified position.
     */
    void set(int rowIndex, int colIndex, T element);

    /**
     * Gets all elements.
     */
    List<List<T>> getData();

    /**
     * Gets a row.
     */
    List<T> getRow(int rowIndex);

    /**
     * Sets a row.
     */
    void setRow(int rowIndex, List<T> data);

    /**
     * Checks if a specific position is inbound.
     */
    boolean inbound(int rowIndex, int colIndex);
}
