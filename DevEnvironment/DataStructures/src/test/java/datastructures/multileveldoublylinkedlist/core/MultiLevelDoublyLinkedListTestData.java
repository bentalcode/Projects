package datastructures.multileveldoublylinkedlist.core;

import base.core.ArrayLists;
import base.core.Matrix;
import base.core.Triple;
import base.interfaces.IMatrix;
import base.interfaces.ITriple;
import datastructures.multileveldoublylinkedlist.interfaces.IMultiLevelDoublyLinkedListData;
import datastructures.multileveldoublylinkedlist.interfaces.IMultiLevelDoublyLinkedListNode;
import datastructures.multileveldoublylinkedlist.interfaces.IMultiLevelDoublyLinkedListTestData;
import java.util.ArrayList;
import java.util.List;

/**
 * The MultiLevelDoublyLinkedListTestData class implements data of tests of a multi-level doubly linked list.
 */
public final class MultiLevelDoublyLinkedListTestData implements IMultiLevelDoublyLinkedListTestData {
    /**
     * The MultiLevelDoublyLinkedListTestData constructor.
     */
    public MultiLevelDoublyLinkedListTestData() {
    }

    /**
     * Gets the data of a multi-level doubly linked lists.
     */
    @Override
    public List<IMultiLevelDoublyLinkedListData<Integer>> getData() {
        List<IMultiLevelDoublyLinkedListData<Integer>> data = new ArrayList<>();

        //data.add(this.getData1());
        data.add(this.getData2());

        return data;
    }

    /**
     * Gets the data of multi-level doubly linked list1.
     */
    private IMultiLevelDoublyLinkedListData<Integer> getData1() {
        ITriple<IMatrix<Integer>, boolean[][], boolean[][]> creationData = this.createCreationData1();
        List<IMultiLevelDoublyLinkedListNode<Integer>> data = this.getData(creationData.first());
        List<Integer> values = this.getValues(creationData.first());
        List<List<Integer>> levels = this.getLevels(creationData.first());
        List<List<Integer>> verticalLevels = this.getVerticalLevels(creationData.first());

        return new MultiLevelDoublyLinkedListData<>(
            creationData,
            data,
            values,
            levels,
            verticalLevels);
    }

    /**
     * Gets the data of multi-level doubly linked list2.
     */
    private IMultiLevelDoublyLinkedListData<Integer> getData2() {
        ITriple<IMatrix<Integer>, boolean[][], boolean[][]> creationData = this.createCreationData2();
        List<IMultiLevelDoublyLinkedListNode<Integer>> data = this.getData(creationData.first());
        List<Integer> values = this.getValues(creationData.first());
        List<List<Integer>> levels = this.getLevels(creationData.first());
        List<List<Integer>> verticalLevels = this.getVerticalLevels(creationData.first());

        return new MultiLevelDoublyLinkedListData<>(
            creationData,
            data,
            values,
            levels,
            verticalLevels);
    }

    /**
     * Gets the creation data of the multi-level doubly linked list1.
     *
     * 1--2--3--4
     *    |
     *    7--8--10--12
     *    |  |   |
     *    9  16 11
     *    |
     *   14--17--18--19--20
     *    |              |
     *   15--23          21
     *       |
     *       24
     */
    private ITriple<IMatrix<Integer>, boolean[][], boolean[][]> createCreationData1() {
        List<List<Integer>> data = new ArrayList<>();

        data.add(ArrayLists.of(   1,    2,    3,    4, null, null));
        data.add(ArrayLists.of(null,    7,    8,   10,   12, null));
        data.add(ArrayLists.of(null,    9,   16,   11, null, null));
        data.add(ArrayLists.of(null,   14,   17,   18,   19,   20));
        data.add(ArrayLists.of(null,   15,   23, null, null,   21));
        data.add(ArrayLists.of(null, null,   24, null, null, null));

        boolean[][] horizonticalConnections = {
            {true, true, true, false, false},
            {false, true, true, true, false},
            {false, false, false, false, false},
            {false, true, true, true, true},
            {false, true, false, false, false},
            {false, false, false, false, false}
        };

        boolean[][] verticalConnections = {
            {false, true, false, false, false, false},
            {false, true, true, true, false, false},
            {false, true, false, false, false, false},
            {false, true, false, false, false, true},
            {false, false, true, false, false, false}
        };

        IMatrix<Integer> matrix = new Matrix<>(data);

        return Triple.of(matrix, horizonticalConnections, verticalConnections);
    }

