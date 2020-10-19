package canmessagegenerator;

import base.BaseException;

/**
 * The JitterMessageHandlerException class implements an exception for capturing errors
 * in the Jitter Message Handler module.
 */
public final class JitterMessageHandlerException extends BaseException {
    /**
     * The JitterMessageHandlerException constructor.
     */
    public JitterMessageHandlerException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The JitterMessageHandlerException constructor.
     */
    public JitterMessageHandlerException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
