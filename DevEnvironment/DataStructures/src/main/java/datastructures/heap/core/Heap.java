package datastructures.heap.core;

import base.interfaces.IBinaryComparator;
import datastructures.priorityqueue.interfaces.IPriorityQueue;

/**
 * The Heap class implements a heap.
 * In a priority queue, an element with high priority is served before an element with low priority.
 */
public final class Heap<T extends Comparable<T>> extends AbstractHeap<T> {
    /**
     * Creates a min heap.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMinHeap(
        Class<T> classType,
        int capacity) {
        return new Heap<>(
            classType,
            capacity,
            base.core.Comparator.defaultComparator(),
            AbstractHeap.defaultComparator());
    }

    /**
     * Creates a min heap.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMinHeap(
        Class<T> classType,
        int capacity,
        IBinaryComparator<T> elementComparator) {

        return new Heap<>(
            classType,
            capacity,
            elementComparator,
            AbstractHeap.defaultComparator());
    }

    /**
     * Creates a min heap.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMinHeap(
        Class<T> classType,
        int capacity,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        return new Heap<>(
            classType,
            capacity,
            elementComparator,
            comparator);
    }

    /**
     * Creates a max heap by using the default invert comparator of an element.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMaxHeap(
        Class<T> classType,
        int capacity) {

        return new Heap<>(
            classType,
            capacity,
            base.core.Comparator.defaultInvertComparator(),
            AbstractHeap.defaultComparator());
    }

    /**
     * Creates a max heap by using the default invert comparator of an element.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMaxHeap(
        Class<T> classType,
        int capacity,
        IBinaryComparator<T> elementComparator) {

        return new Heap<>(
            classType,
            capacity,
            base.core.Comparator.invertComparator(elementComparator),
            AbstractHeap.defaultComparator());
    }

    /**
     * Creates a max heap by inverting the specified comparator of an element.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMaxHeap(
        Class<T> classType,
        int capacity,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        return new Heap<>(
            classType,
            capacity,
            base.core.Comparator.invertComparator(elementComparator),
            comparator);
    }

    /**
     * The Heap constructor.
     */
    public Heap(
        Class<T> classType,
        int capacity) {
        super(
            classType,
            capacity,
            base.core.Comparator.defaultComparator(),
            AbstractHeap.defaultComparator());
    }
    
    /**
     * The Heap constructor.
     */
    public Heap(
        Class<T> classType,
        int capacity,
        IBinaryComparator<T> elementComparator) {

        super(
            classType,
            capacity,
            elementComparator,
            AbstractHeap.defaultComparator());
    }
    
    /**
     * The Heap constructor.
     */
    public Heap(
        Class<T> classType,
        int capacity,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        super(
            classType,
            capacity,
            elementComparator,
            comparator);
    }
}
