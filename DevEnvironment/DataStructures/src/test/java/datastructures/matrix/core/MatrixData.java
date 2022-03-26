package datastructures.matrix.core;

import datastructures.matrix.interfaces.IMatrixData;
import java.util.List;

/**
 * The MatrixData class implements the data of a matrix.
 */
public final class MatrixData<T extends Comparable<T>> implements IMatrixData<T> {
    private final List<List<T>> data;

    /**
     * The MatrixData constructor.
     */
    public MatrixData(List<List<T>> data) {
        this.data = data;
    }

    /**
     * Gets the actual data of the matrix.
     */
    @Override
    public List<List<T>> getData() {
        return this.data;
    }
}
