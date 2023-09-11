package datastructures.heap.core;

import base.core.ArrayIterator;
import datastructures.core.TestData;
import datastructures.heap.interfaces.IHeapData;
import datastructures.interfaces.ITestData;
import datastructures.priorityqueue.interfaces.IPriorityQueue;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The HeapTest class implements tests for a heap.
 */
public final class HeapTest {
    private final ITestData testData = new TestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The HeapTest constructor.
     */
    public HeapTest() {
    }

    /**
     * Tests the creation logic of a heap.
     */
    @Test
    public void heapCreationTest() {
        for (IHeapData<Integer> data : this.testData.getHeapData().getData()) {
            this.testCreation(data);
        }
    }

    /**
     * Tests the creation and removal logic of a heap.
     */
    @Test
    public void listCreationAndRemovalTest() {
        for (IHeapData<Integer> data : this.testData.getHeapData().getData()) {
            this.testCreationWithRemoval(data);
        }
    }

    /**
     * Tests the creation logic of a heap.
     */
    private <T extends Comparable<T>> void testCreation(IHeapData<T> data) {
        IPriorityQueue<T> heap = this.createHeap(data);

        this.assertion.assertEqualsWithIterators(
            heap.getIterator(),
            ArrayIterator.make(data.getData()),
            "Invalid creation logic of a heap.");
    }

    /**
     * Tests the creation and removal logic of a heap.
     */
    private <T extends Comparable<T>> void testCreationWithRemoval(IHeapData<T> data) {
        IPriorityQueue<T> heap = this.createHeap(data);

        this.assertion.assertEqualsWithIterators(
            heap.getIterator(),
            ArrayIterator.make(data.getData()),
            "Invalid creation logic of a heap.");

        int currSize = heap.size();

        while (!heap.empty()) {
            T valueToRemove = heap.peek();
            T removedValue = heap.poll();
            --currSize;

            this.assertion.assertEquals(
                removedValue,
                valueToRemove,
                "Invalid remove logic of a heap: invalid removed value.");

            this.assertion.assertTrue(
                heap.size() == currSize,
                "Invalid remove logic of a heap: invalid size.");
        }
    }

    /**
     * Creates a heap.
     */
    private <T extends Comparable<T>> IPriorityQueue<T> createHeap(IHeapData<T> data) {
        IPriorityQueue<T> heap;

        if (data.getCreationData().length == 0) {
            heap = Heap.make(
                data.getClassType(),
                data.getCapacity(),
                data.getElementComparator());
        }
        else {
            heap = Heap.make(
                data.getCreationData(),
                data.getElementComparator());
        }

        return heap;
    }
}
