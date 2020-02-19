package base.interfaces;

/**
 * The IValueIterable interface defines an iterable of values.
 */
public interface IValueIterable<TValue> {
    /**
     * Gets the iterator of values.
     */
    IIterator<TValue> getValueIterator();
}
