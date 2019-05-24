package datastructures.expressiontree.core;

import base.core.Conditions;
import datastructures.expressiontree.interfaces.IExpressionTreeBinaryOperator;
import datastructures.expressiontree.interfaces.IExpressionTreeOperand;

/**
 * The ExpressionTreeBinaryOperator class implements a binary operator of an expression tree.
 */
public abstract class ExpressionTreeBinaryOperator implements IExpressionTreeBinaryOperator {
    private final IExpressionTreeOperand lhsOperand;
    private final IExpressionTreeOperand rhsOperand;

    /**
     * The ExpressionTree constructor.
     */
    protected ExpressionTreeBinaryOperator(IExpressionTreeOperand lhsOperand, IExpressionTreeOperand rhsOperand) {
        Conditions.validateNotNull(
            lhsOperand,
            "The left hand side operand of a binary operator.");

        Conditions.validateNotNull(
            rhsOperand,
            "The right hand side operand of a binary operator.");

        this.lhsOperand = lhsOperand;
        this.rhsOperand = rhsOperand;
    }
}
