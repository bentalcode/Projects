package datastructures.binarytree.core;

import base.core.Conditions;
import datastructures.binarytree.interfaces.IBinaryTreeLogic;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import java.util.Stack;

/**
 * The BinaryTreeLogic class implements logic of a binary tree.
 */
public final class BinaryTreeLogic<TKey extends Comparable<TKey>, TValue> implements IBinaryTreeLogic<TKey, TValue> {
    /**
     * The BinaryTreeLogic constructor.
     */
    public BinaryTreeLogic() {
    }

    /**
     * Gets the minimum node.
     */
    @Override
    public IBinaryTreeNode<TKey, TValue> getMinimumNode(IBinaryTreeNode<TKey, TValue> root) {
        IBinaryTreeNode<TKey, TValue> currNode = root;

        while (currNode != null && currNode.hasLeftChild()) {
            currNode = currNode.getLeftChild();
        }

        return currNode;
    }

    /**
     * Moves to the minimum node by storing the nodes in the stack.
     */
    @Override
    public void moveMinimumNode(
        IBinaryTreeNode<TKey, TValue> root,
        Stack<IBinaryTreeNode<TKey, TValue>> stack) {

        Conditions.validateNotNull(
            stack,
            "The stack.");

        IBinaryTreeNode<TKey, TValue> currNode  = root;

        while (currNode != null) {
            stack.push(currNode);

            currNode = currNode.getLeftChild();
        }
    }

    /**
     * Gets the maximum node.
     */
    @Override
    public IBinaryTreeNode<TKey, TValue> getMaximumNode(IBinaryTreeNode<TKey, TValue> root) {
        IBinaryTreeNode<TKey, TValue> currNode = root;

        while (currNode != null && currNode.hasRightChild()) {
            currNode = currNode.getRightChild();
        }

        return currNode;
    }

    /**
     * Moves to the maximum node by storing the nodes in the stack.
     */
    @Override
    public void moveMaximumNode(
        IBinaryTreeNode<TKey, TValue> root,
        Stack<IBinaryTreeNode<TKey, TValue>> stack) {

        Conditions.validateNotNull(
            stack,
            "The stack.");

        IBinaryTreeNode<TKey, TValue> currNode = root;

        while (currNode != null) {
            stack.push(currNode);

            currNode = currNode.getRightChild();
        }
    }
}
