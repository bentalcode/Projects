package datastructures.expressiontree.core;

import datastructures.expressiontree.interfaces.IExpressionTreeAddOperator;
import datastructures.expressiontree.interfaces.IExpressionTreeOperand;

/**
 * The ExpressionTreeAddOperator class implements an addition operator of an expression tree.
 */
public final class ExpressionTreeAddOperator extends ExpressionTreeBinaryOperator implements IExpressionTreeAddOperator {
    /**
     * The ExpressionTreeAddOperator constructor.
     */
    public ExpressionTreeAddOperator(IExpressionTreeOperand lhsOperand, IExpressionTreeOperand rhsOperand) {
        super(lhsOperand, rhsOperand);
    }

    /**
     * Checks whether this is an add operator.
     */
    public static boolean isAddOperator(String token) {
        return token.length() == 1 && token.charAt(0) == '+';
    }
}
