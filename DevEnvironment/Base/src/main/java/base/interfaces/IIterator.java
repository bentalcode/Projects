package base.interfaces;

import java.util.Iterator;

/**
 * The IIterator interface defines an iterator.
 */
public interface IIterator<T> extends Iterator<T> {
    /*
     * Resets the iterator.
     */
    void reset();
}
