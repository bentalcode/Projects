package datastructures.queue.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.Collections;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.core.ListIterator;
import base.core.ListReverseIterator;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import datastructures.queue.QueueException;
import datastructures.queue.interfaces.IDequeue;
import datastructures.queue.interfaces.IQueue;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.LinkedList;

/**
 * The LinkedListQueue class implements a linked list queue.
 */
public final class LinkedListQueue<T extends Comparable<T>> implements IDequeue<T> {
    private final LinkedList<T> data = new LinkedList<>();
    private final IBinaryComparator<IQueue<T>> comparator;

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The LinkedListQueue constructor.
     */
    public LinkedListQueue() {
        this(defaultComparator());
    }

    /**
     * The LinkedListQueue constructor.
     */
    public LinkedListQueue(IBinaryComparator<IQueue<T>> comparator) {
        Conditions.validateNotNull(
            comparator,
            "The comparator of a queue.");

        this.comparator = comparator;
    }

    /**
     * Adds an element to the back of the queue.
     */
    @Override
    public void enqueue(T element) {
        this.addBack(element);
    }

    /**
     * Retrieves and removes an element from the front of the queue.
     */
    @Override
    public T dequeue() {
        return this.removeFront();
    }

    /**
     * Adds an element to the front of the queue.
     */
    @Override
    public void addFront(T element) {
        this.data.addFirst(element);
    }

    /**
     * Adds an element to the back of the queue.
     */
    @Override
    public void addBack(T element) {
        this.data.addLast(element);
    }

    /**
     * Gets an element from the front of the queue.
     */
    @Override
    public T front() {
        validateNotEmpty();
        return this.data.getFirst();
    }

    /**
     * Gets an element from the back of the queue.
     */
    @Override
    public T back() {
        validateNotEmpty();
        return this.data.getLast();
    }

    /**
     * Removes an element from the front of the queue.
     */
    @Override
    public T removeFront() {
        validateNotEmpty();
        return this.data.removeFirst();
    }

    /**
     * Removes an element from the back of the queue.
     */
    @Override
    public T removeBack() {
        validateNotEmpty();
        return this.removeBack();
    }

    /**
     * Gets the size of the queue.
     */
    @Override
    public int size() {
        return this.data.size();
    }

    /**
     * Checks whether the queue is empty.
     */
    @Override
    public boolean empty() {
        return this.size() == 0;
    }

    /**
     * Clears the queue.
     */
    @Override
    public void clear() {
        this.data.clear();
    }

    /**
     * Gets the iterator.
     */
    @Override
    public IIterator<T> getIterator() {
        return ListIterator.make(this.data);
    }

    /**
     * Gets the reverse iterator.
     */
    @Override
    public IReverseIterator<T> getReverseIterator() {
        return ListReverseIterator.make(this.data);
    }

    /**
     * Gets string representation of this instance.
     */
    @Override
    public String toString() {
        return Collections.toString(this.getIterator());
    }

    /**
     * Gets the hash code.
     */
    @Override
    public int hashCode() {
        return this.comparator.getHashCode(this);
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean equals(Object other) {
        if (other == null) {
            return false;
        }

        if (this == other) {
            return true;
        }

        if (!this.getClass().isInstance(other)) {
            return false;
        }

        return this.isEqual(Casting.cast(other));
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean isEqual(IQueue<T> other) {
        return this.comparator.isEqual(this, other);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(IQueue<T> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <T extends Comparable<T>> IBinaryComparator<IQueue<T>> defaultComparator() {
        return new LinkedListQueue.Comparator<>();
    }

    /**
     * The Comparator class implements a comparator of a queue.
     */
    public static final class Comparator<T extends Comparable<T>> extends AbstractBinaryComparator<IQueue<T>> {

        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IQueue<T> obj) {
            return new HashCodeBuilder(443, 449)
                .withIterator(obj.getIterator())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IQueue<T> lhs, IQueue<T> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withIterator(lhs.getIterator(), rhs.getIterator())
                .build();
        }

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        @Override
        public int compareTo(IQueue<T> lhs, IQueue<T> rhs) {
            if (lhs == null && rhs == null) {
                return 0;
            }

            if (lhs == null) {
                return -1;
            }

            if (rhs == null) {
                return 1;
            }

            return new CompareToBuilder()
                .withIterator(lhs.getIterator(), rhs.getIterator())
                .build();
        }
    }

    /**
     * Validates that the queue is not empty.
     */
    private void validateNotEmpty() {
        if (this.empty()) {
            String errorMessage = "The queue is empty.";

            this.log.error(errorMessage);
            throw new QueueException(errorMessage);
        }
    }
}
