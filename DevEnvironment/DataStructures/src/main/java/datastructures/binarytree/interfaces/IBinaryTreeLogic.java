package datastructures.binarytree.interfaces;

import java.util.Stack;

/**
 * The IBinaryTreeLogic interface defines logic of a binary tree.
 */
public interface IBinaryTreeLogic<TKey extends Comparable<TKey>, TValue> {
    /**
     * Gets the minimum node.
     */
    IBinaryTreeNode<TKey, TValue> getMinimumNode(IBinaryTreeNode<TKey, TValue> root);

    /**
     * Moves to the minimum node by storing the nodes in the stack.
     */
    void moveMinimumNode(
        IBinaryTreeNode<TKey, TValue> root,
        Stack<IBinaryTreeNode<TKey, TValue>> stack);

    /**
     * Gets the maximum node.
     */
    IBinaryTreeNode<TKey, TValue> getMaximumNode(IBinaryTreeNode<TKey, TValue> root);

    /**
     * Moves to the maximum node by storing the nodes in the stack.
     */
    void moveMaximumNode(
        IBinaryTreeNode<TKey, TValue> root,
        Stack<IBinaryTreeNode<TKey, TValue>> stack);
}
