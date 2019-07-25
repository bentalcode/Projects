package doublylinkedlist.core;

import base.core.Iterator;
import base.interfaces.IIterator;
import base.interfaces.ITriple;
import datastructures.collections.interfaces.IKeyIterator;
import datastructures.collections.interfaces.IValueIterator;
import datastructures.collections.interfaces.IValueReverseIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNodeIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNodeReverseIterator;
import datastructures.node.interfaces.IKeyValueNode;
import datastructures.node.interfaces.IKeyValueNodeIterator;
import testbase.core.Assertion;
import datastructures.doublylinkedlist.core.DoublyLinkedList;
import datastructures.core.TestData;
import datastructures.doublylinkedlist.core.DoublyLinkedListNode;
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
    private final IAssertion assertion = new Assertion();
    private final ITestData testData = new TestData();

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
     * Tests the updation logic of a doubly linked list.
     */
    @Test
    public void DoublyLinkedListUpdationTest() {
        IDoublyLinkedList<Integer> list = new DoublyLinkedList<>();

        List<ITriple<String, Integer, List<Integer>>> data = this.testData.getDoublyLinkedListData();

        this.testUpdation(list, data);
    }

    /**
     * Tests the iteration logic of a doubly linked list.
     */
    @Test
    public void DoublyLinkedListIterationTest() {
        IDoublyLinkedList<Integer> list = new DoublyLinkedList<>();

        List<ITriple<String, Integer, List<Integer>>> data = this.testData.getDoublyLinkedListData();

        this.testIteration(list, data);
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
     * Tests the iteration logic of a doubly linked list.
     */
    private <TValue extends Comparable<TValue>> void testIteration(
        IDoublyLinkedList<TValue> list,
        List<ITriple<String, TValue, List<TValue>>> data) {

        for (ITriple<String, TValue, List<TValue>> entry : data) {
            this.testIteration(
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
     * Tests the iteration logic of a doubly linked list.
     */
    private <TValue extends Comparable<TValue>> void testIteration(
        IDoublyLinkedList<TValue> list,
        String operation,
        TValue item,
        List<TValue> expectedContent) {

        //
        // Update the data of the list...
        //
        this.updateList(list, operation, item);

        //
        // Test the default iterator of the container...
        //
        int index = 0;

        for (IDoublyLinkedListNode<TValue> node : list) {
            this.assertion.assertEquals(
                node.getValue(),
                expectedContent.get(index),
                "Invalid logic of default forward iteration over nodes.");

            ++index;
        }

        //
        // Test the forward iterator over nodes...
        //
        IIterator<IDoublyLinkedListNode<TValue>> nodeIterator = list.getIterator();
        index = 0;

        while (nodeIterator.hasNext()) {
            IDoublyLinkedListNode<TValue> node = nodeIterator.next();

            this.assertion.assertEquals(
                node.getValue(),
                expectedContent.get(index),
                "Invalid logic of forward iteration over nodes.");

            ++index;
        }

        //
        // Test the forward iterator over values...
        //
        IValueIterator<TValue> valueIterator = list.getValueIterator();
        index = 0;

        while (valueIterator.hasNext()) {
            TValue value = valueIterator.next();

            this.assertion.assertEquals(
                value,
                expectedContent.get(index),
                "Invalid logic of forward iteration over values.");

            ++index;
        }

        //
        // Test the reverse iterator over nodes...
        //
        IDoublyLinkedListNodeReverseIterator<TValue> nodeReverseIterator = list.getReverseIterator();
        index = expectedContent.size() - 1;

        while (nodeIterator.hasNext()) {
            IDoublyLinkedListNode<TValue> node = nodeReverseIterator.next();

            this.assertion.assertEquals(
                node.getValue(),
                expectedContent.get(index),
                "Invalid logic of reverse iteration over nodes.");

            --index;
        }

        //
        // Test the reverse iterator over values...
        //
        IValueReverseIterator<TValue> valueReverseIterator = list.getValueReverseIterator();
        index = expectedContent.size() - 1;

        while (valueIterator.hasNext()) {
            TValue value = valueReverseIterator.next();

            this.assertion.assertEquals(
                value,
                expectedContent.get(index),
                "Invalid logic of reverse iteration over values.");

            --index;
        }
    }

    /**
     * Updates the list.
     */
    private <TValue extends Comparable<TValue>> void updateList(
        IDoublyLinkedList<TValue> list,
        String operation,
        TValue item) {

        if (operation.equalsIgnoreCase("addToFront")) {
            list.addToFront(new DoublyLinkedListNode<>(item));
        }
        else if (operation.equalsIgnoreCase("addToBack")) {
            list.addToBack(new DoublyLinkedListNode<>(item));
        }
        else if (operation.equalsIgnoreCase("removeFromFront")) {
            list.removeFromFront();
        }
        else if (operation.equalsIgnoreCase("removeFromBack")) {
            list.removeFromBack();
        }
    }
}
