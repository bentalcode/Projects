package base.interfaces;

/**
 * The IIteratorOfIteratorCollection interface defines an iterator of a collection of iterators.
 */
public interface IIteratorOfIteratorCollection<T> extends IIterator<T> {
    /**
     * Gets the size of a collection.
     */
    int size();

    /**
     * Checks whether a collection is empty.
     */
    boolean isEmpty();
}
