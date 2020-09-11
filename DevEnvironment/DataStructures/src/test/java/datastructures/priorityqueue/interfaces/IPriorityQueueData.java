package datastructures.priorityqueue.interfaces;

import base.interfaces.IBinaryComparator;
import java.util.List;

/**
 * The IPriorityQueueData interface defines the data of a priority queue.
 */
public interface IPriorityQueueData<T extends Comparable<T>> {
    /**
     * Gets the class type.
     */
    Class<T> getClassType();

    /**
     * Gets the comparator of an element.
     */
    IBinaryComparator<T> getElementComparator();

    /**
     * Gets the creation data of a priority queue.
     */
    List<T> getCreationData();

    /**
     * Gets the actual data of a priority queue.
     */
    List<T> getData();
}
