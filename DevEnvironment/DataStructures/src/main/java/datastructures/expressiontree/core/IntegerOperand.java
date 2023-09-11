package datastructures.expressiontree.core;

import datastructures.expressiontree.interfaces.IIntegerOperand;

/**
 * The IntegerOperand class implements an integer operand of an expression tree.
 */
public final class IntegerOperand implements IIntegerOperand {
    private final int value;

    /**
     * The IntegerOperand constructor.
     */
    public IntegerOperand(int value) {
        this.value = value;
    }

    /**
     * Evaluates a result of an expression element.
     */
    @Override
    public double evaluate() {
        return this.value;
    }

    /**
     * Gets an integer value of an operand.
     */
    @Override
    public int getValue() {
        return this.value;
    }
}
