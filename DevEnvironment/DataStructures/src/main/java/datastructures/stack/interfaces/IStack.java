package datastructures.stack.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.IUnaryComparator;
import base.interfaces.ISizableCollection;

/**
 * The IStack interface defines a stack.
 */
public interface IStack<T extends Comparable<T>> extends
    ISizableCollection,
    IIterable<T>,
    IReverseIterable<T>,
    IUnaryComparator<IStack<T>> {

    /**
     * Pushes a new element to the stack.
     */
    void push(T element);

    /**
     * Pops the peak element from the stack.
     */
    void pop();

    /**
     * Gets the peek element of the stack.
     */
    T peek();
}
