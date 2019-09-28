package datastructures.stack.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IReverseIterable;
import base.interfaces.IUnaryComparator;

/**
 * The IStack interface defines a stack.
 */
public interface IStack<T extends Comparable<T>> extends
    IUnaryComparator<IStack<T>>,
    IIterable<T>,
    IReverseIterable<T> {

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

    /**
     * Gets the size of the stack.
     */
    int size();

    /**
     * Checks whether the stack is empty.
     */
    boolean empty();

    /**
     * Clears the stack.
     */
    void clear();
}
