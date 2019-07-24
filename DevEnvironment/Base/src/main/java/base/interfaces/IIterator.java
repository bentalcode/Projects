package base.interfaces;

import java.util.Iterator;

public interface IIterator<T> extends Iterable<T>, Iterator<T> {
    /*
     * Resets the iterator.
     */
    void reset();
}
