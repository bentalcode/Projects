package datastructures.binarytree.core;

import base.interfaces.IBuilder;
import base.interfaces.IPair;
import datastructures.binarytree.interfaces.IBinaryTree;
import java.util.List;

/**
 * The BinaryTreeTraversalBuilder class implements a builder of a binary tree from various traversals.
 */
public final class BinaryTreeTraversalBuilder {

    /**
     * Builds a binary tree from a preorder and an inorder traversal.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryTree<TKey, TValue> buildFromPreorderInorderTraversal(
        List<IPair<TKey, TValue>> preorder,
        List<IPair<TKey, TValue>> inorder) {

        IBuilder<IBinaryTree<TKey, TValue>> builder = new BinaryTreePreorderInorderTraversalBuilder<>(preorder, inorder);
        IBinaryTree<TKey, TValue> tree = builder.build();

        return tree;
    }

    /**
     * Disables the default constructor, this is a static class.
     */
    private BinaryTreeTraversalBuilder() {
    }
}
