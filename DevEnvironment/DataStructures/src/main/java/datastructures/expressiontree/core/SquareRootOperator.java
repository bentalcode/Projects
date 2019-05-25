package datastructures.expressiontree.core;

import datastructures.expressiontree.interfaces.IExpressionTreeSymbols;
import datastructures.expressiontree.interfaces.IOperand;
import datastructures.expressiontree.interfaces.ISquareRootOperator;

/**
 * The SquareRootOperator class implements a square root operator of an expression tree.
 */
public final class SquareRootOperator extends UnaryOperator implements ISquareRootOperator {
    /**
     * The SquareRootOperator constructor.
     */
    public SquareRootOperator(IOperand operand) {
        super(operand);
    }

    /**
     * Evaluates a result of an expression element.
     */
    @Override
    public double evaluate() {
        return Math.sqrt(this.getOperand().evaluate());
    }

    /**
     * Checks whether this token is an add operator.
     */
    public static boolean isOperator(String token) {
        return token.equals(IExpressionTreeSymbols.SquareOperator);
    }
}
