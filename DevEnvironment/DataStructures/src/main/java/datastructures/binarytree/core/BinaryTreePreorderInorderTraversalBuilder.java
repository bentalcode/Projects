package datastructures.binarytree.core;

import base.core.Conditions;
import base.core.Dimensions;
import base.interfaces.IBuilder;
import base.interfaces.IPair;
import datastructures.binarytree.BinaryTreeException;
import datastructures.binarytree.interfaces.IBinaryTree;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * The BinaryTreePreorderInorderTraversalBuilder class implements a builder of a binary tree
 * from an inorder and preorder traversal.
 */
public final class BinaryTreePreorderInorderTraversalBuilder<TKey extends Comparable<TKey>, TValue> implements
    IBuilder<IBinaryTree<TKey, TValue>> {

    private final List<IPair<TKey, TValue>> preorder;
    private final List<IPair<TKey, TValue>> inorder;

    /**
     * The BinaryTreePreorderInorderTraversalBuilder constructor.
     */
    public BinaryTreePreorderInorderTraversalBuilder(
        List<IPair<TKey, TValue>> preorder,
        List<IPair<TKey, TValue>> inorder) {

        Conditions.validateNotNull(preorder, "The preorder traversal data.");
        Conditions.validateNotNull(inorder, "The inorder traversal data.");

        if (preorder.size() != inorder.size())
        {
            String errorMessage = "The length of the preorder and inorder traversals do not match.";
            throw new BinaryTreeException(errorMessage);
        }

        this.preorder = preorder;
        this.inorder = inorder;
    }

    /**
     * Builds the binary tree.
     */
    @Override
    public IBinaryTree<TKey, TValue> build() {
        Map<TKey, Integer> inorderIndexMap = createIndexMap(this.inorder);

        if (this.preorder.isEmpty()) {
            return BinaryTree.make();
        }

        IBinaryTreeNode<TKey, TValue> root = build(
            this.preorder,
            this.inorder,
            0,
            this.preorder.size() - 1,
            0,
            this.inorder.size() - 1,
            inorderIndexMap);

        return BinaryTree.make(root);
    }

    /**
     * Builds the binary tree.
     */
    private static <TKey extends Comparable<TKey>, TValue> IBinaryTreeNode<TKey, TValue> build(
        List<IPair<TKey, TValue>> preorder,
        List<IPair<TKey, TValue>> inorder,
        int preorderStartIndex,
        int preorderEndIndex,
        int inorderStartIndex,
        int inorderEndIndex,
        Map<TKey, Integer> inorderIndexMap) {

        int preorderLength = Dimensions.length(preorderStartIndex, preorderEndIndex);
        int inorderLength = Dimensions.length(inorderStartIndex, inorderEndIndex);
        assert(preorderLength == inorderLength);

        int length = preorderLength;

        if (length == 0)
        {
            return null;
        }

        IPair<TKey, TValue> rootData = preorder.get(preorderStartIndex);
        IBinaryTreeNode<TKey, TValue> root = BinaryTreeNodes.make(rootData.first(), rootData.second());

        if (length == 1)
        {
            return root;
        }

        int rootIndex = getNodeIndex(inorderIndexMap, rootData.first());
        int leftSize = Dimensions.length(inorderStartIndex, rootIndex - 1);

        int preorderLeftStartIndex = preorderStartIndex + 1;
        int preorderLeftEndIndex = preorderStartIndex + leftSize;
        int inorderLeftStartIndex = inorderStartIndex;
        int inorderLeftEndIndex = rootIndex - 1;

        int preorderRightStartIndex = preorderLeftEndIndex + 1;
        int preorderRightEndIndex = preorderEndIndex;
        int inorderRightStartIndex = rootIndex + 1;
        int inorderRightEndIndex = inorderEndIndex;

        IBinaryTreeNode<TKey, TValue> leftChild = build(
            preorder,
            inorder,
            preorderLeftStartIndex,
            preorderLeftEndIndex,
            inorderLeftStartIndex,
            inorderLeftEndIndex,
            inorderIndexMap);

        IBinaryTreeNode<TKey, TValue> rightChild = build(
            preorder,
            inorder,
            preorderRightStartIndex,
            preorderRightEndIndex,
            inorderRightStartIndex,
            inorderRightEndIndex,
            inorderIndexMap);

        root.setLeftChild(leftChild);
        root.setRightChild(rightChild);

        return root;
    }

    /**
     * Creates an index map.
     */
    private static <TKey extends Comparable<TKey>, TValue> Map<TKey, Integer> createIndexMap(
        List<IPair<TKey, TValue>> data) {

        Map<TKey, Integer> result = new HashMap<>();

        for (int index = 0; index < data.size(); ++index) {
            TKey key = data.get(index).first();

            result.put(key, index);
        }

        return result;
    }

    /**
     * Gets an index of a node by a key.
     */
    private static <TKey extends Comparable<TKey>> int getNodeIndex(
        Map<TKey, Integer> indexMap,
        TKey key)
    {
        if (!indexMap.containsKey(key)) {
            String errorMessage =
                "The index of node with key: " + key +
                " was not found in the index map.";

            throw new BinaryTreeException(errorMessage);
        }

        return indexMap.get(key);
    }
}
