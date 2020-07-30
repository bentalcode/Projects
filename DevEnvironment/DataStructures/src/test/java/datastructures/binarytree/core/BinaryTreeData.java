package datastructures.binarytree.core;

import datastructures.binarytree.interfaces.IBinaryTreeData;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import java.util.List;

/**
 * The BinaryTreeData class implements the data of a binary tree.
 */
public final class BinaryTreeData<TKey extends Comparable<TKey>, TValue> implements IBinaryTreeData<TKey, TValue> {
    private final List<IBinaryTreeNode<TKey, TValue>> data;
    private final List<IBinaryTreeNode<TKey, TValue>> levelOrder;
    private final List<IBinaryTreeNode<TKey, TValue>> inorder;
    private final List<IBinaryTreeNode<TKey, TValue>> preorder;
    private final List<IBinaryTreeNode<TKey, TValue>> postorder;

    /**
     * The BinaryTreeData constructor.
     */
    public BinaryTreeData(
        List<IBinaryTreeNode<TKey, TValue>> data,
        List<IBinaryTreeNode<TKey, TValue>> levelOrder,
        List<IBinaryTreeNode<TKey, TValue>> inorder,
        List<IBinaryTreeNode<TKey, TValue>> preorder,
        List<IBinaryTreeNode<TKey, TValue>> postorder) {

        this.data = data;
        this.levelOrder = levelOrder;
        this.inorder = inorder;
        this.preorder = preorder;
        this.postorder = postorder;
    }

    /**
     * Gets the creation data.
     */
    @Override
    public List<IBinaryTreeNode<TKey, TValue>> getCreationData() {
        return this.data;
    }

    /**
     * Gets the level order nodes.
     */
    @Override
    public List<IBinaryTreeNode<TKey, TValue>> getLevelOrder() {
        return this.levelOrder;
    }

    /**
     * Gets the inorder nodes.
     */
    @Override
    public List<IBinaryTreeNode<TKey, TValue>> getInorder() {
        return this.inorder;
    }

    /**
     * Gets the preorder nodes.
     */
    @Override
    public List<IBinaryTreeNode<TKey, TValue>> getPreorder() {
        return this.preorder;
    }

    /**
     * Gets the postorder nodes.
     */
    @Override
    public List<IBinaryTreeNode<TKey, TValue>> getPostorder() {
        return this.postorder;
    }
}
