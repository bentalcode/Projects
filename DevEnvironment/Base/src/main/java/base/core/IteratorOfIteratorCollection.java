package base.core;

import base.interfaces.IBuilder;
import base.interfaces.IIterator;
import base.interfaces.IIteratorOfIteratorCollection;
import java.util.ArrayList;
import java.util.Collection;
import java.util.LinkedList;
import java.util.Queue;

/**
 * The IteratorOfIteratorCollection class implements an iterator of a collection of iterators.
 */
public final class IteratorOfIteratorCollection<T> implements IIteratorOfIteratorCollection<T> {
    private final Collection<IIterator<T>> iterators;
    private Queue<IIterator<T>> iteratorsQueue;

    /**
     * The IteratorOfIteratorCollection constructor.
     */
    public IteratorOfIteratorCollection(Collection<IIterator<T>> iterators) {
        Conditions.validateNotNull(
            iterators,
            "The iterators.");

        this.iterators = iterators;

        this.reset();
    }

    /**
     * Gets the size of a collection.
     */
    public int size() {
        return this.iteratorsQueue.size();
    }

    /**
     * Checks whether a collection is empty.
     */
    public boolean isEmpty() {
        return this.iterators.isEmpty();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return !this.iteratorsQueue.isEmpty();
    }

    /**
     * Gets the next element.
     */
    @Override
    public T next() {
        assert(this.hasNext());

        IIterator<T> currIterator = this.iteratorsQueue.poll();
        T currElement = currIterator.next();

        if (currIterator.hasNext()) {
            this.iteratorsQueue.offer(currIterator);
        }

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.iteratorsQueue = new LinkedList<>();

        for (IIterator<T> iterator : this.iterators) {
            if (iterator.hasNext()) {
                this.iteratorsQueue.offer(iterator);
            }
        }
    }

    /**
     * The Builder class implements a builder for creating a collection of iterators.
     */
    public static final class Builder<T> implements IBuilder<IIteratorOfIteratorCollection<T>> {
        private final Collection<IIterator<T>> iterators = new ArrayList<>();

        /**
         * The Builder constructor.
         */
        public Builder() {
        }

        /**
         * Adds an iterator.
         */
        public Builder<T> addIterator(IIterator<T> iterator) {
            Conditions.validateNotNull(
                iterator,
                "The iterator.");

            this.iterators.add(iterator);

            return this;
        }

        /**
         * Builds an iterator of a collection of iterators.
         */
        @Override
        public IIteratorOfIteratorCollection<T> build() {
            return new IteratorOfIteratorCollection<>(this.iterators);
        }
    }
}
