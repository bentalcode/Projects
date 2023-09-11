package datastructures.matrix.core;

import base.core.RandomGenerator;
import base.interfaces.IRandomGenerator;
import datastructures.matrix.interfaces.IMatrixData;
import datastructures.matrix.interfaces.IMatrixTestData;
import java.util.ArrayList;
import java.util.List;

/**
 * The MatrixTestData class implements data of tests for a matrix.
 */
public final class MatrixTestData implements IMatrixTestData {
    private static final int RANDOM_COLLECTIONS_SIZE = 10;
    private static final int RANDOM_MIN_ROW_SIZE = 10;
    private static final int RANDOM_MAX_ROW_SIZE = 100;
    private static final int RANDOM_MIN_COLUMN_SIZE = 10;
    private static final int RANDOM_MAX_COLUMN_SIZE = 100;

    private final IRandomGenerator randomGenerator = new RandomGenerator();

    /**
     * The MatrixTestData constructor.
     */
    public MatrixTestData() {
    }

    /**
     * Gets data of the tests of a matrix.
     */
    @Override
    public List<IMatrixData<Integer>> getData() {
        List<IMatrixData<Integer>> data = new ArrayList<>();
        data.add(this.getMatrixData1());
        data.add(this.getMatrixData2());
        data.add(this.getMatrixData3());
        data.add(this.getMatrixData4());

        for (int i = 0; i < RANDOM_COLLECTIONS_SIZE; ++i) {
            data.add(
                this.getRandomMatrixData(
                    RANDOM_MIN_ROW_SIZE,
                    RANDOM_MAX_ROW_SIZE,
                    RANDOM_MIN_COLUMN_SIZE,
                    RANDOM_MAX_COLUMN_SIZE));
        }

        return data;
    }

    /**
     * Gets the data of a matrix1.
     */
    private IMatrixData<Integer> getMatrixData1() {
        List<List<Integer>> data = this.createMatrix(1, 1);
        return new MatrixData<>(data);
    }

    /**
     * Gets the data of a matrix2.
     */
    private IMatrixData<Integer> getMatrixData2() {
        List<List<Integer>> data = this.createMatrix(1, 2);
        return new MatrixData<>(data);
    }

    /**
     * Gets the data of a matrix3.
     */
    private IMatrixData<Integer> getMatrixData3() {
        List<List<Integer>> data = this.createMatrix(10, 20);
        return new MatrixData<>(data);
    }

    /**
     * Gets the data of a matrix4.
     */
    private IMatrixData<Integer> getMatrixData4() {
        List<List<Integer>> data = this.createMatrix(100, 200);
        return new MatrixData<>(data);
    }

    /**
     * Gets the random data of a matrix.
     */
    private IMatrixData<Integer> getRandomMatrixData(
        int fromRowSize,
        int toRowSize,
        int fromColumnSize,
        int toColumnSize) {

        int rowsSize = this.randomGenerator.nextInteger(fromRowSize, toRowSize);
        int columnSize = this.randomGenerator.nextInteger(fromColumnSize, toColumnSize);

        List<List<Integer>> data = this.createMatrix(rowsSize, columnSize);

        return new MatrixData<>(data);
    }

    /**
     * Creates data of a matrix.
     */
    private List<List<Integer>> createMatrix(int rows, int columns)
    {
        List<List<Integer>> data = new ArrayList<>();

        int value = 0;
        for (int row = 0; row < rows; ++row) {
            List<Integer> rowData = new ArrayList<>();

            for (int column = 0; column < columns; ++column) {
                ++value;

                rowData.add(value);
            }

            data.add(rowData);
        }

        return data;
    }
}
