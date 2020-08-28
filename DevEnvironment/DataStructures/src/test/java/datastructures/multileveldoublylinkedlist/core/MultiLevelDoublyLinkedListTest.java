package datastructures.multileveldoublylinkedlist.core;

import base.core.ListIterator;
import base.core.Matrix;
import base.core.TwoDimensionalListIterator;
import base.interfaces.IMatrix;
import base.interfaces.ITriple;
import datastructures.core.TestData;
import datastructures.interfaces.ITestData;
import datastructures.multileveldoublylinkedlist.interfaces.IMultiLevelDoublyLinkedList;
import datastructures.multileveldoublylinkedlist.interfaces.IMultiLevelDoublyLinkedListData;
import datastructures.multileveldoublylinkedlist.interfaces.IMultiLevelDoublyLinkedListLogic;
import datastructures.multileveldoublylinkedlist.interfaces.IMultiLevelDoublyLinkedListNode;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.core.IterationTest;
import testbase.interfaces.IAssertion;
import testbase.interfaces.IIterationTest;
import java.util.List;

/**
 * The MultiLevelDoublyLinkedListTest class implements tests for a multi-level doubly linked list.
 */
public final class MultiLevelDoublyLinkedListTest {
    private final ITestData testData = new TestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The MultiLevelDoublyLinkedListTest constructor.
     */
    public MultiLevelDoublyLinkedListTest() {
    }

    /**
     * Initialize the tests.
     */
    @Before
    public void setUp() {
    }

    /**
     * Un-Initializes the tests.
     */
    @After
    public void tearDown() {
    }

    /**
     * Tests the creation logic of a multi-level doubly linked list.
     */
    @Test
    public void multiLevelDoublyLinkedListCreationTest() {
        List<IMultiLevelDoublyLinkedListData<Integer>> data = this.testData.getMultiLevelDoublyLinkedListData().getData();

        for (IMultiLevelDoublyLinkedListData<Integer> listData : data) {
            this.testCreation(listData);
        }
    }

    /**
     * Tests the iteration logic of a multi-level doubly linked list.
     */
    @Test
    public void multiLevelDoublyLinkedListIterationTest() {
        List<IMultiLevelDoublyLinkedListData<Integer>> data = this.testData.getMultiLevelDoublyLinkedListData().getData();

        for (IMultiLevelDoublyLinkedListData<Integer> listData : data) {
            this.testIteration(listData);
        }
    }

    /**
     * Tests the logic of getting levels of a multi-level doubly linked list.
     */
    @Test
    public void getLevelsTest() {
        List<IMultiLevelDoublyLinkedListData<Integer>> data = this.testData.getMultiLevelDoublyLinkedListData().getData();

        for (IMultiLevelDoublyLinkedListData<Integer> listData : data) {
            IMultiLevelDoublyLinkedList<Integer> list = this.createMultiLevelDoublyLinkedList(listData.getCreationData());
            List<List<Integer>> expectedLevels = listData.getLevels();

            this.testGetLevels(list, expectedLevels);
        }
    }

    /**
     * Tests the logic of getting vertical levels of a multi-level doubly linked list.
     */
    @Test
    public void getVerticalLevelsTest() {
        List<IMultiLevelDoublyLinkedListData<Integer>> data = this.testData.getMultiLevelDoublyLinkedListData().getData();

        for (IMultiLevelDoublyLinkedListData<Integer> listData : data) {
            IMultiLevelDoublyLinkedList<Integer> list = this.createMultiLevelDoublyLinkedList(listData.getCreationData());
            List<List<Integer>> expectedLevels = listData.getVerticalLevels();

            this.testGetVerticalLevels(list, expectedLevels);
        }
    }

    /**
     * Tests the logic of flattening by levels a multi-level doubly linked list.
     */
    @Test
    public void flattenByLevelsTest() {
        List<IMultiLevelDoublyLinkedListData<Integer>> data = this.testData.getMultiLevelDoublyLinkedListData().getData();

        for (IMultiLevelDoublyLinkedListData<Integer> listData : data) {
            IMultiLevelDoublyLinkedList<Integer> list =
                this.createMultiLevelDoublyLinkedList(listData.getCreationData());

            List<List<IMultiLevelDoublyLinkedListNode<Integer>>> nodesByLevels =
                listData.getNodesByLevels();

            this.testFlatteningByLevels(list, nodesByLevels);
        }
    }

