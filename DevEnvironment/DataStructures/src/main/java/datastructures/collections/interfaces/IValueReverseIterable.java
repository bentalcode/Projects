package datastructures.collections.interfaces;

/**
 * The IValueReverseIterable interface defines a reverse iterable of values.
 */
public interface IValueReverseIterable<TValue> {
    /**
     * Gets the reverse iterator of values.
     */
    IValueReverseIterator<TValue> getValueReverseIterator();
}
