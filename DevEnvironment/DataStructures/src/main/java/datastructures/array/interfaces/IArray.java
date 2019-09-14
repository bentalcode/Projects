package datastructures.array.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.IUnaryComparator;

/**
 * The IArray interface defines an array.
 */
public interface IArray<T extends Comparable<T>> extends
    IUnaryComparator<IArray<T>>,
    IIterable<T>,
    IReverseIterable<T> {

    /**
     * Gets the value of an index.
     */
    T get(int index);

    /**
     * Gets the value of an index.
     */
    void set(int index, T value);

    /**
     * Gets the size of an array.
     */
    int size();

    /**
     * Checks whether an array is empty.
     */
    boolean empty();

    /**
     * Converts the array to a native array.
     */
    T[] toArray();
}
