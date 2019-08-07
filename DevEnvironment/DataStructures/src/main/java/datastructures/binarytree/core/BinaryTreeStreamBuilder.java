package datastructures.binarytree.core;

import base.core.Conditions;
import base.interfaces.IBuilder;
import base.interfaces.IIterator;
import datastructures.binarytree.interfaces.IBinaryTree;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import datastructures.binarytree.interfaces.IBinaryTreeNodeIterator;

/**
 * The BinaryTreeStreamBuilder class implements a builder for a binary tree from a stream.
 */
public final class BinaryTreeStreamBuilder<TKey extends Comparable<TKey>, TValue> implements IBuilder<IBinaryTree<TKey, TValue>> {
    private final IBinaryTreeNodeIterator<IBinaryTreeNode<TKey, TValue>> iterator;

    /**
     * The BinaryTreeBuilder constructor.
     */
    public BinaryTreeStreamBuilder(IBinaryTreeNodeIterator<IBinaryTreeNode<TKey, TValue>> iterator) {
        Conditions.validateNotNull(
            iterator,
            "The iterator of binary nodes.");

        this.iterator = iterator;
    }

    /**
     * Builds the binary tree.
     */
    @Override
    public IBinaryTree<TKey, TValue> build() {
        boolean previousStatus = this.iterator.includeEndNodes();
        IBinaryTreeNode<TKey, TValue> rootNode = this.read(this.iterator);
        this.iterator.setSkipEndNodesStatus(previousStatus);

        IBinaryTree<TKey, TValue> tree = new BinaryTree<>(rootNode);

        return tree;
    }

    /**
     * Reads the tree from an input stream.
     */
    private IBinaryTreeNode<TKey, TValue> read(IIterator<IBinaryTreeNode<TKey, TValue>> iterator) {
        if (!iterator.hasNext()) {
            return null;
        }

        IBinaryTreeNode<TKey, TValue> rootNode = iterator.next();

        boolean addLeftChild = true;

        while (iterator.hasNext()) {
            IBinaryTreeNode<TKey, TValue> childNode = this.read(iterator);

            if (childNode.getClass().isInstance(BinaryTreeEndNode.class)) {
                addLeftChild = true;
                break;
            }
            else if (addLeftChild) {
                rootNode.setLeftChild(childNode);
                addLeftChild = false;
            }
            else {
                rootNode.setRightChild(childNode);
                addLeftChild = true;
            }
        }

        return rootNode;
    }
}
