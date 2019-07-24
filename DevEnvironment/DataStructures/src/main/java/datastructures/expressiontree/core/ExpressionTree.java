package datastructures.expressiontree.core;

import base.core.Conditions;
import datastructures.expressiontree.ExpressionTreeException;
import datastructures.expressiontree.interfaces.IExpressionTree;
import datastructures.expressiontree.interfaces.IExpressionTreeElement;
import datastructures.expressiontree.interfaces.IExpressionTreeParser;

/**
 * The ExpressionTree class implements an expression tree.
 */
public final class ExpressionTree implements IExpressionTree {
    private IExpressionTreeElement root;

    /**
     * The ExpressionTree constructor.
     */
    public ExpressionTree() {
    }

    /**
     * The ExpressionTree constructor.
     */
    public ExpressionTree(IExpressionTreeElement root) {
        Conditions.validateNotNull(
            root,
            "The root of an expression tree.");

        this.root = root;
    }

    /**
     * Gets the root of an expression tree.
     */
    @Override
    public IExpressionTreeElement getRoot() {
        return this.root;
    }

    /**
     * Evaluates a result of an expression tree.
     */
    @Override
    public double evaluate() {
        if (this.root == null) {
            String errorMessage = "The expression tree does not include any expressions for evaluating.";
            throw new ExpressionTreeException(errorMessage);
        }

        IExpressionTreeElement root = this.root;

        double result = root.evaluate();

        return result;
    }

    /**
     * Parses an expression as a binary tree.
     */
    public static IExpressionTree parse(String expression) {
        IExpressionTreeParser parser = new ExpressionTreeParser(expression);
        return parser.parse();
    }
}
