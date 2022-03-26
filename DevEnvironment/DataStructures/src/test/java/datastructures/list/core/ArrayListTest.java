package datastructures.list.core;

import base.core.ArrayIterator;
import base.core.Lists;
import datastructures.core.TestData;
import datastructures.interfaces.ITestData;
import datastructures.list.interfaces.IArrayList;
import datastructures.list.interfaces.IList;
import datastructures.list.interfaces.IListData;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

/**
 * The ArrayListTest class implements tests for an array list.
 */
public final class ArrayListTest {
    private final ITestData testData = new TestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The ArrayListTest constructor.
     */
    public ArrayListTest() {
    }

    /**
     * Tests the creation logic of a list.
     */
    @Test
    public void listCreationTest() {
        for (IListData<Integer> data : this.testData.getListData().getData()) {
            this.testCreation(data);
        }
    }

    /**
     * Tests the creation and removal logic of a list.
     */
    @Test
    public void listCreationAndRemovalTest() {
        for (IListData<Integer> data : this.testData.getListData().getData()) {
            this.testCreationWithRemoval(data);
        }
    }

    /**
     * Tests the creation logic of a list.
     */
    private <T extends Comparable<T>> void testCreation(IListData<T> data) {
        IList<T> list = this.createArrayList(data);

        this.assertion.assertEqualsWithIterators(
            list.getIterator(),
            base.core.ListIterator.make(data.getData()),
            "Invalid creation logic of a list.");

        this.assertion.assertEqualsWithIterators(
            list.getIterator(),
            ArrayIterator.make(list.toArray()),
            "Invalid creation logic of a list.");
    }

    /**
     * Tests the creation and removal logic of a list.
     */
    private <T extends Comparable<T>> void testCreationWithRemoval(IListData<T> data) {
        IList<T> list = this.createArrayList(data);

        this.assertion.assertEqualsWithIterators(
            list.getIterator(),
            base.core.ListIterator.make(data.getData()),
            "Invalid creation logic of a list.");

        java.util.List<T> values = Lists.fromIterator(list.getIterator());

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
     * Creates an array list.
     */
    private <T extends Comparable<T>> IArrayList<T> createArrayList(IListData<T> data) {
        IArrayList<T> list = new ArrayList<>(data.getClassType());

        for (T item : data.getCreationData()) {
            list.add(item);
        }

        return list;
    }
}
