package datastructures.binarytree.core;

import base.interfaces.IIterator;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import java.util.LinkedList;
import java.util.Queue;

/**
 * The BinaryTreeLevelOrderIterator class implements a level order iterator of a binary tree.
 */
public final class BinaryTreeLevelOrderIterator<TKey extends Comparable<TKey>, TValue> implements IIterator<IBinaryTreeNode<TKey, TValue>> {
    private final IBinaryTreeNode<TKey, TValue> root;
    private Queue<IBinaryTreeNode<TKey, TValue>> queue;

    /**
     * Creates a level order iterator of a binary tree.
     */
    public static <TKey extends Comparable<TKey>, TValue> IIterator<IBinaryTreeNode<TKey, TValue>> of(IBinaryTreeNode<TKey, TValue> root) {
        return new BinaryTreeLevelOrderIterator<>(root);
    }

    /**
     * The BinaryTreeLevelOrderIterator constructor.
     */
    private BinaryTreeLevelOrderIterator(IBinaryTreeNode<TKey, TValue> root) {
        this.root = root;

        this.reset();
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return !this.queue.isEmpty();
    }

    /**
     * Gets the next element.
     */
    @Override
    public IBinaryTreeNode<TKey, TValue> next() {
        assert(this.hasNext());

        IBinaryTreeNode<TKey, TValue> currNode = this.queue.poll();

        if (currNode.hasLeftChild()) {
            this.queue.offer(currNode.getLeftChild());
        }

        if (currNode.hasRightChild()) {
            this.queue.offer(currNode.getRightChild());
        }

        return currNode;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.queue = new LinkedList<>();

        if (this.root != null) {
            this.queue.offer(this.root);
        }
    }
}
