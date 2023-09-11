package datastructures.expressiontree;

import datastructures.DataStructureException;

/**
 * The ExpressionTreeException class implements an exception for capturing errors in the ExpressionTree module.
 */
public class ExpressionTreeException extends DataStructureException {
    /**
     * The ExpressionTreeException constructor.
     */
    public ExpressionTreeException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The ExpressionTreeException constructor.
     */
    public ExpressionTreeException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
