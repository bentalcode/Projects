package datastructures.heap.core;

import base.interfaces.IBinaryComparator;
import datastructures.heap.interfaces.IHeapData;

/**
 * The HeapData class implements the data of a heap.
 */
public final class HeapData<T extends Comparable<T>> implements IHeapData<T> {
    private final Class<T> classType;
    private final int capacity;
    private final IBinaryComparator<T> elementComparator;
    private final T[] creationData;
    private final T[] data;

    /**
     * The HeapData constructor.
     */
    public HeapData(
        Class<T> classType,
        int capacity,
        IBinaryComparator<T> elementComparator,
        T[] creationData,
        T[] data) {

        this.classType = classType;
        this.capacity = capacity;
        this.elementComparator = elementComparator;
        this.creationData = creationData;
        this.data = data;
    }

    /**
     * Gets the class type.
     */
    @Override
    public Class<T> getClassType() {
        return this.classType;
    }

    /**
     * Gets the capacity.
     */
    @Override
    public int getCapacity() {
        return this.capacity;
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
    public T[] getCreationData() {
        return this.creationData;
    }

    /**
     * Gets the actual data of the heap.
     */
    @Override
    public T[] getData() {
        return this.data;
    }
}
