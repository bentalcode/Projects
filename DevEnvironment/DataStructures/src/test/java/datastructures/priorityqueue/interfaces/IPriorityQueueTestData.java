package datastructures.priorityqueue.interfaces;

import java.util.List;

/**
 * The IPriorityQueueTestData interface defines the data of the tests of a priority queue.
 */
public interface IPriorityQueueTestData {
    /**
     * Gets data of the tests of a priority queue.
     */
    List<IPriorityQueueData<Integer>> getData();
}
