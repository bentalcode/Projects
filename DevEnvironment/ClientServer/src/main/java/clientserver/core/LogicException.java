package clientserver.core;

import clientserver.ClientServerException;

/**
 * The LogicException class implements an exception for capturing errors
 * in the logic module.
 */
public class LogicException extends ClientServerException {
    /**
     * The LogicException constructor.
     */
    public LogicException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The LogicException constructor.
     */
    public LogicException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
