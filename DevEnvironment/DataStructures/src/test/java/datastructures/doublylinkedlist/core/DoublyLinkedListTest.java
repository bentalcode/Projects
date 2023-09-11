package datastructures.doublylinkedlist.core;

import base.core.Iterator;
import base.core.ListIterator;
import base.core.ListReverseIterator;
import base.interfaces.ITriple;
import datastructures.core.TestData;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListData;
import testbase.core.Assertion;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedList;
import datastructures.interfaces.ITestData;
import java.util.List;
import testbase.core.IterationTest;
import testbase.interfaces.IAssertion;
import testbase.interfaces.IIterationTest;
import org.junit.Test;

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
     * Tests the creation logic of a doubly linked list.
     */
    @Test
    public void doublyLinkedListCreationTest() {
        List<IDoublyLinkedListData<Integer>> data = this.testData.getDoublyLinkedListData().getData();

        for (IDoublyLinkedListData<Integer> listData : data) {
            this.testCreation(listData);
        }
    }

    /**
     * Tests the iteration logic of a doubly linked list.
     */
    @Test
    public void doublyLinkedListIterationTest() {
        List<IDoublyLinkedListData<Integer>> data = this.testData.getDoublyLinkedListData().getData();

        for (IDoublyLinkedListData<Integer> listData : data) {
            this.testIteration(listData);
        }
    }

    /**
     * Tests the update logic of a doubly linked list.
     */
    @Test
    public void doublyLinkedListUpdateTest() {
        IDoublyLinkedList<Integer> list = new DoublyLinkedList<>();

        List<ITriple<String, Integer, List<Integer>>> data =
            this.testData.getDoublyLinkedListData().getUpdateData();

        this.testUpdate(list, data);
    }

    /**
     * Tests the creation logic of a doubly linked list.
     */
    private <T extends Comparable<T>> void testCreation(IDoublyLinkedListData<T> data) {
        //
        // Create the container...
        //
        IDoublyLinkedList<T> container = createDoublyLinkedList(data.getValues());

        //
        // Test the data of the container...
        //
        this.assertion.assertEqualsWithIterators(
            container.getIterator(),
            ListIterator.make(data.getNodes()),
            "Invalid creation logic of a doubly linked list.");
    }

    /**
     * Tests the iteration logic of a doubly linked list.
     */
    private <T extends Comparable<T>> void testIteration(IDoublyLinkedListData<T> data) {
        //
        // Create the container...
        //
        IDoublyLinkedList<T> container = createDoublyLinkedList(data.getValues());

        //
        // Test the default iterator of the container...
        //
        IIterationTest iterationTest = new IterationTest();
        iterationTest.testIteration(
            container,
            ListIterator.make(data.getNodes()),
            "DoublyLinkedList");

        //
        // Test the forward iterator of the container...
        //
        iterationTest.testForwardIteration(
            container,
            ListIterator.make(data.getNodes()),
            "DoublyLinkedList");

        //
        // Test the reverse iterator of the container...
        //
        iterationTest.testReverseIteration(
            container,
            ListReverseIterator.make(data.getNodes()),
            "DoublyLinkedList");

        //
        // Test the value iterator of the container...
        //
        iterationTest.testValueIteration(
            container,
            ListIterator.make(data.getValues()),
            "DoublyLinkedList");

        //
        // Test the value reverse iterator of the container...
        //
        iterationTest.testValueReverseIteration(
            container,
            ListReverseIterator.make(data.getValues()),
            "DoublyLinkedList");
    }

    /**
     * Tests the update logic of a doubly linked list.
     */
    private <T extends Comparable<T>> void testUpdate(
        IDoublyLinkedList<T> list,
        List<ITriple<String, T, List<T>>> data) {

        for (ITriple<String, T, List<T>> entry : data) {
            this.testUpdate(
                list,
                entry.first(),
                entry.second(),
                entry.third());
        }
    }

    /**
     * Tests the update logic of a doubly linked list.
     */
    private <T extends Comparable<T>> void testUpdate(
        IDoublyLinkedList<T> list,
        String operation,
        T item,
        List<T> expectedContent) {

        this.updateList(list, operation, item);

        this.assertion.assertEqualsWithIterators(
            list.getValueIterator(),
            Iterator.make(expectedContent),
            "Invalid updating logic of a doubly linked list.");
    }

    /**
     * Creates a doubly linked list.
     */
    private static <T extends Comparable<T>> IDoublyLinkedList<T> createDoublyLinkedList(List<T> data) {
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
            list.addToFront(DoublyLinkedListNode.make(item));
        }
        else if (operation.equalsIgnoreCase("addToBack")) {
            list.addToBack(DoublyLinkedListNode.make(item));
        }
        else if (operation.equalsIgnoreCase("removeFromFront")) {
            list.removeFromFront();
        }
        else if (operation.equalsIgnoreCase("removeFromBack")) {
            list.removeFromBack();
        }
    }
}
