package datastructures.priorityqueue.core;

import base.interfaces.IBinaryComparator;
import datastructures.priorityqueue.interfaces.IPriorityQueue;

/**
 * The Heap class implements a heap.
 *
 * A binary heap is a complete binary tree which satisfies the heap ordering property.
 * The ordering can be one of two types:
 *
 * The min-heap property: The value of each node is greater than or equal to the value of its parent,
 * with the minimum-value element at the root.
 *
 * The max-heap property: The value of each node is less than or equal to the value of its parent,
 * with the maximum-value element at the root.
 *
 */
public final class Heap<T extends Comparable<T>> extends AbstractHeap<T> {
    /**
     * Creates a min heap.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMinHeap(Class<T> classType) {
        return new Heap<>(
            classType,
            AbstractHeap.defaultComparator(),
            base.core.Comparator.defaultComparator());
    }

    /**
     * Creates a min heap.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMinHeap(
        Class<T> classType,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        return new Heap<>(
            classType,
            comparator,
            base.core.Comparator.defaultComparator());
    }

    /**
     * Creates a min heap.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMinHeap(
        Class<T> classType,
        IBinaryComparator<IPriorityQueue<T>> comparator,
        IBinaryComparator<T> elementComparator) {

        return new Heap<>(
            classType,
            comparator,
            elementComparator);
    }

    /**
     * Creates a max heap by using the default invert comparator of an element.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMaxHeap(Class<T> classType) {
        return new Heap<>(
            classType,
            AbstractHeap.defaultComparator(),
            base.core.Comparator.defaultInvertComparator());
    }

    /**
     * Creates a max heap by using the default invert comparator of an element.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMaxHeap(
        Class<T> classType,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        return new Heap<>(
            classType,
            comparator,
            base.core.Comparator.defaultInvertComparator());
    }

    /**
     * Creates a max heap by inverting the specified comparator of an element.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMaxHeap(
        Class<T> classType,
        IBinaryComparator<IPriorityQueue<T>> comparator,
        IBinaryComparator<T> elementComparator) {

        return new Heap<>(
            classType,
            comparator,
            base.core.Comparator.invertComparator(elementComparator));
    }

    /**
     * The Heap constructor.
     */
    public Heap(
        Class<T> classType,
        IBinaryComparator<T> elementComparator) {

        this(
            classType,
            AbstractHeap.defaultComparator(),
            elementComparator);
    }

    /**
     * The Heap constructor.
     */
    public Heap(
        Class<T> classType,
        IBinaryComparator<IPriorityQueue<T>> comparator,
        IBinaryComparator<T> elementComparator) {

        super(
            classType,
            comparator,
            elementComparator);
    }
}
