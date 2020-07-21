package datastructures.heap.core;

import base.interfaces.IBinaryComparator;
import datastructures.priorityqueue.interfaces.IPriorityQueue;

/**
 * The Heap class implements a heap.
 * In a priority queue, an element with high priority is served before an element with low priority.
 */
public final class Heap<T extends Comparable<T>> extends AbstractHeap<T> {
    /**
     * Creates a min heap with an initial capacity.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMinHeap(
        Class<?> classType,
        int capacity) {

        return new Heap<T>(
            classType,
            capacity,
            base.core.Comparator.defaultComparator(),
            AbstractHeap.defaultComparator());
    }

    /**
     * Creates a min heap with an initial capacity.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMinHeap(
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
     * Creates a min heap with an initial capacity.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMinHeap(
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
     * Creates a min heap with an initial data.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMinHeap(T[] data) {
        return new Heap<>(
            data,
            base.core.Comparator.defaultComparator(),
            AbstractHeap.defaultComparator());
    }

    /**
     * Creates a min heap with an initial data.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMinHeap(
        T[] data,
        IBinaryComparator<T> elementComparator) {

        return new Heap<>(
            data,
            elementComparator,
            AbstractHeap.defaultComparator());
    }

    /**
     * Creates a min heap with an initial data.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMinHeap(
        T[] data,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        return new Heap<>(
            data,
            elementComparator,
            comparator);
    }

    /**
     * Creates a max heap with an initial capacity by using the default invert comparator of an element.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMaxHeap(
        Class<?> classType,
        int capacity) {

        return new Heap<T>(
            classType,
            capacity,
            base.core.Comparator.defaultInvertComparator(),
            AbstractHeap.defaultComparator());
    }

    /**
     * Creates a max heap with an initial capacity by using the default invert comparator of an element.
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
     * Creates a max heap with an initial capacity by inverting the specified comparator of an element.
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
     * Creates a max heap with an initial data by using the default invert comparator of an element.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMaxHeap(T[] data) {
        return new Heap<>(
            data,
            base.core.Comparator.defaultInvertComparator(),
            AbstractHeap.defaultComparator());
    }

    /**
     * Creates a max heap with an initial data by using the default invert comparator of an element.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMaxHeap(
        T[] data,
        IBinaryComparator<T> elementComparator) {

        return new Heap<>(
            data,
            base.core.Comparator.invertComparator(elementComparator),
            AbstractHeap.defaultComparator());
    }

    /**
     * Creates a max heap with an initial data by inverting the specified comparator of an element.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMaxHeap(
        T[] data,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        return new Heap<>(
            data,
            base.core.Comparator.invertComparator(elementComparator),
            comparator);
    }

    /**
     * The Heap constructor with an initial capacity.
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
     * The Heap constructor with an initial capacity.
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
     * The Heap constructor with an initial capacity.
     */
    public Heap(
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
    public Heap(T[] data) {
        super(
            data,
            base.core.Comparator.defaultComparator(),
            AbstractHeap.defaultComparator());
    }

    /**
     * The Heap constructor with an initial data.
     */
    public Heap(
        T[] data,
        IBinaryComparator<T> elementComparator) {

        super(
            data,
            elementComparator,
            AbstractHeap.defaultComparator());
    }

    /**
     * The Heap constructor with an initial data.
     */
    public Heap(
        T[] data,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        super(
            data,
            elementComparator,
            comparator);
    }

    /**
     * The Heap constructor with an initial data.
     */
    public Heap(
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

    /**
     * Copies the priority queue.
     */
    @Override
    public IPriorityQueue<T> copy() {
        return new Heap(
            this.getData(),
            this.size(),
            this.getElementComparator(),
            this.getComparator());
    }
}
