package base.interfaces;

/**
 * The IReverseIterable interface defines a reverse iterable object.
 */
public interface IReverseIterable<T> extends Iterable<T> {
    /**
     * Gets the reverse iterator.
     */
    IReverseIterator<T> getReverseIterator();
}
