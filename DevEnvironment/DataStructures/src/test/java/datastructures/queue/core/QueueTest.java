package datastructures.queue.core;

import base.core.ListIterator;
import base.core.ListReverseIterator;
import datastructures.core.TestData;
import datastructures.queue.interfaces.IQueue;
import datastructures.queue.interfaces.IQueueData;
import testbase.core.Assertion;
import datastructures.interfaces.ITestData;
import testbase.core.IterationTest;
import testbase.interfaces.IAssertion;
import testbase.interfaces.IIterationTest;
import java.util.List;
import org.junit.Test;

/**
 * The QueueTest class implements tests for a queue.
 */
public final class QueueTest {
    private final ITestData testData = new TestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The QueueTest constructor.
     */
    public QueueTest() {
    }

    /**
     * Tests the creation logic of a queue.
     */
    @Test
    public void queueCreationTest() {
        List<IQueueData<Integer>> data = this.testData.getQueueData().getData();

        for (IQueueData<Integer> listData : data) {
            this.testCreation(listData);
        }
    }

    /**
     * Tests the iteration logic of a queue.
     */
    @Test
    public void queueIterationTest() {
        List<IQueueData<Integer>> data = this.testData.getQueueData().getData();

        for (IQueueData<Integer> listData : data) {
            this.testIteration(listData);
        }
    }

    /**
     * Tests the sizable logic of a queue.
     */
    @Test
    public void queueSizableTest() {
        List<IQueueData<Integer>> data = this.testData.getQueueData().getData();

        for (IQueueData<Integer> listData : data) {
            this.testSizable(listData);
        }
    }

    /**
     * Tests the removing logic of a queue.
     */
    @Test
    public void queueRemovingTest() {
        List<IQueueData<Integer>> data = this.testData.getQueueData().getData();

        for (IQueueData<Integer> listData : data) {
            this.testRemoving(listData);
        }
    }

    /**
     * Tests the creation logic of a queue.
     */
    private <T extends Comparable<T>> void testCreation(IQueueData<T> data) {
        //
        // Create the container...
        //
        IQueue<T> container = createQueue(data.getValues());

        //
        // Test the data of the container...
        //
        this.assertion.assertEqualsWithIterators(
            container.getIterator(),
            ListIterator.make(data.getValues()),
            "Invalid creation logic of a queue.");
    }

    /**
     * Tests the sizable logic of a queue.
     */
    private <T extends Comparable<T>> void testSizable(IQueueData<T> data) {
        //
        // Create the container...
        //
        IQueue<T> container = createQueue(data.getValues());

        //
        // Test the empty api of the container...
        //
        this.assertion.assertEquals(
            container.empty(),
            data.getValues().size() == 0,
            "Invalid empty() logic of a queue.");

        //
        // Test the size api of the container...
        //
        this.assertion.assertEquals(
            container.size(),
            data.getValues().size(),
            "Invalid size() logic of a queue.");
    }

    /**
     * Tests the removing logic of a queue.
     */
    private <T extends Comparable<T>> void testRemoving(IQueueData<T> data) {
        //
        // Create the container...
        //
        IQueue<T> container = createQueue(data.getValues());

        //
        // Test the removing api of the container...
        //
        int expectedSize = container.size();
        while (!container.empty()) {
            container.dequeue();
            --expectedSize;

            this.assertion.assertEquals(
                container.size(),
                expectedSize,
                "Invalid removing logic of a queue.");
        }
    }

    /**
     * Tests the iteration logic of a queue.
     */
    private <T extends Comparable<T>> void testIteration(IQueueData<T> data) {
        //
        // Create the container...
        //
        IQueue<T> container = createQueue(data.getValues());

        //
        // Test the default iterator of the container...
        //
        IIterationTest iterationTest = new IterationTest();
        iterationTest.testIteration(
            container,
            ListIterator.make(data.getValues()),
            "Queue");

        //
        // Test the forward iterator of the container...
        //
        iterationTest.testForwardIteration(
            container,
            ListIterator.make(data.getValues()),
            "Queue");

        //
        // Test the reverse iterator of the container...
        //
        iterationTest.testReverseIteration(
            container,
            ListReverseIterator.make(data.getValues()),
            "Queue");
    }

    /**
     * Creates a queue.
     */
    private static <T extends Comparable<T>> IQueue<T> createQueue(List<T> data) {
        IQueue<T> result = new LinkedListQueue<>();

        for (T element : data) {
            result.enqueue(element);
        }

        return result;
    }
}
