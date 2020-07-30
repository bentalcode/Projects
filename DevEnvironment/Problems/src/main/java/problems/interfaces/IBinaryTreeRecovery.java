package problems.interfaces;

import datastructures.binarytree.interfaces.IBinaryTree;

/**
 * The IBinaryTreeRecovery interface defines recovery of a binary tree.
 */
public interface IBinaryTreeRecovery<TKey extends Comparable<TKey>, TValue> {
    /**
     * Recovers a binary tree.
     *
     * Two elements of a binary search tree (BST) are swapped by mistake.
     * Recover the tree without changing its structure.
     *
     * Returns false if the tree is not needed to get recovered.
     */
    boolean recover(IBinaryTree<TKey, TValue> tree);
}
