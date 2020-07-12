package clientserver;

import base.BaseException;

/**
 * The ClientServerException class implements an exception for capturing errors
 * in the client-server module.
 */
public class ClientServerException extends BaseException {
    /**
     * The ClientServerException constructor.
     */
    public ClientServerException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The ClientServerException constructor.
     */
    public ClientServerException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
