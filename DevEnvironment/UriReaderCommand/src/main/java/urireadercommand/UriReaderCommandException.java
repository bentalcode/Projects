package urireadercommand;

import command.CommandException;

/**
 * The UriReaderCommandException class captures errors in the uri-reader-command module.
 */
public class UriReaderCommandException extends CommandException {
    /**
     * The UriReaderCommandException constructor.
     */
    public UriReaderCommandException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The UriReaderCommandException constructor.
     */
    public UriReaderCommandException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
