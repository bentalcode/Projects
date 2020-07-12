package cheadercommand;

import command.CommandException;

/**
 * The CHeaderCommandException class captures errors in the cheader-command module.
 */
public class CHeaderCommandException extends CommandException {
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
