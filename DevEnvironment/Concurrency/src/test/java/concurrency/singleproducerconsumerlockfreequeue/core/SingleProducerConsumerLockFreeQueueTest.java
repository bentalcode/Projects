package concurrency.singleproducerconsumerlockfreequeue.core;

import base.core.ListIterator;
import base.interfaces.IIterator;
import base.interfaces.IReceiver;
import concurrency.interfaces.IConcurrentQueue;
import concurrency.interfaces.IMessageQueueTrackingInformation;
import java.util.ArrayList;
import java.util.List;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.core.CollectionValues;
import testbase.interfaces.IAssertion;

/**
 * The SingleProducerConsumerLockFreeQueueTest class implements tests
 * for a lock free single producer consumer queue.
 */
public final class SingleProducerConsumerLockFreeQueueTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The LockFreeSingleProducerConsumerQueueTest constructor.
     */
    public SingleProducerConsumerLockFreeQueueTest() {
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
     * Tests the logic of a single producer-consumer circular buffer queue.
     */
    @Test
    public void singleProducerConsumerCircularBufferQueueTest() {
        for (int size = 1; size <= 100; ++size) {
            int capacity = size;
            List<Integer> values = CollectionValues.createListValues(size);
            this.testSingleProducerConsumerCircularBufferQueue(Integer.class, values, capacity);
        }
    }

    /**
     * Tests the logic of a single producer-consumer circular buffer queue with a fixed capacity.
     */
    @Test
    public void singleProducerConsumerCircularBufferQueueWithFixedCapacityTest() {
        int capacity = 10;

        for (int size = 1; size <= 100; ++size) {
            List<Integer> values = CollectionValues.createListValues(size);
            this.testSingleProducerConsumerCircularBufferQueue(Integer.class, values, capacity);
        }
    }

    /**
     * Tests the logic of a single producer-consumer circular buffer queue.
     */
    private <T extends Comparable<T>> void testSingleProducerConsumerCircularBufferQueue(
        Class<T> classType,
        List<T> data,
        int capacity) {

        IConcurrentQueue<T> queue = new SingleProducerConsumerCircularBufferQueue<>(classType, capacity);
        IMessageQueueTrackingInformation messageQueueTrackingInformation = new MessageQueueTrackingInformation();

        ConcurrentSingleProducerConsumerCircularBufferQueue<T> concurrentQueue =
            ConcurrentSingleProducerConsumerCircularBufferQueue.make(
                queue,
                messageQueueTrackingInformation);

        IIterator<T> dataIterator = ListIterator.make(data);

        int numberOfElements = data.size();
        List<T> receivedData = new ArrayList<>(numberOfElements);

        IReceiver<T> receiver = new IReceiver<T>() {
            @Override
            public void receive(T element) {
                receivedData.add(element);
            }
        };

        concurrentQueue.publish(dataIterator);
        concurrentQueue.subscribe(receiver);

        synchronized (messageQueueTrackingInformation) {
            while (messageQueueTrackingInformation.numberOfMessagesPublished() < numberOfElements ||
                    messageQueueTrackingInformation.numberOfMessagesReceived() < numberOfElements) {
                try {
                    messageQueueTrackingInformation.wait();
                }
                catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }

        concurrentQueue.shutdown();

        this.assertion.assertEqualsWithIterators(
            ListIterator.make(data),
            ListIterator.make(receivedData),
            "Incorrect logic of single producer and consumer.");
    }
}
