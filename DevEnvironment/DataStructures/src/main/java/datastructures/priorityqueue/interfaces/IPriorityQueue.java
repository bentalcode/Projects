package datastructures.priorityqueue.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.IUnaryComparator;

/**
 * The IPriorityQueue interface defines a priority queue.
 */
public interface IPriorityQueue<T extends Comparable<T>> extends
    IUnaryComparator<IPriorityQueue<T>>,
    IIterable<T>,
    IReverseIterable<T> {

    /**
     * Offers an element to the priority queue.
     */
    void offer(T element);

    /**
     * Polls the peek element from the priority queue.
     */
    T poll();

    /**
     * Gets the peek element of the priority queue.
     */
    T peek();

    /**
     * Gets the size of a priority queue.
     */
    int size();

    /**
     * Checks whether a priority queue is empty.
     */
    boolean empty();

    /**
     * Clears the priority queue.
     */
    void clear();

    /**
     * Checks whether the priority queue contains an element.
     */
    boolean contains(T element);
}
