package datastructures.expressiontree.interfaces;

/**
 * The IBinaryOperator interface defines a binary operator of an expression tree.
 */
public interface IBinaryOperator extends IOperator {
    /**
     * Gets the left hand side operand.
     */
    IOperand getLeftOperand();

    /**
     * Gets the right hand side operand.
     */
    IOperand getRightOperand();
}
