package datastructures.expressiontree.core;

import datastructures.expressiontree.interfaces.IAddOperator;
import datastructures.expressiontree.interfaces.IOperand;
import datastructures.expressiontree.interfaces.IExpressionTreeSymbols;

/**
 * The PowOperator class implements a pow operator of an expression tree.
 */
public final class PowOperator extends UnaryOperator
    implements IAddOperator {

    /**
     * The PowOperator constructor.
     */
    public PowOperator(IOperand operand) {
        super(operand);
    }

    /**
     * Checks whether this token is an add operator.
     */
    public static boolean isOperator(String token) {
        return token.length() == 1 && token.charAt(0) == IExpressionTreeSymbols.PowOperator;
    }
}
