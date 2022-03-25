package datastructures.queue.core;

import datastructures.queue.interfaces.IQueueData;
import datastructures.queue.interfaces.IQueueTestData;
import java.util.ArrayList;
import java.util.List;
import testbase.core.CollectionValues;

/**
 * The QueueTestData class implements data of tests of a queue.
 */
public final class QueueTestData implements IQueueTestData {
    /**
     * The QueueTestData constructor.
     */
    public QueueTestData() {
    }

    /**
     * Gets the data of queues.
     */
    @Override
    public List<IQueueData<Integer>> getData() {
        List<IQueueData<Integer>> data = new ArrayList<>();

        data.add(this.getQueueData(0));
        data.add(this.getQueueData(50));
        data.add(this.getQueueData(100));

        return data;
    }

    /**
     * Gets the data of a queue.
     */
    private IQueueData<Integer> getQueueData(int size) {
        List<Integer> values = CollectionValues.createListValues(size);
        return new QueueData<>(values);
    }
}
