package datastructures.linkedlist.core;

import base.core.Iterator;
import base.core.ListIterator;
import base.interfaces.ITriple;
import datastructures.core.TestData;
import datastructures.linkedlist.interfaces.ILinkedList;
import datastructures.linkedlist.interfaces.ILinkedListNode;
import datastructures.linkedlist.interfaces.IListData;
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
        List<IListData<Integer>> data = this.testData.getLinkedListData().getData();

        for (IListData<Integer> listData : data) {
            this.testCreation(listData);
        }
    }

    /**
     * Tests the iteration logic of a linked list.
     */
    @Test
    public void LinkedListIterationTest() {
        List<IListData<Integer>> data = this.testData.getLinkedListData().getData();

        for (IListData<Integer> listData : data) {
            this.testIteration(listData);
        }
    }

    /**
     * Tests the updation logic of a linked list.
     */
    @Test
    public void LinkedListUpdationTest() {
        ILinkedList<Integer> list = new LinkedList<>();

        List<ITriple<String, Integer, List<Integer>>> data =
            this.testData.getLinkedListData().getUpdationData();

        this.testUpdation(list, data);
    }

    /**
     * Tests the creation logic of a linked list.
     */
    private <TValue extends Comparable<TValue>> void testCreation(IListData<TValue> data) {
        //
        // Create the container...
        //
        ILinkedList<TValue> container = this.createLinkedList(data.getCreationData());

        //
        // Test the data of the container...
        //
        this.assertion.assertEquals(
            container.getValueIterator(),
            ListIterator.of(data.getData()),
            "Invalid creation logic of a linked list.");
    }

    /**
     * Tests the iteration logic of a linked list.
     */
    private <TValue extends Comparable<TValue>> void testIteration(IListData<TValue> data) {
        //
        // Create the container...
        //
        ILinkedList<TValue> container = this.createLinkedList(data.getCreationData());
        ILinkedList<TValue> expectedContainer = this.createLinkedList(data.getCreationData());

        //
        // Test the default iterator of the container...
        //
        IIterationTest iterationTest = new IterationTest();
        iterationTest.testIteration(
            container,
            expectedContainer,
            "LinkedList");

        //
        // Test the forward iterator of the container...
        //
        iterationTest.testForwardIteration(
            container,
            expectedContainer,
            "LinkedList");

        //
        // Test the value iterator of the container...
        //
        iterationTest.testValueIteration(
            container,
            expectedContainer,
            "LinkedList");
    }

    /**
     * Tests the updation logic of a linked list.
     */
    private <TValue extends Comparable<TValue>> void testUpdation(
        ILinkedList<TValue> list,
        List<ITriple<String, TValue, List<TValue>>> data) {

        for (ITriple<String, TValue, List<TValue>> entry : data) {
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
    private <TValue extends Comparable<TValue>> void testUpdation(
        ILinkedList<TValue> list,
        String operation,
        TValue item,
        List<TValue> expectedContent) {

        this.updateList(list, operation, item);

        this.assertion.assertEquals(
            list.getValueIterator(),
            Iterator.of(expectedContent),
            "Invalid updation logic of a linked list.");
    }

    /**
     * Creates a linked list.
     */
    private <TValue extends Comparable<TValue>> ILinkedList<TValue> createLinkedList(List<TValue> data) {
        ILinkedList<TValue> result = new LinkedList<>();

        for (TValue element : data) {
            result.addToBack(element);
        }

        return result;
    }

    /**
     * Updates the list.
     */
    private <TValue extends Comparable<TValue>> void updateList(
        ILinkedList<TValue> list,
        String operation,
        TValue item) {

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
            ILinkedListNode<TValue> currNode = list.getNode(0);
            list.removeAfter(currNode);
        }
    }
}
