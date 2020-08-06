package datastructures.binarytree.core;

import base.interfaces.IIterator;
import datastructures.binarytree.interfaces.IBinaryTreeLogic;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import java.util.Stack;

/**
 * The BinaryTreeInorderIterator class implements an inorder iterator of a binary tree.
 */
public final class BinaryTreeInorderIterator<TKey extends Comparable<TKey>, TValue> implements IIterator<IBinaryTreeNode<TKey, TValue>> {
    private final IBinaryTreeNode<TKey, TValue> root;
    private final IBinaryTreeLogic<TKey, TValue> binaryTreeLogic = new BinaryTreeLogic<>();
    private Stack<IBinaryTreeNode<TKey, TValue>> stack;

    /**
     * Creates an inorder iterator of a binary tree.
     */
    public static <TKey extends Comparable<TKey>, TValue> IIterator<IBinaryTreeNode<TKey, TValue>> of(IBinaryTreeNode<TKey, TValue> root) {
        return new BinaryTreeInorderIterator<>(root);
    }

    /**
     * The BinaryTreeInorderIterator constructor.
     */
    private BinaryTreeInorderIterator(IBinaryTreeNode<TKey, TValue> root) {
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

        IBinaryTreeNode<TKey, TValue> currNode = this.stack.pop();

        if (currNode.hasRightChild()) {
            this.binaryTreeLogic.moveMinimumNode(currNode.getRightChild(), this.stack);
        }

        return currNode;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.stack = new Stack<>();

        if (this.root != null) {
            this.binaryTreeLogic.moveMinimumNode(this.root, this.stack);
        }
    }
}