    /**
     * Tests the logic of flattening by vertical levels a multi-level doubly linked list.
     */
    @Test
    public void flattenByVerticalLevelsTest() {
        List<IMultiLevelDoublyLinkedListData<Integer>> data = this.testData.getMultiLevelDoublyLinkedListData().getData();

        for (IMultiLevelDoublyLinkedListData<Integer> listData : data) {
            IMultiLevelDoublyLinkedList<Integer> list =
                this.createMultiLevelDoublyLinkedList(listData.getCreationData());

            List<List<IMultiLevelDoublyLinkedListNode<Integer>>> nodesByLevels =
                listData.getNodesByVerticalLevels();

            this.testFlatteningByVerticalLevels(list, nodesByLevels);
        }
    }

    /**
     * Tests the logic of flattening by depth levels a multi-level doubly linked list.
     */
    @Test
    public void flattenByVerticalDepthTest() {
        List<IMultiLevelDoublyLinkedListData<Integer>> data = this.testData.getMultiLevelDoublyLinkedListData().getData();

        for (IMultiLevelDoublyLinkedListData<Integer> listData : data) {
            IMultiLevelDoublyLinkedList<Integer> list =
                this.createMultiLevelDoublyLinkedList(listData.getCreationData());

            List<List<IMultiLevelDoublyLinkedListNode<Integer>>> nodesByLevels =
                listData.getNodesByDepthLevels();

            this.testFlatteningByDepthLevels(list, nodesByLevels);
        }
    }

    /**
     * Tests the creation logic of a multi-level doubly linked list.
     */
    private <T extends Comparable<T>> void testCreation(IMultiLevelDoublyLinkedListData<T> data) {
        //
        // Create the container...
        //
        IMultiLevelDoublyLinkedList<T> container = this.createMultiLevelDoublyLinkedList(data.getCreationData());

        //
        // Test the data of the container...
        //
        this.assertion.assertEqualsWithIterators(
            container.getIterator(),
            ListIterator.make(data.getData()),
            "Invalid creation logic of a doubly linked list.");
    }

    /**
     * Tests the iteration logic of a multi-level doubly linked list.
     */
    private <T extends Comparable<T>> void testIteration(IMultiLevelDoublyLinkedListData<T> data) {
        //
        // Create the container...
        //
        IMultiLevelDoublyLinkedList<T> container = this.createMultiLevelDoublyLinkedList(data.getCreationData());

        //
        // Test the default iterator of the container...
        //
        IIterationTest iterationTest = new IterationTest();
        iterationTest.testIteration(
            container,
            ListIterator.make(data.getData()),
            "MultiLevelDoublyLinkedList");

        //
        // Test the forward iterator of the container...
        //
        iterationTest.testForwardIteration(
            container,
            ListIterator.make(data.getData()),
            "MultiLevelDoublyLinkedList");

        //
        // Test the value iterator of the container...
        //
        iterationTest.testValueIteration(
            container,
            ListIterator.make(data.getValues()),
            "MultiLevelDoublyLinkedList");
    }

    /**
     * Tests the logic of getting levels of a multi-level doubly linked list.
     */
    private <T extends Comparable<T>> void testGetLevels(
        IMultiLevelDoublyLinkedList<T> list,
        List<List<T>> expectedResult) {

        IMultiLevelDoublyLinkedListLogic<T> logic = list.getLogic();
        List<List<T>> result = logic.getLevels();

        this.assertion.assertEqualsWithIterators(
            TwoDimensionalListIterator.make(result),
            TwoDimensionalListIterator.make(expectedResult),
            "Incorrect logic of getting levels of a multi-level doubly linked list.");
    }

    /**
     * Tests the logic of getting vertical levels of a multi-level doubly linked list.
     */
    private <T extends Comparable<T>> void testGetVerticalLevels(
        IMultiLevelDoublyLinkedList<T> list,
        List<List<T>> expectedResult) {

        IMultiLevelDoublyLinkedListLogic<T> logic = list.getLogic();
        List<List<T>> result = logic.getVerticalLevels();

        this.assertion.assertEqualsWithIterators(
            TwoDimensionalListIterator.make(result),
            TwoDimensionalListIterator.make(expectedResult),
            "Incorrect logic of getting vertical levels of a multi-level doubly linked list.");
    }

