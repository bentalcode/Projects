package datastructures.list.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.IUnaryComparator;

/**
 * The IList interface defines a list.
 */
public interface IList<TValue extends Comparable<TValue>> extends
    IUnaryComparator<IList<TValue>>,
    IIterable<TValue>,
    IReverseIterable<TValue> {

    /**
     * Appends a specified element to the end of the list.
     */
    void add(TValue element);

    /**
     * Sets an element at the specified index.
     */
    void set(int index, TValue element);

    /**
     * Gets an element at the specified index.
     */
    TValue get(int index);

    /**
     * Removes an element at specified index.
     * Shifts any subsequent elements to the left.
     * Returns the element that was removed from the list.
     */
    TValue remove(int index);

    /**
     * Gets the size of an array.
     */
    int size();

    /**
     * Checks whether the list is empty.
     */
    boolean empty();

    /**
     * Clears the elements of the list.
     */
    void clear();

    /**
     * Checks whether the list contains an element.
     */
    boolean contains(TValue element);

    /**
     * Gets the corresponding index of the first element which is matching to the specified element.
     * Returns -1 if no element was found.
     */
    int indexOf(TValue element);

    /**
     * Sorts the list.
     */
    void sort();

    /**
     * Converts the list to a native array.
     */
    TValue[] toArray();
}
