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
 * The BinaryTreePreorderInorderTraversalBuilder class implements a builder of a binary tree
 * from a preorder and an inorder traversal.
 */
public final class BinaryTreePreorderInorderTraversalBuilder<TKey extends Comparable<TKey>, TValue>
    extends BinaryTreeTraversalBuilder<TKey, TValue> {

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

        if (preorder.size() != inorder.size()) {
            String errorMessage = "The length of a preorder and a inorder traversals do not match.";
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

        int preorderLength = Indexes.size(preorderStartIndex, preorderEndIndex);
        int inorderLength = Indexes.size(inorderStartIndex, inorderEndIndex);
        assert(preorderLength == inorderLength);

        if (preorderLength == 0) {
            return null;
        }

        IPair<TKey, TValue> rootData = preorder.get(preorderStartIndex);
        IBinaryTreeNode<TKey, TValue> root = BinaryTreeNodes.make(rootData.first(), rootData.second());

        if (preorderLength == 1) {
            return root;
        }

        int rootIndex = getNodeIndex(inorderIndexMap, rootData.first());
        int leftSize = Indexes.size(inorderStartIndex, rootIndex - 1);

        IBinaryTreeNode<TKey, TValue> leftChild = build(
            preorder,
            inorder,
            preorderStartIndex + 1,
            preorderStartIndex + leftSize,
            inorderStartIndex,
            rootIndex - 1,
            inorderIndexMap);

        IBinaryTreeNode<TKey, TValue> rightChild = build(
            preorder,
            inorder,
            preorderStartIndex + leftSize + 1,
            preorderEndIndex,
            rootIndex + 1,
            inorderEndIndex,
            inorderIndexMap);

        root.setLeftChild(leftChild);
        root.setRightChild(rightChild);

        return root;
    }
}
