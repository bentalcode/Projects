package base.interfaces;

import java.util.List;

/**
 * The ITwoDimensionalList interface defines a generic two-dimensional list.
 * The list can contain rows with different sizes.
 */
public interface ITwoDimensionalList<T extends Comparable<T>> extends
    ISizableCollection,
    IIterable<T>,
    IUnaryComparator<ITwoDimensionalList<T>> {

    /**
     * Gets the number of rows.
     */
    int rowsSize();

    /**
     * Gets the number of columns in a specific row.
     */
    int columnSize(int rowIndex);

    /**
     * Gets an element at a specified position.
     */
    T get(int rowIndex, int columnIndex);

    /**
     * Gets elements of a specified row.
     */
    List<T> getRow(int rowIndex);
}
