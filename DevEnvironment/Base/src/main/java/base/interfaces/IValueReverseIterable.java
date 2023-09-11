package base.interfaces;

/**
 * The IValueReverseIterable interface defines a reverse iterable of values.
 * Use this interface only as a secondary iterable option for avoiding conflict with the primary iterable.
 */
public interface IValueReverseIterable<TValue> {
    /**
     * Gets the reverse iterator of values.
     */
    IReverseIterator<TValue> getValueReverseIterator();
}
