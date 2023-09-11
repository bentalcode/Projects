package datastructures.bplustree;

import datastructures.DataStructureException;

/**
 * The BPlusTreeException class implements an exception for capturing errors in the BPlusTree module.
 */
public class BPlusTreeException extends DataStructureException {
    /**
     * The BPlusTreeException constructor.
     */
    public BPlusTreeException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The BPlusTreeException constructor.
     */
    public BPlusTreeException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
