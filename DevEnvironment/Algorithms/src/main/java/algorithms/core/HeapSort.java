package algorithms.core;

import algorithms.interfaces.ISort;
import base.core.Conditions;
import base.interfaces.IBinaryComparator;
import datastructures.heap.core.Heap;
import datastructures.priorityqueue.interfaces.IPriorityQueue;

/**
 * The HeapSort class implements a heap sort.
 */
public final class HeapSort<T extends Comparable<T>> implements ISort<T> {
    private final Class<T> classType;
    private final IBinaryComparator<T> comparator;

    /**
     * The HeapSort constructor.
     */
    public HeapSort(
        Class<T> classType,
        IBinaryComparator<T> comparator) {

        Conditions.validateNotNull(
            classType,
            "The class type.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of elements.");

        this.classType = classType;
        this.comparator = comparator;
    }

    /**
     * Sorts an array.
     */
    public void sort(T[] arr) {
        Conditions.validateNotNull(
            arr,
            "The array to sort.");

        if (arr.length <= 1) {
            return;
        }

        this.heapSort(arr, 0, arr.length - 1);
    }

    /**
     * Heap sorts an array.
     */
    private void heapSort(T[] arr, int startIndex, int endIndex) {
        assert(startIndex >= 0 && startIndex < arr.length);
        assert(endIndex >= startIndex && endIndex < arr.length);

        int capacity = endIndex - startIndex + 1;
        IPriorityQueue<T> priorityQueue = Heap.createMinHeap(
            this.classType,
            capacity,
            this.comparator);

        for (int i = startIndex; i <= endIndex; ++i) {
            T currValue = arr[i];
            priorityQueue.offer(currValue);
        }

        int insertIndex = startIndex;
        while (!priorityQueue.empty()) {
            arr[insertIndex] = priorityQueue.poll();

            ++insertIndex;
        }
    }
}
