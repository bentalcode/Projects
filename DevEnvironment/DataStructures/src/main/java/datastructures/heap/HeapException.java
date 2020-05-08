package datastructures.heap;

/**
 * The HeapException class implements an exception for capturing errors in the heap module.
 */
public class HeapException extends RuntimeException {
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