    /**
     * Gets the creation data of the multi-level doubly linked list2.
     *
     * 1--2--3--4--5
     * |     |
     * 6--7  8--9
     *    |
     *   10--11
     *       |
     *       12
     */
    private ITriple<IMatrix<Integer>, boolean[][], boolean[][]> createCreationData2() {
        List<List<Integer>> data = new ArrayList<>();

        data.add(ArrayLists.of(   1,    2,    3,    4,    5));
        data.add(ArrayLists.of(   6,    7,    8,    9, null));
        data.add(ArrayLists.of(null,   10,   11, null, null));
        data.add(ArrayLists.of(null, null,   12, null, null));

        boolean[][] horizonticalConnections = {
            {true, true, true, true},
            {true, false, true, false},
            {false, true, false, false},
            {false, false, false, false}
        };

        boolean[][] verticalConnections = {
            {true, false, true, false, false},
            {false, true, false, false, false},
            {false, false, true, false, false}
        };

        IMatrix<Integer> matrix = new Matrix<>(data);

        return Triple.of(matrix, horizonticalConnections, verticalConnections);
    }

    /**
     * Gets the data of the multi-level doubly linked list.
     */
    private <T extends Comparable<T>> List<IMultiLevelDoublyLinkedListNode<T>> getData(IMatrix<T> matrix) {
        int rowsSize = matrix.rowsSize();
        int colsSize = matrix.colsSize();
        int size = rowsSize * colsSize;

        List<IMultiLevelDoublyLinkedListNode<T>> result = new ArrayList<>(size);

        for (int row = 0; row < rowsSize; ++row) {
            for (int col = 0; col < colsSize; ++col) {
                T item = matrix.get(row, col);

                if (item != null) {
                    result.add(MultiLevelDoublyLinkedListNode.of(item));
                }
            }
        }

        return result;
    }

    /**
     * Gets the values of the multi-level doubly linked list.
     */
    private <T extends Comparable<T>> List<T> getValues(IMatrix<T> matrix) {
        int rowsSize = matrix.rowsSize();
        int colsSize = matrix.colsSize();

        int size = rowsSize * colsSize;
        List<T> result = new ArrayList<>(size);

        for (int row = 0; row < rowsSize; ++row) {
            for (int col = 0; col < colsSize; ++col) {
                T item = matrix.get(row, col);

                if (item != null) {
                    result.add(item);
                }
            }
        }

        return result;
    }

    /**
     * Gets the levels of a multi-level doubly linked list.
     */
    private <T extends Comparable<T>> List<List<T>> getLevels(IMatrix<T> matrix) {
        int rowsSize = matrix.rowsSize();
        int colsSize = matrix.colsSize();

        List<List<T>> result = new ArrayList<>(rowsSize);

        for (int row = 0; row < rowsSize; ++row) {
            List<T> level = new ArrayList<>();

            for (int col = 0; col < colsSize; ++col) {
                T item = matrix.get(row, col);

                if (item != null) {
                    level.add(item);
                }
            }

            result.add(level);
        }

        return result;
    }

    /**
     * Gets the vertical levels of a multi-level doubly linked list.
     */
    private <T extends Comparable<T>> List<List<T>> getVerticalLevels(IMatrix<T> matrix) {
        int rowsSize = matrix.rowsSize();
        int colsSize = matrix.colsSize();

        List<List<T>> result = new ArrayList<>(colsSize);

        for (int col = 0; col < colsSize; ++col) {
            List<T> level = new ArrayList<>();

            for (int row = 0; row < rowsSize; ++row) {
                T item = matrix.get(row, col);

                if (item != null) {
                    level.add(item);
                }
            }

            result.add(level);
        }

        return result;
    }
}
