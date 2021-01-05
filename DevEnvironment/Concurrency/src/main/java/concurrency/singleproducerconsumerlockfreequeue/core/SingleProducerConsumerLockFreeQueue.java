package concurrency.singleproducerconsumerlockfreequeue.core;

import base.core.Arrays;
import base.core.Conditions;
import concurrency.interfaces.IConcurrentQueue;
import java.util.Optional;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * The LockFreeSingleProducerConsumerQueue class implements a single producer consumer
 * lock free queue by using a circular buffer.
 * The wait-free and lock-free circular queue is a useful technique for time and memory sensitive
 * systems.
 *
 * The wait-free nature of the queue gives a fixed number of steps for each operation.
 * The lock-free nature of the queue enables two thread communication from a single source thread
 * (the Producer) to a single destination thread (the Consumer) without using any locks.
 *
 * The power of wait-free and lock-free together makes this type of circular queue attractive
 * in a range of areas, from interrupt and signal handlers to real-time systems or other time
 * sensitive software.
 */
public final class SingleProducerConsumerLockFreeQueue<T> implements IConcurrentQueue<T> {
    private final int capacity;
    private final T[] elements;
    private final AtomicInteger headIndex = new AtomicInteger();
    private final AtomicInteger tailIndex = new AtomicInteger();

    /**
     * The LockFreeSingleProducerConsumerQueue constructor.
     */
    public SingleProducerConsumerLockFreeQueue(
        Class<T> classType,
        int capacity) {

        Conditions.validate(
            capacity > 0,
            "The capacity of a queue has to be positive.");

        this.capacity = capacity;
        this.elements = Arrays.newInstance(classType, this.capacity + 1);
    }

    /**
     * Adds an element to the back of the queue.
     */
    @Override
    public boolean enqueue(T element) {
        if (this.full()) {
            return false;
        }

        int currIndex = this.tailIndex.get();
        int nextIndex = incrementIndex(currIndex);

        this.elements[currIndex] = element;
        this.tailIndex.set(nextIndex);

        return true;
    }

    /**
     * Retrieves and removes an element from the front of the queue.
     */
    @Override
    public Optional<T> dequeue() {
        if (this.empty()) {
            return Optional.empty();
        }

        int currIndex = this.headIndex.get();
        int nextIndex = this.incrementIndex(currIndex);

        T currElement = this.elements[currIndex];
        this.headIndex.set(nextIndex);

        return Optional.of(currElement);
    }

    /**
     * Gets the size of the queue.
     */
    @Override
    public int size() {
        return (this.tailIndex.get() - this.headIndex.get() + this.elements.length) % this.elements.length;
    }

    /**
     * Gets the capacity of the queue.
     */
    @Override
    public int getCapacity() {
        return this.capacity;
    }

    /**
     * Checks whether the queue is empty.
     */
    @Override
    public boolean empty() {
        return this.headIndex.get() == this.tailIndex.get();
    }

    /**
     * Checks whether the queue is full.
     */
    public boolean full() {
        int headIndex = this.headIndex.get();
        int nextIndex = incrementIndex(this.tailIndex.get());
        return nextIndex == headIndex;
    }

    /**
     * Increments an index.
     */
    private int incrementIndex(int index) {
        int newIndex = index + 1;
        return index(newIndex);
    }

    /**
     * Gets the aligned index.
     */
    private int index(int index) {
        return index % this.elements.length;
    }
}
