package datastructures.expressiontree.core;

import datastructures.expressiontree.interfaces.IOperand;
import datastructures.expressiontree.interfaces.IExpressionTreeSymbols;
import datastructures.expressiontree.interfaces.IPowOperator;

/**
 * The PowOperator class implements a pow operator of an expression tree.
 */
public final class PowOperator extends BinaryOperator implements IPowOperator {
    /**
     * The PowOperator constructor.
     */
    public PowOperator(IOperand lhsOperand, IOperand rhsOperand) {
        super(lhsOperand, rhsOperand);
    }

    /**
     * Evaluates a result of an expression element.
     */
    @Override
    public double evaluate() {
        return Math.pow(this.getLeftOperand().evaluate(), this.getRightOperand().evaluate());
    }

    /**
     * Checks whether this token is an add operator.
     */
    public static boolean isOperator(String token) {
        return token.length() == 1 && token.charAt(0) == IExpressionTreeSymbols.PowOperator;
    }
}
