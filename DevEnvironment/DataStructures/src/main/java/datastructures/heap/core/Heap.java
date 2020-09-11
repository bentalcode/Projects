package datastructures.heap.core;

import base.interfaces.IBinaryComparator;
import datastructures.priorityqueue.interfaces.IPriorityQueue;

/**
 * The Heap class implements a heap.
 * In a priority queue, an element with high priority is served before an element with low priority.
 */
public final class Heap<T extends Comparable<T>> extends AbstractHeap<T> {
    /**
     * Creates a heap with an initial capacity.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> make(
        Class<?> classType,
        int capacity) {

        return new Heap<T>(
            classType,
            capacity,
            base.core.Comparator.make(),
            AbstractHeap.defaultComparator());
    }

    /**
     * Creates a heap with an initial capacity and an element comparator.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> make(
        Class<?> classType,
        int capacity,
        IBinaryComparator<T> elementComparator) {

        return new Heap<>(
            classType,
            capacity,
            elementComparator,
            AbstractHeap.defaultComparator());
    }

    /**
     * Creates a heap with an initial capacity, an element comparator and a comparator.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> make(
        Class<?> classType,
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
     * Creates a heap with an initial data.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> make(T[] data) {
        return new Heap<>(
            data,
            data != null ? data.length : 0,
            base.core.Comparator.make(),
            AbstractHeap.defaultComparator());
    }

    /**
     * Creates a heap with an initial data and an element comparator.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> make(
        T[] data,
        IBinaryComparator<T> elementComparator) {

        return new Heap<>(
            data,
            data != null ? data.length : 0,
            elementComparator,
            AbstractHeap.defaultComparator());
    }

    /**
     * Creates a heap with an initial data, an element comparator and a comparator
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> make(
        T[] data,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        return new Heap<>(
            data,
            data != null ? data.length : 0,
            elementComparator,
            comparator);
    }

    /**
     * The Heap constructor with an initial capacity.
     */
    private Heap(
        Class<?> classType,
        int capacity,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        super(
            classType,
            capacity,
            elementComparator,
            comparator);
    }

    /**
     * The Heap constructor with an initial data.
     */
    private Heap(
        T[] data,
        int size,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        super(
            data,
            size,
            elementComparator,
            comparator);
    }
}
