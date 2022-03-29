package datastructures.priorityqueue.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IMatch;
import base.interfaces.IReverseIterable;
import base.interfaces.IUnaryComparator;
import base.interfaces.ISizableCollection;

/**
 * The IPriorityQueue interface defines a priority queue.
 */
public interface IPriorityQueue<T extends Comparable<T>> extends
    ISizableCollection,
    IIterable<T>,
    IReverseIterable<T>,
    IUnaryComparator<IPriorityQueue<T>> {

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
     * Clears the priority queue.
     */
    void clear();

    /**
     * Checks whether the priority queue contains an element.
     */
    boolean contains(T element);

    /**
     * Finds an element in a priority queue.
     * Returns -1 if the element does not exist.
     */
    int find(T element);

    /**
     * Finds an element in a priority queue by a match predicate.
     * Returns -1 if the element does not exist.
     */
    int find(IMatch<T> match);

    /**
     * Updates a value of a specific element and heapify it up.
     */
    void updateAndHeapifyUp(int index, T element);

    /**
     * Updates a value of a specific element and heapify it down.
     */
    void updateAndHeapifyDown(int index, T element);
}
