package datastructures.array;

import datastructures.DataStructureException;

/**
 * The ArrayException class implements an exception for capturing errors in the array module.
 */
public class ArrayException extends DataStructureException {
    /**
     * The ArrayException constructor.
     */
    public ArrayException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The ArrayException constructor.
     */
    public ArrayException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
