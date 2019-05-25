package datastructures.expressiontree.core;

import datastructures.expressiontree.interfaces.IExpressionTreeElement;
import datastructures.expressiontree.interfaces.IExpressionTreeSymbols;

/**
 * The ExpressionTreeElement class implements an element of an expression tree.
 */
public abstract class ExpressionTreeElement implements IExpressionTreeElement {
    /**
     * The ExpressionTree constructor.
     */
    protected ExpressionTreeElement() {
    }

    /**
     * Checks whether this token is an operand.
     */
    public static boolean isOperand(String token) {
        return
            !ExpressionTreeElement.isOperator(token) &&
            !ExpressionTreeElement.isOpenParentheses(token) &&
            !ExpressionTreeElement.isCloseParentheses(token);
    }

    /**
     * Checks whether this token is an operator.
     */
    public static boolean isOperator(String token) {
        return
            ExpressionTreeElement.isUnaryOperator(token) ||
            ExpressionTreeElement.isBinaryOperator(token);
    }

    /**
     * Checks whether this token is an unary operator.
     */
    public static boolean isUnaryOperator(String token) {
        return SquareRootOperator.isOperator(token);
    }

    /**
     * Checks whether this token is a binary operator.
     */
    public static boolean isBinaryOperator(String token) {
        return
            AddOperator.isOperator(token) ||
            SubtractOperator.isOperator(token) ||
            MultiplyOperator.isOperator(token) ||
            DivideOperator.isOperator(token) ||
            PowOperator.isOperator(token);
    }

    /**
     * Checks whether this token is an open parentheses.
     */
    public static boolean isOpenParentheses(String token) {
        return token.length() == 1 && token.charAt(0) == IExpressionTreeSymbols.OpenParentheses;
    }

    /**
     * Checks whether this token is a close parentheses.
     */
    public static boolean isCloseParentheses(String token) {
        return token.length() == 1 && token.charAt(0) == IExpressionTreeSymbols.CloseParentheses;
    }
}
