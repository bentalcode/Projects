package datastructures.binarytree.core;

import base.core.Casting;
import base.interfaces.IBinaryComparator;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import java.util.Stack;

/**
 * The BinaryTreeEndNode class implements an internal end nodes of a binary tree, which is used for serialization.
 */
public final class BinaryTreeEndNode<TKey extends Comparable<TKey>, TValue> implements IBinaryTreeNode<TKey, TValue> {
    private final IBinaryComparator<IBinaryTreeNode<TKey, TValue>> comparator = BinaryTreeNode.DefaultComparator();

    /**
     * The BinaryTreeEndNode constructor.
     */
    public BinaryTreeEndNode() {
    }

    /**
     * Gets the key of the node.
     */
    @Override
    public TKey getKey() {
        return null;
    }

    /**
     * Gets the value of the node.
     */
    @Override
    public TValue getValue() {
        return null;
    }

    /**
     * Sets the value of the node.
     */
    @Override
    public void setValue(TValue value) {
    }

    /**
     * Gets the node of a left child.
     */
    @Override
    public IBinaryTreeNode<TKey, TValue> getLeftChild() {
        return null;
    }

    /**
     * Gets the node of a right child.
     */
    @Override
    public IBinaryTreeNode<TKey, TValue> getRightChild() {
        return null;
    }

    /**
     * Sets the node of a left child.
     */
    @Override
    public void setLeftChild(IBinaryTreeNode<TKey, TValue> node) {
    }

    /**
     * Sets the node of a right child.
     */
    @Deprecated
    public void setRightChild(IBinaryTreeNode<TKey, TValue> node) {
    }

    /**
     * Checks whether there is a left child.
     */
    @Override
    public boolean hasLeftChild() {
        return false;
    }

    /**
     * Checks whether there is a right child.
     */
    @Override
    public boolean hasRightChild() {
        return false;
    }

    /**
     * Gets the minimum node.
     */
    @Override
    public IBinaryTreeNode<TKey, TValue> getMinimumNode() {
        return null;
    }

    /**
     * Moves to the minimum node by storing the nodes in the stack.
     */
    @Override
    public void moveMinimumNode(Stack<IBinaryTreeNode<TKey, TValue>> stack) {
    }

    /**
     * Gets the maximum node.
     */
    @Override
    public IBinaryTreeNode<TKey, TValue> getMaximumNode() {
        return null;
    }

    /**
     * Moves to the maximum node by storing the nodes in the stack.
     */
    @Override
    public void moveMaximumNode(Stack<IBinaryTreeNode<TKey, TValue>> stack) {
    }

    /**
     * Gets a hash code of this instance.
     */
    @Override
    public int hashCode() {
        return 0;
    }

    /**
     * Gets the hash code of a node of a B+ tree.
     */
    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }

        if (!this.getClass().isInstance(obj)) {
            return false;
        }

        return this.isEqual(Casting.cast(obj));
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean isEqual(IBinaryTreeNode<TKey, TValue> other) {
        return this.comparator.isEqual(this, other);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(IBinaryTreeNode<TKey, TValue> other) {
        return this.comparator.compareTo(this, other);
    }
}
