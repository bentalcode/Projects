package datastructures.collections.interfaces;

/**
 * The IKeyReverseIterable interface defines a reverse iterable of keys.
 */
public interface IKeyReverseIterable<TKey extends Comparable<TKey>> {
    /**
     * Gets the reverse iterator of keys.
     */
    IKeyReverseIterator<TKey> getKeyReverseIterator();
}
