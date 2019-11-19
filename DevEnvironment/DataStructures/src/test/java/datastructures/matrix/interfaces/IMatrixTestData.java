package datastructures.matrix.interfaces;

import java.util.List;

/**
 * The IMatrixTestData interface defines the data of the tests of a matrix.
 */
public interface IMatrixTestData {
    /**
     * Gets data of the tests of a matrix.
     */
    List<IMatrixData<Integer>> getData();
}
