package datastructures.expressiontree.interfaces;

/**
 * The IExpressionTreeIntegerOperand interface defines an integer operand of an expression tree.
 */
public interface IExpressionTreeIntegerOperand extends IExpressionTreeOperand {
    /**
     * Gets an integer value of an operand.
     */
    int getValue();
}
