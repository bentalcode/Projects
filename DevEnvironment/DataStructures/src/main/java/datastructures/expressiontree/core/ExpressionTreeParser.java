package datastructures.expressiontree.core;

import base.core.Conditions;
import datastructures.binarytree.interfaces.IBinaryTree;
import datastructures.expressiontree.interfaces.IExpressionTreeElement;
import datastructures.expressiontree.interfaces.IExpressionTreeParser;

/**
 * The IExpressionTreeParser class implements a parser of an expression tree.
 */
public final class ExpressionTreeParser implements IExpressionTreeParser {
    private final String expression;

    /**
     * The ExpressionTree constructor.
     */
    public ExpressionTreeParser(String expression) {
        Conditions.validateNotNull(
            expression,
            "The expression string.");

        this.expression = expression;
    }

    /**
     * Gets the corresponding binary tree.
     */
    @Override
    public IBinaryTree<String, IExpressionTreeElement> parse() {
        String[] tokens = this.expression.split(" ");
        transformToPostfixExpression(tokens);

        throw new UnsupportedOperationException();
    }

    /**
     * Transforms an expression to postfix form.
     */
    private void transformToPostfixExpression(String[] tokens) {
    }
}
