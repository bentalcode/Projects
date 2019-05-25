package datastructures.expressiontree.core;

import base.core.Conditions;
import datastructures.expressiontree.interfaces.IBinaryOperator;
import datastructures.expressiontree.interfaces.IOperand;

/**
 * The BinaryOperator class implements a binary operator of an expression tree.
 */
public abstract class BinaryOperator implements IBinaryOperator {
    private final IOperand lhsOperand;
    private final IOperand rhsOperand;

    /**
     * The ExpressionTree constructor.
     */
    protected BinaryOperator(IOperand lhsOperand, IOperand rhsOperand) {
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
