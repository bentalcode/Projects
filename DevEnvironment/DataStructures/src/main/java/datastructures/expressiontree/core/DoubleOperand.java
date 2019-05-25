package datastructures.expressiontree.core;

import datastructures.expressiontree.interfaces.IDoubleOperand;

/**
 * The DoubleOperand class implements a double operand of an expression tree.
 */
public final class DoubleOperand implements IDoubleOperand {
    private final double value;

    /**
     * The DoubleOperand constructor.
     */
    public DoubleOperand(double value) {
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
     * Gets a double value of an operand.
     */
    @Override
    public double getValue() {
        return this.value;
    }
}
