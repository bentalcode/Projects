package datastructures.string.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.IUnaryComparator;

/**
 * The ICircularString interface defines a circular string.
 */
public interface ICircularString extends
    IUnaryComparator<ICircularString>,
    IIterable<Character>,
    IReverseIterable<Character> {

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
