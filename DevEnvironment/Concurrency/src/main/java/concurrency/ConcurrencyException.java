package concurrency;

import base.BaseException;

/**
 * The ConcurrencyException class implements an exception for capturing errors in the concurrency module.
 */
public class ConcurrencyException extends BaseException {
    /**
     * The ConcurrencyException constructor.
     */
    public ConcurrencyException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The ConcurrencyException constructor.
     */
    public ConcurrencyException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
