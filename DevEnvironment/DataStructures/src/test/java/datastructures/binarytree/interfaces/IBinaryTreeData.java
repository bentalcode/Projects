package datastructures.binarytree.interfaces;

import base.interfaces.IPair;
import java.util.List;

/**
 * The IBinaryTreeData interface defines the data of a binary tree.
 */
public interface IBinaryTreeData<TKey extends Comparable<TKey>, TValue> {
    /**
     * Gets the creation data.
     */
    List<IBinaryTreeNode<TKey, TValue>> getCreationData();

    /**
     * Gets the level order nodes.
     */
    List<IBinaryTreeNode<TKey, TValue>> getLevelOrder();

    /**
     * Gets the inorder nodes.
     */
    List<IBinaryTreeNode<TKey, TValue>> getInorder();

    /**
     * Gets the preorder nodes.
     */
    List<IBinaryTreeNode<TKey, TValue>> getPreorder();

    /**
     * Gets the postorder nodes.
     */
    List<IBinaryTreeNode<TKey, TValue>> getPostorder();

    /**
     * Gets the level order data.
     */
    List<IPair<TKey, TValue>> getLevelOrderData();

    /**
     * Gets the inorder data.
     */
    List<IPair<TKey, TValue>> getInorderData();

    /**
     * Gets the preorder data.
     */
    List<IPair<TKey, TValue>> getPreorderData();

    /**
     * Gets the postorder data.
     */
    List<IPair<TKey, TValue>> getPostorderData();
}
