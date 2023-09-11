package datastructures.expressiontree.core;

import datastructures.expressiontree.interfaces.IDivideOperator;
import datastructures.expressiontree.interfaces.IOperand;
import datastructures.expressiontree.interfaces.IExpressionTreeSymbols;

/**
 * The DivideOperator class implements a divide operator of an expression tree.
 */
public final class DivideOperator extends BinaryOperator implements IDivideOperator {
    /**
     * The DivideOperator constructor.
     */
    public DivideOperator(IOperand lhsOperand, IOperand rhsOperand) {
        super(lhsOperand, rhsOperand);
    }

    /**
     * Evaluates a result of an expression element.
     */
    @Override
    public double evaluate() {
        return this.getLeftOperand().evaluate() / this.getRightOperand().evaluate();
    }

    /**
     * Checks whether this token is a divide operator.
     */
    public static boolean isOperator(String token) {
        return token.length() == 1 && token.charAt(0) == IExpressionTreeSymbols.DivideOperator;
    }
}
