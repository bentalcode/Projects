package datastructures.priorityqueue.core;

import base.interfaces.IBinaryComparator;
import datastructures.list.interfaces.IList;
import datastructures.priorityqueue.interfaces.IPriorityQueue;

/**
 * The PriorityQueue class implements a priority queue.
 * In a priority queue, an element with high priority is served before an element with low priority.
 */
public final class PriorityQueue<T extends Comparable<T>> extends AbstractPriorityQueue<T> {
    /**
     * Creates a priority queue.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> make(Class<?> classType) {
        return new PriorityQueue<T>(
            classType,
            base.core.Comparator.make(),
            AbstractPriorityQueue.defaultComparator());
    }

    /**
     * Creates a priority queue with an element comparator.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> make(
        Class<?> classType,
        IBinaryComparator<T> elementComparator) {

        return new PriorityQueue<>(
            classType,
            elementComparator,
            AbstractPriorityQueue.defaultComparator());
    }

    /**
     * Creates a priority queue with an element comparator and a comparator.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> make(
        Class<?> classType,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        return new PriorityQueue<>(
            classType,
            elementComparator,
            comparator);
    }

    /**
     * Creates a priority queue with an initial data.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> make(IList<T> data) {
        return new PriorityQueue<>(
            data,
            base.core.Comparator.make(),
            AbstractPriorityQueue.defaultComparator());
    }

    /**
     * Creates a priority queue with an initial data and an element comparator.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> make(
        IList<T> data,
        IBinaryComparator<T> elementComparator) {

        return new PriorityQueue<>(
            data,
            elementComparator,
            AbstractPriorityQueue.defaultComparator());
    }

    /**
     * Creates a priority queue with initial data, an element comparator and a comparator.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> make(
        IList<T> data,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        return new PriorityQueue<>(
            data,
            elementComparator,
            comparator);
    }

    /**
     * The PriorityQueue constructor.
     */
    private PriorityQueue(
        Class<?> classType,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        super(
            classType,
            elementComparator,
            comparator);
    }

    /**
     * The PriorityQueue constructor.
     */
    private PriorityQueue(
        IList<T> data,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        super(
            data,
            elementComparator,
            comparator);
    }
}
