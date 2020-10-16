package canmessagegenerator;

import base.BaseException;

/**
 * The MessageJitterException class implements an exception for capturing errors
 * in the Message Jitter module.
 */
public final class MessageJitterException extends BaseException {
    /**
     * The MessageJitterException constructor.
     */
    public MessageJitterException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The MessageJitterException constructor.
     */
    public MessageJitterException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
