package datastructures.array.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.IUnaryComparator;

/**
 * The ICircularString interface defines a circular string.
 */
public interface ICircularArray<T extends Comparable<T>> extends
    IUnaryComparator<ICircularArray<T>>,
    IIterable<T>,
    IReverseIterable<T> {

    /**
     * Gets the start index.
     */
    int getStartIndex();

    /**
     * Gets the value of an index.
     */
    T get(int index);

    /**
     * Gets the size of an array.
     */
    int size();

    /**
     * Checks whether an array is empty.
     */
    boolean empty();
}
