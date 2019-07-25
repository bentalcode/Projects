package base.interfaces;

/**
 * The IReverseIterable interface defines a reverse iterable.
 */
public interface IReverseIterable<T> {
    /**
     * Returns a reverse iterator.
     */
    IReverseIterator<T> iterator();
}
