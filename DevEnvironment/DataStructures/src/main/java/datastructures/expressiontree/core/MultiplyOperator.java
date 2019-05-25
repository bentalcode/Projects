package datastructures.expressiontree.core;

import datastructures.expressiontree.interfaces.IMultiplyOperator;
import datastructures.expressiontree.interfaces.IOperand;
import datastructures.expressiontree.interfaces.IExpressionTreeSymbols;

/**
 * The MultiplyOperator class implements a multiply operator of an expression tree.
 */
public final class MultiplyOperator extends BinaryOperator
    implements IMultiplyOperator {

    /**
     * The MultiplyOperator constructor.
     */
    public MultiplyOperator(IOperand lhsOperand, IOperand rhsOperand) {
        super(lhsOperand, rhsOperand);
    }

    /**
     * Checks whether this token is a multiply operator.
     */
    public static boolean isOperator(String token) {
        return token.length() == 1 && token.charAt(0) == IExpressionTreeSymbols.MultiplyOperator;
    }
}
