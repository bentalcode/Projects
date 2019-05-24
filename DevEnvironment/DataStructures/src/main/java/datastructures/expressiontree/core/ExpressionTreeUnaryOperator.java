package datastructures.expressiontree.core;

import base.core.Conditions;
import datastructures.expressiontree.interfaces.IExpressionTreeOperand;
import datastructures.expressiontree.interfaces.IExpressionTreeUnaryOperator;

/**
 * The ExpressionTreeUnaryOperator class implements an unary operator of an expression tree.
 */
public abstract class ExpressionTreeUnaryOperator implements IExpressionTreeUnaryOperator {
    private final IExpressionTreeOperand operand;

    /**
     * The ExpressionTree constructor.
     */
    protected ExpressionTreeUnaryOperator(IExpressionTreeOperand operand) {
        Conditions.validateNotNull(
            operand,
            "The operand of an unary operator.");

        this.operand = operand;
    }
}
