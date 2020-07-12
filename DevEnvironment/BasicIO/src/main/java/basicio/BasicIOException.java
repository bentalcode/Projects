package basicio;

import base.BaseException;

/**
 * The BasicIOException class implements an exception for capturing errors in the basic-io module.
 */
public class BasicIOException extends BaseException {
    /**
     * The BasicIOException constructor.
     */
    public BasicIOException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The BasicIOException constructor.
     */
    public BasicIOException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
