package datastructures.expressiontree.interfaces;

/**
 * The IExpressionTree interface defines an expression tree.
 */
public interface IExpressionTree {
    /**
     * Gets the root of an expression tree.
     */
    IExpressionTreeElement getRoot();

    /**
     * Evaluates a result of an expression tree.
     */
    double evaluate();
}
