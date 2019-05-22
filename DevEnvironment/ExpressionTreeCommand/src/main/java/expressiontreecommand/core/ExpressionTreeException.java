package expressiontree.core;

/**
 * The ExpressionTreeCommandException class captures errors in the expression-tree-command module.
 */
public class ExpressionTreeCommandException extends RuntimeException {
    /**
     * The ExpressionTreeCommandException constructor.
     */
    public ExpressionTreeCommandException(String errorMessage) {
        super(errorMessage);
    }

    /**
     * The ExpressionTreeCommandException constructor.
     */
    public ExpressionTreeCommandException(String errorMessage, Exception e) {
        super(errorMessage, e);
    }
}
