package command;

/**
 * The CommandException class implements an exception for capturing errors in the command module.
 */
public class CommandException extends RuntimeException {
    /**
     * The CommandException constructor.
     */
    public CommandException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The CommandException constructor.
     */
    public CommandException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
