package datastructures.expressiontree.core;

import base.core.Conditions;
import datastructures.binarytree.interfaces.IBinaryTree;
import datastructures.expressiontree.interfaces.IExpressionTree;
import datastructures.expressiontree.interfaces.IExpressionTreeElement;
import datastructures.expressiontree.interfaces.IExpressionTreeParser;

/**
 * The ExpressionTree class implements an expression tree.
 */
public final class ExpressionTree implements IExpressionTree {
    private final IBinaryTree<String, IExpressionTreeElement> tree;

    /**
     * The ExpressionTree constructor.
     */
    public ExpressionTree(IBinaryTree<String, IExpressionTreeElement> tree) {
        Conditions.validateNotNull(
            tree,
            "The expression tree.");

        this.tree = tree;
    }

    /**
     * Gets the corresponding expression as a binary tree.
     */
    @Override
    public IBinaryTree<String, IExpressionTreeElement> getTree() {
        return this.tree;
    }

    /**
     * Parses an expression as a binary tree.
     */
    public static IBinaryTree<String, IExpressionTreeElement> parse(String expression) {
        IExpressionTreeParser parser = new ExpressionTreeParser(expression);

        return parser.parse();
    }
}
