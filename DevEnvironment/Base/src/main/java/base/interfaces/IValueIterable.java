package base.interfaces;

/**
 * The IValueIterable interface defines an iterable of values.
 * Use this interface only as a secondary iterable option for avoiding conflict with the primary iterable.
 */
public interface IValueIterable<TValue> {
    /**
     * Gets the iterator of values.
     */
    IIterator<TValue> getValueIterator();
}
