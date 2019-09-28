package datastructures.list.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.IUnaryComparator;

/**
 * The ICircularList interface defines a circular list.
 */
public interface ICircularList<T extends Comparable<T>> extends
    IUnaryComparator<ICircularList<T>>,
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
     * Gets the size of the list.
     */
    int size();

    /**
     * Checks whether the list is empty.
     */
    boolean empty();
}
