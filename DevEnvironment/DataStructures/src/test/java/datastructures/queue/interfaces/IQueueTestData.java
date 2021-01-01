package datastructures.queue.interfaces;

import java.util.List;

/**
 * The IQueueTestData interface defines the data of the queue.
 */
public interface IQueueTestData {
    /**
     * Gets the data of queues.
     */
    List<IQueueData<Integer>> getData();
}
