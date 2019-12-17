package base.interfaces;

/**
 * The IIteratorFactory interface defines a factory for creating an iterator.
 */
public interface IIteratorFactory<T, V> {
    /*
     * Creates a new iterator.
     */
    IIterator<T> create(V value);
}
