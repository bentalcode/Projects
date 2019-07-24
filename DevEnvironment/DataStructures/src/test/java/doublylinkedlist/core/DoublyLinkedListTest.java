package doublylinkedlist.core;

import testbase.core.Triple;
import datastructures.collections.interfaces.IValueIterator;
import datastructures.doublylinkedlist.core.DoublyLinkedList;
import datastructures.core.TestData;
import datastructures.doublylinkedlist.core.DoublyLinkedListNode;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedList;
import datastructures.interfaces.ITestData;
import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import java.util.List;
import java.util.ListIterator;

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
    private <TValue> void testDoublyLinkedList(
        DoublyLinkedList<TValue> list,
        List<Triple<String, TValue, List<TValue>>> data) {

        for (Triple<String, TValue, List<TValue>> entry : data) {
            this.testOperation(list, entry.first(), entry.second(), entry.third());
        }
    }

    /**
     * Tests the operation logic of a doubly linked list.
     */
    private <TValue> void testOperation(
        IDoublyLinkedList<TValue> list,
        String operation,
        TValue item,
        List<TValue> expectedContent) {

        if (operation.equalsIgnoreCase("addToFront")) {
            list.addToFront(new DoublyLinkedListNode<>(item));
        }

        this.validateContent(list, expectedContent);
    }

    /**
     * Validates the content of a doubly linked list.
     */
    private <TValue> void validateContent(
        IDoublyLinkedList<TValue> list,
        List<TValue> expectedContent) {

        IValueIterator<TValue> actualValueIterator = list.getValueIterator();
        ListIterator<TValue> expectedValueIterator = expectedContent.listIterator();

        while (actualValueIterator.hasNext() && expectedValueIterator.hasNext()) {
            TValue actualValue = actualValueIterator.next();
            TValue expectedValue = expectedValueIterator.next();

            Assert.assertEquals(actualValue, expectedValue);
        }

        Assert.assertTrue(
            "Invalid content of a doubly linked list.",
            !actualValueIterator.hasNext() && !expectedValueIterator.hasNext());
    }
}
