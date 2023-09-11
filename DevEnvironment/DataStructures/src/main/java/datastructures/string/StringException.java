package datastructures.string;

import datastructures.DataStructureException;

/**
 * The StringException class implements an exception for capturing errors in the string module.
 */
public class StringException extends DataStructureException {
    /**
     * The StringException constructor.
     */
    public StringException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The StringException constructor.
     */
    public StringException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
