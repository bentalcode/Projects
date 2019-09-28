package datastructures.list.core;

import base.core.ArrayIterator;
import base.core.Lists;
import datastructures.core.TestData;
import datastructures.interfaces.ITestData;
import datastructures.list.interfaces.IList;
import datastructures.list.interfaces.IListData;
import java.util.List;
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
    private <T extends Comparable<T>> void testCreation(IListData<T> data) {
        IList<T> list = this.createList(data);

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
    private <T extends Comparable<T>> void testCreationWithRemoval(IListData<T> data) {
        IList<T> list = this.createList(data);

        this.assertion.assertEquals(
            list.getIterator(),
            base.core.ListIterator.of(data.getData()),
            "Invalid creation logic of a list.");

        List<T> values = Lists.fromIterator(list.getIterator());

        int currIndex = 0;
        int currSize = values.size();

        for (T valueToRemove : values) {
            T removedValue = list.remove(currIndex);
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
    private <T extends Comparable<T>> IList<T> createList(IListData<T> data) {
        IList<T> list = new ArrayList<>(data.getClassType());

        for (T item : data.getCreationData()) {
            list.add(item);
        }

        return list;
    }
}