    /**
     * Tests the logic of flattening by levels a multi-level doubly linked list.
     */
    private <T extends Comparable<T>> void testFlatteningByLevels(
        IMultiLevelDoublyLinkedList<T> list,
        List<List<IMultiLevelDoublyLinkedListNode<T>>> nodesByLevels) {

        IMultiLevelDoublyLinkedListLogic logic = list.getLogic();
        logic.flatten();

        this.assertion.assertEqualsWithIterators(
            list.getIterator(),
            TwoDimensionalListIterator.make(nodesByLevels),
            "Incorrect logic of flattening by levels a multi-level doubly linked list.");
    }

    /**
     * Tests the logic of flattening by vertical levels a multi-level doubly linked list.
     */
    private <T extends Comparable<T>> void testFlatteningByVerticalLevels(
        IMultiLevelDoublyLinkedList<T> list,
        List<List<IMultiLevelDoublyLinkedListNode<T>>> nodesByLevels) {

        IMultiLevelDoublyLinkedListLogic logic = list.getLogic();
        logic.flattenByVerticalLevels();

        this.assertion.assertEqualsWithIterators(
            list.getIterator(),
            TwoDimensionalListIterator.make(nodesByLevels),
            "Incorrect logic of flattening by vertical levels a multi-level doubly linked list.");
    }

    /**
     * Tests the logic of flattening by depth levels a multi-level doubly linked list.
     */
    private <T extends Comparable<T>> void testFlatteningByDepthLevels(
        IMultiLevelDoublyLinkedList<T> list,
        List<List<IMultiLevelDoublyLinkedListNode<T>>> nodesByLevels) {

        IMultiLevelDoublyLinkedListLogic logic = list.getLogic();
        logic.flattenByDepthLevels();

        this.assertion.assertEqualsWithIterators(
            list.getIterator(),
            TwoDimensionalListIterator.make(nodesByLevels),
            "Incorrect logic of flattening by depth levels a multi-level doubly linked list.");
    }

    /**
     * Creates a multi-level doubly linked list.
     */
    private <T extends Comparable<T>> IMultiLevelDoublyLinkedList<T> createMultiLevelDoublyLinkedList(
        ITriple<IMatrix<T>, boolean[][], boolean[][]> data) {

        IMultiLevelDoublyLinkedList<T> result = new MultiLevelDoublyLinkedList<>();

        IMatrix<T> matrix = data.first();

        if (matrix.empty()) {
            return result;
        }

        int rows = matrix.rowsSize();
        int cols = matrix.colsSize();

        //
        // Creates a matrix with the nodes...
        //
        IMatrix<IMultiLevelDoublyLinkedListNode<T>> nodes = new Matrix<>(rows, cols);

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                T nodeValue = matrix.get(row, col);

                if (nodeValue != null) {
                    nodes.set(row, col, MultiLevelDoublyLinkedListNode.make(nodeValue));
                }
            }
        }

        //
        // Connects the nodes in the matrix...
        //
        boolean[][] horizonticalConnections = data.second();
        boolean[][] verticalConnections = data.third();

        for (int row = 0; row < rows; ++row) {
            IMultiLevelDoublyLinkedListNode<T> prevNode = null;

            for (int col = 0; col < cols; ++col) {
                IMultiLevelDoublyLinkedListNode<T> currNode = nodes.get(row, col);
                IMultiLevelDoublyLinkedListNode<T> aboveNode = (row > 0) ? nodes.get(row - 1, col) : null;

                if (result.empty()) {
                    result.addToFront(currNode);
                }
                else  {
                    if (col > 0 && horizonticalConnections[row][col - 1]) {
                        assert(prevNode != null && currNode != null);

                        if (prevNode != null && currNode != null) {
                            result.addAfter(prevNode, currNode);
                        }
                    }

                    if (row > 0 && verticalConnections[row - 1][col]) {
                        assert(aboveNode != null && currNode != null);

                        if (aboveNode != null && currNode != null) {
                            result.addBellow(aboveNode, currNode);
                        }
                    }

                }

                prevNode = (col == cols - 1) ? null : currNode;
            }
        }

        return result;
    }
}
