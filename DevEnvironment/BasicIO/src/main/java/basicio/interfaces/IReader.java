package basicio.interfaces;

/**
 * The IReader interface defines a reader.
 */
public interface IReader<T> {
    /**
     * Checks whether there is a next element.
     */
    boolean hasNext();

    /**
     * Gets the next element.
     */
    T next();
}
