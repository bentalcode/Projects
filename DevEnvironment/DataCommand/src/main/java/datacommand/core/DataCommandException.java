package datacommand.core;

import base.BaseException;

/**
 * The DataCommandException class captures errors in the data-command module.
 */
public class DataCommandException extends BaseException {
    /**
     * The DataCommandException constructor.
     */
    public DataCommandException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The DataCommandException constructor.
     */
    public DataCommandException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
