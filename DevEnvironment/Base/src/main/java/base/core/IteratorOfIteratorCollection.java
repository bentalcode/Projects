package base.core;

import base.interfaces.IBuilder;
import base.interfaces.IIterable;
import base.interfaces.IIterator;
import base.interfaces.IIteratorFactory;
import java.util.ArrayList;
import java.util.Collection;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * The IteratorOfIteratorCollection class implements an iterator of a collection of iterators.
 */
public final class IteratorOfIteratorCollection<T> implements IIterator<T> {
    private final Collection<IIterator<T>> iterators;
    private Queue<IIterator<T>> iteratorsQueue;

    /**
     * Creates a new iterator from a collection of iterators.
     */
    public static <T> IIterator<T> of(Collection<IIterator<T>> iterators) {
        return new IteratorOfIteratorCollection<>(iterators);
    }

    /**
     * Creates a new iterator from a collection of iterables.
     */
    public static <T extends IIterable<T>> IIterator<T> ofIterables(Collection<T> iterables) {
        Conditions.validateNotNull(
            iterables,
            "The collection of iterable objects.");

        List<IIterator<T>> iterators = new ArrayList<>();

        for (T iterable : iterables) {
            iterators.add(iterable.getIterator());
        }

        return new IteratorOfIteratorCollection<>(iterators);
    }

    /**
     * Creates a new iterator from a collection of objects.
     */
    public static <T, V> IIterator<T> ofObjects(
        Collection<V> objects,
        IIteratorFactory<T, V> iteratorFactory) {

        Conditions.validateNotNull(
            objects,
            "The collection of objects.");

        Conditions.validateNotNull(
            iteratorFactory,
            "The iterator factory.");

        List<IIterator<T>> iterators = new ArrayList<>();

        for (V object : objects) {
            IIterator<T> iterator = iteratorFactory.create(object);
            iterators.add(iterator);
        }

        return new IteratorOfIteratorCollection<>(iterators);
    }

    /**
     * The IteratorOfIteratorCollection constructor.
     */
    private IteratorOfIteratorCollection(Collection<IIterator<T>> iterators) {
        Conditions.validateNotNull(
            iterators,
            "The iterators.");

        this.iterators = iterators;

        this.reset();
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

        IIterator<T> currIterator = this.iteratorsQueue.peek();
        T currElement = currIterator.next();

        if (!currIterator.hasNext()) {
            this.iteratorsQueue.poll();
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
     * The Builder class implements a builder for creating an iterator of a collection of iterators.
     */
    public static final class Builder<T> implements IBuilder<IIterator<T>> {
        private final List<IIterator<T>> iterators = new ArrayList<>();

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
        public IIterator<T> build() {
            return IteratorOfIteratorCollection.of(this.iterators);
        }
    }
}
