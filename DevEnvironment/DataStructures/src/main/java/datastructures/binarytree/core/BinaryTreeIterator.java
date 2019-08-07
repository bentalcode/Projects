package datastructures.binarytree.core;

import base.interfaces.IIterator;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import java.util.Stack;

/**
 * The BinaryTreeIterator class implements an iterator of a binary tree.
 */
public class BinaryTreeIterator<TKey extends Comparable<TKey>, TValue> implements IIterator<IBinaryTreeNode<TKey, TValue>> {
    private final IBinaryTreeNode<TKey, TValue> root;
    private final Stack<IBinaryTreeNode<TKey, TValue>> stack = new Stack<>();

    /**
     * Creates a new iterator of a binary tree.
     */
    public static <TKey extends Comparable<TKey>, TValue> IIterator<IBinaryTreeNode<TKey, TValue>> of(IBinaryTreeNode<TKey, TValue> root) {
        return new BinaryTreeIterator<>(root);
    }

    /**
     * The BinaryTreeIterator constructor.
     */
    private BinaryTreeIterator(IBinaryTreeNode<TKey, TValue> root) {
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

        if (currElement.hasRightChild()) {
            currElement.getRightChild().moveMinimumNode(this.stack);
        }

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        if (this.root != null) {
            this.root.moveMinimumNode(this.stack);
        }
    }
}
