package datastructures.expressiontree.interfaces;

/**
 * The IUnaryOperator interface defines a unary operator of an expression tree.
 */
public interface IUnaryOperator extends IOperator, IOperand {
    /**
     * Gets an operand.
     */
    IOperand getOperand();
}
