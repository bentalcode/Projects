package datastructures.priorityqueue.core;

import base.interfaces.IBinaryComparator;
import datastructures.priorityqueue.interfaces.IPriorityQueueData;
import java.util.List;

/**
 * The PriorityQueueData class implements the data of a priority queue.
 */
public final class PriorityQueueData<TValue extends Comparable<TValue>> implements IPriorityQueueData<TValue> {
    private final Class<TValue> classType;
    private final IBinaryComparator<TValue> elementComparator;
    private final List<TValue> creationData;
    private final List<TValue> data;

    /**
     * The PriorityQueueData constructor.
     */
    public PriorityQueueData(
        Class<TValue> classType,
        IBinaryComparator<TValue> elementComparator,
        List<TValue> creationData,
        List<TValue> data) {

        this.classType = classType;
        this.elementComparator = elementComparator;
        this.creationData = creationData;
        this.data = data;
    }

    /**
     * Gets the class type.
     */
    public Class<TValue> getClassType() {
        return this.classType;
    }

    /**
     * Gets the comparator of an element.
     */
    @Override
    public IBinaryComparator<TValue> getElementComparator() {
        return this.elementComparator;
    }

    /**
     * Gets the creation data.
     */
    @Override
    public List<TValue> getCreationData() {
        return this.creationData;
    }

    /**
     * Gets the actual data of the priority queue.
     */
    @Override
    public List<TValue> getData() {
        return this.data;
    }
}
