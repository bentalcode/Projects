package datastructures.expressiontree.interfaces;

import datastructures.binarytree.interfaces.IBinaryTree;

/**
 * The IExpressionTree interface defines an expression tree.
 */
public interface IExpressionTree {
    /**
     * Gets the corresponding expression as a binary tree.
     */
    IBinaryTree<String, IExpressionTreeElement> getTree();
}
