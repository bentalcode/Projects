package cheadercommand.core;

/**
 * The CHeaderCommandException class captures errors in the cheader-command module.
 */
public class CHeaderCommandException extends RuntimeException {
    /**
     * The CHeaderCommandException constructor.
     */
    public CHeaderCommandException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The CHeaderCommandException constructor.
     */
    public CHeaderCommandException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
