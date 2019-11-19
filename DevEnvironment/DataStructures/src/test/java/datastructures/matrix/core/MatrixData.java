package datastructures.matrix.core;

import datastructures.matrix.interfaces.IMatrixData;
import java.util.List;

/**
 * The MatrixData class implements the data of a matrix.
 */
public final class MatrixData<T extends Comparable<T>> implements IMatrixData<T> {
    private final Class<T> classType;
    private final List<List<T>> creationData;
    private final List<List<T>> data;

    /**
     * The MatrixData constructor.
     */
    public MatrixData(
        Class<T> classType,
        List<List<T>> creationData,
        List<List<T>> data) {

        this.classType = classType;
        this.creationData = creationData;
        this.data = data;
    }

    /**
     * Gets the class type.
     */
    @Override
    public Class<T> getClassType() {
        return this.classType;
    }

    /**
     * Gets the creation data of the matrix.
     */
    @Override
    public List<List<T>> getCreationData() {
        return this.creationData;
    }

    /**
     * Gets the actual data of the matrix.
     */
    @Override
    public List<List<T>> getData() {
        return this.data;
    }
}
