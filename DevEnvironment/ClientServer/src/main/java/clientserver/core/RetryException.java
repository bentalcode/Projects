package clientserver.core;

import clientserver.ClientServerException;

/**
 * The RetryException class implements an exception for capturing errors in the Retry Handler module.
 */
public class RetryException extends ClientServerException {
    /**
     * The RetryException constructor.
     */
    public RetryException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The RetryException constructor.
     */
    public RetryException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
