package datastructures.binarytree.core;

import base.interfaces.IReverseIterator;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import java.util.Stack;

/**
 * The BinaryTreeReverseInorderIterator class implements a reverse inorder iterator of a binary tree.
 */
public final class BinaryTreeReverseInorderIterator<TKey extends Comparable<TKey>, TValue> implements IReverseIterator<IBinaryTreeNode<TKey, TValue>> {
    private final IBinaryTreeNode<TKey, TValue> root;
    private Stack<IBinaryTreeNode<TKey, TValue>> stack;

    /**
     * Creates a new reverse inorder iterator of a binary tree.
     */
    public static <TKey extends Comparable<TKey>, TValue> IReverseIterator<IBinaryTreeNode<TKey, TValue>> of(IBinaryTreeNode<TKey, TValue> root) {
        return new BinaryTreeReverseInorderIterator<>(root);
    }

    /**
     * The BinaryTreeReverseInorderIterator constructor.
     */
    private BinaryTreeReverseInorderIterator(IBinaryTreeNode<TKey, TValue> root) {
        this.root = root;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return !this.stack.empty();
    }

    /**
     * Gets the next element.
     */
    @Override
    public IBinaryTreeNode<TKey, TValue> next() {
        assert(this.hasNext());

        IBinaryTreeNode<TKey, TValue> currElement = this.stack.pop();

        if (currElement.hasLeftChild()) {
            currElement.getLeftChild().moveMaximumNode(this.stack);
        }

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.stack = new Stack<>();

        if (this.root != null) {
            this.root.moveMaximumNode(this.stack);
        }
    }
}
