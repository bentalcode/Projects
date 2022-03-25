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
}
