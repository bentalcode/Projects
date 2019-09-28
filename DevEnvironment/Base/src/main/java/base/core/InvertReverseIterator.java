package base.core;

import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;

/**
 * The InvertReverseIterator class implements an iterator of a reverse iterator
 * by inverting a reverse iterator to a forward iterator.
 */
public final class InvertReverseIterator<T> implements IIterator<T> {
    private final IReverseIterator<T> reverseIterator;

    /**
     * Creates a reverse iterator by inverting a reverse iterator to a forward iterator.
     */
    public static <T> IIterator<T> of(IReverseIterator<T> reverseIterator) {
        Conditions.validateNotNull(
            reverseIterator,
            "The reverse iterator to invert.");

        return new InvertReverseIterator<>(reverseIterator);
    }

    /**
     * The InvertReverseIterator constructor.
     */
    private InvertReverseIterator(IReverseIterator<T> reverseIterator) {
        Conditions.validateNotNull(
            reverseIterator,
            "The reverse iterator to invert.");

        this.reverseIterator = reverseIterator;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.reverseIterator.hasNext();
    }

    /**
     * Gets the next element.
     */
    @Override
    public T next() {
        assert(this.hasNext());

        T element = this.reverseIterator.next();

        return element;
    }

    /*
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.reverseIterator.reset();
    }
}
