package base.interfaces;

/**
 * The IStreamReader interface defines a reader of a stream.
 */
public interface IStreamReader<T> {
    /*
     * Reads the input stream.
     */
    void read(IIterator<T> iterator);
}
