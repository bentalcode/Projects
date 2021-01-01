package datastructures.queue.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.ISizableCollection;
import base.interfaces.IUnaryComparator;

/**
 * The IQueue interface defines a queue.
 */
public interface IQueue<T extends Comparable<T>> extends
    ISizableCollection,
    IIterable<T>,
    IReverseIterable<T>,
    IUnaryComparator<IQueue<T>> {

    /**
     * Adds an element to the back of the queue.
     */
    void enqueue(T element);

    /**
     * Retrieves and removes an element from the front of the queue.
     */
    T dequeue();

    /**
     * Gets an element from the front of the queue.
     */
    T front();

    /**
     * Removes an element from the front of the queue.
     */
    T removeFront();

    /**
     * Clears the queue.
     */
    void clear();
}
