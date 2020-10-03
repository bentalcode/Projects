package datastructures.binarytree.core;

import datastructures.binarytree.interfaces.IBinaryTreeNode;

/**
 * The BinaryTreeNodes class implements a factory for creating nodes of a binary tree.
 */
public final class BinaryTreeNodes {
    /**
     * Creates a new binary tree node.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryTreeNode<TKey, TValue> make(TKey key, TValue value) {
        return new BinaryTreeNode<>(key, value);
    }

    /**
     * Creates a new binary tree end node.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryTreeNode<TKey, TValue> endNode() {
        return new BinaryTreeEndNode<>();
    }

    /**
     * Disables the default constructor, this is a static class.
     */
    private BinaryTreeNodes() {
    }
}
