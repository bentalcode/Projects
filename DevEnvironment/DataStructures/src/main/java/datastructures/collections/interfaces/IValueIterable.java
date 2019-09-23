package datastructures.collections.interfaces;

/**
 * The IValueIterable interface defines an iterable of values.
 */
public interface IValueIterable<TValue> {
    /**
     * Gets the iterator of values.
     */
    IValueIterator<TValue> getValueIterator();
}
