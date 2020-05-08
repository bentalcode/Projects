package datastructures.heap.interfaces;

import base.interfaces.IBinaryComparator;

/**
 * The IHeapData interface defines the data of a heap.
 */
public interface IHeapData<T extends Comparable<T>> {
    /**
     * Gets the class type.
     */
    Class<T> getClassType();

    /**
     * Gets the capacity.
     */
    int getCapacity();

    /**
     * Gets the comparator of an element.
     */
    IBinaryComparator<T> getElementComparator();

    /**
     * Gets the creation data.
     */
    T[] getCreationData();

    /**
     * Gets the actual data of the heap.
     */
    T[] getData();
}
