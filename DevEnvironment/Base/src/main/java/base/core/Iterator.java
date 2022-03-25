package base.core;

import base.interfaces.IIterator;
import java.util.Collection;

/**
 * The Iterator class implements a wrapper for the build-in iterator.
 */
public final class Iterator<T> implements IIterator<T> {
    private final java.util.Iterator<T> iterator;

    /**
     * Creates a new operator.
     */
    public static <T> IIterator<T> make(Collection<T> collection) {
        Conditions.validateNotNull(
            collection,
            "The collection.");

        return new Iterator<>(collection.iterator());
    }

    /**
     * The AbstractIterator constructor.
     */
    private Iterator(java.util.Iterator<T> iterator) {
        Conditions.validateNotNull(
            iterator,
            "The iterator.");

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
     * Do nothing.
     */
    @Override
    public void reset() {
    }
}
