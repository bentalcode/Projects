package clientserver.core;

import clientserver.ClientServerException;

/**
 * The HttpException class implements an exception for capturing errors in the Retry Handler module.
 */
public class HttpException extends ClientServerException {
    /**
     * The HttpException constructor.
     */
    public HttpException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The HttpException constructor.
     */
    public HttpException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
