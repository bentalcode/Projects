package datastructures.priorityqueue.core;

import base.interfaces.IBinaryComparator;
import datastructures.priorityqueue.interfaces.IPriorityQueue;

import java.util.PriorityQueue;

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
public final class Heap<TValue extends Comparable<TValue>> extends AbstractHeap<TValue> {
    /**
     * Creates a min heap.
     */
    public static <TValue extends Comparable<TValue>> IPriorityQueue<TValue> createMinHeap(Class<TValue> classType) {
        return new Heap(
            classType,
            AbstractHeap.defaultComparator(),
            base.core.Comparator.defaultComparator());
    }

    /**
     * Creates a min heap.
     */
    public static <TValue extends Comparable<TValue>> IPriorityQueue<TValue> createMinHeap(
        Class<TValue> classType,
        IBinaryComparator<IPriorityQueue<TValue>> comparator) {

        return new Heap(
            classType,
            comparator,
            base.core.Comparator.defaultComparator());
    }

    /**
     * Creates a min heap.
     */
    public static <TValue extends Comparable<TValue>> IPriorityQueue<TValue> createMinHeap(
        Class<TValue> classType,
        IBinaryComparator<IPriorityQueue<TValue>> comparator,
        IBinaryComparator<IPriorityQueue<TValue>> elementComparator) {

        return new Heap(
            classType,
            comparator,
            elementComparator);
    }

    /**
     * Creates a max heap by using the default invert comparator of an element.
     */
    public static <TValue extends Comparable<TValue>> IPriorityQueue<TValue> createMaxHeap(Class<TValue> classType) {
        return new Heap(
            classType,
            AbstractHeap.defaultComparator(),
            base.core.Comparator.defaultInvertComparator());
    }

    /**
     * Creates a max heap by using the default invert comparator of an element.
     */
    public static <TValue extends Comparable<TValue>> IPriorityQueue<TValue> createMaxHeap(
        Class<TValue> classType,
        IBinaryComparator<IPriorityQueue<TValue>> comparator) {

        return new Heap(
                classType,
                comparator,
                base.core.Comparator.defaultInvertComparator());
    }

    /**
     * Creates a max heap by inverting the specified comparator of an element.
     */
    public static <TValue extends Comparable<TValue>> IPriorityQueue<TValue> createMaxHeap(
        Class<TValue> classType,
        IBinaryComparator<IPriorityQueue<TValue>> comparator,
        IBinaryComparator<IPriorityQueue<TValue>> elementComparator) {

        return new Heap(
            classType,
            comparator,
            base.core.Comparator.invertComparator(elementComparator));
    }

    /**
     * The Heap constructor.
     */
    public Heap(
        Class<TValue> classType,
        IBinaryComparator<TValue> elementComparator) {

        this(
            classType,
            AbstractHeap.defaultComparator(),
            elementComparator);
    }

    /**
     * The Heap constructor.
     */
    public Heap(
        Class<TValue> classType,
        IBinaryComparator<IPriorityQueue<TValue>> comparator,
        IBinaryComparator<TValue> elementComparator) {

        super(
            classType,
            comparator,
            elementComparator);
    }
}
