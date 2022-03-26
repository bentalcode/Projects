package datastructures.matrix.interfaces;

import java.util.List;

/**
 * The IMatrixData interface defines the data of a matrix.
 */
public interface IMatrixData<T extends Comparable<T>> {
    /**
     * Gets the actual data of the stack.
     */
    List<List<T>> getData();
}
