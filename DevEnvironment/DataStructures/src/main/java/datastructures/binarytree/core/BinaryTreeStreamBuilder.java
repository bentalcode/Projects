package datastructures.binarytree.core;

import base.core.Conditions;
import base.interfaces.IBuilder;
import datastructures.binarytree.interfaces.IBinaryTree;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import datastructures.binarytree.interfaces.IBinaryTreeNodeIterator;
import java.util.List;

/**
 * The BinaryTreeStreamBuilder class implements a builder for a binary tree from a stream.
 */
public final class BinaryTreeStreamBuilder<TKey extends Comparable<TKey>, TValue> implements IBuilder<IBinaryTree<TKey, TValue>> {
    private final IBinaryTreeNodeIterator<IBinaryTreeNode<TKey, TValue>> iterator;

    /**
     * Builds a binary tree from a list of nodes.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryTree<TKey, TValue> build(
        List<IBinaryTreeNode<TKey, TValue>> nodes) {

        IBinaryTreeNodeIterator<IBinaryTreeNode<TKey, TValue>> dataIterator = BinaryTreeNodeListIterator.make(nodes);
        IBuilder<IBinaryTree<TKey, TValue>> builder = new BinaryTreeStreamBuilder<>(dataIterator);
        IBinaryTree<TKey, TValue> tree = builder.build();

        return tree;
    }

    /**
     * The BinaryTreeStreamBuilder constructor.
     */
    private BinaryTreeStreamBuilder(IBinaryTreeNodeIterator<IBinaryTreeNode<TKey, TValue>> iterator) {
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
        boolean previousStatus = this.iterator.getSkipIterator().disableSkipElements();
        IBinaryTreeNode<TKey, TValue> rootNode = this.read(this.iterator);
        this.iterator.getSkipIterator().setSkipElementsStatus(previousStatus);

        IBinaryTree<TKey, TValue> tree = new BinaryTree<>(rootNode);

        return tree;
    }

    /**
     * Reads the tree from an input stream.
     */
    private IBinaryTreeNode<TKey, TValue> read(IBinaryTreeNodeIterator<IBinaryTreeNode<TKey, TValue>> iterator) {
        if (!iterator.hasNext()) {
            return null;
        }

        IBinaryTreeNode<TKey, TValue> rootNode = iterator.next();

        if (this.iterator.getSkipIterator().isSkipElement(rootNode)) {
            return null;
        }

        if (iterator.hasNext()) {
            IBinaryTreeNode<TKey, TValue> childNode = this.read(iterator);

            if (childNode != null) {
                rootNode.setLeftChild(childNode);
            }
        }

        if (iterator.hasNext()) {
            IBinaryTreeNode<TKey, TValue> childNode = this.read(iterator);

            if (childNode != null) {
                rootNode.setRightChild(childNode);
            }
        }

        return rootNode;
    }
}
