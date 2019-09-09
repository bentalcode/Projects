package base.core;

import base.interfaces.IIterator;
import java.util.Collection;

/**
 * The CollectionIterator class implements an iterator of a collection.
 */
public class CollectionIterator<T> implements IIterator<T> {
    private final Collection<T> collection;
    private java.util.Iterator<T> iterator;

    /**
     * Creates a new iterator of a list.
     */
    public static <T> IIterator<T> of(Collection<T> collection) {
        return new CollectionIterator<>(collection);
    }

    /**
     * The ListIterator constructor.
     */
    private CollectionIterator(Collection<T> collection) {
        Conditions.validateNotNull(
            collection,
            "The collection to iterate.");

        this.collection = collection;

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

        T currElement = this.iterator.next();

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.iterator = this.collection.iterator();
    }
}
