package datastructures.binarytree.core;

import base.core.Conditions;
import base.core.Indexes;
import base.interfaces.IPair;
import datastructures.binarytree.BinaryTreeException;
import datastructures.binarytree.interfaces.IBinaryTree;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import java.util.List;
import java.util.Map;

/**
 * The BinaryTreePreorderPostorderTraversalBuilder class implements a builder of a binary tree
 * from a preorder and a postorder traversal.
 */
public final class BinaryTreePreorderPostorderTraversalBuilder<TKey extends Comparable<TKey>, TValue> extends
    BinaryTreeTraversalBuilder<TKey, TValue> {

    private final List<IPair<TKey, TValue>> preorder;
    private final List<IPair<TKey, TValue>> postorder;

    /**
     * The BinaryTreePreorderPostorderTraversalBuilder constructor.
     */
    public BinaryTreePreorderPostorderTraversalBuilder(
        List<IPair<TKey, TValue>> preorder,
        List<IPair<TKey, TValue>> postorder) {

        Conditions.validateNotNull(preorder, "The preorder traversal data.");
        Conditions.validateNotNull(postorder, "The postorder traversal data.");

        if (preorder.size() != postorder.size()) {
            String errorMessage = "The length of a preorder and a postorder traversals do not match.";
            throw new BinaryTreeException(errorMessage);
        }

        this.preorder = preorder;
        this.postorder = postorder;
    }

    /**
     * Builds the binary tree.
     */
    @Override
    public IBinaryTree<TKey, TValue> build() {
        Map<TKey, Integer> postorderIndexMap = createIndexMap(this.postorder);

        if (this.preorder.isEmpty()) {
            return BinaryTree.make();
        }

        IBinaryTreeNode<TKey, TValue> root = build(
            this.preorder,
            this.postorder,
            0,
            this.preorder.size() - 1,
            0,
            this.postorder.size() - 1,
            postorderIndexMap);

        return BinaryTree.make(root);
    }

    /**
     * Builds the binary tree.
     */
    private static <TKey extends Comparable<TKey>, TValue> IBinaryTreeNode<TKey, TValue> build(
        List<IPair<TKey, TValue>> preorder,
        List<IPair<TKey, TValue>> postorder,
        int preorderStartIndex,
        int preorderEndIndex,
        int postorderStartIndex,
        int postorderEndIndex,
        Map<TKey, Integer> postorderIndexMap) {

        int preorderLength = Indexes.size(preorderStartIndex, preorderEndIndex);
        int postorderLength = Indexes.size(postorderStartIndex, postorderEndIndex);
        assert(preorderLength == postorderLength);

        if (preorderLength == 0) {
            return null;
        }

        IPair<TKey, TValue> rootData = preorder.get(preorderStartIndex);
        IBinaryTreeNode<TKey, TValue> root = BinaryTreeNodes.make(rootData.first(), rootData.second());

        if (preorderLength == 1) {
            return root;
        }

        IPair<TKey, TValue> leftRootData = preorder.get(preorderStartIndex + 1);
        int leftRootIndex = getNodeIndex(postorderIndexMap, leftRootData.first());
        int leftSize = Indexes.size(postorderStartIndex, leftRootIndex);

        int preorderLeftStartIndex = preorderStartIndex + 1;
        int preorderLeftEndIndex = preorderStartIndex + leftSize;
        int postorderLeftStartIndex = postorderStartIndex;
        int postorderLeftEndIndex = leftRootIndex;

        int preorderRightStartIndex = preorderLeftEndIndex + 1;
        int preorderRightEndIndex = preorderEndIndex;
        int postorderRightStartIndex = postorderLeftEndIndex + 1;
        int postorderRightEndIndex = postorderEndIndex - 1;

        IBinaryTreeNode<TKey, TValue> leftChild = build(
            preorder,
            postorder,
            preorderLeftStartIndex,
            preorderLeftEndIndex,
            postorderLeftStartIndex,
            postorderLeftEndIndex,
            postorderIndexMap);

        IBinaryTreeNode<TKey, TValue> rightChild = build(
            preorder,
            postorder,
            preorderRightStartIndex,
            preorderRightEndIndex,
            postorderRightStartIndex,
            postorderRightEndIndex,
            postorderIndexMap);

        root.setLeftChild(leftChild);
        root.setRightChild(rightChild);

        return root;
    }
}
