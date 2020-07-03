package basicio.interfaces;

/**
 * The IReverseReader interface defines a reverse reader.
 */
public interface IReverseReader<T> {
    /**
     * Checks whether there is a next element.
     */
    boolean hasNext();

    /**
     * Gets the next element.
     */
    T next();
}
