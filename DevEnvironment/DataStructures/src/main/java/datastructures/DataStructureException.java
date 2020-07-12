package datastructures;

import base.BaseException;

/**
 * The DataStructureException class implements an exception for capturing errors in the data-structure module.
 */
public class DataStructureException extends BaseException {
    /**
     * The DataStructureException constructor.
     */
    public DataStructureException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The DataStructureException constructor.
     */
    public DataStructureException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
