package base.interfaces;

/**
 * The IIterator interface defines an iterable object.
 */
public interface IIterable<T> extends Iterable<T> {
    /**
     * Gets the iterator.
     */
    default IIterator<T> iterator() {
        return this.getIterator();
    }

    /**
     * Gets the iterator.
     */
    IIterator<T> getIterator();
}
