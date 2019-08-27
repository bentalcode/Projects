package datastructures.binarytree.core;

import base.interfaces.IIterator;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import java.util.Stack;

/**
 * The BinaryTreePostorderIterator class implements a postorder iterator of a binary tree.
 */
public final class BinaryTreePostorderIterator<TKey extends Comparable<TKey>, TValue> implements IIterator<IBinaryTreeNode<TKey, TValue>> {
    private final IBinaryTreeNode<TKey, TValue> root;
    private final Stack<IBinaryTreeNode<TKey, TValue>> stack = new Stack<>();

    /**
     * Creates a new postorder iterator of a binary tree.
     */
    public static <TKey extends Comparable<TKey>, TValue> IIterator<IBinaryTreeNode<TKey, TValue>> of(IBinaryTreeNode<TKey, TValue> root) {
        return new BinaryTreePostorderIterator<>(root);
    }

    /**
     * The BinaryTreePostorderIterator constructor.
     */
    private BinaryTreePostorderIterator(IBinaryTreeNode<TKey, TValue> root) {
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

        IBinaryTreeNode<TKey, TValue> currElement;

        while (true) {
            IBinaryTreeNode<TKey, TValue> activeElement = this.stack.pop();

            if (activeElement.hasRightChild() &&
                !this.stack.empty() && activeElement.getRightChild() == this.stack.peek()) {

                IBinaryTreeNode<TKey, TValue> rightChildNode = this.stack.pop();
                this.stack.push(activeElement);
                activeElement = rightChildNode;

                this.moveMinimumNode(activeElement);
            }
            else {
                currElement = activeElement;
                break;
            }
        }

        return currElement;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.moveMinimumNode(this.root);
    }

    /**
     * Moves to the minimum node.
     */
    private void moveMinimumNode(IBinaryTreeNode<TKey, TValue> node) {
        IBinaryTreeNode<TKey, TValue> currNode = node;

        while (currNode != null) {
            if (currNode.hasRightChild()) {
                this.stack.push(currNode.getRightChild());
            }

            this.stack.push(currNode);

            currNode = currNode.getLeftChild();
        }
    }
}
