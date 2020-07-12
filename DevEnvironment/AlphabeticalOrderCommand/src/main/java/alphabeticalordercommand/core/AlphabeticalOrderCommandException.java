package alphabeticalordercommand.core;

import base.BaseException;

/**
 * The AlphabeticalOrderCommandException class captures errors in the command module.
 */
public class AlphabeticalOrderCommandException extends BaseException {
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
