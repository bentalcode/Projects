package doublylinkedlist.core;

import base.core.Iterator;
import testbase.core.Assertion;
import base.core.Triple;
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
     * Tests the logic of a doubly linked list.
     */
    @Test
    public void DoublyLinkedListTest() {
        DoublyLinkedList<Integer> list = new DoublyLinkedList<>();

        List<Triple<String, Integer, List<Integer>>> data = this.testData.getDoublyLinkedListData();

        this.testDoublyLinkedList(list, data);
    }

    /**
     * Tests the logic of a doubly linked list.
     */
    private <TValue extends Comparable<TValue>> void testDoublyLinkedList(
        DoublyLinkedList<TValue> list,
        List<Triple<String, TValue,
        List<TValue>>> data) {

        for (Triple<String, TValue, List<TValue>> entry : data) {
            this.testOperation(
                list,
                entry.first(),
                entry.second(),
                entry.third());
        }
    }

    /**
     * Tests the operation logic of a doubly linked list.
     */
    private <TValue extends Comparable<TValue>> void testOperation(
        IDoublyLinkedList<TValue> list,
        String operation,
        TValue item,
        List<TValue> expectedContent) {

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

        IAssertion assertion = new Assertion();
        assertion.assertEquals(
            list.getValueIterator(),
            Iterator.of(expectedContent),
            "Invalid content of doubly linked list.");
    }
}
