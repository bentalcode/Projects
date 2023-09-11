package datastructures.queue.interfaces;

import java.util.List;

/**
 * The IQueueData interface defines the data of a queue.
 */
public interface IQueueData<T extends Comparable<T>> {
    /**
     * Gets the values of the queue.
     */
    List<T> getValues();
}
