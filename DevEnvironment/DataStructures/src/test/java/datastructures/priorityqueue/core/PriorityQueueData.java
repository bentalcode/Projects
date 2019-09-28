package datastructures.priorityqueue.core;

import base.interfaces.IBinaryComparator;
import datastructures.priorityqueue.interfaces.IPriorityQueueData;
import java.util.List;

/**
 * The PriorityQueueData class implements the data of a priority queue.
 */
public final class PriorityQueueData<T extends Comparable<T>> implements IPriorityQueueData<T> {
    private final Class<T> classType;
    private final IBinaryComparator<T> elementComparator;
    private final List<T> creationData;
    private final List<T> data;

    /**
     * The PriorityQueueData constructor.
     */
    public PriorityQueueData(
        Class<T> classType,
        IBinaryComparator<T> elementComparator,
        List<T> creationData,
        List<T> data) {

        this.classType = classType;
        this.elementComparator = elementComparator;
        this.creationData = creationData;
        this.data = data;
    }

    /**
     * Gets the class type.
     */
    public Class<T> getClassType() {
        return this.classType;
    }

    /**
     * Gets the comparator of an element.
     */
    @Override
    public IBinaryComparator<T> getElementComparator() {
        return this.elementComparator;
    }

    /**
     * Gets the creation data.
     */
    @Override
    public List<T> getCreationData() {
        return this.creationData;
    }

    /**
     * Gets the actual data of the priority queue.
     */
    @Override
    public List<T> getData() {
        return this.data;
    }
}
