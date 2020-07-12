package datastructures.heap;

import base.BaseException;

/**
 * The HeapException class implements an exception for capturing errors in the heap module.
 */
public class HeapException extends BaseException {
    /**
     * The HeapException constructor.
     */
    public HeapException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The HeapException constructor.
     */
    public HeapException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
