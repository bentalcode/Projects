package datastructures.linkedlist.core;

import base.core.Iterator;
import base.core.ListIterator;
import base.interfaces.ITriple;
import datastructures.core.TestData;
import datastructures.linkedlist.interfaces.ILinkedList;
import datastructures.linkedlist.interfaces.ILinkedListNode;
import datastructures.linkedlist.interfaces.ILinkedListData;
import testbase.core.Assertion;
import datastructures.interfaces.ITestData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.IterationTest;
import testbase.interfaces.IAssertion;
import testbase.interfaces.IIterationTest;
import java.util.List;

/**
 * The LinkedListTest class implements tests for a linked list.
 */
public final class LinkedListTest {
    private final ITestData testData = new TestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The LinkedListTest constructor.
     */
    public LinkedListTest() {
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
     * Tests the creation logic of a linked list.
     */
    @Test
    public void LinkedListCreationTest() {
        List<ILinkedListData<Integer>> data = this.testData.getLinkedListData().getData();

        for (ILinkedListData<Integer> listData : data) {
            this.testCreation(listData);
        }
    }

    /**
     * Tests the iteration logic of a linked list.
     */
    @Test
    public void LinkedListIterationTest() {
        List<ILinkedListData<Integer>> data = this.testData.getLinkedListData().getData();

        for (ILinkedListData<Integer> listData : data) {
            this.testIteration(listData);
        }
    }

    /**
     * Tests the updation logic of a linked list.
     */
    @Test
    public void LinkedListUpdationTest() {
        ILinkedList<Integer> list = new LinkedList<>();

        List<ITriple<String, Integer, List<Integer>>> data = this.testData.getLinkedListData().getUpdationData();
        this.testUpdation(list, data);
    }

    /**
     * Tests the creation logic of a linked list.
     */
    private <T extends Comparable<T>> void testCreation(ILinkedListData<T> data) {
        //
        // Create the container...
        //
        ILinkedList<T> container = this.createLinkedList(data.getCreationData());

        //
        // Test the data of the container...
        //
        this.assertion.assertEquals(
            container.getIterator(),
            ListIterator.of(data.getData()),
            "Invalid creation logic of a linked list.");
    }

    /**
     * Tests the iteration logic of a linked list.
     */
    private <T extends Comparable<T>> void testIteration(ILinkedListData<T> data) {
        //
        // Create the container...
        //
        ILinkedList<T> container = this.createLinkedList(data.getCreationData());

        //
        // Test the default iterator of the container...
        //
        IIterationTest iterationTest = new IterationTest();
        iterationTest.testIteration(
            container,
            ListIterator.of(data.getData()),
            "LinkedList");

        //
        // Test the forward iterator of the container...
        //
        iterationTest.testForwardIteration(
            container,
            ListIterator.of(data.getData()),
            "LinkedList");

        //
        // Test the value iterator of the container...
        //
        iterationTest.testValueIteration(
            container,
            ListIterator.of(data.getValues()),
            "LinkedList");
    }

    /**
     * Tests the updation logic of a linked list.
     */
    private <T extends Comparable<T>> void testUpdation(
        ILinkedList<T> list,
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
     * Tests the updation logic of a linked list.
     */
    private <T extends Comparable<T>> void testUpdation(
        ILinkedList<T> list,
        String operation,
        T item,
        List<T> expectedContent) {

        this.updateList(list, operation, item);

        this.assertion.assertEquals(
            list.getValueIterator(),
            Iterator.of(expectedContent),
            "Invalid updation logic of a linked list.");
    }

    /**
     * Creates a linked list.
     */
    private <T extends Comparable<T>> ILinkedList<T> createLinkedList(List<T> data) {
        ILinkedList<T> result = new LinkedList<>();

        for (T element : data) {
            result.addToBack(element);
        }

        return result;
    }

    /**
     * Updates the list.
     */
    private <T extends Comparable<T>> void updateList(
        ILinkedList<T> list,
        String operation,
        T item) {

        if (operation.equalsIgnoreCase("addToFront")) {
            list.addToFront(LinkedListNode.of(item));
        }
        else if (operation.equalsIgnoreCase("addToBack")) {
            list.addToBack(LinkedListNode.of(item));
        }
        else if (operation.equalsIgnoreCase("removeFromFront")) {
            list.removeFromFront();
        }
        else if (operation.equalsIgnoreCase("removeAfter")) {
            ILinkedListNode<T> currNode = list.getNode(0);
            list.removeAfter(currNode);
        }
    }
}
