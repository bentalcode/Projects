package datastructures.doublylinkedlist.core;

import base.core.Iterator;
import base.core.ListIterator;
import base.interfaces.ITriple;
import datastructures.core.TestData;
import datastructures.doublylinkedlist.interfaces.IListData;
import testbase.core.Assertion;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedList;
import datastructures.interfaces.ITestData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.IterationTest;
import testbase.interfaces.IAssertion;
import testbase.interfaces.IIterationTest;
import java.util.List;

/**
 * The DoublyLinkedListTest class implements tests for a doubly linked list.
 */
public final class DoublyLinkedListTest {
    private final ITestData testData = new TestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The DoublyLinkedListTest constructor.
     */
    public DoublyLinkedListTest() {
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
     * Tests the creation logic of a doubly linked list.
     */
    @Test
    public void DoublyLinkedListCreationTest() {
        List<IListData<Integer>> data = this.testData.getDoublyLinkedListData().getData();

        for (IListData<Integer> listData : data) {
            this.testCreation(listData);
        }
    }

    /**
     * Tests the iteration logic of a doubly linked list.
     */
    @Test
    public void DoublyLinkedListIterationTest() {
        List<IListData<Integer>> data = this.testData.getDoublyLinkedListData().getData();

        for (IListData<Integer> listData : data) {
            this.testIteration(listData);
        }
    }

    /**
     * Tests the updation logic of a doubly linked list.
     */
    @Test
    public void DoublyLinkedListUpdationTest() {
        IDoublyLinkedList<Integer> list = new DoublyLinkedList<>();

        List<ITriple<String, Integer, List<Integer>>> data =
            this.testData.getDoublyLinkedListData().getUpdationData();

        this.testUpdation(list, data);
    }

    /**
     * Tests the creation logic of a doubly linked list.
     */
    private <T extends Comparable<T>> void testCreation(IListData<T> data) {
        //
        // Create the container...
        //
        IDoublyLinkedList<T> container = this.createDoublyLinkedList(data.getCreationData());

        //
        // Test the data of the container...
        //
        this.assertion.assertEquals(
            container.getValueIterator(),
            ListIterator.of(data.getData()),
            "Invalid creation logic of a doubly linked list.");
    }

    /**
     * Tests the iteration logic of a doubly linked list.
     */
    private <T extends Comparable<T>> void testIteration(IListData<T> data) {
        //
        // Create the container...
        //
        IDoublyLinkedList<T> container = this.createDoublyLinkedList(data.getCreationData());
        IDoublyLinkedList<T> expectedContainer = this.createDoublyLinkedList(data.getCreationData());

        //
        // Test the default iterator of the container...
        //
        IIterationTest iterationTest = new IterationTest();
        iterationTest.testIteration(
            container,
            expectedContainer,
            "DoublyLinkedList");

        //
        // Test the forward iterator of the container...
        //
        iterationTest.testForwardIteration(
            container,
            expectedContainer,
            "DoublyLinkedList");

        //
        // Test the reverse iterator of the container...
        //
        iterationTest.testReverseIteration(
            container,
            expectedContainer,
            "DoublyLinkedList");

        //
        // Test the value iterator of the container...
        //
        iterationTest.testValueIteration(
            container,
            expectedContainer,
            "DoublyLinkedList");

        //
        // Test the value reverse iterator of the container...
        //
        iterationTest.testValueReverseIteration(
            container,
            expectedContainer,
            "DoublyLinkedList");
    }

    /**
     * Tests the updation logic of a doubly linked list.
     */
    private <T extends Comparable<T>> void testUpdation(
        IDoublyLinkedList<T> list,
        List<ITriple<String, T, List<T>>> data) {

        for (ITriple<String, T, List<T>> entry : data) {
            this.testUpdation(
                list,
                entry.first(),
                entry.second(),
                entry.third());
        }
    }

    /**
     * Tests the updation logic of a doubly linked list.
     */
    private <T extends Comparable<T>> void testUpdation(
        IDoublyLinkedList<T> list,
        String operation,
        T item,
        List<T> expectedContent) {

        this.updateList(list, operation, item);

        this.assertion.assertEquals(
            list.getValueIterator(),
            Iterator.of(expectedContent),
            "Invalid updation logic of a doubly linked list.");
    }

    /**
     * Creates a doubly linked list.
     */
    private <T extends Comparable<T>> IDoublyLinkedList<T> createDoublyLinkedList(List<T> data) {
        IDoublyLinkedList<T> result = new DoublyLinkedList<>();

        for (T element : data) {
            result.addToBack(element);
        }

        return result;
    }

    /**
     * Updates the list.
     */
    private <T extends Comparable<T>> void updateList(
        IDoublyLinkedList<T> list,
        String operation,
        T item) {

        if (operation.equalsIgnoreCase("addToFront")) {
            list.addToFront(DoublyLinkedListNode.of(item));
        }
        else if (operation.equalsIgnoreCase("addToBack")) {
            list.addToBack(DoublyLinkedListNode.of(item));
        }
        else if (operation.equalsIgnoreCase("removeFromFront")) {
            list.removeFromFront();
        }
        else if (operation.equalsIgnoreCase("removeFromBack")) {
            list.removeFromBack();
        }
    }
}
