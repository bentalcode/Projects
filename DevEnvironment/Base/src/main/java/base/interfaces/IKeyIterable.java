package base.interfaces;

/**
 * The IKeyIterable interface defines an iterable of keys.
 */
public interface IKeyIterable<TKey extends Comparable<TKey>> {
    /**
     * Gets the iterator of keys.
     */
    IIterator<TKey> getKeyIterator();
}
