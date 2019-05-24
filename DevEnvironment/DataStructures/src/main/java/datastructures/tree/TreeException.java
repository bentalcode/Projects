package datastructures.tree;

import datastructures.DataStructureException;

/**
 * The TreeException class implements an exception for capturing errors in the Tree module.
 */
public class TreeException extends DataStructureException {
    /**
     * The TreeException constructor.
     */
    public TreeException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The TreeException constructor.
     */
    public TreeException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
