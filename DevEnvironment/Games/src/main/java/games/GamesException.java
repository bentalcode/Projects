package games;

import base.BaseException;

/**
 * The GamesException class implements an exception for capturing errors in the games module.
 */
public class GamesException extends BaseException {
    /**
     * The GamesException constructor.
     */
    public GamesException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The GamesException constructor.
     */
    public GamesException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
