package datastructures.expressiontree.interfaces;

/**
 * The IMultiplyOperator interface defines a multiply operator of an expression tree.
 */
public interface IMultiplyOperator extends IBinaryOperator {
    /**
     * Evaluates a result of an expression element.
     */
    double evaluate();
}
