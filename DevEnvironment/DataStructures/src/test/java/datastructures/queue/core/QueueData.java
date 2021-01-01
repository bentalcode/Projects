package datastructures.queue.core;

import datastructures.queue.interfaces.IQueueData;
import java.util.List;

/**
 * The QueueData class implements the data of a queue.
 */
public final class QueueData<T extends Comparable<T>> implements IQueueData<T> {
    private final List<T> values;

    /**
     * The QueueData constructor.
     */
    public QueueData(List<T> values) {
        this.values = values;
    }

    /**
     * Gets the values of the queue.
     */
    @Override
    public List<T> getValues() {
        return this.values;
    }
}
