package datastructures.binarytree.core;

import base.interfaces.IIterator;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import java.util.LinkedList;
import java.util.Queue;

/**
 * The BinaryTreeLevelOrderWithEndNodesIterator class implements a level order iterator of a binary tree,
 * which iterates over the end nodes as well.
 */
public final class BinaryTreeLevelOrderWithEndNodesIterator<TKey extends Comparable<TKey>, TValue>
    implements IIterator<IBinaryTreeNode<TKey, TValue>> {

    private final IBinaryTreeNode<TKey, TValue> root;
    private Queue<IBinaryTreeNode<TKey, TValue>> queue;

    /**
     * Creates a level order iterator of a binary tree.
     */
    public static <TKey extends Comparable<TKey>, TValue> IIterator<IBinaryTreeNode<TKey, TValue>> make(IBinaryTreeNode<TKey, TValue> root) {
        return new BinaryTreeLevelOrderWithEndNodesIterator<>(root);
    }

    /**
     * The BinaryTreeLevelOrderIterator constructor.
     */
    private BinaryTreeLevelOrderWithEndNodesIterator(IBinaryTreeNode<TKey, TValue> root) {
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

        if (currNode.getClass().isAssignableFrom(BinaryTreeEndNode.class)) {
            return currNode;
        }

        this.queue.offer(currNode.hasLeftChild() ? currNode.getLeftChild() : BinaryTreeNodes.endNode());
        this.queue.offer(currNode.hasRightChild() ? currNode.getRightChild() : BinaryTreeNodes.endNode());

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
