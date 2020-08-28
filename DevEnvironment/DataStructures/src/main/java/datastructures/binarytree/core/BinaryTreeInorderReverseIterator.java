package datastructures.binarytree.core;

import base.interfaces.IReverseIterator;
import datastructures.binarytree.interfaces.IBinaryTreeLogic;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import java.util.Stack;

/**
 * The BinaryTreeInorderReverseIterator class implements a reverse inorder iterator of a binary tree.
 */
public final class BinaryTreeInorderReverseIterator<TKey extends Comparable<TKey>, TValue> implements IReverseIterator<IBinaryTreeNode<TKey, TValue>> {
    private final IBinaryTreeNode<TKey, TValue> root;
    private Stack<IBinaryTreeNode<TKey, TValue>> stack;
    private final IBinaryTreeLogic<TKey, TValue> binaryTreeLogic = new BinaryTreeLogic<>();

    /**
     * Creates a reverse inorder iterator of a binary tree.
     */
    public static <TKey extends Comparable<TKey>, TValue> IReverseIterator<IBinaryTreeNode<TKey, TValue>> make(IBinaryTreeNode<TKey, TValue> root) {
        return new BinaryTreeInorderReverseIterator<>(root);
    }

    /**
     * The BinaryTreeInorderReverseIterator constructor.
     */
    private BinaryTreeInorderReverseIterator(IBinaryTreeNode<TKey, TValue> root) {
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

        if (currNode.hasLeftChild()) {
            this.binaryTreeLogic.moveMaximumNode(currNode.getLeftChild(), this.stack);
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
            IBinaryTreeLogic<TKey, TValue> binaryTreeLogic = new BinaryTreeLogic<>();
            binaryTreeLogic.moveMaximumNode(this.root, this.stack);
        }
    }
}
