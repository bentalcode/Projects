package datastructures.string.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.IUnaryComparator;
import base.interfaces.ISizableCollection;

/**
 * The ICircularString interface defines a circular string.
 */
public interface ICircularString extends
    ISizableCollection,
    IIterable<Character>,
    IReverseIterable<Character>,
    IUnaryComparator<ICircularString> {

    /**
     * Gets the start index.
     */
    int getStartIndex();

    /**
     * Gets the value of an index.
     */
    char charAt(int index);

    /**
     * Gets the size of a string.
     */
    int size();

    /**
     * Checks whether a string is empty.
     */
    boolean empty();
}
