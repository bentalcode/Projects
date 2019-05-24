package datastructures.binarytree;

import datastructures.DataStructureException;

/**
 * The BinaryTreeException class implements an exception for capturing errors in the BinaryTree module.
 */
public class BinaryTreeException extends DataStructureException {
    /**
     * The BinaryTreeException constructor.
     */
    public BinaryTreeException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The BinaryTreeException constructor.
     */
    public BinaryTreeException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
