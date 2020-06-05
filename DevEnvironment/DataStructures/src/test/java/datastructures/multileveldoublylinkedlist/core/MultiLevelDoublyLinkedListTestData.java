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

        data.add(getData1());
        data.add(getData2());

        return data;
    }

    /**
     * Gets the data of multi-level doubly linked list1.
     */
    private static IMultiLevelDoublyLinkedListData<Integer> getData1() {
        ITriple<IMatrix<Integer>, boolean[][], boolean[][]> creationData = createCreationData1();
        List<IMultiLevelDoublyLinkedListNode<Integer>> data = getData(creationData.first());
        List<Integer> values = getValues(creationData.first());
        List<List<Integer>> levels = getLevels(creationData.first());
        List<List<Integer>> verticalLevels = getVerticalLevels(creationData.first());
        List<List<IMultiLevelDoublyLinkedListNode<Integer>>> nodesByLevels = getNodeLists(levels);
        List<List<IMultiLevelDoublyLinkedListNode<Integer>>> nodesByVerticalLevels = getNodeLists(verticalLevels);
        List<List<IMultiLevelDoublyLinkedListNode<Integer>>> nodesByDepthLevels = getNodesByDepthLevels1();

        return new MultiLevelDoublyLinkedListData<>(
            creationData,
            data,
            values,
            levels,
            verticalLevels,
            nodesByLevels,
            nodesByVerticalLevels,
            nodesByDepthLevels);
    }

    /**
     * Gets the data of multi-level doubly linked list2.
     */
    private static IMultiLevelDoublyLinkedListData<Integer> getData2() {
        ITriple<IMatrix<Integer>, boolean[][], boolean[][]> creationData = createCreationData2();
        List<IMultiLevelDoublyLinkedListNode<Integer>> data = getData(creationData.first());
        List<Integer> values = getValues(creationData.first());
        List<List<Integer>> levels = getLevels(creationData.first());
        List<List<Integer>> verticalLevels = getVerticalLevels(creationData.first());
        List<List<IMultiLevelDoublyLinkedListNode<Integer>>> nodesByLevels = getNodeLists(levels);
        List<List<IMultiLevelDoublyLinkedListNode<Integer>>> nodesByVerticalLevels = getNodeLists(verticalLevels);
        List<List<IMultiLevelDoublyLinkedListNode<Integer>>> nodesByDepthLevels = getNodesByDepthLevels2();

        return new MultiLevelDoublyLinkedListData<>(
            creationData,
            data,
            values,
            levels,
            verticalLevels,
            nodesByLevels,
            nodesByVerticalLevels,
            nodesByDepthLevels);
    }

    /**
     * Creates the creation data of the multi-level doubly linked list1.
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
    private static ITriple<IMatrix<Integer>, boolean[][], boolean[][]> createCreationData1() {
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
     * Creates the creation data of the multi-level doubly linked list2.
     *
     * 1--2--3--4--5
     * |     |
     * 6--7  8--9
     *    |
     *   10--11
     *       |
     *       12
     */
    private static ITriple<IMatrix<Integer>, boolean[][], boolean[][]> createCreationData2() {
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
    private static <T extends Comparable<T>> List<IMultiLevelDoublyLinkedListNode<T>> getData(IMatrix<T> matrix) {
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
    private static <T extends Comparable<T>> List<T> getValues(IMatrix<T> matrix) {
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
    private static <T extends Comparable<T>> List<List<T>> getLevels(IMatrix<T> matrix) {
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
    private static <T extends Comparable<T>> List<List<T>> getVerticalLevels(IMatrix<T> matrix) {
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

    /**
     * Gets lists of nodes of a multi-level doubly linked list.
     */
    private static <T extends Comparable<T>> List<List<IMultiLevelDoublyLinkedListNode<T>>> getNodeLists(List<List<T>> lists) {
        List<List<IMultiLevelDoublyLinkedListNode<T>>> result = new ArrayList<>(lists.size());

        for (List<T> list : lists) {
            List<IMultiLevelDoublyLinkedListNode<T>> nodeList = getNodeList(list);
            result.add(nodeList);
        }

        return result;
    }

    /**
     * Gets list of nodes of a multi-level doubly linked list.
     */
    private static <T extends Comparable<T>> List<IMultiLevelDoublyLinkedListNode<T>> getNodeList(List<T> list) {
        List<IMultiLevelDoublyLinkedListNode<T>> result = new ArrayList<>(list.size());

        for (T value : list) {
            result.add(MultiLevelDoublyLinkedListNode.of(value));
        }

        return result;
    }

    /**
     * Gets the nodes by depth levels of multi-level doubly linked list1.
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
    private static List<List<IMultiLevelDoublyLinkedListNode<Integer>>> getNodesByDepthLevels1() {
        List<List<IMultiLevelDoublyLinkedListNode<Integer>>> result = ArrayLists.of(
            ArrayLists.of(
                MultiLevelDoublyLinkedListNode.of(1)),
            ArrayLists.of(
                MultiLevelDoublyLinkedListNode.of(2),
                MultiLevelDoublyLinkedListNode.of(7),
                MultiLevelDoublyLinkedListNode.of(9),
                MultiLevelDoublyLinkedListNode.of(14),
                MultiLevelDoublyLinkedListNode.of(15),
                MultiLevelDoublyLinkedListNode.of(23),
                MultiLevelDoublyLinkedListNode.of(24)),
            ArrayLists.of(
                MultiLevelDoublyLinkedListNode.of(17),
                MultiLevelDoublyLinkedListNode.of(18),
                MultiLevelDoublyLinkedListNode.of(19),
                MultiLevelDoublyLinkedListNode.of(20),
                MultiLevelDoublyLinkedListNode.of(21)),
            ArrayLists.of(
                MultiLevelDoublyLinkedListNode.of(8),
                MultiLevelDoublyLinkedListNode.of(16)),
            ArrayLists.of(
                MultiLevelDoublyLinkedListNode.of(10),
                MultiLevelDoublyLinkedListNode.of(11)),
            ArrayLists.of(
                MultiLevelDoublyLinkedListNode.of(12)),
            ArrayLists.of(
                MultiLevelDoublyLinkedListNode.of(3),
                MultiLevelDoublyLinkedListNode.of(4)));

        return result;
    }

    /**
     * Gets the nodes by depth levels of multi-level doubly linked list2.
     *
     * 1--2--3--4--5
     * |     |
     * 6--7  8--9
     *    |
     *   10--11
     *       |
     *       12
     */
    private static List<List<IMultiLevelDoublyLinkedListNode<Integer>>> getNodesByDepthLevels2() {
        List<List<IMultiLevelDoublyLinkedListNode<Integer>>> result = ArrayLists.of(
            ArrayLists.of(
                MultiLevelDoublyLinkedListNode.of(1),
                MultiLevelDoublyLinkedListNode.of(6),
                MultiLevelDoublyLinkedListNode.of(7),
                MultiLevelDoublyLinkedListNode.of(10),
                MultiLevelDoublyLinkedListNode.of(11),
                MultiLevelDoublyLinkedListNode.of(12)),
            ArrayLists.of(
                MultiLevelDoublyLinkedListNode.of(2),
                MultiLevelDoublyLinkedListNode.of(3),
                MultiLevelDoublyLinkedListNode.of(8),
                MultiLevelDoublyLinkedListNode.of(9)),
            ArrayLists.of(
                MultiLevelDoublyLinkedListNode.of(4),
                MultiLevelDoublyLinkedListNode.of(5)));

        return result;
    }
}
