package datastructures.priorityqueue.interfaces;

import base.interfaces.IBinaryComparator;
import java.util.List;

/**
 * The IPriorityQueueData interface defines the data of a priority queue.
 */
public interface IPriorityQueueData<TValue extends Comparable<TValue>> {
    /**
     * Gets the class type.
     */
    Class<TValue> getClassType();

    /**
     * Gets the comparator of an element.
     */
    IBinaryComparator<TValue> getElementComparator();

    /**
     * Gets the creation data.
     */
    List<TValue> getCreationData();

    /**
     * Gets the actual data of the priority queue.
     */
    List<TValue> getData();
}
