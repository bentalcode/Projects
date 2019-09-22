package datastructures.doublylinkedlist.core;

import base.core.Iterator;
import base.core.ListIterator;
import base.core.ListReverseIterator;
import base.interfaces.IBuilder;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import base.interfaces.ITriple;
import datastructures.core.TestData;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;
import testbase.core.Assertion;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedList;
import datastructures.interfaces.ITestData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.interfaces.IAssertion;
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
     * Tests the creation logic of a binary tree.
     */
    @Test
    public void DoublyLinkedListCreationTest() {
        List<List<IDoublyLinkedListNode<Integer>>> data = this.testData.getDoublyLinkedListData().getData();

        for (List<IDoublyLinkedListNode<Integer>> listData : data) {
            IIterator<IDoublyLinkedListNode<Integer>> dataIterator = ListIterator.of(listData);

            this.testCreation(dataIterator);
        }
    }

    /**
     * Tests the iteration logic of a doubly linked list.
     */
    @Test
    public void DoublyLinkedListIterationTest() {
        List<List<IDoublyLinkedListNode<Integer>>> data = this.testData.getDoublyLinkedListData().getData();

        for (List<IDoublyLinkedListNode<Integer>> listData : data) {
            IIterator<IDoublyLinkedListNode<Integer>> dataIterator = ListIterator.of(listData);
            IReverseIterator<IDoublyLinkedListNode<Integer>> reverseDataIterator = ListReverseIterator.of(listData);

            this.testIteration(
                dataIterator,
                reverseDataIterator);
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
    private <TValue extends Comparable<TValue>> void testCreation(
        IIterator<IDoublyLinkedListNode<TValue>> dataIterator) {

        //
        // Create the list...
        //
        IBuilder<IDoublyLinkedList<TValue>> builder = new DoublyLinkedListStreamBuilder<>(dataIterator);
        IDoublyLinkedList<TValue> list = builder.build();

        dataIterator.reset();

        //
        // Test the data of the list...
        //
        this.assertion.assertEquals(
            list.getIterator(),
            dataIterator,
            DoublyLinkedListNode.defaultComparator(),
            "Invalid creation logic of a doubly linked list.");
    }

    /**
     * Tests the iteration logic of a doubly linked list.
     */
    private <TValue extends Comparable<TValue>> void testIteration(
        IIterator<IDoublyLinkedListNode<TValue>> dataIterator,
        IReverseIterator<IDoublyLinkedListNode<TValue>> reverseDataIterator) {

        //
        // Create the list...
        //
        IBuilder<IDoublyLinkedList<TValue>> builder = new DoublyLinkedListStreamBuilder<>(dataIterator);
        IDoublyLinkedList<TValue> list = builder.build();

        dataIterator.reset();

        //
        // Test the default iterator of the container...
        //
        for (IDoublyLinkedListNode<TValue> currNode : list) {

            IDoublyLinkedListNode<TValue> dataNode = dataIterator.next();

            this.assertion.assertEquals(
                currNode,
                dataNode,
                "Invalid logic of default forward iteration.");
        }

        dataIterator.reset();

        //
        // Test the forward iterator of the container for nodes...
        //
        IIterator<IDoublyLinkedListNode<TValue>> iterator = list.getIterator();

        while (iterator.hasNext() && dataIterator.hasNext()) {
            IDoublyLinkedListNode<TValue> currNode = iterator.next();
            IDoublyLinkedListNode<TValue> dataNode = dataIterator.next();

            this.assertion.assertEquals(
                currNode,
                dataNode,
                "Invalid logic of forward iterator.");
        }

        dataIterator.reset();

        //
        // Test the forward iterator of the container for values...
        //
        IIterator<TValue> valueIterator = list.getValueIterator();

        while (iterator.hasNext() && dataIterator.hasNext()) {
            TValue currNode = valueIterator.next();
            TValue dataNode = dataIterator.next().getValue();

            this.assertion.assertEquals(
                currNode,
                dataNode,
                "Invalid logic of forward iterator.");
        }

        valueIterator.reset();

        //
        // Test the reverse iterator of the container for nodes...
        //
        IIterator<IDoublyLinkedListNode<TValue>> reverseIterator = list.getReverseIterator();

        while (reverseIterator.hasNext() && reverseDataIterator.hasNext()) {
            IDoublyLinkedListNode<TValue> currNode = reverseIterator.next();
            IDoublyLinkedListNode<TValue> dataNode = reverseDataIterator.next();

            this.assertion.assertEquals(
                currNode,
                dataNode,
                "Invalid logic of reverse iterator.");
        }

        reverseDataIterator.reset();

        //
        // Test the reverse iterator of the container for values...
        //
        IReverseIterator<TValue> reverseValueIterator = list.getValueReverseIterator();

        while (reverseIterator.hasNext() && reverseValueIterator.hasNext()) {
            TValue currValue = reverseValueIterator.next();
            TValue dataValue = reverseDataIterator.next().getValue();

            this.assertion.assertEquals(
                currValue,
                dataValue,
                "Invalid logic of reverse iterator.");
        }

        reverseDataIterator.reset();
    }

    /**
     * Tests the updation logic of a doubly linked list.
     */
    private <TValue extends Comparable<TValue>> void testUpdation(
        IDoublyLinkedList<TValue> list,
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
     * Tests the updation logic of a doubly linked list.
     */
    private <TValue extends Comparable<TValue>> void testUpdation(
        IDoublyLinkedList<TValue> list,
        String operation,
        TValue item,
        List<TValue> expectedContent) {

        this.updateList(list, operation, item);

        this.assertion.assertEquals(
            list.getValueIterator(),
            Iterator.of(expectedContent),
            "Invalid updation logic of a doubly linked list.");
    }

    /**
     * Updates the list.
     */
    private <TValue extends Comparable<TValue>> void updateList(
        IDoublyLinkedList<TValue> list,
        String operation,
        TValue item) {

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
