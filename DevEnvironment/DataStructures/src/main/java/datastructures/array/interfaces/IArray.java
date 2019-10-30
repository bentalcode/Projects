package datastructures.array.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.IUnaryComparator;
import base.interfaces.ISizableCollection;

/**
 * The IArray interface defines an array.
 */
public interface IArray<T extends Comparable<T>> extends
    ISizableCollection,
    IIterable<T>,
    IReverseIterable<T>,
    IUnaryComparator<IArray<T>> {

    /**
     * Sets the value of an index.
     */
    void set(int index, T element);

    /**
     * Gets the value of an index.
     */
    T get(int index);

    /**
     * Converts the array to a native array.
     */
    T[] toArray();
}
