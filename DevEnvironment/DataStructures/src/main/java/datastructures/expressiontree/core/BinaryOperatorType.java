package datastructures.expressiontree.core;

import base.core.Enums;
import datastructures.expressiontree.interfaces.IBinaryOperator;
import datastructures.expressiontree.interfaces.IExpressionTreeSymbols;
import datastructures.expressiontree.interfaces.IOperand;

/**
 * The BinaryOperatorType enum defines types of a binary operator of an expression tree.
 */
public enum BinaryOperatorType {
    /**
     * The add operator.
     */
    AddOperator(String.valueOf(IExpressionTreeSymbols.AddOperator)) {
        /**
         * Creates a binary operator.
         */
        public IBinaryOperator create(IOperand lhsOperand, IOperand rhsOperand) {
            return new AddOperator(lhsOperand, rhsOperand);
        }
    },

    /**
     * The subtract operator.
     */
    SubtractOperator(String.valueOf(IExpressionTreeSymbols.SubtractOperator)) {
        /**
         * Creates a binary operator.
         */
        public IBinaryOperator create(IOperand lhsOperand, IOperand rhsOperand) {
            return new SubtractOperator(lhsOperand, rhsOperand);
        }
    },

    /**
     * The multiply operator.
     */
    MultiplyOperator(String.valueOf(IExpressionTreeSymbols.MultiplyOperator)) {
        /**
         * Creates a binary operator.
         */
        public IBinaryOperator create(IOperand lhsOperand, IOperand rhsOperand) {
            return new MultiplyOperator(lhsOperand, rhsOperand);
        }
    },

    /**
     * The divide operator.
     */
    DivideOperator(String.valueOf(IExpressionTreeSymbols.DivideOperator)) {
        /**
         * Creates a binary operator.
         */
        public IBinaryOperator create(IOperand lhsOperand, IOperand rhsOperand) {
            return new DivideOperator(lhsOperand, rhsOperand);
        }
    },

    /**
     * The pow operator.
     */
    PowOperator(String.valueOf(IExpressionTreeSymbols.PowOperator)) {
        /**
         * Creates a binary operator.
         */
        public IBinaryOperator create(IOperand lhsOperand, IOperand rhsOperand) {
            return new PowOperator(lhsOperand, rhsOperand);
        }
    };

    private final String name;

    /**
     * The BinaryOperatorType constructor.
     */
    BinaryOperatorType(String name) {
        this.name = name;
    }

    /**
     * Creates a binary operator.
     */
    public abstract IBinaryOperator create(IOperand lhsOperand, IOperand rhsOperand);

    /**
     * Gets the string representation of this instance.
     */
    @Override
    public String toString() {
        return this.name;
    }

    /**
     * Parses a binary operator type.
     */
    public static BinaryOperatorType parse(String str) {
        return Enums.parse(BinaryOperatorType.class, str);
    }

    /**
     * Tries to parse a binary operator type.
     */
    public static BinaryOperatorType tryParse(String str) {
        return Enums.tryParse(BinaryOperatorType.class, str);
    }
}
