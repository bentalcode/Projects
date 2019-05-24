package datastructures.blocktree;

import datastructures.DataStructureException;

/**
 * The BlockTreeException class implements an exception for capturing errors in the BlockTree module.
 */
public class BlockTreeException extends DataStructureException {
    /**
     * The BlockTreeException constructor.
     */
    public BlockTreeException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The BlockTreeException constructor.
     */
    public BlockTreeException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
