package datastructures.collections.interfaces;

/**
 * The IKeyIterable interface defines an iterable of keys.
 */
public interface IKeyIterable<TKey extends Comparable<TKey>> {
    /**
     * Gets the iterator of keys.
     */
    IKeyIterator<TKey> getKeyIterator();
}
