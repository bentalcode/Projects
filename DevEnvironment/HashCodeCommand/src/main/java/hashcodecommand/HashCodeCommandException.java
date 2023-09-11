package hashcodecommand;

import command.CommandException;

/**
 * The HashCodeCommandException class captures errors in the hashcode-command module.
 */
public class HashCodeCommandException extends CommandException {
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
