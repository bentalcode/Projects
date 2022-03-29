package datastructures.collections.core;

import base.core.Conditions;
import base.interfaces.IBuilder;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterable;
import base.interfaces.IReverseIterator;
import java.util.ArrayList;
import java.util.Collection;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * The ReverseIteratorOfReverseIteratorCollection class implements a reverse iterator of
 * a collection of reverse iterators.
 */
public final class ReverseIteratorOfReverseIteratorCollection<T> implements IReverseIterator<T> {
    private final Collection<IReverseIterator<T>> reverseIterators;
    private Queue<IReverseIterator<T>> reverseIteratorsQueue;

    /**
     * Creates a new reverse iterator of a collection of reverse iterators.
     */
    public static <T> IReverseIterator<T> make(Collection<IReverseIterator<T>> reverseIterators) {
        return new ReverseIteratorOfReverseIteratorCollection<>(reverseIterators);
    }

    /**
     * Creates a new reverse iterator from a collection of reverse iterables.
     */
    public static <T extends IReverseIterable<T>> IIterator<T> ofIterables(Collection<T> reverseIterables) {
        Conditions.validateNotNull(
            reverseIterables,
            "The collection of reverse iterable objects.");

        List<IReverseIterator<T>> reverseIterators = new ArrayList<>();

        for (T reverseIterable : reverseIterables) {
            reverseIterators.add(reverseIterable.getReverseIterator());
        }

        return new ReverseIteratorOfReverseIteratorCollection<>(reverseIterators);
    }

    /**
     * The ReverseIteratorOfReverseIteratorCollection constructor.
     */
    private ReverseIteratorOfReverseIteratorCollection(Collection<IReverseIterator<T>> reverseIterators) {
        Conditions.validateNotNull(
            reverseIterators,
            "The reverse iterators.");

        this.reverseIterators = reverseIterators;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return !this.reverseIteratorsQueue.isEmpty();
    }

    /**
     * Gets the next element.
     */
    @Override
    public T next() {
        assert(this.hasNext());

        IReverseIterator<T> currIterator = this.reverseIteratorsQueue.poll();
        assert (currIterator != null);

        T currElement = currIterator.next();

        if (currIterator.hasNext()) {
            this.reverseIteratorsQueue.offer(currIterator);
        }

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.reverseIteratorsQueue = new LinkedList<>();

        for (IReverseIterator<T> reverseIterator : this.reverseIterators) {
            reverseIteratorsQueue.offer(reverseIterator);
        }
    }

    /**
     * The Builder class implements a builder for creating a reverse iterator of a collection of reverse iterators.
     */
    public static final class Builder<T> implements IBuilder<IReverseIterator<T>> {
        private final List<IReverseIterator<T>> reverseIterators = new ArrayList<>();

        /**
         * The Builder constructor.
         */
        public Builder() {
        }

        /**
         * Adds a reverse iterator.
         */
        public Builder<T> addReverseIterator(IReverseIterator<T> reverseIterator) {
            Conditions.validateNotNull(
                reverseIterator,
                "The reverse iterator.");

            this.reverseIterators.add(reverseIterator);

            return this;
        }

        /**
         * Builds a reverse iterator of a collection of reverse iterators.
         */
        @Override
        public IReverseIterator<T> build() {
            return ReverseIteratorOfReverseIteratorCollection.make(this.reverseIterators);
        }
    }
}
