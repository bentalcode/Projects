package concurrency.interfaces;

import base.interfaces.ISizableCollection;
import java.util.Optional;

/**
 * The IConcurrentQueue interface defines a concurrent queue.
 */
public interface IConcurrentQueue<T> extends ISizableCollection {
    /**
     * Adds an element to the back of the queue.
     */
    boolean enqueue(T element);

    /**
     * Retrieves and removes an element from the front of the queue.
     */
    Optional<T> dequeue();

    /**
     * Gets the capacity of the queue.
     */
    int getCapacity();
}
