package datastructures.binarytree.core;

import base.interfaces.IReverseIterator;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import java.util.Stack;

/**
 * The BinaryTreeReverseIterator class implements a reverse iterator of a binary tree.
 */
public class BinaryTreeReverseIterator<TKey extends Comparable<TKey>, TValue> implements IReverseIterator<IBinaryTreeNode<TKey, TValue>> {
    private final IBinaryTreeNode<TKey, TValue> root;
    private final Stack<IBinaryTreeNode<TKey, TValue>> stack = new Stack<>();

    /**
     * Creates a new reverse iterator of a binary tree.
     */
    public static <TKey extends Comparable<TKey>, TValue> IReverseIterator<IBinaryTreeNode<TKey, TValue>> of(IBinaryTreeNode<TKey, TValue> root) {
        return new BinaryTreeReverseIterator<>(root);
    }

    /**
     * The BinaryTreeReverseIterator constructor.
     */
    private BinaryTreeReverseIterator(IBinaryTreeNode<TKey, TValue> root) {
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
            currElement.getRightChild().moveMaximumNode(this.stack);
        }

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        if (this.root != null) {
            this.root.moveMaximumNode(this.stack);
        }
    }
}
