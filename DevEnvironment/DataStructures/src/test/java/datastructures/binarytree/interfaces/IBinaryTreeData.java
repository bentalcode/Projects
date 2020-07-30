package datastructures.binarytree.interfaces;

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
}
