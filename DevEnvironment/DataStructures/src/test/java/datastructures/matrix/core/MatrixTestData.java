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
    private static int RandomCollectionsSize = 10;
    private static int RandomMinRowSize = 10;
    private static int RandomMaxRowSize = 100;
    private static int RandomMinColumnSize = 10;
    private static int RandomMaxColumnSize = 100;

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

        for (int i = 0; i < RandomCollectionsSize; ++i) {
            data.add(this.getRandomMatrixData(
                RandomMinRowSize,
                RandomMaxRowSize,
                RandomMinColumnSize,
                RandomMaxColumnSize));
        }

        return data;
    }

    /**
     * Gets the data of a matrix1.
     */
    private IMatrixData<Integer> getMatrixData1() {
        List<List<Integer>> creationData = this.createMatrix(1, 1);
        List<List<Integer>> data = creationData;
        return new MatrixData<>(Integer.class, creationData, data);
    }

    /**
     * Gets the data of a matrix2.
     */
    private IMatrixData<Integer> getMatrixData2() {
        List<List<Integer>> creationData = this.createMatrix(1, 2);
        List<List<Integer>> data = creationData;
        return new MatrixData<>(Integer.class, creationData, data);
    }

    /**
     * Gets the data of a matrix3.
     */
    private IMatrixData<Integer> getMatrixData3() {
        List<List<Integer>> creationData = this.createMatrix(10, 20);
        List<List<Integer>> data = creationData;
        return new MatrixData<>(Integer.class, creationData, data);
    }

    /**
     * Gets the data of a matrix4.
     */
    private IMatrixData<Integer> getMatrixData4() {
        List<List<Integer>> creationData = this.createMatrix(100, 200);
        List<List<Integer>> data = creationData;
        return new MatrixData<>(Integer.class, creationData, data);
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

        List<List<Integer>> creationData = this.createMatrix(rowsSize, columnSize);
        List<List<Integer>> data = creationData;

        return new MatrixData<>(Integer.class, creationData, data);
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
