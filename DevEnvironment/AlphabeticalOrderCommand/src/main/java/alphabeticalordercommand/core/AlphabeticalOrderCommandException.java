package alphabeticalordercommand.core;

/**
 * The AlphabeticalOrderCommandException class captures errors in the command module.
 */
public class AlphabeticalOrderCommandException extends RuntimeException {
    /**
     * The AlphabeticalOrderCommandException constructor.
     */
    public AlphabeticalOrderCommandException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The AlphabeticalOrderCommandException constructor.
     */
    public AlphabeticalOrderCommandException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
