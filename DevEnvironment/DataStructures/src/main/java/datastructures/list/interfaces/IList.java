package datastructures.list.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.IUnaryComparator;
import datastructures.collections.interfaces.ISizableCollection;

/**
 * The IList interface defines a list.
 */
public interface IList<T extends Comparable<T>> extends
    ISizableCollection,
    IIterable<T>,
    IReverseIterable<T>,
    IUnaryComparator<IList<T>> {

    /**
     * Appends a specified element to the end of the list.
     */
    void add(T element);

    /**
     * Sets an element at the specified index.
     */
    void set(int index, T element);

    /**
     * Gets an element at the specified index.
     */
    T get(int index);

    /**
     * Removes an element at specified index.
     * Shifts any subsequent elements to the left.
     * Returns the element that was removed from the list.
     */
    T remove(int index);

    /**
     * Clears the elements of the list.
     */
    void clear();

    /**
     * Checks whether the list contains an element.
     */
    boolean contains(T element);

    /**
     * Gets the corresponding index of the first element which is matching to the specified element.
     * Returns -1 if no element was found.
     */
    int indexOf(T element);

    /**
     * Sorts the list.
     */
    void sort();

    /**
     * Converts the list to a native array.
     */
    T[] toArray();
}
