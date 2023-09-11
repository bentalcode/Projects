package datastructures.queue.interfaces;

/**
 * The IDequeue interface defines a double-ended queue.
 */
public interface IDequeue<T extends Comparable<T>> extends IQueue<T> {
    /**
     * Adds an element to the front of the queue.
     */
    void addFront(T element);

    /**
     * Adds an element to the back of the queue.
     */
    void addBack(T element);

    /**
     * Gets an element from the back of the queue.
     */
    T back();

    /**
     * Removes an element from the back of the queue.
     */
    T removeBack();
}
