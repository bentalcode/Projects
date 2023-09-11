package datastructures.stack;

import datastructures.DataStructureException;

/**
 * The StackException class implements an exception for capturing errors in the stack module.
 */
public class StackException extends DataStructureException {
    /**
     * The StackException constructor.
     */
    public StackException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The StackException constructor.
     */
    public StackException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
