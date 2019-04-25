package datacommand.core;

/**
 * The DataCommandException class captures errors in the data-command module.
 */
public class DataCommandException extends RuntimeException {
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
