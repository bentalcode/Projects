package datastructures.list;

import datastructures.DataStructureException;

/**
 * The ListException class implements an exception for capturing errors in the list module.
 */
public class ListException extends DataStructureException {
    /**
     * The ListException constructor.
     */
    public ListException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The ListException constructor.
     */
    public ListException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
