package datastructures.priorityqueue.core;

import base.core.ListIterator;
import datastructures.core.TestData;
import datastructures.interfaces.ITestData;
import datastructures.priorityqueue.interfaces.IPriorityQueue;
import datastructures.priorityqueue.interfaces.IPriorityQueueData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

/**
 * The PriorityQueueTest class implements tests for a priority queue.
 */
public final class PriorityQueueTest {
    private final ITestData testData = new TestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The PriorityQueueTest constructor.
     */
    public PriorityQueueTest() {
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
     * Tests the creation logic of a priority queue.
     */
    @Test
    public void priorityQueueCreationTest() {
        for (IPriorityQueueData<Integer> data : this.testData.getPriorityQueueData().getData()) {
            this.testCreation(data);
        }
    }

    /**
     * Tests the creation and removal logic of a priority queue.
     */
    @Test
    public void listCreationAndRemovalTest() {
        for (IPriorityQueueData<Integer> data : this.testData.getPriorityQueueData().getData()) {
            this.testCreationWithRemoval(data);
        }
    }

    /**
     * Tests the creation logic of a priority queue.
     */
    private <T extends Comparable<T>> void testCreation(IPriorityQueueData<T> data) {
        IPriorityQueue<T> priorityQueue = this.createPriorityQueue(data);

        this.assertion.assertEqualsWithIterators(
            priorityQueue.getIterator(),
            ListIterator.of(data.getData()),
            "Invalid creation logic of a priority queue.");
    }

    /**
     * Tests the creation and removal logic of a priority queue.
     */
    private <T extends Comparable<T>> void testCreationWithRemoval(IPriorityQueueData<T> data) {
        IPriorityQueue<T> priorityQueue = this.createPriorityQueue(data);

        this.assertion.assertEqualsWithIterators(
            priorityQueue.getIterator(),
            ListIterator.of(data.getData()),
            "Invalid creation logic of a priority queue.");

        int currSize = priorityQueue.size();

        while (!priorityQueue.empty()) {
            T valueToRemove = priorityQueue.peek();
            T removedValue = priorityQueue.poll();
            --currSize;

            this.assertion.assertEquals(
                removedValue,
                valueToRemove,
                "Invalid remove logic of a priority queue: invalid removed value.");

            this.assertion.assertTrue(
                priorityQueue.size() == currSize,
                "Invalid remove logic of a priority queue: invalid size.");
        }
    }

    /**
     * Creates a priority queue.
     */
    private <T extends Comparable<T>> IPriorityQueue<T> createPriorityQueue(
        IPriorityQueueData<T> data) {

        IPriorityQueue<T> priorityQueue = new PriorityQueue<>(
            data.getClassType(),
            data.getElementComparator());

        for (T item : data.getCreationData()) {
            priorityQueue.offer(item);
        }

        return priorityQueue;
    }
}
