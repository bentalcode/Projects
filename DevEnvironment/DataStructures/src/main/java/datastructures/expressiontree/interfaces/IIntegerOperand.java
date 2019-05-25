package datastructures.expressiontree.interfaces;

/**
 * The IIntegerOperand interface defines an integer operand of an expression tree.
 */
public interface IIntegerOperand extends IOperand {
    /**
     * Gets an integer value of an operand.
     */
    int getValue();
}
