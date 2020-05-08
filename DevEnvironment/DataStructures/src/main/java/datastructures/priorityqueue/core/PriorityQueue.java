package datastructures.priorityqueue.core;

import base.interfaces.IBinaryComparator;
import datastructures.priorityqueue.interfaces.IPriorityQueue;

/**
 * The PriorityQueue class implements a priority queue.
 * In a priority queue, an element with high priority is served before an element with low priority.
 */
public final class PriorityQueue<T extends Comparable<T>> extends AbstractPriorityQueue<T> {
    /**
     * Creates a min priority queue.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMinPriorityQueue(
        Class<T> classType) {

        return new PriorityQueue<>(
            classType,
            base.core.Comparator.defaultComparator(),
            AbstractPriorityQueue.defaultComparator());
    }

    /**
     * Creates a min priority queue.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMinPriorityQueue(
        Class<T> classType,
        IBinaryComparator<T> elementComparator) {

        return new PriorityQueue<>(
            classType,
            elementComparator,
            AbstractPriorityQueue.defaultComparator());
    }

    /**
     * Creates a min priority queue.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMinPriorityQueue(
        Class<T> classType,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        return new PriorityQueue<>(
            classType,
            elementComparator,
            comparator);
    }

    /**
     * Creates a max priority queue by using the default invert comparator of an element.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMaxPriorityQueue(
        Class<T> classType) {

        return new PriorityQueue<>(
            classType,
            base.core.Comparator.defaultInvertComparator(),
            AbstractPriorityQueue.defaultComparator());
    }

    /**
     * Creates a max priority queue by using the default invert comparator of an element.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMaxPriorityQueue(
        Class<T> classType,
        IBinaryComparator<T> elementComparator) {

        return new PriorityQueue<>(
            classType,
            base.core.Comparator.invertComparator(elementComparator),
            AbstractPriorityQueue.defaultComparator());
    }

    /**
     * Creates a max priority queue by inverting the specified comparator of an element.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMaxPriorityQueue(
        Class<T> classType,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        return new PriorityQueue<>(
            classType,
            base.core.Comparator.invertComparator(elementComparator),
            comparator);
    }

    /**
     * The PriorityQueue constructor.
     */
    public PriorityQueue(Class<T> classType) {
        super(
            classType,
            base.core.Comparator.defaultComparator(),
            AbstractPriorityQueue.defaultComparator());
    }

    /**
     * The PriorityQueue constructor.
     */
    public PriorityQueue(
        Class<T> classType,
        IBinaryComparator<T> elementComparator) {

        super(
            classType,
            elementComparator,
            AbstractPriorityQueue.defaultComparator());
    }

    /**
     * The PriorityQueue constructor.
     */
    public PriorityQueue(
        Class<T> classType,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        super(
            classType,
            elementComparator,
            comparator);
    }
}
