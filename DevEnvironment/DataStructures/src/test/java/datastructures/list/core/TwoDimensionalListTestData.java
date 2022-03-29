package datastructures.list.core;

import base.core.RandomGenerator;
import base.interfaces.IRandomGenerator;
import datastructures.list.interfaces.IList;
import datastructures.list.interfaces.ITwoDimensionalListData;
import datastructures.list.interfaces.ITwoDimensionalListTestData;
import java.util.List;

/**
 * The TwoDimensionalListTestData class implements data of tests for a two-dimensional list.
 */
public final class TwoDimensionalListTestData implements ITwoDimensionalListTestData {
    private static final int RANDOM_COLLECTIONS_SIZE = 10;
    private static final int RANDOM_MIN_ROW_SIZE = 10;
    private static final int RANDOM_MAX_ROW_SIZE = 100;
    private static final int RANDOM_MIN_COLUMN_SIZE = 10;
    private static final int RANDOM_MAX_COLUMN_SIZE = 100;

    private final IRandomGenerator randomGenerator = new RandomGenerator();

    /**
     * The TwoDimensionalListTestData constructor.
     */
    public TwoDimensionalListTestData() {
    }

    /**
     * Gets data of the tests of a two-dimensional list.
     */
    @Override
    public List<ITwoDimensionalListData<Integer>> getData() {
        List<ITwoDimensionalListData<Integer>> data = new java.util.ArrayList<>();

        data.add(this.getTwoDimensionalListData1());
        data.add(this.getTwoDimensionalListData2());
        data.add(this.getTwoDimensionalListData3());

        for (int i = 0; i < RANDOM_COLLECTIONS_SIZE; ++i) {
            data.add(this.getRandomTwoDimensionalListData(
                RANDOM_MIN_ROW_SIZE,
                RANDOM_MAX_ROW_SIZE,
                RANDOM_MIN_COLUMN_SIZE,
                RANDOM_MAX_COLUMN_SIZE));
        }

        return data;
    }

    /**
     * Gets the data of a two-dimensional list1.
     */
    private ITwoDimensionalListData<Integer> getTwoDimensionalListData1() {
        IList<IList<Integer>> data = this.createTwoDimensionalList(1, 2);
        return new TwoDimensionalListData<>(data);
    }

    /**
     * Gets the data of a two-dimensional list2.
     */
    private ITwoDimensionalListData<Integer> getTwoDimensionalListData2() {
        IList<IList<Integer>> data = this.createTwoDimensionalList(10, 20);
        return new TwoDimensionalListData<>(data);
    }

    /**
     * Gets the data of a two-dimensional list3.
     */
    private ITwoDimensionalListData<Integer> getTwoDimensionalListData3() {
        IList<IList<Integer>> data = this.createTwoDimensionalList(100, 200);
        return new TwoDimensionalListData<>(data);
    }

    /**
     * Gets the random data of a two-dimensional list..
     */
    private ITwoDimensionalListData<Integer> getRandomTwoDimensionalListData(
        int fromRowSize,
        int toRowSize,
        int fromColumnSize,
        int toColumnSize) {

        int rowsSize = this.randomGenerator.nextInteger(fromRowSize, toRowSize);
        int columnSize = this.randomGenerator.nextInteger(fromColumnSize, toColumnSize);

        IList<IList<Integer>> data = this.createTwoDimensionalList(rowsSize, columnSize);

        return new TwoDimensionalListData<>(data);
    }

    /**
     * Creates data of a two-dimensional list.
     */
    private IList<IList<Integer>> createTwoDimensionalList(int rows, int columns)
    {
        IList<IList<Integer>> data = new datastructures.list.core.ArrayList<>(ArrayList.class);

        int value = 0;
        for (int row = 0; row < rows; ++row) {
            IList<Integer> rowData = new datastructures.list.core.ArrayList<>(Integer.class);

            for (int column = 0; column < columns; ++column) {
                ++value;

                rowData.add(value);
            }

            data.add(rowData);
        }

        return data;
    }
}
