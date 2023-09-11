package base.core;

import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;

/**
 * The InvertIterator class implements a reverse iterator of an iterator
 * by inverting a forward iterator to a reverse iterator.
 */
public final class InvertIterator<T> implements IReverseIterator<T> {
    private final IIterator<T> iterator;

    /**
     * Creates an iterator by inverting a forward iterator to a reverse iterator.
     */
    public static <T> IReverseIterator<T> make(IIterator<T> iterator) {
        Conditions.validateNotNull(
            iterator,
            "The iterator to invert.");

        return new InvertIterator<>(iterator);
    }

    /**
     * The InvertIterator constructor.
     */
    private InvertIterator(IIterator<T> iterator) {
        Conditions.validateNotNull(
            iterator,
            "The iterator to invert.");

        this.iterator = iterator;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.iterator.hasNext();
    }

    /**
     * Gets the next element.
     */
    @Override
    public T next() {
        assert(this.hasNext());

        return this.iterator.next();
    }

    /*
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.iterator.reset();
    }
}
