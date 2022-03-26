package datastructures.linkedlist.core;

import base.core.Iterator;
import base.core.ListIterator;
import base.interfaces.ITriple;
import datastructures.core.TestData;
import datastructures.linkedlist.interfaces.ILinkedList;
import datastructures.linkedlist.interfaces.ILinkedListNode;
import datastructures.linkedlist.interfaces.ILinkedListData;
import datastructures.interfaces.ITestData;
import testbase.core.Assertion;
import testbase.core.IterationTest;
import testbase.interfaces.IAssertion;
import testbase.interfaces.IIterationTest;
import java.util.List;
import org.junit.Test;

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
     * Tests the creation logic of a linked list.
     */
    @Test
    public void linkedListCreationTest() {
        List<ILinkedListData<Integer>> data = this.testData.getLinkedListData().getData();

        for (ILinkedListData<Integer> listData : data) {
            this.testCreation(listData);
        }
    }

    /**
     * Tests the iteration logic of a linked list.
     */
    @Test
    public void linkedListIterationTest() {
        List<ILinkedListData<Integer>> data = this.testData.getLinkedListData().getData();

        for (ILinkedListData<Integer> listData : data) {
            this.testIteration(listData);
        }
    }

    /**
     * Tests the updation logic of a linked list.
     */
    @Test
    public void linkedListUpdationTest() {
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
        ILinkedList<T> container = this.createLinkedList(data.getValues());

        //
        // Test the data of the container...
        //
        this.assertion.assertEqualsWithIterators(
            container.getIterator(),
            ListIterator.make(data.getNodes()),
            "Invalid creation logic of a linked list.");
    }

    /**
     * Tests the iteration logic of a linked list.
     */
    private <T extends Comparable<T>> void testIteration(ILinkedListData<T> data) {
        //
        // Create the container...
        //
        ILinkedList<T> container = this.createLinkedList(data.getValues());

        //
        // Test the default iterator of the container...
        //
        IIterationTest iterationTest = new IterationTest();
        iterationTest.testIteration(
            container,
            ListIterator.make(data.getNodes()),
            "LinkedList");

        //
        // Test the forward iterator of the container...
        //
        iterationTest.testForwardIteration(
            container,
            ListIterator.make(data.getNodes()),
            "LinkedList");

        //
        // Test the value iterator of the container...
        //
        iterationTest.testValueIteration(
            container,
            ListIterator.make(data.getValues()),
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

        this.assertion.assertEqualsWithIterators(
            list.getValueIterator(),
            Iterator.make(expectedContent),
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
            list.addToFront(LinkedListNode.make(item));
        }
        else if (operation.equalsIgnoreCase("addToBack")) {
            list.addToBack(LinkedListNode.make(item));
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
