package datastructures.expressiontree.core;

import base.core.Enums;
import datastructures.expressiontree.interfaces.IExpressionTreeSymbols;
import datastructures.expressiontree.interfaces.IOperand;
import datastructures.expressiontree.interfaces.IUnaryOperator;

/**
 * The UnaryOperatorType enum defines types of an unary operator of an expression tree.
 */
public enum UnaryOperatorType {
    /**
     * The square root operator.
     */
    SquareRoot (IExpressionTreeSymbols.SquareRootOperator) {

        /**
         * Creates an unary operator.
         */
        public IUnaryOperator create(IOperand operand) {
            return new SquareRootOperator(operand);
        }
    };

    private final String name;

    /**
     * The UnaryOperatorType constructor.
     */
    UnaryOperatorType(String name) {
        this.name = name;
    }

    /**
     * Creates an unary operator.
     */
    public abstract IUnaryOperator create(IOperand operand);

    /**
     * Gets the string representation of this instance.
     */
    @Override
    public String toString() {
        return this.name;
    }

    /**
     * Parses an unary operator type.
     */
    public static UnaryOperatorType parse(String str) {
        return Enums.parse(UnaryOperatorType.class, str);
    }

    /**
     * Tries to parse an unary operator type.
     */
    public static UnaryOperatorType tryParse(String str) {
        return Enums.tryParse(UnaryOperatorType.class, str);
    }
}
