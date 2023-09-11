package datastructures.expressiontree.core;

import datastructures.expressiontree.interfaces.IOperand;
import datastructures.expressiontree.interfaces.ISubtractOperator;
import datastructures.expressiontree.interfaces.IExpressionTreeSymbols;

/**
 * The SubtractOperator class implements a subtract operator of an expression tree.
 */
public final class SubtractOperator extends BinaryOperator implements ISubtractOperator {
    /**
     * The SubtractOperator constructor.
     */
    public SubtractOperator(IOperand lhsOperand, IOperand rhsOperand) {
        super(lhsOperand, rhsOperand);
    }

    /**
     * Evaluates a result of an expression element.
     */
    @Override
    public double evaluate() {
        return this.getLeftOperand().evaluate() - this.getRightOperand().evaluate();
    }

    /**
     * Checks whether this token is an add operator.
     */
    public static boolean isOperator(String token) {
        return token.length() == 1 && token.charAt(0) == IExpressionTreeSymbols.SubtractOperator;
    }
}
