package datastructures.expressiontree.core;

import base.core.Conditions;
import datastructures.expressiontree.interfaces.IOperand;
import datastructures.expressiontree.interfaces.IUnaryOperator;

/**
 * The UnaryOperator class implements an unary operator of an expression tree.
 */
public abstract class UnaryOperator implements IUnaryOperator {
    private final IOperand operand;

    /**
     * The ExpressionTree constructor.
     */
    protected UnaryOperator(IOperand operand) {
        Conditions.validateNotNull(
            operand,
            "The operand of an unary operator.");

        this.operand = operand;
    }

    /**
     * Gets an operand.
     */
    @Override
    public IOperand getOperand() {
        return this.operand;
    }
}
