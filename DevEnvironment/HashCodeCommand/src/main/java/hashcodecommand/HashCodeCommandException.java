package hashcodecommand;

/**
 * The HashCodeCommandException class captures errors in the hashcode-command module.
 */
public class HashCodeCommandException extends RuntimeException {
    /**
     * The HashCodeCommandException constructor.
     */
    public HashCodeCommandException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The HashCodeCommandException constructor.
     */
    public HashCodeCommandException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
