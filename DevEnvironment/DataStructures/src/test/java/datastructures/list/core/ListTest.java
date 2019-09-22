package datastructures.list.core;

import base.core.ArrayIterator;
import base.core.Lists;
import datastructures.core.TestData;
import datastructures.interfaces.ITestData;
import datastructures.list.interfaces.IList;
import datastructures.list.interfaces.IListData;
import java.util.List;

import datastructures.priorityqueue.core.Heap;
import datastructures.priorityqueue.interfaces.IPriorityQueue;
import datastructures.priorityqueue.interfaces.IPriorityQueueData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

/**
 * The ListTest class implements tests for a hash map.
 */
public final class ListTest {
    private final ITestData testData = new TestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The ListTest constructor.
     */
    public ListTest() {
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
     * Tests the creation logic of a list.
     */
    @Test
    public void ListCreationTest() {
        for (IListData<Integer> data : this.testData.getListData().getData()) {
            this.testCreation(data);
        }
    }

    /**
     * Tests the creation and removal logic of a list.
     */
    @Test
    public void ListCreationAndRemovalTest() {
        for (IListData<Integer> data : this.testData.getListData().getData()) {
            this.testCreationWithRemoval(data);
        }
    }

    /**
     * Tests the creation logic of a list.
     */
    private <TValue extends Comparable<TValue>> void testCreation(IListData<TValue> data) {
        IList<TValue> list = this.createList(data);

        this.assertion.assertEquals(
            list.getIterator(),
            base.core.ListIterator.of(data.getData()),
            "Invalid creation logic of a list.");

        this.assertion.assertEquals(
            list.getIterator(),
            ArrayIterator.of(list.toArray()),
            "Invalid creation logic of a list.");
    }

    /**
     * Tests the creation and removal logic of a list.
     */
    private <TValue extends Comparable<TValue>> void testCreationWithRemoval(IListData<TValue> data) {
        IList<TValue> list = this.createList(data);

        this.assertion.assertEquals(
            list.getIterator(),
            base.core.ListIterator.of(data.getData()),
            "Invalid creation logic of a list.");

        List<TValue> values = Lists.fromIterator(list.getIterator());

        int index = 0;
        int currSize = values.size();

        for (TValue valueToRemove : values) {
            TValue removedValue = list.remove(index);
            --currSize;

            this.assertion.assertEquals(
                removedValue,
                valueToRemove,
                "Invalid remove logic of list: invalid removed value.");

            this.assertion.assertTrue(
                list.size() == currSize,
                "Invalid remove logic of list: invalid size.");
        }
    }

    /**
     * Creates a list.
     */
    private <TValue extends Comparable<TValue>> IList<TValue> createList(IListData<TValue> data) {
        IList<TValue> list = new ArrayList<>(data.getClassType());

        for (TValue item : data.getCreationData()) {
            list.add(item);
        }

        return list;
    }
}
