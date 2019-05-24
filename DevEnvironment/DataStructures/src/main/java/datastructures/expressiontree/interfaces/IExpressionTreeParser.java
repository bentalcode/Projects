package datastructures.expressiontree.interfaces;

import datastructures.binarytree.interfaces.IBinaryTree;

/**
 * The IExpressionTreeParser interface defines a parser of an expression tree.
 */
public interface IExpressionTreeParser {
    /**
     * Parses an expression tree.
     */
    IBinaryTree<String, IExpressionTreeElement> parse();
}
