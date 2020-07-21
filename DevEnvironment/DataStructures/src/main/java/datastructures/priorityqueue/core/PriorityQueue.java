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
     * Creates a min priority queue.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMinPriorityQueue(Class<?> classType) {
        return new PriorityQueue<T>(
            classType,
            base.core.Comparator.defaultComparator(),
            AbstractPriorityQueue.defaultComparator());
    }

    /**
     * Creates a min priority queue.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMinPriorityQueue(
        Class<?> classType,
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
        Class<?> classType,
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
    public static <T extends Comparable<T>> IPriorityQueue<T> createMaxPriorityQueue(Class<?> classType) {
        return new PriorityQueue<T>(
            classType,
            base.core.Comparator.defaultInvertComparator(),
            AbstractPriorityQueue.defaultComparator());
    }

    /**
     * Creates a max priority queue by using the default invert comparator of an element.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMaxPriorityQueue(
        Class<?> classType,
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
        Class<?> classType,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        return new PriorityQueue<>(
            classType,
            base.core.Comparator.invertComparator(elementComparator),
            comparator);
    }

    /**
     * Creates a min priority queue.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMinPriorityQueue(IList<T> data) {
        return new PriorityQueue<>(
            data,
            base.core.Comparator.defaultComparator(),
            AbstractPriorityQueue.defaultComparator());
    }

    /**
     * Creates a min priority queue.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMinPriorityQueue(
        IList<T> data,
        IBinaryComparator<T> elementComparator) {

        return new PriorityQueue<>(
            data,
            elementComparator,
            AbstractPriorityQueue.defaultComparator());
    }

    /**
     * Creates a min priority queue.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMinPriorityQueue(
        IList<T> data,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        return new PriorityQueue<>(
            data,
            elementComparator,
            comparator);
    }

    /**
     * Creates a max priority queue by using the default invert comparator of an element.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMaxPriorityQueue(IList<T> data) {
        return new PriorityQueue<>(
            data,
            base.core.Comparator.defaultInvertComparator(),
            AbstractPriorityQueue.defaultComparator());
    }

    /**
     * Creates a max priority queue by using the default invert comparator of an element.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMaxPriorityQueue(
        IList<T> data,
        IBinaryComparator<T> elementComparator) {

        return new PriorityQueue<>(
            data,
            base.core.Comparator.invertComparator(elementComparator),
            AbstractPriorityQueue.defaultComparator());
    }

    /**
     * Creates a max priority queue by inverting the specified comparator of an element.
     */
    public static <T extends Comparable<T>> IPriorityQueue<T> createMaxPriorityQueue(
        IList<T> data,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        return new PriorityQueue<>(
            data,
            base.core.Comparator.invertComparator(elementComparator),
            comparator);
    }

    /**
     * The PriorityQueue constructor.
     */
    public PriorityQueue(Class<?> classType) {
        super(
            classType,
            base.core.Comparator.defaultComparator(),
            AbstractPriorityQueue.defaultComparator());
    }

    /**
     * The PriorityQueue constructor.
     */
    public PriorityQueue(
        Class<?> classType,
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
    public PriorityQueue(IList<T> data) {
        super(
            data,
            base.core.Comparator.defaultComparator(),
            AbstractPriorityQueue.defaultComparator());
    }

    /**
     * The PriorityQueue constructor.
     */
    public PriorityQueue(
        IList<T> data,
        IBinaryComparator<T> elementComparator) {

        super(
            data,
            elementComparator,
            AbstractPriorityQueue.defaultComparator());
    }

    /**
     * The PriorityQueue constructor.
     */
    public PriorityQueue(
        IList<T> data,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        super(
            data,
            elementComparator,
            comparator);
    }

    /**
     * Copies the priority queue.
     */
    @Override
    public IPriorityQueue<T> copy() {
        return new PriorityQueue<>(
            this.getData(),
            this.getElementComparator(),
            this.getComparator());
    }
}
