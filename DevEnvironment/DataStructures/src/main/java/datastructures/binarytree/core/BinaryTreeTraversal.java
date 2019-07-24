package datastructures.binarytree.core;

import base.core.Conditions;
import base.interfaces.IVisitor;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import datastructures.binarytree.interfaces.IBinaryTreeTraversal;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

/**
 * The BinaryTreeTraversal class implements various search methods in a binary tree.
 */
public final class BinaryTreeTraversal<TKey extends Comparable<TKey>, TValue> implements IBinaryTreeTraversal<TKey, TValue> {
    /**
     * The BinaryTreeTraversal constructor.
     */
    public BinaryTreeTraversal() {
    }

    /**
     * Performs a Breadth-First search.
     * Implemented with a queue.
     */
    @Override
    public void breadthFirstSearch(
        IBinaryTreeNode<TKey, TValue> root,
        IVisitor<IBinaryTreeNode<TKey, TValue>> visitor) {

        this.validate(visitor);

        if (root == null) {
            return;
        }

        Queue<IBinaryTreeNode<TKey, TValue>> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            IBinaryTreeNode<TKey, TValue> currNode = queue.poll();

            visitor.visit(currNode);

            if (currNode.getLeftChild() != null) {
                queue.offer(currNode.getLeftChild());
            }

            if (currNode.getRightChild() != null) {
                queue.offer(currNode.getRightChild());
            }
        }
    }

    /**
     * Performs a Depth-First search.
     * Implemented with a stack.
     */
    @Override
    public void depthFirstSearch(
        IBinaryTreeNode<TKey, TValue> root,
        IVisitor<IBinaryTreeNode<TKey, TValue>> visitor) {

        this.validate(visitor);

        if (root == null) {
            return;
        }

        Stack<IBinaryTreeNode<TKey, TValue>> stack = new Stack<>();

        stack.push(root);

        while (!stack.empty()) {
            IBinaryTreeNode<TKey, TValue> currNode = stack.pop();

            visitor.visit(currNode);

            if (currNode.getRightChild() != null) {
                stack.push(currNode.getRightChild());
            }

            if (currNode.getLeftChild() != null) {
                stack.push(currNode.getLeftChild());
            }
        }
    }
    
    /**
     * Performs a pre-order search.
     */
    @Override
    public void preOrder(
        IBinaryTreeNode<TKey, TValue> root,
        IVisitor<IBinaryTreeNode<TKey, TValue>> visitor) {

        this.validate(visitor);

        if (root == null) {
            return;
        }

        //
        // Traverse the root...
        //
        visitor.visit(root);

        //
        // Traverse the left sub tree...
        //
        this.inOrder(root.getLeftChild(), visitor);

        //
        // Traverse the right sub root...
        //
        this.inOrder(root.getRightChild(), visitor);
    }

    /**
     * Performs an in-order search.
     */
    @Override
    public void inOrder(
        IBinaryTreeNode<TKey, TValue> root,
        IVisitor<IBinaryTreeNode<TKey, TValue>> visitor) {

        this.validate(visitor);

        if (root == null) {
            return;
        }

        //
        // Traverse the left sub tree...
        //
        this.inOrder(root.getLeftChild(), visitor);

        //
        // Traverse the root...
        //
        visitor.visit(root);

        //
        // Traverse the right sub root...
        //
        this.inOrder(root.getRightChild(), visitor);
    }

    /**
     * Performs a post-order search.
     */
    @Override
    public void postOrder(
        IBinaryTreeNode<TKey, TValue> root,
        IVisitor<IBinaryTreeNode<TKey, TValue>> visitor) {

        this.validate(visitor);

        if (root == null) {
            return;
        }

        //
        // Traverse the left sub tree...
        //
        this.inOrder(root.getLeftChild(), visitor);

        //
        // Traverse the right sub root...
        //
        this.inOrder(root.getRightChild(), visitor);

        //
        // Traverse the root...
        //
        visitor.visit(root);
    }

    /**
     * Validates a visitor of a tree node.
     */
    private void validate(IVisitor<IBinaryTreeNode<TKey, TValue>> visitor) {
        Conditions.validateNotNull(
            visitor,
            "The visitor of a binary tree node.");
    }
}
